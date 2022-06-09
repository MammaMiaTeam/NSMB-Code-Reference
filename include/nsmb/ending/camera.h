#pragma once

#include "nsmb/graphics/util/perspview.h"


// vtable at 020E9BF8 (ov8)
class EndingCamera : public PerspView {

public:

	using StateFunction = void(EndingCamera::*)();


	inline EndingCamera() {}

	// D0: 020DE16C
	// D1: 020DE104
	virtual ~EndingCamera();

	// 020DE4F8
	virtual s32 onCreate() override;
	// 020DE408
	virtual s32 onUpdate() override;
	// 020DE424
	virtual s32 onRender() override;

	// 020DE31C
	void setState(u32 stateID);
	// 020DE2A8
	void callState();

	// 020DE348
	void slideshowState();
	// 020DE404
	void cutsceneState();

	// 020DE1DC
	void setOrtho(fx32 tangent, fx32 bitangent, fx32 left, fx32 right);

	// 020DE288
	Vec3 setVector(fx32 x, fx32 y, fx32 z);

	static constexpr u16 objectID = 324;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 4;

	// 020E9BF0
	static const ObjectProfile profile;

	// 020EE888
	static const StateFunction stateFunctions[2];


	StateFunction updateFunction;
	Vec3 unused110;
	u32 stateID;
	u32 updateStep;
	u32 unused128[4];

};
NTR_SIZE_GUARD(EndingCamera, 0x138);
