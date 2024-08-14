#pragma once
#include "nsmb/graphics/util/orthoview.hpp"


// ov10
class StageCamera : public OrthoView
{
public:

	typedef void(StageCamera::* StateFunction)();

	//C3:020ce658
	NTR_INLINE StageCamera() {}

	// D0:
	// D1:
	NTR_INLINE virtual ~StageCamera() override {}

	//020ce540
	virtual s32 onCreate() override;

	//020ce42c
	virtual s32 onUpdate() override;

	//020ce46c
	virtual s32 onRender() override;

	static constexpr u16 ObjectID = 316;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 0;

	//02123c80
	static ObjectProfile profile;

	StateFunction unk108; //State function
	Vec3 unk110;
	u32 unk120; //Current state index
	u32 unk124; //Execute pre-state bool
	u32 unk128;
	u32 unk12C;
	u32 unk130; //Roll
	u32 unk134;

};
NTR_SIZE_GUARD(StageCamera, 0x138);
