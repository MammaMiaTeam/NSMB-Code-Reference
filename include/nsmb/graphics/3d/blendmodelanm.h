#pragma once
#include "nitro_if.h"
#include "nsmb/graphics/3D/model.h"
#include "nsmb/graphics/util/framectrl.h"


//vtable 0203c4dc
class BlendModelAnm : public Model
{
public:

	struct BlendAnimation {
		NNSG3dAnmObj* animation;
		bool attached;//True if the animation object is attached to the render object
	};

	FrameCtrl frameController;
	void* animFile; //Anim file ptr
	BlendAnimation blendAnims[2];
	u32 currentAnimID; //Current animation ID
	u32 lastAnimID; //Last animation ID
	fx32 blendRatio; //Blend ratio
	fx32 blendStep; //Blend increment
	s8 selector1; //Selector 1 (start interpolation)
	s8 selector2; //Selector 2 (end interpolation) [c1->c0]

	//020193e0
	sym BlendModelAnm() __body

	//D0:020193c0
	//D1:020193c0
	sym virtual ~BlendModelAnm() override __body

	//02019214
	sym virtual void render(const VecFx32* scale) override __body

	//020191cc
	sym virtual void render(const MtxFx43& transform, const VecFx32* scale) override __body

	//0201918c
	sym virtual void render() override __body

	//020192a8
	sym bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID) __rbody //Loads the model with the given params from the bmd. Allocates memory for both BlendAnimations, initializes the frame controller and registers the first animation. returns true if successful, false otherwise.

	//02018fb8
	sym void pushAnimation(u32 animID, u32 steps, FrameCtrl::Type type, fx32 speed, u16 startFrame) __body
	/*
		Pushes a new animation to blend to.
		If animID equals the current animation's ID, frame controller settings are applied only.
		If animID equals the last animation's ID which is not fully back-blended, the animation is blended back to itself.
		If animID is a new animation ID, the animation including the frame controller is initialized. It resets the blend ratio to 0 and calculates the blend increment with 1 / (steps + 1).
	*/

	//02019138
	sym void update() __body //Updates the frame controller and increments the blend ratio. If the ratio exceeds 1.0 after update, it is capped at 1.0 and unregisters the animation.

	//02019288
	sym void attachAnimation(BlendAnimation* anim) __body //If it's active, unregister it from the model and deactivate it

	//0201925c
	sym void detachAnimation(BlendAnimation* anim) __body //Register anim for the model and activate it

};
NTR_SIZE_GUARD(BlendModelAnm, 0xC4);
