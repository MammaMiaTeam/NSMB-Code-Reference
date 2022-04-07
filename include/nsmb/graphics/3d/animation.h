#pragma once
#include "nitro_if.h"


//vtable 0203c4ac
class Animation
{
public:

	NNSG3dRenderObj* renderObj;
	NNSG3dResMdl* modelInfo;
	NNSG3dResTex* texture;
	void* animFile; //Anim file
	NNSG3dAnmObj* animation;
	u32 animID; //Anim ID
	u16 frameCount; //Total animation frames

	//C1:02018f68
	//C2:02018f90
	sym Animation() __body

	//D0:02018f38
	//D1:02018f58
	//D2:02018f28
	sym virtual ~Animation() __body

	//02018e74
	sym bool create(NNSG3dRenderObj* model, void* animFile, u32 animID, NNSG3dResTex* texture) __rbody //Creates the animation with the given parameters. returns true if successful, false otherwise.

	//02018e28
	sym void init(u32 animID, u16 startFrame) __body //If animID doesn't equal the current animation ID, the new animation is loaded and attached if successful. The startFrame is set in both cases.

	//02018dd8
	sym bool reset(u32 animID) __rbody //Sets the current animation to animID and initializes the animation object. returns true if successful, false otherwise.

	//02018dc0
	sym void attach() __body //Links the animation to the render object

	//02018da8
	sym void detach() __body //Unlinks the animation from the render object

	inline void setFrame(fx32 frame) {
		NNS_G3dAnmObjSetFrame(animation, frame);
	}

};
NTR_SIZE_GUARD(Animation, 0x20);
