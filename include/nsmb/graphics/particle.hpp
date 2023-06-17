#pragma once
#include "nsmb/math/vector.hpp"


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
		bool start(u32 emitterID, u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* controller);

		// 0x2021bf0
		void end();

	};
	NTR_SIZE_GUARD(Emitter, 0x1C);


	class EmitterSystem {
	public:

		u32 numActiveEmitters;
		u8 curEmitterID;

		Emitter emitters[64];
		Emitter* activeEmitters[16];

		// 0x2021bac
		EmitterSystem();

		NTR_INLINE ~EmitterSystem() {
			unregisterAllEmitters();
		}

		// 0x2021ae8
		void destroyAllEmitters();

		// 0x2021a88
		void unregisterAllEmitters();

		// 0x2021a48
		Emitter* getEmitter(u32 emitterID);

		// 0x202194c
		u32 startEmitter(u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* controller);

		// 0x2021920
		void registerEmitter(Emitter* pEmitter);

		// 0x20218e0
		void unregisterEmitter(Emitter* pEmitter);
	};
	NTR_SIZE_GUARD(EmitterSystem, 0x748);


	class ControllerBase {
	public:

		NTR_INLINE ControllerBase() {}

		// 0x2021f08
		virtual void spawn(SPLEmitter* emitter);

		// 0x2021f00
		virtual bool destroy(SPLEmitter* emitter, bool generate);

	};
	NTR_SIZE_GUARD(ControllerBase, 0x4);


	class Controller : public ControllerBase {
	public:

		fx16 spawnRateDec; // ???

		// 0x2021eb8
		Controller();

		// 0x2021e8c
		virtual void spawn(SPLEmitter* emitter) override;

		// 0x2021e7c
		virtual bool destroy(SPLEmitter* emitter, bool generate) override;

	};
	NTR_SIZE_GUARD(Controller, 0x8);


	class ControllerLiquid : public Controller {
	public:

		NTR_INLINE ControllerLiquid() {} // the one at 0x2021edc doesn't set the vtable, there could even be another class between this one and Controller

		// 0x2021e00
		virtual bool destroy(SPLEmitter* pEmitter, bool generate) override;

	};
	NTR_SIZE_GUARD(ControllerLiquid, sizeof(Controller));


	class ControllerManualLiquid : public ControllerBase {
	public:

		NTR_INLINE ControllerManualLiquid() {}

		// 0x2021d78
		virtual bool destroy(SPLEmitter* pEmitter, bool generate) override;

	};
	NTR_SIZE_GUARD(ControllerManualLiquid, sizeof(ControllerBase));


	class ControllerManual : public ControllerBase {
	public:

		NTR_INLINE ControllerManual() {}

		// 0x2021d20
		virtual bool destroy(SPLEmitter* pEmitter, bool generate) override;

		// 0x2021cfc
		static ControllerManual* getHandlerController();

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
		Handler();

		// 0x2023118
		// 0x20230a8
		virtual ~Handler();


		// 0x202308c
		static void* allocate(u32 size);

		// 0x2022dd0
		void init(u32 id);

		// 0x2022d98
		static BossFileInfo* getBossParticleInfo(u32 area);

		// 0x2022d68
		static u32 getBossParticleFileID(u32 area);

		// 0x2022cb4
		void initBoss();

		// 0x2022c3c
		void updateParticles();

		// 0x2022be4
		static void renderParticles();

		// 0x2022b64
		static void createParticle(u32 particleID, const Vec3& position);

		// 0x2022aac
		static void createParticleEx(u32 particleID, const Vec3& position, void* arg, ParticleSystemCallback func);

		// 0x2022a90
		static void setAxisCallback(SPLEmitter* emitter, const VecFx16& axis);

		// 0x2022a7c
		static void createParticleAxis(u32 particleID, const Vec3& position, const VecFx16* axis);

		// 0x2022a70
		static void setSimpleCollisionYCallback(SPLEmitter* emitter, const fx32& collY);

		// 0x2022a64
		static void setRadiusCallback(SPLEmitter* emitter, const fx32& radius);

		// 0x2022a50
		static void createParticleRadius(u32 particleID, const Vec3& position, const fx32* radius);

		// 0x2022a44
		static void setParticleLifeCallback(SPLEmitter* emitter, const u16& life);

		// 0x2022a30
		static void createParticleLife(u32 particleID, const Vec3& position, const u16* life);

		// 0x2022a04
		static SPLEmitter* getSPLEmitter(u32 emitterID);

		// 0x2022890
		static u32 runEmitter(u32 emitterID, u32 particleID, const Vec3& position, const VecFx16* axis = nullptr, const fx32* collY = nullptr, const fx16* baseScale = nullptr, ControllerBase* controller = nullptr);

		// 0x2022824
		static u32 runEmitterBoss(u32 emitterID, u32 particleID, const Vec3& position, const VecFx16* axis = nullptr, const fx32* collY = nullptr, const fx16* baseScale = nullptr, ControllerBase* controller = nullptr);

		// 0x20227bc
		static u32 runEmitterManualLiquid(u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis = nullptr);

		// 0x2022754
		static u32 runEmitterManual(u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis = nullptr);

		// 0x20226e4
		static u32 createSmokePuff(fx32 x, fx32 y, fx32 z);

		// 0x2022674
		static u32 createRockSmoke(fx32 x, fx32 y, fx32 z);

		// 0x20226fc
		static u32 createBigRockSmoke(fx32 x, fx32 y, fx32 z);

		// 0x2022528
		static u32 createRockExplosion(fx32 x, fx32 y, fx32 z);

		// 0x202245c
		static u32 createBigRockExplosion(fx32 x, fx32 y, fx32 z);

		// 0x20223e4
		static u32 createSandSmoke(fx32 x, fx32 y, fx32 z);

		// 0x2022364
		static u32 createLittleWhiteSmoke(fx32 x, fx32 y, fx32 z);

		// 0x20222ec
		static u32 createGlitterStars(fx32 x, fx32 y, fx32 z);

		// 0x2022274
		static u32 createBubbles(fx32 x, fx32 y, fx32 z);

		// 0x2022244
		static void createBigSmokePuff(const Vec3& position);

		// 0x2022220
		static void createSmokePuff(const Vec3& position);

		// 0x20221fc
		static void createWaterParticles(const Vec3& position);

		// 0x20221d8
		static void createLavaParticles(const Vec3& position);

		// 0x20221b4
		static void createPoisonedWaterParticles(const Vec3& position);

		// 0x2022134
		static void createParticleBoss(u32 particleID, const Vec3& position);

		// 0x20220d8
		static void createParticleBossSimpleCollisionY(u32 particleID, const Vec3& position, const fx32* collY);

		// 0x20220a4
		static SPLEmitter* getSPLEmitterSafe(u32 emitterID); // checks if Emitter is nullptr before accessing SPLEmitter.

		// 0x2022074
		static void stopEmitterGeneration(u32 emitterID);

		// 0x2022020
		static void stopEmitterGenerationBoss(u32 emitterID); // swaps SPLEmitter and calls stopEmitterGeneration, despite it not using SPLEmitter directly at all

		// 0x2022008
		static void setEmitterGenerationRate(u32 emitterID, u32 rate);

		// 0x2021ff0
		static void setEmitterParticleLife(u32 emitterID, u16 life);

		// 0x2021f7c
		static u32 runEmitterInitialVelocityAxis(u32 emitterID, u32 particleID, const Vec3& position, const VecFx16* axis = nullptr, const fx32* collY = nullptr, const fx16* baseScale = nullptr, const fx16* initVelocityAxis = nullptr, ControllerBase* controller = nullptr);

		// 0x2021f58
		static void setPolygonAttributeBoss(u32 attribute);

		// 0x2021f30
		static void resetPolygonAttributeBoss(u32 attribute);

		// 0x2021f0c
		static void disable();
	};
	NTR_SIZE_GUARD(Handler, 0x7F4);

}
