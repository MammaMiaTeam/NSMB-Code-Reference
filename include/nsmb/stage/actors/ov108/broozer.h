#pragma once
#include "nsmb.h"


// vtable at 0218AEFC (ov108)
class Broozer : public StageEntity3DAnm {

public:

	using StateFunction = bool(Broozer::*)();

	// D0: 02189A00
	// D1: 021899E0
	virtual ~Broozer();

	// 02189A74
	s32 onCreate() override;
	// 02189D40
	bool onPrepareResources() override;

	// 02189A28
	bool updateMain() override;
	// 02189D98
	bool updateDefeated() override;

	// 0218A9A4
	void onEntityHit() override;
	// 0218AA04
	void onFireballHit() override;
	// 0218A9EC
	void onStarmanHit() override;
	// 0218A98C
	void onSlidingHit() override;
	// 0218A9D4
	void onMegaHit() override;
	// 0218A9BC
	void onMegaKicked() override;
	// 0218AA1C
	void onStomped() override;
	// 0218A974
	void onGroundPound() override;
	// 0218A95C
	void onBlueShellHit() override;
	// 0218A958
	void onMegaWalkShockwave() override;

	// 0218AB34
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 0218AB00
	void setDefeated();
	// 0218A8C0
	void updatePunchSound();
	// 0218A858
	bool hasLeftCamera();
	// 0218A82C
	bool incrementAnimationSpeed(fx32 value);
	// 0218A7E0
	bool updateTurnRotation();

	// 0218ACB4
	bool switchState(const StateFunction& function);
	// 0218AC6C
	void updateState();

	// 0218A5EC
	bool walkState();
	// 0218A524
	bool turnState();
	// 0218A278
	bool searchState();
	// 0218A150
	bool alertState();
	// 02189EC0
	bool runState();
	// 02189DE0
	bool stompedState();

	// 0218AD40
	static bool loadResources();

	static constexpr u16 objectID = 120;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 139;

	// 0218AEF0
	static const ActorProfile profile;

	// 0218ADB4
	static const ActiveColliderInfo activeColliderInfo;

	// 0218ADAC
	static const fx32 walkVelocities[2];
	// 0218ADA4
	static const fx32 runVelocities[2];

	// 0218B020
	static const StateFunction sWalk;
	// 0218B028
	static const StateFunction sStomped;
	// 0218B030
	static const StateFunction sRun;
	// 0218B038
	static const StateFunction sAlert;
	// 0218B040
	static const StateFunction sSearch;
	// 0218B048
	static const StateFunction sTurn;


	FxRect hitboxRect;

	const StateFunction* updateFunction;

	LineSensorH bottomSensor;
	PointSensor topSensor;
	LineSensorV sideSensor;

	fx32 animationSpeed;
	fx32 homePositionX;

	u32 punchSoundTimer;
	u16 searchRange;
	u16 searchRangeTimer;
	u16 unused50C;
	u16 turningFlag;
	u16 searchTimer;
	u16 searchActionTimer;
	u16 searchAction;
	u16 hitCounter;
	u16 blockBreakCooldown;
	u16 fogTimer;
	u16 unk51C;
	u16 attackFlag;
	u16 unused520;
	u16 unk522;
	u16 turnTimer;
	u16 stunnedTimer;
	u8 searchingFlag;
	s8 updateStep;

};
NTR_SIZE_GUARD(Broozer, 0x52C);
