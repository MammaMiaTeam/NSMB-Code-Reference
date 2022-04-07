#pragma once
#include "nsmb/graphics/3d/animation.h"
#include "nsmb/graphics/3d/model.h"


//vtable 0212f8b8
class PlayerCap
{
public:

	Model model;
	Animation animation;
	FrameCtrl frameController;
	u8 playerID;
	u8 animType;

	//0212f8e0
	static u16 texPaletteBase[2];

	//0212f8e4
	static u32 texImageParam[2];

	//0212e5a4
	static u32 modelFileIDs[2];

	//0212e5b4
	static PlayerCapAnimation capAnimations[9];

	//0212e5ac
	static u16 texPaletteOffset[4];

	//0212df20
	PlayerCap();

	//D0:0212dec0
	//D1:0212def4
	virtual ~PlayerCap();

	//0212de44
	bool create(u8 playerID);

	//0212dce4
	bool render(bool skip, fx32 frame, s8 texPalette, GXRgb diffuse, GXRgb ambient, bool toon);

	//0212dc68
	void setAnimation(u8 animType, bool smallPlayer);

	//0212df4c
	static bool loadFiles();

};
NTR_SIZE_GUARD(PlayerCap, 0xC4);
