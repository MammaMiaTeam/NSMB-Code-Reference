#pragma once
#include "nitro_if.h"


namespace BNBL
{

	struct File
	{
		struct Rect
		{
			u16 x;
			u16 y;
			u8 width;
			u8 height;
		};

		char magic[4];
		u16 padding;
		u16 rectCount;
		Rect rects[];
	};


	// 0x020558E8
	u32 getYFromAnchoredPos(u16 pos_field, u32 width);

	// 0x02055930
	u32 getXFromAnchoredPos(u16 pos_field, u32 width);


	// 0x02055A0C
	s16 getRectangleIDAtPos(void* bnbl, s32 x, s32 y);

	NTR_INLINE s16 getTouchedRectangleID(void* bnbl) {
		return getRectangleIDAtPos(bnbl, penX, penY);
	}


	// 0x02055AD4
	u16 getRectangleCount(void* bnbl);

};
