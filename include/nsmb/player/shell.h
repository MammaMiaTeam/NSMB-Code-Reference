#pragma once
#include "nsmb/graphics/3d/model.h"


//vtable 0212f8c8
class PlayerShell
{
public:

	Model model;

	//0212f8ec
	static u16 texPaletteBase;

	//0212f8f0
	static u32 texImageParam;

	//0212e180
	PlayerShell();

	//D0:0212e130
	//D1:0212e15c
	virtual ~PlayerShell();

	//0212e0f8
	bool create();

	//0212e020
	bool render(bool skip, s8 texPalette, GXRgb diffuse, GXRgb ambient, bool toon);

	//0212e1a4
	static bool loadFiles();

};
NTR_SIZE_GUARD(PlayerShell, 0x94);
