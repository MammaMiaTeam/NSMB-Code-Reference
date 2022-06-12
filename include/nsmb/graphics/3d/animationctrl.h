#pragma once
#include "nitro_if.h"
#include "nsmb/graphics/3D/animation.h"
#include "nsmb/graphics/util/framectrl.h"


//vtable 0203c4cc
class AnimationCtrl : public Animation
{
public:

	FrameCtrl frameController;

	//02018d88
	sym AnimationCtrl() __body

	//D0:02018d40
	//D1:02018d68
	sym virtual ~AnimationCtrl() __body

	//02018cf4
	sym bool createCtrl(NNSG3dRenderObj* model, void* animFile, u32 animID, NNSG3dResTex* texture) __rbody //Creates the animation and sets up the frame controller with the given parameters. returns true if successful, false otherwise.

	//02018c74
	sym void init(u32 animID, FrameCtrl::Type type, fx32 speed, u16 startFrame) __body //If animID doesn't equal the current animation ID, the new animation is loaded and attached if successful. In both cases the frame controller is reinitialized with type and speed, startFrame is only set when the animation ID changed.

	//02018c54
	sym void update() __body //Steps the frame controller and updates the animation accordingly

	//02018c3c
	sym void setFrame(u16 frame) __body //Sets the animation's frame and updates it accordingly
	
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
