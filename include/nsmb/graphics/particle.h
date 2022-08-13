#pragma once
#include "nsmb/math/vector.h"


/*
*	TODO:
*	should probably be in another file
*/

struct BossFileInfo {
	u32 file;
	u32 area;
};


struct SPLArcHdr;
struct SPLEmitter;
struct SPLManager;

using EmitterT = u32;

namespace Particle {


	class Emitter;
	class EmitterSystem;
	class ControllerBase;
	class Controller;
	class ControllerLiquid;
	class ControllerManualLiquid;
	class ControllerManual;
	class Handler;


	typedef void (*ParticleSystemCallback)(SPLEmitter* system, ...);


	class Emitter {
	public:

		u32 emitterID;
		u32 particleID;

		bool active;

		SPLEmitter* pSPLEmitter;
		ControllerBase* pController;

		Emitter* pNextEmitter; // linked list
		Emitter* pPrevEmitter;

		inline Emitter() {}

		// 0x2021c10
		sym bool start(u32 emitterID, u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* controller) __rbody

		// 0x2021bf0
		sym void end() __body

	};
	NTR_SIZE_GUARD(Emitter, 0x1C);


	class EmitterSystem {
	public:

		u32 numActiveEmitters;
		u8 curEmitterID;

		Emitter emitters[64];
		Emitter* activeEmitters[16];

		// 0x2021bac
		sym EmitterSystem() __body

		NTR_INLINE ~EmitterSystem() {
			unregisterAllEmitters();
		}

		// 0x2021ae8
		sym void destroyAllEmitters() __body

		// 0x2021a88
		sym void unregisterAllEmitters() __body

		// 0x2021a48
		sym Emitter* getEmitter(u32 emitterID) __rbody

		// 0x202194c
		sym u32 startEmitter(u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* controller) __rbody

		// 0x2021920
		sym void registerEmitter(Emitter* pEmitter) __body

		// 0x20218e0
		sym void unregisterEmitter(Emitter* pEmitter) __body
	};
	NTR_SIZE_GUARD(EmitterSystem, 0x748);


	class ControllerBase {
	public:

		NTR_INLINE ControllerBase() {}

		// 0x2021f08
		sym virtual void spawn(SPLEmitter* emitter) __body

		// 0x2021f00
		sym virtual bool destroy(SPLEmitter* emitter, bool generate) __rbody

	};
	NTR_SIZE_GUARD(ControllerBase, 0x4);


	class Controller : public ControllerBase {
	public:

		fx16 spawnRateDec; // ???

		// 0x2021eb8
		sym Controller() __body

		// 0x2021e8c
		sym virtual void spawn(SPLEmitter* emitter) override __body

		// 0x2021e7c
		sym virtual bool destroy(SPLEmitter* emitter, bool generate) override __rbody

	};
	NTR_SIZE_GUARD(Controller, 0x8);


	class ControllerLiquid : public Controller {
	public:

		NTR_INLINE ControllerLiquid() {} // the one at 0x2021edc doesn't set the vtable, there could even be another class between this one and Controller

		// 0x2021e00
		sym virtual bool destroy(SPLEmitter* pEmitter, bool generate) override __rbody

	};
	NTR_SIZE_GUARD(ControllerLiquid, sizeof(Controller));


	class ControllerManualLiquid : public ControllerBase {
	public:

		NTR_INLINE ControllerManualLiquid() {}

		// 0x2021d78
		sym virtual bool destroy(SPLEmitter* pEmitter, bool generate) override __rbody

	};
	NTR_SIZE_GUARD(ControllerManualLiquid, sizeof(ControllerBase));


	class ControllerManual : public ControllerBase {
	public:

		NTR_INLINE ControllerManual() {}

		// 0x2021d20
		sym virtual bool destroy(SPLEmitter* pEmitter, bool generate) override __rbody

		// 0x2021cfc
		sym static ControllerManual* getHandlerController() __rbody

	};
	NTR_SIZE_GUARD(ControllerManual, sizeof(ControllerBase));


	/*
		The interface between the game and the SPL library.
		Used to load, create, update and render particles
	*/
	class Handler {
	public:

		enum class STDParticleID {
			Course,
			WorldMap,
			Cutscene
		};

		SPLArcHdr* pSPA;
		SPLArcHdr* pBossSPA;

		SPLManager* pSPLManager;
		SPLManager* pBossSPLManager;

		EmitterSystem emitterSystem;

		u32			smokePuffEmitterID;
		Controller	smokePuffController;

		u32					bubblesEmitterID;
		ControllerLiquid	bubblesController;

		ControllerManualLiquid	controllerManualLiquid;
		ControllerManual		controllerManual;

		u32			bigGraySmokeEmitterID;
		Controller	bigGraySmokeController;

		u32			graySmokeEmitterID;
		Controller	graySmokeController;

		u32			flashEmitterID;
		Controller	flashController;

		u32			expandingGraySmokeEmitterID;
		Controller	expandingGraySmokeController;

		u32			bigFlashEmitterID;
		Controller	bigFlashController;

		u32			bigExpandingGraySmokeEmitterID;
		Controller	bigExpandingGraySmokeController;

		u32			littleSmokeEmitterID;
		Controller	littleSmokeController;

		u32			littleWhiteSmokeEmitterID;
		Controller	littleWhiteSmokeController;

		u32			unusedEmitterID;
		Controller	unusedController;

		u32			glitterStarsEmitterID;
		Controller	glitterStarsController;

		// DATA


		// 0x203cf80
		static bool bParticlesEnabled;


		// BSS


		// 0x208b4f8
		static u16 nMaxSPLParticles;

		// 0x208b4fc
		static u16 nMaxSPLParticlesBoss;

		// 0x208b500
		static u16 nMaxSPLEmitters;

		// 0x208b504
		static u16 nMaxSPLEmittersBoss;

		// 0x208b508
		static u16 nMaxSystemEmitters;


		// 0x208b50C
		static void* pParticleHeapBeg;

		// 0x208b510
		static void* pParticleHeapCur;

		// 0x208b514
		static void* pParticleHeapEnd;


		// 0x208b518
		static SPLArcHdr* pMiniGamesSPA;

		// 0x208b51c
		static SPLManager* pCurSPLManager;

		// 0x208b520
		static Handler* pHandler;

		// 0x208b524
		static SPLArcHdr* pMainGameSPA;


		// 0x2023180
		sym Handler() __body

		// 0x2023118
		// 0x20230a8
		sym virtual ~Handler() __body


		// 0x202308c
		sym static void* allocate(u32 size) __rbody

		// 0x2022dd0
		sym void init(u32 id) __body

		// 0x2022d98
		sym static BossFileInfo* getBossParticleInfo(u32 area) __rbody

		// 0x2022d68
		sym static u32 getBossParticleFileID(u32 area) __rbody

		// 0x2022cb4
		sym void initBoss() __body

		// 0x2022c3c
		sym void updateParticles() __body

		// 0x2022be4
		sym static void renderParticles() __body

		// 0x2022b64
		sym static void createParticle(u32 particleID, const Vec3& position) __body

		// 0x2022aac
		sym static void createParticleEx(u32 particleID, const Vec3& position, void* arg, ParticleSystemCallback func) __body

		// 0x2022a90
		sym static void setAxisCallback(SPLEmitter* emitter, const VecFx16& axis) __body

		// 0x2022a7c
		sym static void createParticleAxis(u32 particleID, const Vec3& position, const VecFx16* axis) __body

		// 0x2022a70
		sym static void setSimpleCollisionYCallback(SPLEmitter* emitter, const fx32& collY) __body

		// 0x2022a64
		sym static void setRadiusCallback(SPLEmitter* emitter, const fx32& radius) __body

		// 0x2022a50
		sym static void createParticleRadius(u32 particleID, const Vec3& position, const fx32* radius) __body

		// 0x2022a44
		sym static void setParticleLifeCallback(SPLEmitter* emitter, const u16& life) __body

		// 0x2022a30
		sym static void createParticleLife(u32 particleID, const Vec3& position, const u16* life) __body

		// 0x2022a04
		sym static SPLEmitter* getSPLEmitter(u32 emitterID) __rbody

		// 0x2022890
		sym static u32 runEmitter(u32 emitterID, u32 particleID, const Vec3& position, const VecFx16* axis = nullptr, const fx32* collY = nullptr, const fx16* baseScale = nullptr, ControllerBase* controller = nullptr) __rbody

		// 0x2022824
		sym static u32 runEmitterBoss(u32 emitterID, u32 particleID, const Vec3& position, const VecFx16* axis = nullptr, const fx32* collY = nullptr, const fx16* baseScale = nullptr, ControllerBase* controller = nullptr) __rbody

		// 0x20227bc
		sym static u32 runEmitterManualLiquid(u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis = nullptr) __rbody

		// 0x2022754
		sym static u32 runEmitterManual(u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis = nullptr) __rbody

		// 0x20226e4
		sym static u32 createSmokePuff(fx32 x, fx32 y, fx32 z) __rbody

		// 0x2022674
		sym static u32 createRockSmoke(fx32 x, fx32 y, fx32 z) __rbody

		// 0x20226fc
		sym static u32 createBigRockSmoke(fx32 x, fx32 y, fx32 z) __rbody

		// 0x2022528
		sym static u32 createRockExplosion(fx32 x, fx32 y, fx32 z) __rbody

		// 0x202245c
		sym static u32 createBigRockExplosion(fx32 x, fx32 y, fx32 z) __rbody

		// 0x20223e4
		sym static u32 createSandSmoke(fx32 x, fx32 y, fx32 z) __rbody

		// 0x2022364
		sym static u32 createLittleWhiteSmoke(fx32 x, fx32 y, fx32 z) __rbody

		// 0x20222ec
		sym static u32 createGlitterStars(fx32 x, fx32 y, fx32 z) __rbody

		// 0x2022274
		sym static u32 createBubbles(fx32 x, fx32 y, fx32 z) __rbody

		// 0x2022244
		sym static void createBigSmokePuff(const Vec3& position) __body

		// 0x2022220
		sym static void createSmokePuff(const Vec3& position) __body

		// 0x20221fc
		sym static void createWaterParticles(const Vec3& position) __body

		// 0x20221d8
		sym static void createLavaParticles(const Vec3& position) __body

		// 0x20221b4
		sym static void createPoisonedWaterParticles(const Vec3& position) __body

		// 0x2022134
		sym static void createParticleBoss(u32 particleID, const Vec3& position) __body

		// 0x20220d8
		sym static void createParticleBossSimpleCollisionY(u32 particleID, const Vec3& position, const fx32* collY) __body

		// 0x20220a4
		sym static SPLEmitter* getSPLEmitterSafe(u32 emitterID) __rbody // checks if Emitter is nullptr before accessing SPLEmitter.

		// 0x2022074
		sym static void stopEmitterGeneration(u32 emitterID) __body

		// 0x2022020
		sym static void stopEmitterGenerationBoss(u32 emitterID) __body // swaps SPLEmitter and calls stopEmitterGeneration, despite it not using SPLEmitter directly at all

		// 0x2022008
		sym static void setEmitterGenerationRate(u32 emitterID, u32 rate) __body

		// 0x2021ff0
		sym static void setEmitterParticleLife(u32 emitterID, u16 life) __body

		// 0x2021f7c
		sym static u32 runEmitterInitialVelocityAxis(u32 emitterID, u32 particleID, const Vec3& position, const VecFx16* axis = nullptr, const fx32* collY = nullptr, const fx16* baseScale = nullptr, const fx16* initVelocityAxis = nullptr, ControllerBase* controller = nullptr) __rbody

		// 0x2021f58
		sym static void setPolygonAttributeBoss(u32 attribute) __body

		// 0x2021f30
		sym static void resetPolygonAttributeBoss(u32 attribute) __body

		// 0x2021f0c
		sym static void disable() __body
	};
	NTR_SIZE_GUARD(Handler, 0x7F4);

}
