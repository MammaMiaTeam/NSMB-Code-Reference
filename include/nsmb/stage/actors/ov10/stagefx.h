#pragma once
#include "nsmb.h"


// vtable at 02127838 (ov10)
class StageFX : public StageController
{
public:

	enum class Type : u32
	{
		Start,
		Clear,		// handles both stage clear and MvsL victory
		Lose,		// broken in singleplayer
		TimesUp,
		VsTimesUp,	// unused
		VsClear,	// redirects to the other type with higher delay and runs some unknown MvsL functions
		VsLose		// same as above
	};

	using StateFunction = void(StageFX::*)();

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
	sym virtual void onCleanupResources() override __body

	// 020FC54C
	sym void initStart() __body
	// 020FC214
	sym void initClear() __body
	// 020FBFDC
	sym void initLose() __body
	// 020FBCF8
	sym void initTimesUp() __body
	// 020FBC2C
	sym void initVsTimesUp() __body
	// 020FBA00
	sym void initVsClear() __body
	// 020FB9E0
	sym void initVsLose() __body

	// 020FC2B4
	sym void updateStart() __body
	// 020FC050
	sym void updateClear() __body
	// 020FBD30
	sym void updateLose() __body
	// 020FBC5C
	sym void updateTimesUp() __body
	// 020FBA20
	sym void updateVsTimesUp() __body
	// 020FB998
	sym void updateVsClear() __body
	// 020FB948
	sym void updateVsLose() __body

	// 020FC548
	sym void renderStart() __body
	// 020FC1C0
	sym void renderClear() __body
	// 020FBF60
	sym void renderLose() __body
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

	// 0212770C
	static const u32 stageClearFileIDs[2];
	// 02127704
	static const u32 vsLoseFileIDs[2];
	// 0212774C
	static const u32 vsWinFileIDs[2];

	// 0212771C
	static const u8* stageClearPalettes[2];
	// 021277BC
	static const u8 stageClearLuigiPalettes[12];
	// 021277C8
	static const u8 stageClearMarioPalettes[12];

	// 02127764
	static const GXOamAttr* stageClearOAMDatas[2];
	// 021276E4
	static const GXOamAttr* vsLoseOAMDatas[2];
	// 02127754
	static const GXOamAttr* vsWinOAMDatas[2];

	// 0212780C
	static const fx32 stageClearScales[11];
	// 021277E0
	static const fx32 timesUpScales[11];

	// 0212AEB0
	static const StateFunction initFunctions[6];
	// 0212AEE8
	static const StateFunction updateFunctions[6];
	// 0212AF20
	static const StateFunction renderFunctions[6];


	Type type;
	Type initialType;

	u32 step;
	u32 scalePaletteCounter;
	u32 waitTimer;
	u32 unused138;				// set in initStart
	u32 character;
	fx32 targetYPos;
	GXOamAttr* oamData;
	SpringFunction loseSpring;
	u8 palette;
	bool renderLives;

};
NTR_SIZE_GUARD(StageFX, 0x16C);
