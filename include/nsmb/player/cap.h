#pragma once
#include "nsmb/graphics/3d/animation.h"
#include "nsmb/graphics/3d/model.h"


// vtable at 0212F8B0 (ov11)
class PlayerCap {
public:

	PlayerCap();
	virtual ~PlayerCap();

	bool create(u8 playerID);
	bool render(BOOL skip, fx32 frame, s8 texPalette, GXRgb diffuse, GXRgb ambient, BOOL toon);
	void setAnimation(u8 animType, BOOL smallPlayer);

	static bool loadResources();

	static u16 paletteParams[2];
	static u32 textureParams[2];

	static u32 modelFileIDs[2];
	static u16 paletteOffsets[4];
	static PlayerCapAnimation capAnimations[9];


	Model model;
	Animation animation;
	FrameCtrl frameController;
	u8 playerID;
	s8 animType;

};
NTR_SIZE_GUARD(PlayerCap, 0xC4);
