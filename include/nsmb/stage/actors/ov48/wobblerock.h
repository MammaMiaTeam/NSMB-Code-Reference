#pragma once
#include "nsmb.h"


// vtable at 0214892C (ov48)
class WobbleRock : public StageEntity
{
public:

	using StateFunction = bool(WobbleRock::*)();

	// D0: 0214767C
	// D1: 021475F0
	virtual ~WobbleRock();

	// 021477F0
	s32 onCreate() override;
	// 02147710
	s32 onDestroy() override;
	// 02147734
	s32 onRender() override;
	// 02147BC4
	bool onPrepareResources() override;

	// 021477A4
	bool updateMain() override;

	// 02147A34
	void updateBalance();

	// 02147AF0
	bool switchState(StateFunction function);
	// 02147ABC
	void updateState();

	// 02147948
	bool mainState();
	// 021478E0
	bool fallState();

	// 02147BFC
	static bool loadResources();

	static constexpr u16 objectID = 170;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 209;

	// 02148920
	static const ActorProfile profile;


	StateFunction updateFunction;

	Model model;

	RotatingPlatform platform;

	u32 unused4FC;

	s16 wobbleAngle;
	s16 previousAngle;
	s8 updateStep;
	s8 wobbleForce;

};
NTR_SIZE_GUARD(WobbleRock, 0x508);
