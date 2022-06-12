#pragma once
#include "nitro_if.h"
#include "nsmb/graphics/3D/model.h"
#include "nsmb/graphics/util/framectrl.h"


//vtable 0203c4fc
class ModelAnm : public Model
{
public:

	FrameCtrl frameController;
	void* animFile; //Animation file ptr
	NNSG3dAnmObj* animation;
	u32 animID; //Anim ID

	//02019644
	sym ModelAnm() __body

	//D0:020195fc
	//D1:02019624
	sym virtual ~ModelAnm() override __body

	//02019518
	virtual void render(const VecFx32* scale) override;

	//020194f8
	virtual void render(const MtxFx43& transform, const VecFx32* scale) override;

	//020194e0
	virtual void render() override;

	//02019530
	bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID); //Loads the model from bmd and the animation from bca. Also allocates unka0 on heap. Default initializes the frame animation. Attaches the animation to the render object. returns true if successful, false otherwise.

	//02019440
	void init(u32 animID, FrameCtrl::Type type, fx32 speed, u16 startFrame); //If animID equals the current animation ID, type and speed are applied to the frame controller. If not, the animation object is reset and is initialized with the given parameters.


	NTR_INLINE void update() {
		frameController.update();
	}

	NTR_INLINE bool finished() {
		return frameController.finished();
	}

	NTR_INLINE void setFrame(u16 frame) {
		frameController.setFrame(frame);
		NNS_G3dAnmObjSetFrame(animation, frame << FX32_SHIFT);
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
NTR_SIZE_GUARD(ModelAnm, 0xA8);
