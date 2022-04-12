#pragma once
#include "nsmb/graphics/util/perspview.h"


// ov8
class EndingCamera : public PerspView
{
public:

	typedef void(EndingCamera::* StateFunction)();

	//C3:020DE6A8
	EndingCamera();

	//D0:020DE16C
	//D1:020DE104
	virtual ~EndingCamera();

	//020DE4F8
	virtual s32 onCreate() override;

	//020DE408
	virtual s32 onUpdate() override;

	//020DE424
	virtual s32 onRender() override;

	static constexpr u16 objectID = 324;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 4;

	//020E9BF0
	static ObjectProfile profile;

	StateFunction unk108;
	Vec3 unk110;
	u32 unk120;
	u32 unk124;
	u32 unk128;
	u32 unk12c;
	u32 unk130;
	u32 unk134;

};
NTR_SIZE_GUARD(EndingCamera, 0x138);
