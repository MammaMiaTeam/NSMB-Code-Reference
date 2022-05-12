#pragma once
#include "nsmb.h"


// vtable at 02126420 (ov10)
class Goomba : public StageEntity
{
public:

	using StateFunction = bool(Goomba::*)(void*);


	// D0: 020E06F4
	// D1: 020E0698
	virtual ~Goomba();

	// 020E0AB4
	s32 onCreate() override;
	// 020E0758
	s32 onDestroy() override;
	// 020E0764
	s32 onRender() override;
	// 020E0760
	void onCleanupResources() override;

	// 020E09EC
	bool updateMain() override;
	// 020E1648
	bool updateDefeated() override;

	// 020E1B78
	virtual void onStomped();
	// 020E1B08
	virtual void onMegaWalkShockwave();

	// 020E2228
	bool playerCollision(ActiveCollider& self, ActiveCollider& other);
	// 020E2018
	void entityCollision(ActiveCollider& self, StageActor& actor);
	// 020E1BB0
	void damagePlayer(ActiveCollider& self, Player& player);

	// 020E22B0
	void doPlayerJump(Player& player, fx32 jumpVelocity);

	// 020E23F4
	bool updateMusicEvents(fx32 jumpVelocity);
	// 020E19AC
	void updateMegaDropped();
	// 020E1694
	bool updateSpriteAnimation();

	// 020E24A8
	bool switchState(StateFunction function, void* arg = nullptr);
	// 020E2448
	void updateState();

	// 020E1538
	bool walkState(void* arg);
	// 020E1478
	bool turnState(void* arg);
	// 020E13D0
	bool stompedState(void* arg);
	// 020E1330
	bool megaDroppedState(void* arg);
	// 020E127C
	bool pipeFallState(void* arg);
	// 020E1060
	bool paraWalkState(void* arg);
	// 020E0F60
	bool paraTurnState(void* arg);
	// 020E0D98
	bool pipeExitState(void* arg);

	static constexpr u16 objectID = 83;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 160;

	// 021263FC
	static const ActorProfile profile;

	// 02121854
	static const ActiveColliderInfo activeColliderInfo;

	// 02121844
	static const fx32 pipeTargetsY[4];
	// 02121824
	static const fx32 pipeTargetsX[4];
	// 02121814
	static const fx32 pipeVelocitiesY[4];
	// 02121804
	static const fx32 pipeVelocitiesX[4];
	// 021217EC
	static const PointSensor bottomSensor;
	// 021217D4
	static const PointSensor sideSensor;
	// 021217C0
	static const fx32 velocitiesX[2];
	// 02121834
	static const u16 walkWingsFrameIDs[8];
	// 021217B0
	static const u16 turnFrameIDs[3];
	// 021217A8
	static const u16 turnWingsFrameIDs[3];
	// 021217A4
	static const u16 stompedFrameLengths[2];
	// 021217A0
	static const u16 stompedFrameIDs[2];


	StateFunction updateFunction;

	FxRect hitboxRect;
	PointSensor droppedBottomSensor;

	u32 unused418;
	fx32 pipeTargetX;
	fx32 pipeTargetY;
	u32 unused424;
	bool32 musicTriggered;
	s16 stompCooldown;
	u16 unused42E;
	u16 unused430;
	u16 unused432;
	u16 wingedFlag;
	u16 unused436;
	u16 unused438;
	u16 unused43A;
	u16 unused43C;					// Unused cooldown
	u16 unused43E;
	u16 animationType;
	u16 animationFrameID;
	u16 spriteFrameID;
	u16 animationFrameTimer;
	u16 stunnedTrigger;				// Unused, only controls the below timer and cooldown. Does not trigger any stunned mechanic
	u16 stunnedTimer;				// Unused
	u16 stunnedCooldown;			// Unused
	u16 paraTurnTimer;
	u16 paraJumpCounter;
	u16 miniGoombaFlag;
	u16 stationaryFlag;
	u16 pipeDirection;
	u8 megaDropStep;
	u8 invisibleFlag;
	s8 updateStep;

};
NTR_SIZE_GUARD(Goomba, 0x45C);


// vtable at 02126648 (ov10)
class Paragoomba : public Goomba
{
public:

	// D0: 020E268C
	// D1: 020E2624
	virtual ~Paragoomba() {}

	static constexpr u16 objectID = 84;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 161;

	// 02126408
	static const ActorProfile profile;

	// 021217C8
	static const PointSensor topSensor;

};
NTR_SIZE_GUARD(Paragoomba, sizeof(Goomba));


// vtable at 02126534 (ov10)
class MiniGoomba : public Goomba
{
public:

	// D0: 020E2764
	// D1: 020E26FC
	virtual ~MiniGoomba() {}

	static constexpr u16 objectID = 85;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 162;

	// 02126414
	static const ActorProfile profile;

	// 021217F8
	static const PointSensor sideSensor;
	// 021217E0
	static const PointSensor bottomSensor;
	// 021217B8
	static const fx32 velocitiesX[2];

};
NTR_SIZE_GUARD(MiniGoomba, sizeof(Goomba));
