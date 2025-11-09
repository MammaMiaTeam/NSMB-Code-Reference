#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/2d/oam.hpp>
#include <nsmb/extra/bits.hpp>

// vtable at 021261cc (ov10)
class KoopaTroopa : public StageEntity {
public:

	using StateFunction = bool(KoopaTroopa::*)();

	enum class Type : u8 {
		Green,
		Red,   // stays on ledge
		Blue,  // spawns a blue shell powerup when stomped
		Blue2, // ^ and stays on ledge
	};

	struct Settings : StrongBitFlag<u32> {
		Type type 		   : 4;
		bool emptyShell    : 4;
		u32 unused 		   : 20;
		bool shellDespawns : 4; // if true shell can despawn after a while in inShellState if spawned as an empty shell; used by Bowser Jr
	};

	enum class State : u8 {
		Walk,
		InShell,
		JumpFly,
		HorizontalFly,
		VerticalFly
	};

	// D1: 020dddb0
	// D0: 020dde0c
	virtual ~KoopaTroopa() override;

	// 020df05c
	s32 onCreate() override;
	// 020de3a8
	s32 onRender() override;
	// 020de278
	s32 onDestroy() override;

	// 020de2d4
	void onCleanupResources() override;
	
	// 020def70
	bool updateMain() override;
	// 020df41c
	bool updateCarried() override;
	// 020de248
	void updateAnimation() override;
	// 020df3b0
	void thrown() override;
	// 020df374
	void thrownStop() override;
	// 020df520
	void grabbed() override;
	// 020df504
	void released() override;
	// 020df7e8
	void shellKicked() override;
	// 020df754
	void shellStopped() override;
	// 020de2d8
	void onBlockHit() override;
	// 020dde70
	void onStomped() override;
	// 020ddeec
	void onGroundPound() override;
	// 020dee0c
	void entityCollision(ActiveCollider& self, StageActor& actor) override;
	// 020de7d0
	void damagePlayer(ActiveCollider& self, Player& player) override;
	// 020de1f8
	void defeat(fx32 velX, fx32 velY, fx32 accelY, u8 arg) override;

	// 020de5ec
	virtual bool onDamageDealt(const Player& player); // when player is damaged by walking koopa... but why virtual??

	// 020de770
	bool checkDamaged();
	// 020dfb94
	bool updateBeginShellExit();
	// 020de1c8
	void startDespawnTimer();
	// 020de11c
	void updateDespawn();
	// 020de080
	void bowserJrThrow(u8 direction, u16 throwType);
	// 020de06c
	void enableACEntityDetection(); // enables active collider entity detection -- called by bowser jr

	// 020e04d0
	void updateRotationAndState();
	// 020e0558
	bool switchState(StateFunction function);

	// 020dfc58
	bool walkState();
	// 020df644
	bool turnState();
	// 020df548
	bool danceState();
	// 020df9f8
	bool inShellState();
	// 020df8b4
	bool exitShellState();
	// 020dffb0
	bool jumpFlyState();
	// 020e00f8
	bool horizontalFlyState();
	// 020e036c
	bool verticalFlyState();

	// 020df358
	static bool loadResources();


	static constexpr u16 ObjectID = 94;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 163;

	// 021261b4
	static const ActorProfile profile;

	// 02121784
	static const AcConfig defaultAcConfig;

	// 02121750
	static const PointSensor defaultTopSensor;
	// 0212175c
	static const PointSensor defaultBottomSensor;
	// 02121774
	static const PointSensor defaultSideSensor;

	// 02121768
	static const fx16 bowserJrThrowVelocitiesX[3][2]; // [BowserJr::ThrowType][direction]
	// 02121740
	static const fx16 bowserJrThrowVelocitiesY[3][2]; // [BowserJr::ThrowType][direction]

	// 0212173c
	static const fx16 velocitiesX[2]; // [direction]

	// 02121748
	static const fx32 jumpFlyVelocitiesX[2]; // [direction]
	// 02121734
	static const fx16 flyVelocities[2]; // [direction]

	// 02121738
	static const s16 shellExitRotationsX[2];

	// 02121730
	static const u8 paletteOffsets[4]; // [Type]


	static constexpr Vec2 ActiveSize = { 80, 32 };
	static constexpr Vec2 ViewOffset = { 0,  16 };
	static constexpr Vec2 RenderSize = { 16, 32 };

	// 020dfb88, 020dfc98
	static constexpr fx32 FallAccel = -0.1875fx; // vertical acceleration when falling
	// 020df688, 020dfca8
	static constexpr fx32 FallTargetVelY = -4.0fx;
	// 020dfb8c
	static constexpr u16 InShellLength = 511; // number of frames Koopa will spend inside shell before exiting; 8.5 seconds + 1 frame
	// 020de1f4
	static constexpr u16 ShellDespawnDelay = 1800; // number of frames before Koopa despawns (if shellDespawns is true); 30 seconds


	OAM::Anim spriteAnimation;

	StateFunction updateFunctiom;
	StateFunction lastUpdateFunction;

	AcConfig acConfig;
	PointSensor topSensor;
	PointSensor bottomSensor;
	LineSensorV sideSensor;

	u16 despawnCountdown;	// when this hits 0 the actor is destroyed; decremented and checked in updateDespawn
	u16 despawnFlashTimer;	// visibility of shell is toggled when it reaches 0 then is reset to 4
	u16 despawnFlashFrame;	// alternates between 1 and 0 every four frames, representing whether or not shell is visible

	u16 shellExitCountdown;
	u16 commonTimer;			// for shell exit and wing flapping
	u8 directionChangeCooldown;

	u8 align46B; // alignment

	u8 verticalDirection;
	bool onGround;
	bool shellDespawns;
	u8 moveDirection;
	bool turning;
	State stateID;
	u8 unk472;			// direction??
	s8 updateStep;


#if NTR_EXT_EXISTS(KoopaTroopa)
	#include NTR_EXT_INCLUDE(KoopaTroopa)
#endif

};
#if !NTR_EXT_EXISTS(KoopaTroopa)
NTR_SIZE_GUARD(KoopaTroopa, 0x474);
#endif


class KoopaParatroopa : public KoopaTroopa {
public:

	enum class MoveMode : u8 {
		Jump,
		HorizontalFly,
		VerticalFly
	};

	enum class StartPosition : u8 {
		Middle = 0,
		// VerticalFly, HorizontalFly
		Bottom = 1, 	Left  = 1,
		Top    = 2, 	Right = 2
	};

	enum class StartDirection : u8 {
		Down = 0, Left  = 0,
		Up 	 = 1, Right = 1,
	};

	struct Settings : StrongBitFlag<u32> {
		Type type 		  	   	: 4;
		MoveMode moveMode 	   	: 4;
		StartPosition startPos 	: 4;
		StartDirection startDir : 4;
		u16 unused 				: 16;
	};

	static constexpr u16 ObjectID = 95;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 164;

	// 021261c0
	static const ActorProfile profile;


	static constexpr u32 DirectionChangeDelay = 48; // number of frames of flying before switching directions; 0.8 seconds


#if NTR_EXT_EXISTS(KoopaParatroopa)
	#include NTR_EXT_INCLUDE(KoopaParatroopa)
#endif

};
#if !NTR_EXT_EXISTS(KoopaParatroopa)
NTR_SIZE_GUARD(KoopaParatroopa, sizeof(KoopaTroopa));
#endif
