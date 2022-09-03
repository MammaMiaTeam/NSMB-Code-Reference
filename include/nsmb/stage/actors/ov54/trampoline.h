#pragma once
#include "nsmb.h"


// vtable at 0216D160 (ov54)
class Trampoline : public StageEntity3D
{
public:
	
	static constexpr u16 JumpTriggerNone	= 0;
	static constexpr u16 JumpTriggerBoost	= 1;
	static constexpr u16 JumpTriggerNormal	= 2;

	static constexpr fx32 JumpVelocity = 2.8125fx;

	using StateFunction = bool(Trampoline::*)();

	// D0: 02154F88
	// D1: 02154F00
	virtual ~Trampoline();

	// 021550B8
	s32 onCreate() override;
	// 02155358
	bool onPrepareResources() override;

	// 0215505C
	bool updateMain() override;
	// 02155018
	bool updateCarried() override;
	// 0215553C
	bool updateDropped() override;

	// 02155490
	void thrown() override;
	// 02155464
	void thrownStop() override;
	// 0215551C
	void grabbed() override;
	// 021554B4
	void released() override;

	// 02155C98
	void onBlockHit() override;
	// 02155C94
	void onMegaWalkShockwave() override;
	// 02155C90
	void onMegaGroundPoundShockwave() override;

	// 02155058
	void preRender3D() override;
	// 02155034
	void postRender3D() override;

	// 02155CEC
	bool switchState(const StateFunction& function);
	// 02155CA4
	void updateState();

	// 02155390
	void setModelCallback(NNSG3dSbcCallBackFunc cb);
	// 021553B8
	static void modelCallback(NNSG3dRS* rs);
	// 0215545C
	void setModelOwner(void* ptr);

	// 02155938
	void updatePlayerJump(u8 playerID);
	// 02155B6C
	bool updateJumpBoostKeys(Player& player, u8 playerID);
	// 02155BE0
	bool updatePlayerInteractions();
	// 02155E10
	bool checkStomp(ActiveCollider& collider, Player& player);

	// 021556C4
	bool mainState();
	// 02155520
	bool carriedState();

	// 02155D78
	static void activeCallback(ActiveCollider& self, ActiveCollider& other);

	// 02155E80
	static bool loadResources();

	static constexpr u16 objectID = 237;
	
	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 50;
	
	// 0216D154
	static const ActorProfile profile;

	// 0216C06C
	static const ActiveColliderInfo activeColliderInfo;

	// 0216C05C
	static const LineSensorH bottomSensorBig;
	// 0216C04C
	static const LineSensorV sideSensor;
	// 0216C03C
	static const LineSensorV sideSensorBig;
	// 0216C02C
	static const LineSensorH topSensorBig;
	// 0216C020
	static const PointSensor topSensor;
	// 0216C014
	static const PointSensor bottomSensor;

	// 0216C00C
	static const fx32 jumpOffsets[2];
	// 0216C004
	static const fx32 jumpBoostVelocities[2];
	// 0216C000
	static const u8 animationDurations[2];

	// 02171750
	static const StateFunction sMainState;
	// 02171758
	static const StateFunction sCarriedState;


	const StateFunction* updateFunction;

	FxRect hitboxRect;
	Vec3 modelTopPosition;

	fx32 playerVelocity[2];
	fx32 playerPositionX[2];

	fx32 hitboxY;
	fx32 hitboxHeight;

	fx32 groundForce;
	u32 biggerFlag;
	fx32 animScale;
	fx32 animScaleInv;

	u16 playerJumpBoost[2];
	u16 remainingGroundForce;
	u16 playerReleaseCooldown[2];
	u16 transferGroundForce;
	u16 playerJumping[2];
	u16 playerJumpTrigger[2];

	u16 stomping;
	u16 bounceCounter;
	s8 updateStep;
	u8 carryCooldown;
	u8 contractTimer;

};
NTR_SIZE_GUARD(Trampoline, 0x508);
