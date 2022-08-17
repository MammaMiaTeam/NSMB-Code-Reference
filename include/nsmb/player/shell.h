#pragma once
#include "nsmb/graphics/3d/model.h"


// vtable at 0212F8C0 (ov11)
class PlayerShell {
public:

	PlayerShell();
	virtual ~PlayerShell();

	bool create();
	bool render(BOOL skip, s8 texPalette, GXRgb diffuse, GXRgb ambient, BOOL toon);

	static bool loadResources();

	static u16 paletteParams;
	static u32 textureParams;


	Model model;

};
NTR_SIZE_GUARD(PlayerShell, 0x94);
