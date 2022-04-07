#pragma once
#include "entity.h"
#include "nsmb/graphics/3d/modelanm.h"


class StageEntity3DAnm : public StageEntity
{
public:

	ModelAnm model;

	u8 unk498; // poly ID?
	u16 initRotation;

	Vec2 rotationTranslation; // if y != 0 -> trans y, rot x, trans -y otherwise trans calls are skipped
	Vec2 renderOffset;

	bool fogFlag;
	u8 alpha;

	// 020cee34
	StageEntity3DAnm();

	// render process: translate (position + renderOffset); rotate Y, rotate X (see rotationTranslation), rotate Z
	// 020ceae0
	virtual s32 onRender() override;

	// D0: 020ced44
	// D1: 020cedc0
	// D2: 020cecd0
	virtual ~StageEntity3DAnm() override;

	// 020ceac8
	virtual void updateAnimation() override;

	// 020ceccc
	virtual void preRender3D();

	// 020cecc8
	virtual void postRender3D();

};
NTR_SIZE_GUARD(StageEntity3DAnm, 0x4BC);
