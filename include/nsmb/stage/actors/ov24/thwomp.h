#pragma once
#include "nsmb.h"


// vtable at 0213F6E8 (ov24)
class Thwomp : public StageEntity3D {

public:

	using StateFunction = bool(Thwomp::*)();

	// D0: 0213DA68
	// D1: 0213D9E0
	virtual ~Thwomp() {}

	// 0213DB20
	s32 onCreate() override;
	// 0213DAF8
	s32 onDestroy() override;
	// 0213DCFC
	bool onPrepareResources() override;

	// 0213DB00
	bool updateMain() override;
	// 0213E1B0
	bool updateDefeated() override;
	// 0213E170
	bool updateDefeatedMega() override;

	// 0213E1F0
	void onBlockHit() override;
	// 0213E248
	void onStarmanHit() override;
	// 0213E278
	void onMegaHit() override;
	// 0213E260
	void onMegaKicked() override;
	// 0213E230
	void onBlueShellHit() override;

	// 0213DF50
	void spawnLandingParticles() const;

	// 0213E2D8
	bool switchState(const StateFunction& function);
	// 0213E290
	void updateState();

	// 0213E0CC
	bool idleState();
	// 0213E04C
	bool alertState();
	// 0213DFA8
	bool attackState();
	// 0213DE60
	bool fallState();
	// 0213DDEC
	bool landState();
	// 0213DD74
	bool riseState();

	// 0213E364
	static bool loadResources();

	static constexpr u16 objectID = 37;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 51;

	// 0213F6D0
	static const ActorProfile profile;

	// 0213F1F8
	static const ActiveColliderInfo activeColliderInfo;

	// 0213F1E8
	static LineSensorH topSensor;
	// 0213F1D8
	static LineSensorH bottomSensor;

	// 0213F1B8
	static const fx32 attackRanges[2];
	// 0213F1C0
	static const fx32 shakeOffsets[2];

	// 0213FAA0
	static const StateFunction sIdle;
	// 0213FAA8
	static const StateFunction sAlert;
	// 0213FA98
	static const StateFunction sAttack;
	// 0213FA90
	static const StateFunction sFall;
	// 0213FAB8
	static const StateFunction sLand;
	// 0213FAB0
	static const StateFunction sRise;


	AnimationCtrl faceAnimation;

	const StateFunction* updateFunction;

	LineSensorH giantBottomSensor;

	u32 unused4E0;
	u32 giantFlag;
	u32 unusedFlag;
	u16 shakeTimer;
	u16 shakePhase;

	s8 updateStep;
	u8 waitTimer;

};
NTR_SIZE_GUARD(Thwomp, 0x4F4);


// vtable at 0213F804 (ov24)
class GiantThwomp : public Thwomp
{
public:

	// D0: 0213E4F0
	// D1: 0213E45C
	virtual ~GiantThwomp() {}

	static constexpr u16 objectID = 38;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 52;

	// 0213F6DC
	static const ActorProfile profile;

	// 0213F214
	static const ActiveColliderInfo activeColliderInfo;

	// 0213F1C8
	static LineSensorH topSensor;

};
NTR_SIZE_GUARD(GiantThwomp, sizeof(Thwomp));
