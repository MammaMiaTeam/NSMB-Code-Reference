#ifndef NSMB_PARTICLE_INCLUDED
#define NSMB_PARTICLE_INCLUDED

#include "nitro_if.h"

#include "Vector.h"

// should probably be in another file
struct BossFileInfo {
	u32 file;
	u32 area;
};

namespace Particle {

	struct SPLEmitter;
	struct SPLManager;

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
		void start(u32 emitterID, u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x2021bf0
		void end();

	};

	class StaticSystem {
	public:

		u32 numActiveEmitters;
		u8 curEmitterID;

		Emitter emitters[64];
		Emitter* activeEmitters[16];

		// 0x2021bac
		StaticSystem();

		inline ~StaticSystem() {
			unregisterAllEmitters();
		}

		// 0x2021ae8
		void destroyAllEmitters();

		// 0x2021a88
		void unregisterAllEmitters();

		// 0x2021a48
		Emitter* getEmitter(u32 emitterID);

		// 0x202194c
		u32 startFreeEmitter(u32 particleID, const VecFx32* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x2021920
		void registerEmitter(Emitter* pEmitter);

		// 0x20218e0
		void unregisterEmitter(Emitter* pEmitter);
	};

	class ControllerBase {
	public:

		inline ControllerBase() {}

		// 0x2021f08
		virtual void spawn(void* pEmitter);

		// 0x2021f00
		virtual BOOL destroy(void* pEmitter, BOOL generate);

	};

	class Controller : public ControllerBase {
	public:

		fx16 spawnRateDec; // ???

		// 0x2021eb8
		Controller();

		// 0x2021e8c
		void spawn(void* pEmitter) override;

		// 0x2021e7c
		void destroy(void* pEmitter, BOOL generate) override;

	};

	class ControllerLiquid : public Controller {
	public:

		inline ControllerLiquid() {} // the one at 0x2021edc doesn't set the vtable, there could even be another class between this one and Controller

		// 0x2021e00
		void destroy(void* pEmitter, BOOL generate) override;

	};

	class ControllerManualLiquid : public ControllerBase {
	public:

		inline ControllerManualLiquid() {}

		// 0x2021d78
		void destroy(void* pEmitter, BOOL generate) override;

	};

	class ControllerManual : public ControllerBase {
	public:

		inline ControllerManual() {}

		// 0x2021d20
		void destroy(void* pEmitter, BOOL generate) override;

		// 0x2021cfc
		static ControllerManual* getHandlerController();

	};

	/*
		The interface between the game and the SPL library.
		Used to load, create, update and render particles
	*/
	class Handler {
	public:

		enum STDParticleID {
			PCL_COURSE,
			PCL_WORLDMAP,
			PCL_CUTSCENE
		};

		void* pSPA;				// SPLArcHdr*
		void* pBossSPA;			// SPLArcHdr*

		void* pSPLManager;		// SPLManager*
		void* pBossSPLManager;	// SPLManager*

		StaticSystem sSystem;

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
		static u16 nMaxParticles;

		// 0x208b4fc
		static u16 nMaxParticlesBoss;

		// 0x208b500
		static u16 nMaxEmitters;

		// 0x208b504
		static u16 nMaxEmittersBoss;

		// 0x208b508
		static u16 nMaxEmittersBoss;


		// 0x208b50C
		static void* pParticleHeapBeg;

		// 0x208b510
		static void* pParticleHeapCur;

		// 0x208b514
		static void* pParticleHeapEnd;


		// 0x208b518
		static void* pMinigamesSPA;

		// 0x208b51c
		static SPLManager* pCurSPLManager;

		// 0x208b520
		static Handler* pHandler;

		// 0x208b524
		static void* pSPA;


		// 0x2023180
		Handler();

		// 0x2023118
		// 0x20230a8
		virtual ~Handler();


		// 0x202308c
		static void* allocate(u32 size);

		// 0x2022dd0
		void init(STDParticleID id);

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
		static void createParticle(u32 particleID, const Vec3* position);

		// 0x2022aac
		static void createParticleEx(u32 particleID, const Vec3* position, void* pArg, ParticleSystemCallback* pFunc);

		// 0x2022a90
		static void setAxisCallback(SPLEmitter* pEmitter, const VecFx16* axis);

		// 0x2022a7c
		static void createParticle_axis(u32 particleID, const Vec3* position, const VecFx16* axis);

		// 0x2022a70
		static void setSimpleCollisionYCallback(SPLEmitter* pEmitter, const fx32* collY);

		// 0x2022a64
		static void setRadiusCallback(SPLEmitter* pEmitter, const fx32* radius);

		// 0x2022a50
		static void createParticle_radius(u32 particleID, const Vec3* position, const fx32* radius);

		// 0x2022a44
		static void setParticleLifeCallback(SPLEmitter* pEmitter, const u16* life);

		// 0x2022a30
		static void createParticle_life(u32 particleID, const Vec3* position, const u16* life);

		// 0x2022a04
		static SPLEmitter* getSPLEmitter(u32 emitterID);

		// 0x2022890
		static u32 createStaticParticle(u32 emitterID, u32 particleID, const Vec3* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x2022824
		static u32 createStaticParticle_boss(u32 emitterID, u32 particleID, const Vec3* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, ControllerBase* pController);

		// 0x20227bc
		static u32 createStaticParticle_manualLiquid(u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis);

		// 0x2022754
		static u32 createStaticParticle_manual(u32 emitterID, u32 pclID, fx32 x, fx32 y, fx32 z, const VecFx16* axis);

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
		static u32 createLittleSmoke(fx32 x, fx32 y, fx32 z);

		// 0x2022364
		static u32 createLittleWhiteSmoke(fx32 x, fx32 y, fx32 z);

		// 0x20222ec
		static u32 createGlitterStars(fx32 x, fx32 y, fx32 z);

		// 0x2022274
		static u32 createBubbles(fx32 x, fx32 y, fx32 z);

		// 0x2022244
		static void createBigSmokePuff(const Vec3* position);

		// 0x2022220
		static void createSmokePuff(const Vec3* position);

		// 0x20221fc
		static void createWaterParticles(const Vec3* position);

		// 0x20221d8
		static void createLavaParticles(const Vec3* position);

		// 0x20221b4
		static void createPoisonedWaterParticles(const Vec3* position);

		// 0x2022134
		static void createParticle_boss(u32 particleID, const Vec3* position);

		// 0x20220d8
		static void createParticleBoss_simpleCollisionY(u32 particleID, const Vec3* position, const fx32* collY);

		// 0x20220a4
		static SPLEmitter* getSPLEmitter_safe(u32 emitterID); // checks if Emitter is nullptr before accessing SPLEmitter.

		// 0x2022074
		static void stopEmitterGeneration(u32 emitterID);

		// 0x2022020
		static void stopEmitterGeneration_boss(u32 emitterID); // swaps SPLEmitter and calls stopEmitterGeneration, despite it not using SPLEmitter directly at all

		// 0x2022008
		static void setEmitterGenerationRate(u32 emitterID, u32 rate);

		// 0x2021ff0
		static void setEmitterParticleLife(u32 emitterID, u16 life);

		// 0x2021f7c
		static u32 createStaticParticle_initialVelocityAxis(u32 emitterID, u32 particleID, const Vec3* position, const VecFx16* axis, const fx32* collY, const fx16* baseScale, const fx16* initVelocityAxis, ControllerBase* pController);

		// 0x2021f58
		static void setPolygonAttribute_boss(u32 attribute);

		// 0x2021f30
		static void resetPolygonAttribute_boss(u32 attribute);

		// 0x2021f0c
		static void disable();
	};

}

#endif	// NSMB_PARTICLE_INCLUDED
