#pragma once
#include "nsmb.h"


// vtable at 021795DC (ov71)
class PhantomHand : public StageEntity
{
public:

	using StateFunction = bool(PhantomHand::*)();

	// 02177BE4
	PhantomHand();
	// D0: 02177B0C
	// D1: 02177B7C
	virtual ~PhantomHand() {}

	// 02177A18
	s32 onCreate() override;
	// 02177920
	s32 onRender() override;
	// 02177AB4
	bool onPrepareResources() override;

	// 021778F4
	bool updateMain() override;

	// 02177800
	bool switchState(StateFunction function);
	// 02177798
	void updateState();

	// 02177644
	bool mainState();

	// 02177C54
	static bool loadResources();

	static constexpr u16 objectID = 152;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 176;

	// 021795D0
	static const ActorProfile profile;


	BlendModelAnm model;

	StateFunction updateFunction;
	StateFunction lastUpdateFunction;

	u32 unused4C8[2];

	s8 updateStep;

};
NTR_SIZE_GUARD(PhantomHand, 0x4D4);
