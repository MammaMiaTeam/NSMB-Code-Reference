#ifndef NSMB_PARTICLE_H_
#define NSMB_PARTICLE_H_

#include "nitro_if.h"
#include "nsmb/vector.h"

// should probably be in another file
struct BossFileInfo {
	u32 file;
	u32 area;
};

namespace Particle {

	struct SPLEmitter;
	struct SPLManager;

	class Emitter;
	class EmitterSystem;
	class ControllerBase;
	class Controller;
	class ControllerLiquid;
	class ControllerManualLiquid;
	class ControllerManual;
	class Handler;


	typedef void (ParticleSystemCallback)(SPLEmitter* system, ...);


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
		GEN_FUNC(void start,u32 emitterID, u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x2021bf0
		GEN_FUNC(void end);

	};

	class EmitterSystem {
	public:

		u32 numActiveEmitters;
		u8 curEmitterID;

		Emitter emitters[64];
		Emitter* activeEmitters[16];

		// 0x2021bac
		GEN_FUNC(EmitterSystem);

		inline ~EmitterSystem() {
			unregisterAllEmitters();
		}

		// 0x2021ae8
		GEN_FUNC(void destroyAllEmitters);

		// 0x2021a88
		GEN_FUNC(void unregisterAllEmitters);

		// 0x2021a48
		GEN_FUNC(Emitter* getEmitter,u32 emitterID);

		// 0x202194c
		GEN_FUNC(u32 startFreeEmitter,u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x2021920
		GEN_FUNC(void registerEmitter,Emitter* pEmitter);

		// 0x20218e0
		GEN_FUNC(void unregisterEmitter,Emitter* pEmitter);
	};

	class ControllerBase {
	public:

		inline ControllerBase() {}

		// 0x2021f08
		GEN_FUNC(virtual void spawn,void* pEmitter);

		// 0x2021f00
		GEN_FUNC(virtual BOOL destroy,void* pEmitter, BOOL generate);

	};

	class Controller : public ControllerBase {
	public:

		fx16 spawnRateDec; // ???

		// 0x2021eb8
		GEN_FUNC(Controller);

		// 0x2021e8c
		GEN_FUNC(virtual void spawn,void* pEmitter)// override;

		// 0x2021e7c
		GEN_FUNC(virtual BOOL destroy,void* pEmitter, BOOL generate)// override;

	};

	class ControllerLiquid : public Controller {
	public:

		inline ControllerLiquid() {} // the one at 0x2021edc doesn't set the vtable, there could even be another class between this one and Controller

		// 0x2021e00
		GEN_FUNC(virtual BOOL destroy,void* pEmitter, BOOL generate)// override;

	};

	class ControllerManualLiquid : public ControllerBase {
	public:

		inline ControllerManualLiquid() {}

		// 0x2021d78
		GEN_FUNC(virtual BOOL destroy,void* pEmitter, BOOL generate) //override;

	};

	class ControllerManual : public ControllerBase {
	public:

		inline ControllerManual() {}

		// 0x2021d20
		GEN_FUNC(virtual BOOL destroy,void* pEmitter, BOOL generate) //override;

		// 0x2021cfc
		GEN_FUNC(static ControllerManual* getHandlerController);

	};

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

		void* pSPA;				// SPLArcHdr*
		void* pBossSPA;			// SPLArcHdr*

		void* pSPLManager;		// SPLManager*
		void* pBossSPLManager;	// SPLManager*

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
		static void* pMiniGamesSPA;

		// 0x208b51c
		static SPLManager* pCurSPLManager;

		// 0x208b520
		static Handler* pHandler;

		// 0x208b524
		static void* pMainGameSPA;


		// 0x2023180
		GEN_FUNC(Handler);

		// 0x2023118
		// 0x20230a8
		GEN_FUNC(virtual ~Handler);


		// 0x202308c
		GEN_FUNC(static void* allocate,u32 size);

		// 0x2022dd0
		GEN_FUNC(void init,u32 id);

		// 0x2022d98
		GEN_FUNC(static BossFileInfo* getBossParticleInfo,u32 area);

		// 0x2022d68
		GEN_FUNC(static u32 getBossParticleFileID,u32 area);

		// 0x2022cb4
		GEN_FUNC(void initBoss);

		// 0x2022c3c
		GEN_FUNC(void updateParticles);

		// 0x2022be4
		GEN_FUNC(static void renderParticles);

		// 0x2022b64
		GEN_FUNC(static void createParticle,u32 particleID, const Vec3* position);

		// 0x2022aac
		GEN_FUNC(static void createParticleEx,u32 particleID, const Vec3* position, void* pArg, ParticleSystemCallback* pFunc);

		// 0x2022a90
		GEN_FUNC(static void setAxisCallback,SPLEmitter* pEmitter, const VecFx16* axis);

		// 0x2022a7c
		GEN_FUNC(static void createParticleAxis,u32 particleID, const Vec3* position, const VecFx16* axis);

		// 0x2022a70
		GEN_FUNC(static void setSimpleCollisionYCallback,SPLEmitter* pEmitter, const fx32* collY);

		// 0x2022a64
		GEN_FUNC(static void setRadiusCallback,SPLEmitter* pEmitter, const fx32* radius);

		// 0x2022a50
		GEN_FUNC(static void createParticleRadius,u32 particleID, const Vec3* position, const fx32* radius);

		// 0x2022a44
		GEN_FUNC(static void setParticleLifeCallback,SPLEmitter* pEmitter, const u16* life);

		// 0x2022a30
		GEN_FUNC(static void createParticleLife,u32 particleID, const Vec3* position, const u16* life);

		// 0x2022a04
		GEN_FUNC(static SPLEmitter* getSPLEmitter,u32 emitterID);

		// 0x2022890
		GEN_FUNC(static u32 runEmitter,u32 emitterID, u32 particleID, const Vec3* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x2022824
		GEN_FUNC(static u32 runEmitterBoss,u32 emitterID, u32 particleID, const Vec3* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x20227bc
		GEN_FUNC(static u32 runEmitterManualLiquid,u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis);

		// 0x2022754
		GEN_FUNC(static u32 runEmitterManual,u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis);

		// 0x20226e4
		GEN_FUNC(static u32 createSmokePuff,fx32 x, fx32 y, fx32 z);

		// 0x2022674
		GEN_FUNC(static u32 createRockSmoke,fx32 x, fx32 y, fx32 z);

		// 0x20226fc
		GEN_FUNC(static u32 createBigRockSmoke,fx32 x, fx32 y, fx32 z);

		// 0x2022528
		GEN_FUNC(static u32 createRockExplosion,fx32 x, fx32 y, fx32 z);

		// 0x202245c
		GEN_FUNC(static u32 createBigRockExplosion,fx32 x, fx32 y, fx32 z);

		// 0x20223e4
		GEN_FUNC(static u32 createLittleSmoke,fx32 x, fx32 y, fx32 z);

		// 0x2022364
		GEN_FUNC(static u32 createLittleWhiteSmoke,fx32 x, fx32 y, fx32 z);

		// 0x20222ec
		GEN_FUNC(static u32 createGlitterStars,fx32 x, fx32 y, fx32 z);

		// 0x2022274
		GEN_FUNC(static u32 createBubbles,fx32 x, fx32 y, fx32 z);

		// 0x2022244
		GEN_FUNC(static void createBigSmokePuff,const Vec3* position);

		// 0x2022220
		GEN_FUNC(static void createSmokePuff,const Vec3* position);

		// 0x20221fc
		GEN_FUNC(static void createWaterParticles,const Vec3* position);

		// 0x20221d8
		GEN_FUNC(static void createLavaParticles,const Vec3* position);

		// 0x20221b4
		GEN_FUNC(static void createPoisonedWaterParticles,const Vec3* position);

		// 0x2022134
		GEN_FUNC(static void createParticleBoss,u32 particleID, const Vec3* position);

		// 0x20220d8
		GEN_FUNC(static void createParticleBossSimpleCollisionY,u32 particleID, const Vec3* position, const fx32* collY);

		// 0x20220a4
		GEN_FUNC(static SPLEmitter* getSPLEmitterSafe,u32 emitterID); // checks if Emitter is nullptr before accessing SPLEmitter.

		// 0x2022074
		GEN_FUNC(static void stopEmitterGeneration,u32 emitterID);

		// 0x2022020
		GEN_FUNC(static void stopEmitterGenerationBoss,u32 emitterID); // swaps SPLEmitter and calls stopEmitterGeneration, despite it not using SPLEmitter directly at all

		// 0x2022008
		GEN_FUNC(static void setEmitterGenerationRate,u32 emitterID, u32 rate);

		// 0x2021ff0
		GEN_FUNC(static void setEmitterParticleLife,u32 emitterID, u16 life);

		// 0x2021f7c
		GEN_FUNC(static u32 runEmitterInitialVelocityAxis,u32 emitterID, u32 particleID, const Vec3* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, const fx16* initVelocityAxis, ControllerBase* pController);

		// 0x2021f58
		GEN_FUNC(static void setPolygonAttributeBoss,u32 attribute);

		// 0x2021f30
		GEN_FUNC(static void resetPolygonAttributeBoss,u32 attribute);

		// 0x2021f0c
		GEN_FUNC(static void disable);
	};

}

#endif // !NSMB_PARTICLE_H_
