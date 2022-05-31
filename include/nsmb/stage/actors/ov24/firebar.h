#pragma once
#include "nsmb.h"


// vtable at 0213F934 (ov24)
class FireBar : public StageEntity {

public:

	using StateFunction = bool(FireBar::*)();

	// D0: 0213E644
	// D1: 0213E58C
	virtual ~FireBar() {}

	// 0213EA14
	s32 onCreate() override;
	// 0213E704
	s32 onDestroy() override;
	// 0213E9A4
	s32 onUpdate() override;
	// 0213E740
	s32 onRender() override;
	// 0213E73C
	void onCleanupResources() override;
	// 0213EC40
	bool onPrepareResources() override;

	// 0213EED0
	void onBlueShellHit() override;

	// 0213EED4
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 0213EF68
	bool switchState(const StateFunction& function);
	// 0213EF20
	void updateState();

	// 0213ECC0
	bool mainState();

	// 0213EFFC
	static bool loadResources();

	static constexpr u16 objectID = 65;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 79;

	// 0213F928
	static const ActorProfile profile;

	// 0213F230
	static const ActiveColliderInfo activeColliderInfo;

	// 0213FAC0
	static const StateFunction sMain;


	Model model;
	AnimationCtrl textureAnimation;

	const StateFunction* updateFunction;

	ActiveCollider fireballColliders[32];	// Elements 15/31 are unused as the length cannot reach 16
	Vec3 fireballPositions[32];				// Ditto

	u32 unused1CB4;
	s16 spinRotation;
	u16 length;
	bool16 doubleSided;
	bool16 faster;
	bool16 clockwise;
	s8 updateStep;

};
NTR_SIZE_GUARD(FireBar, 0x1CC4);
