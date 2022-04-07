#pragma once
#include "nsmb/graphics/util/orthoview.h"


// ov10
class StageCamera : public OrthoView
{
public:

	typedef void(StageCamera::* StateFunction)();

	StateFunction unk108;//State function
	Vec3 unk110;
	u32 unk120;//Current state index
	u32 unk124;//Execute pre-state bool
	u32 unk128;
	u32 unk12C;
	u32 unk130;//Roll
	u32 unk134;

	//02123c80
	static ObjectProfile profile;

	//C3:020ce658
	__inline StageCamera() {}

	// D0:
	// D1:
	__inline virtual ~StageCamera() override {}

	//020ce540
	sym virtual s32 onCreate() override __rbody

	//020ce42c
	sym virtual s32 onUpdate() override __rbody

	//020ce46c
	sym virtual s32 onRender() override __rbody

};
NTR_SIZE_GUARD(StageCamera, 0x138);
