#pragma once

#include "bnbl.hpp"
#include "bncd.hpp"
#include "bncl.hpp"
#include "nsmb/core/graphics/2d/oam.hpp"

namespace UI
{
	// 02004564
	void initSub(BNCD* bncd, BNCL* bncl, BNBL* bnbl);

	// 020042D8
	void drawObject(BNCL::Object* object, BNCL::Object* maybeBgObj, bool subScreen, const Vec2* scale, s16 rot, u32 xOffset, u32 yOffset, u8 palette, OAM::Flags flags);

	// 0200429C
	// Note: Ignores BNCL position alignment
	void getObjectPosition(s16 position[2], u16 bnclObjectID);

	// 0200421C
	// Note: Ignores BNCL position alignment
	bool draw(u16 bnclObjectID, GXOamAttr* oamAttrs, OAM::Flags flags, u8 palette, u8 affineSet, const Vec2* scale, s16 rot, const s16 rotCenter[2], OAM::Settings settings, u32 xOffset, u32 yOffset);

	// 0200419C
	// Note: Ignores BNCL position alignment
	bool drawSub(u16 bnclObjectID, GXOamAttr* oamAttrs, OAM::Flags flags, u8 palette, u8 affineSet, const Vec2* scale, s16 rot, const s16 rotCenter[2], OAM::Settings settings, u32 xOffset, u32 yOffset);

	// 02085888
	extern BNBL* bnbl;
	// 0208588C
	extern BNCL* bncl;
	// 02085890
	extern BNCL* bnclSub;
	// 02085898
	extern BNCD* bncdSub;

}
