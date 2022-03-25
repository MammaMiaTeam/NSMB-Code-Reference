#pragma once
#include "nsmb.h"


// vtable at 02127840 (ov10)
class StageFX : public StageController {

public:

	enum Type : u32 {
		StageStart,
		Victory,
		VsLose,
		TimesUp,
		VsTimesUp, // unused
		DelayedVictory,
		DelayedVsLose
	};

	using StateFunction = bool(StageFX::*)();

	// D0: 020FB5A8
	// D1: 020FB57C
	sym inline virtual ~StageFX() {}

	// 020FC7CC
	sym virtual s32 onCreate() override __rbody
	// 020FC578
	sym virtual s32 onUpdate() override __rbody
	// 020FC684
	sym virtual s32 onRender() override __rbody
	// 020FC794
	sym virtual s32 onDestroy() override __rbody

	// 020FC790
	sym virtual void pendingDestroy() override __body

	// 020FC54C
	sym void initStageStart() __body
	// 020FC214
	sym void initVictory() __body
	// 020FBFDC
	sym void initVsLose() __body
	// 020FBCF8
	sym void initTimesUp() __body
	// 020FBC2C
	sym void initVsTimesUp() __body
	// 020FBA00
	sym void initDelayedVictory() __body
	// 020FB9E0
	sym void initDelayedVsLose() __body

	// 020FC2B4
	sym void updateStageStart() __body
	// 020FC050
	sym void updateVictory() __body
	// 020FBD30
	sym void updateVsLose() __body
	// 020FBC5C
	sym void updateTimesUp() __body
	// 020FBA20
	sym void updateVsTimesUp() __body
	// 020FB998
	sym void updateDelayedVictory() __body
	// 020FB948
	sym void updateDelayedVsLose() __body

	// 020FC548
	sym void renderStageStart() __body
	// 020FC1C0
	sym void renderVictory() __body
	// 020FBF60
	sym void renderVsLose() __body
	// 020FBCB4
	sym void renderTimesUp() __body
	// 020FBBE0
	sym void renderVsTimesUp() __body

	// 020FB5F4
	sym void renderLostLives() __body

	// 020FB900
	sym bool updateScalePalette(fx32* scales, u8* palettes) __rbody

	// 020FB5DC
	sym static u32 getSettings(Type type, u8 character, u8 unk) __rbody

	static constexpr u16 objectID = 18;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 25;

	// 021277D4
	static const ActorProfile profile;

	// 0212AEB0
	static const StateFunction initFuncs[6];

	// 0212AEE8
	static const StateFunction updateFuncs[6];

	// 0212AF20
	static const StateFunction renderFuncs[6];


	Type type;
	Type initialType;

	u32 step;
	u32 scalePaletteCounter;
	u32 waitTimer;
	u32 unused138; // only set in initStageStart
	u32 character;
	fx32 vsTimesUpY;
	GXOamAttr* oamData;
	u32 unused148[8];
	u8 palette;
	bool renderLives;

};

static_assert(sizeof(StageFX) == 0x16C, "");
