#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/modelanm.hpp>

// ov42
class BobOmb : public StageEntity {
public:

	using StateFunction = bool(BobOmb::*)();

	enum Direction {
		Up,
		Down,
		Left,
		Right
	};


	virtual ~BobOmb();

	s32 onCreate() override;
	s32 onDestroy() override;
	s32 onRender() override;
	void onCleanupResources() override;
	bool onPrepareResources() override;

	bool updateMain() override;
	bool updateCarried() override;
	bool updateDropped() override;

	void updateAnimation() override;
	void thrown() override;
	void thrownStop() override;
	void grabbed() override;
	void released() override;
	void onBlockHit() override;
	void onFireballHit() override;
	void onGroundPound() override;
	void entityCollision(ActiveCollider& self, StageActor& actor) override;
	void damagePlayer(ActiveCollider& self, Player& player) override;
	void defeat(fx32 velX, fx32 velY, fx32 accelY, u8 unk) override;

	void setBumped();
	bool tickFuse();
	void explode();

	bool pipeOutState();
	bool montyTankHeldState();
	bool explodeState();
	bool kickedState();
	bool groundPoundedState();
	bool tickingState();
	bool turnState();
	bool walkState();

	void updateState();
	bool switchState(StateFunction function);


	static BobOmb* spawnFromMontyTank(const Vec3& position, bool primed);

	static void groundPoundedActiveCallback(ActiveCollider& self, ActiveCollider& other);
	static void weaponActiveCallback(ActiveCollider& self, ActiveCollider& other);
	static void explodeCallback(ActiveCollider& self, ActiveCollider& other);

	static bool loadResources();


	static constexpr u16 ObjectID = 35;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 48;

	static const ActorProfile profile;

	static const u8 tileShardTypes[4]; // [0=Red block,1=Wood block,2=Stone block,3=Used block]
	static const fx16 directionalWalkVelocities[2];
	static const fx16 directionalBumpedVelocities[2];
	static const fx16 directionalTurnRotationSpeeds[2];
	static PointSensor topSensor;
	static PointSensor bottomSensor;
	static PointSensor sideSensor;
	static const fx32 pipeOutVelocitiesX[4]; // [0-3=Direction, see enum above]
	static const fx32 pipeOutVelocitiesY[4]; // [0-3=Direction, see enum above]
	static const AcConfig acConfig;
	static const s16 blastGrid[2][3 * 3]; // [0=X,1=Y][0-9=Grid position index]


	ModelAnm model;
	StateFunction updateFunction;
	StateFunction lastUpdateFunction; // Used when switching back from turnState to the previous state.
	u32 montyTankGUID;
	u16 explodeFrame; // Counting up upon detonation, below 9 frames it will sequentially destroy a 3x3 (4x3) grid of tiles, Bob-Omb is destroyed on the 16th frame.
	u16 fuseTimer; // Set to 240 upon creation, ticks down when activated, red flashing occurs below 60, detonation at 0.
	u8 playerID;
	u8 explodeDelay; // Set to 1, when it reaches 0 destruction logic will start and a damaging ActiveCollider will be configured.
	s8 updateStep;
	bool attachToMontyTank; // Set when held by Monty Tank: Bob-Omb won't hurt players and won't start ticking until it gets released (set to false).
	bool primedLanded; // Set when the Bob-Omb touches ground after the primed spawn cooldown reaches 0.
	bool primedSpawn; // Set when the spawn type will cause detonation without any interaction (self-destruct).
	u8 primedSpawnCooldown; // When it reaches 0, collision will start being detected and bouncing physics will be applied.

};
NTR_SIZE_GUARD(BobOmb, 0x4BC);
