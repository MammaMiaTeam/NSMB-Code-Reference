#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/math/springfunction.hpp>

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
	inline virtual ~StageFX() {}

	// 020FC7CC
	virtual s32 onCreate() override;
	// 020FC578
	virtual s32 onUpdate() override;
	// 020FC684
	virtual s32 onRender() override;
	// 020FC794
	virtual s32 onDestroy() override;

	// 020FC790
	virtual void onCleanupResources() override;

	// 020FC54C
	void initStart();
	// 020FC214
	void initClear();
	// 020FBFDC
	void initLose();
	// 020FBCF8
	void initTimesUp();
	// 020FBC2C
	void initVsTimesUp();
	// 020FBA00
	void initVsClear();
	// 020FB9E0
	void initVsLose();

	// 020FC2B4
	void updateStart();
	// 020FC050
	void updateClear();
	// 020FBD30
	void updateLose();
	// 020FBC5C
	void updateTimesUp();
	// 020FBA20
	void updateVsTimesUp();
	// 020FB998
	void updateVsClear();
	// 020FB948
	void updateVsLose();

	// 020FC548
	void renderStart();
	// 020FC1C0
	void renderClear();
	// 020FBF60
	void renderLose();
	// 020FBCB4
	void renderTimesUp();
	// 020FBBE0
	void renderVsTimesUp();

	// 020FB5F4
	void renderLostLives();

	// 020FB900
	bool updateScalePalette(fx32* scales, u8* palettes);

	// 020FB5DC
	static u32 getSettings(Type type, u8 character, u8 unk);

	static constexpr u16 ObjectID = 18;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 25;

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
	u32 unused138;				// Written in initStart
	u32 character;
	fx32 targetYPos;
	GXOamAttr* oamData;
	SpringFunction loseSpring;
	u8 palette;
	bool renderLives;


#if NTR_EXT_EXISTS(StageFX)
	#include NTR_EXT_INCLUDE(StageFX)
#endif

};
#if !NTR_EXT_EXISTS(StageFX)
NTR_SIZE_GUARD(StageFX, 0x16C);
#endif
