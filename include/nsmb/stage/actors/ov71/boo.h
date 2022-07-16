#pragma once
#include "nsmb.h"


// vtable at 02179390 (ov71)
class Boo : public StageEntity3DAnm
{
public:

	using StateFunction = bool(Boo::*)();

	enum class Type : u32
	{
		Boo,				// Regular Boo
		BalloonBoo,			// Regular Balloon Boo
		BalloonBooEvent,	// Balloon Boo triggered by an event
		BalloonBooChase		// Balloon Boo that chases the player like a regular Boo (no deflation)
	};

	enum class SpeedType : u32
	{
		Boo,
		BooFaster,
		BalloonBoo,
		BalloonBooFaster,
		BalloonBooChase
	};

	enum class BooAnimation : u16
	{
		Chase,			// Waving arms
		Turn,			// Turning around
		Shy				// Covering eyes
	};

	enum class BalloonAnimation : u8
	{
		Deflate,		// Deflating (chasing)
		Inflate,		// Inflating (waiting)
		Wait			// Waiting for player to turn
	};

	enum class BalloonAction : u8
	{
		ChaseDeflated,	// Chasing player when deflated
		Chase,			// Chasing player while deflating
		Wait			// Waiting for player to turn
	};

	// D0: 021759F0
	// D1: 021759A0
	virtual ~Boo();

	// 02175D38
	s32 onCreate() override;
	// 02175A48
	s32 onRender() override;
	// 021760EC
	bool onPrepareResources() override;

	// 02175C18
	bool updateMain() override;

	// 021772E4
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 021771C4
	void updateSpriteAnimation();
	// 02177194
	void updateMusicEvents();
	// 02177128
	bool hasLeftCamera();
	// 021770A0
	bool updateTurnRotation();
	// 0217707C
	bool checkPlayerInZone();
	// 02176FEC
	void updateZoneLimit();
	// 02176EE4
	void updateInflateParticles();
	// 02176E24
	void updateDeflateParticles();
	// 02176DD0
	void updateChaseSound();
	// 02176D6C
	void updateInflateSound();
	// 02176A20
	bool updateChase();
	// 02176758
	void updateAnimations();
	// 021765FC
	void updateStandard();
	// 02176528
	void updateZoneLimited();
	// 02175CC4
	bool destroyViewLeft();

	// 021773DC
	bool switchState(const StateFunction& function);
	// 02177394
	void updateState();

	// 021763AC
	bool mainState();
	// 02176298
	bool eventDeflateState();
	// 02176184
	bool eventInflateState();

	// 02177468
	static bool loadResources();

	static constexpr u16 objectID = 41;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 55;

	// 02179378
	static const ActorProfile profile;

	// 02179154
	static const ActiveColliderInfo activeColliderInfo;

	// 02179190
	static const fx32 chaseVelocitiesY[5][2];
	// 02179258
	static const fx32 chaseAccelerationsY[5][2];
	// 02179208
	static const fx32 chaseVelocitiesX[5][2];
	// 021791B8
	static const fx32 chaseAccelerationsX[5][2];
	// 02179230
	static const fx32 balloonChaseVelocitiesX[5][2];
	// 021791E0
	static const fx32 balloonChaseAccelerationsX[5][2];

	// 02179170
	static const fx32 stackOffsets[8];

	// 02179144
	static const u16 turnFrameIDs[2][4];
	// 0217913C
	static const u16 waveFrameIDs[4];

	// 02179138
	static const s16 rotationY[2];
	// 0217912C
	static const s16 rotationYStep[2];
	// 02179130
	static const s16 balloonRotationY[2];
	// 02179134
	static const s16 balloonRotationYStep[2];

	// 021799A8
	static const StateFunction sMain;
	// 021799B0
	static const StateFunction sEventDeflate;
	// 021799A0
	static const StateFunction sEventInflate;


	AnimationCtrl faceAnimation;				// Face texture animation (Balloon Boo)

	FxRect hitboxRect;							// Hitbox rectangle

	Vec3 rootPosition;							// Current root position (Balloon Boo)
	Vec3 spawnPositionCentered;					// Spawn position offset by 8 pixels vertically
	Vec3 tailPosition;							// Current tail position (Balloon Boo)
	Vec3 mouthPosition;							// Current mouth position (Balloon Boo)
	Vec3 spawnPosition;							// Spawn position

	const StateFunction* updateFunction;

	fx32 spawnY;								// Set to position.y upon creation
	fx32 balloonScale;							// Balloon Boo scale
	fx32 renderOffsetY;							// Vertical rendering offset
	u32 inflateSoundTimer;						// Cooldown set to 3 frames. When this reaches zero a sound effect is played (SE_EMY_FO_GLOW_UP)
	u32 unused55C;								// Unused

	// Actor settings
	Type type;									// Boo type
	u32 balloonFlag;							// 1 if the Boo is a Balloon Boo
	SpeedType speedType;						// Current Boo velocity index
	u32 balloonBehavior;						// Not 0 if the Balloon Boo chases the player like a regular Boo
	u32 zoneLimitFlag;							// 0 or 1 depending on whether the Balloon Boo movement is restricted to a zone

	EmitterT deflateSmokeLeftEmitterID;			// Smoke particle emitter during deflation (left)
	EmitterT deflateSmokeRightEmitterID;		// Smoke particle emitter during deflation (right)
	EmitterT inflateSmallFlowRightEmitterID;	// Small air flow particle emitter during inflation (right)
	EmitterT inflateLargeFlowRightEmitterID;	// Large air flow particle emitter during inflation (right)
	EmitterT inflateSmallFlowLeftEmitterID;		// Small air flow particle emitter during inflation (left)
	EmitterT inflateLargeFlowLeftEmitterID;		// Large air flow particle emitter during inflation (left)

	u32 unused58C;								// Written in updateMusicEvents, onCreate
	u32 unused590;								// Written in updateMusicEvents
	u16 bobTimer;								// Sine index responsible for moving the Boo up/down
	u16 unk596;									// Written in onCreate
	BooAnimation booAnimation;					// Current Boo animation
	u16 chaseSoundTimer;						// Cooldown set to 8 frames. When this reaches zero a sound effect is played (SE_EMY_FO_CHASE)
	u16 animationFrameID;						// Current Boo sprite animation frame index
	u16 spriteFrameID;							// Current Boo sprite frame index
	u16 animationFrameTimer;					// Timer indicating the current Boo sprite animation frame. Ticks up to 8 frames in BooAnimation::Chase and 2 frames in BooAnimation::Turn
	u16 turningFlag;							// Set to 1 when the Boo is turning
	u16 danceFlag;								// Set to 1 during a music event. Freezes the Boo as there is no music interaction implementation
	u16 turnTimer;								// Cooldown set to 16 frames. When this reaches zero, the turning animation is played
	u16 shyTimer;								// Cooldown set to 16 frames. When this reaches zero, the Boo switches from waiting (shy) to chasing
	u8 booStackIndex;							// Current Boo stack index (0-7), used to stack boos vertically at different heights to prevent overlapping
	BalloonAnimation balloonAnimation;			// Current Balloon Boo animation
	u8 zoneID;									// The zone a Balloon Boo is restricted in
	s8 updateStep;

};
NTR_SIZE_GUARD(Boo, 0x5B0);


// vtable at 021794B0 (ov71)
class BalloonBoo : public Boo
{
public:

	// D0: 021775E0
	// D1: 02177584
	virtual ~BalloonBoo() {}

	// 02177484
	static bool loadResources();

	static constexpr u16 objectID = 42;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 56;

	// 02179384
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(BalloonBoo, sizeof(Boo));
