#pragma once
#include "nsmb.h"


// vtable at 02145394 (ov34)
class Whomp : public StageEntity3DAnm {

public:

	using StateFunction = bool(Whomp::*)();

	// D0: 02143090
	// D1: 02143070
	virtual ~Whomp();

	// 02143268
	s32 onCreate() override;
	// 021430B8
	s32 onRender() override;
	// 0214379C
	bool onPrepareResources() override;

	// 0214323C
	bool updateMain() override;

	// 0214497C
	void onMegaWalkShockwave() override;

	// 02144E5C
	bool switchState(const StateFunction& function);
	// 02144E14
	void updateState();

	// 02144D6C
	void createLandParticles();

	// 02144C08
	void doBreak(u8 playerID);

	// 02144A6C
	bool playerCollided(u8 playerID);
	// 021449C4
	bool walkCheckPlayerCollision();
	// 02144980
	bool stillCheckPlayerCollision();

	// 02144800
	bool playerCollidedDamage(u8 playerID);
	// 02144794
	bool checkPlayerCollisionDamage();

	// 021446C4
	void updateWalkingSound();

	// 0214467C
	bool noTileBelow(const PointSensor& sensor) const;

	// 021444B0
	bool walkIdleState();
	// 021443B8
	bool walkTurnState();
	// 02144278
	bool walkRunState();
	// 021441B0
	bool walkJumpState();
	// 02144030
	bool walkFallState();
	// 02143F0C
	bool walkLandState();
	// 02143DB0
	bool walkRaiseState();

	// 02143D08
	bool stillIdleState();
	// 02143C40
	bool stillJumpState();
	// 02143AD0
	bool stillFallState();
	// 021439A8
	bool stillLandState();
	// 021438B4
	bool stillRaiseState();

	// 021437F4
	bool breakState();

	// 02144EE8
	static bool loadResources();

	static constexpr u16 objectID = 73;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 85;

	// 02145388
	static const ActorProfile profile;

	// 02144FE0
	static const ActiveColliderInfo activeColliderInfo;

	// 02144FD4
	static PointSensor sideSensor;
	// 02144FC8
	static PointSensor bottomSensor;

	// 02144FC0
	static const fx32 attackRanges[2];
	// 02144FB8
	static const fx32 coinOffsets[2];
	// 02144FB0
	static const fx32 tileOffsets[2];
	// 02144FA8
	static const fx32 walkVelocities[2];
	// 02144FA0
	static const fx32 runVelocities[2];
	// 02144F9C
	static const s16 shakeVelocities[2];

	// 0214550C
	static const StateFunction sWalkIdle;
	// 021454C4
	static const StateFunction sWalkTurn;
	// 02145524
	static const StateFunction sWalkRun;
	// 0214551C
	static const StateFunction sWalkJump;
	// 02145514
	static const StateFunction sWalkFall;
	// 02145504
	static const StateFunction sWalkLand;
	// 021454FC
	static const StateFunction sWalkRaise;

	// 021454F4
	static const StateFunction sStillIdle;
	// 021454EC
	static const StateFunction sStillJump;
	// 021454E4
	static const StateFunction sStillFall;
	// 021454CC
	static const StateFunction sStillLand;
	// 021454DC
	static const StateFunction sStillRaise;

	// 021454D4
	static const StateFunction sBreak;


	FxRect tallRect;
	FxRect landRectLeft;
	FxRect landRectRight;

	const StateFunction* updateFunction;

	fx32 bottomY;
	fx32 topY;

	u32 initSettings;
	u32 sizeFlag;
	u32 typeFlag;

	s16 landShakeRotation;
	u16 landTimer;
	u16 walkTimer;
	u16 unused50A;

	u16 landingFlag;
	u16 unused50E;

	u16 shakeState;
	u16 shakeTimer;
	u16 breakTimer;

	u16 runningFlag;

	s8 updateStep;

};
NTR_SIZE_GUARD(Whomp, 0x51C);
