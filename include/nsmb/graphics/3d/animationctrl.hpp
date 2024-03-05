#pragma once
#include "nsmb_nitro.hpp"
#include "nsmb/graphics/3d/animation.hpp"
#include "nsmb/graphics/util/framectrl.hpp"


//vtable 0203c4cc
class AnimationCtrl : public Animation
{
public:

	FrameCtrl frameController;

	//02018d88
	AnimationCtrl();

	//D0:02018d40
	//D1:02018d68
	virtual ~AnimationCtrl();

	//02018cf4
	bool createCtrl(NNSG3dRenderObj* model, void* animFile, u32 animID, NNSG3dResTex* texture); //Creates the animation and sets up the frame controller with the given parameters. returns true if successful, false otherwise.

	//02018c74
	void init(u32 animID, FrameCtrl::Type type, fx32 speed, u16 startFrame); //If animID doesn't equal the current animation ID, the new animation is loaded and attached if successful. In both cases the frame controller is reinitialized with type and speed, startFrame is only set when the animation ID changed.

	//02018c54
	void update(); //Steps the frame controller and updates the animation accordingly

	//02018c3c
	void setFrame(u16 frame); //Sets the animation's frame and updates it accordingly
	
	NTR_INLINE bool finished() {
		return frameController.finished();
	}

	constexpr u16 getFrame() {
		return frameController.currentFrame >> FX32_SHIFT;
	}

	constexpr void setFullFrame(fx32 frame) {
		frameController.currentFrame = frame;
	}

	constexpr fx32 getFullFrame() {
		return frameController.currentFrame;
	}

	constexpr void setFrameCount(u16 count) {
		frameController.setFrameCount(count);
	}

	NTR_INLINE u16 getFrameCount() {
		return frameController.getFrameCount();
	}

	constexpr void setSpeed(fx32 speed) {
		frameController.speed = speed;
	}

	constexpr fx32 getSpeed() {
		return frameController.speed;
	}

};
NTR_SIZE_GUARD(AnimationCtrl, 0x2C);
