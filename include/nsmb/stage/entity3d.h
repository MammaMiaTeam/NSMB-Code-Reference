#pragma once
#include "entity.h"
#include "nsmb/graphics/3d/model.h"


class StageEntity3D : public StageEntity
{
public:

	Model model;

	Vec2 rotationTranslation; // if y != 0 -> trans y, rot x, trans -y otherwise trans calls are skipped
	Vec2 renderOffset;

	bool fogFlag; // unused (missing functionality)
	u8 alpha;

	inline StageEntity3D() {}

	// render process: translate (position + renderOffset); rotate Y, rotate X (see rotationTranslation), rotate Z
	// 020ce92c
	virtual s32 onRender() override;

	// D0: 020ce83c
	// D1: 020ce8b8
	inline virtual ~StageEntity3D() override {}

	// 020ceac4
	virtual void preRender3D();

	// 020ceac0
	virtual void postRender3D();

};
NTR_SIZE_GUARD(StageEntity3D, 0x4A0);
