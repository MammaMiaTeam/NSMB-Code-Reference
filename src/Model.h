#ifndef NSMB_MODEL_INCLUDED
#define NSMB_MODEL_INCLUDED

#include "nitro_if.h"

#include "Vector.h"



//vtable 0203c4bc
/*
02019bf8: dtor
02019bd8: dtor_free
*/
class ModelBase 
{
public:

	NNSG3dRenderObj renderModel;

	//02019c08
	ModelBase();

	//02019bc8: dtor1

	virtual ~ModelBase();

	//02019b7c
	static NNSG3dResMdl* loadModel(void* bmd, u32 modelID, NNSG3dResTex** texture);	//Loads the model with ID modelID from the NSBMD-file pointed to by bmd and outputs texture (if a valid one has been found). Returns a pointer to the model if successful, a nullptr otherwise.

};



//vtable 0203c51c
/*
02019a10: dtor
020199e8: dtor_free
02019944:
020198c4: render //scale
02019864: render //transform
02019858: render
*/
class Model : public ModelBase
{
public:

	NNSG3dResMdl* modelInfo;
	NNSG3dResTex* textureInfo;

	union {
		struct {
			MtxFx33 unk60;
			VecFx32 unk84;
		};
		MtxFx43 unk60;
	};

	//02019a30
	Model();

	//02019a5c
	Model(); //Ctor used by subclasses

	virtual ~Model();

	//020199c8: dtor1

	//02019948
	bool create(void* bmd, u32 modelID, u32 polygonID); //Loads the model with ID modelID from the bmd, assigns texture and model, sets the polygon ID and disables ambient/emission components. Returns true if successful, false otherwise.

	//02019934
	//void draw();

	//02019838
	void setCommandCallback(NNSG3dSbcCallBackFunc* cb, u8* address, u8 cmd, NNSG3dSbcCallBackTiming timing); //Sets the SBC command callback with the given timing (address is eliminated and only left for backwards compatibility)
	/*
		The callback is executed when the current SBC command equals cmd.
		Timings:
		A: Before
		B: During
		C: After
	*/

	//0201980c
	NNSG3dResMatData* getMaterialData(u32 index); //Returns a pointer to the model's material data with the given index (doesn't check for index out of bounds)

	//020197fc
	NNSG3dResMat* getMaterialCollection(); //Returns a pointer to the model's material collection

	//020197e0
	s32 getMaterialIndex(const NNSG3dResName* name); //Returns an index to the material given by name or -1 if no matching entry could be found

	//020197d4
	NNSG3dResNodeInfo* getNodeInfo(); //Returns a pointer to the node info

	//020197bc
	s32 getNodeIndex(const NNSG3dResName* name); //Returns an index to the node given by name or -1 if no matching entry could be found

	//02019740
	static bool getNodeMatrixInternal(NNSG3dResNodeInfo* nodeInfo, u32 nodeIndex, MtxFx43* mtx); //If the model's matrix is on the stack, it calculates the node matrix and stores it in mtx. Returns true after operation, false if the matrix wasn't on stack.

	//0201972c
	bool getNodeMatrix(u32 nodeIndex, MtxFx43* mtx); //Calls getNodeMatrixInternal on the model's node info with index nodeIndex. The resulting matrix is stored in mtx and true is returned; on failure, false is returned.

	//020196dc
	bool getNodePosition(u32 nodeIndex, Vec3* position); //Returns the translation component of the node matrix with index nodeIndex in position. Returns true on success, false on failure.

	//0201967c
	bool restoreNodeMatrix(u32 nodeIndex); //Restores the node matrix with index nodeIndex. Returns true if successful, false otherwise.
};



class FrameControl
{
public:

	static constexpr u32 typeMask = 0xC0000000;
	static constexpr u32 lastFrameMask = 0x3FFFFFFF;

	enum Type : u32{
		Looping	= 0x00000000,
		Standard = 0x40000000
	};

	u32 settings;		/*
							Masked settings:
							0x3FFFFFFF: Frame count as fx32
							0xC0000000: Animation type
						*/
	fx32 currentFrame;	//Current animation frame
	fx32 speed;			//Speed of animation

	//0201feb8
	void update(); //Updates currentFrame by speed. If it's looping, currentFrame is wrapped around. If not, currentFrame is incremented until it reaches frames - 1. When timer becomes negative due to negative speeds, it's kept at 0.

	//0201fe9c
	void init(u16 frames, FrameControl::Type type, fx32 speed, u16 startFrame); //Initializes the controller with the given parameters

	//0201fe88
	u16 getFrameCount(); //Returns the frame count (truncated integer)

	//0201fe74
	void setAnimationType(FrameControl::Type type); //Sets the animation type

	//0201fe34
	bool finished(); //If speed is positive, it returns true if current frame exceeds frames - 1. If speed is negative, it returns true if currentFrame equals 0 or less.

	//0201fd1c
	bool passing(u16 targetFrame); //Returns true if the next update passes targetFrame, false otherwise

};



struct BlendAnimation {
	NNSG3dAnmObj* unka0;
	bool unka4;
};


//vtable 0203c4dc
/*
020193c0: dtor
02019398: dtor_free
02019944:
02019214:
020191cc:
0201918c:
*/
class ModelAnm : public Model
{
public:

	FrameControl unk90;
	void* unk9c; //Anim file ptr
	BlendAnimation unka0[2];
	u32 unkb0; //Current animation ID
	u32 unkb4; //Last animation ID
	fx32 unkb8; //Blend ratio
	fx32 unkbc; //Blend increment
	s8 unkc0; //Selector 1 (start interpolation)
	s8 unkc1; //Selector 2 (end interpolation) [c1->c0]

	//020193e0
	ModelAnm();

	//020192a8
	bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID); //Loads the model with the given params from the bmd. Allocates memory for both BlendAnimations, initializes the frame controller and registers the first animation. Returns true if successful, false otherwise.

	//02018fb8
	void pushAnimation(u32 animID, u32 steps, FrameControl::Type type, fx32 speed, u16 startFrame);
	/*
		Pushes a new animation to blend to.
		If animID equals the current animation's ID, frame controller settings are applied only.
		If animID equals the last animation's ID which is not fully back-blended, the animation is blended back to itself.
		If animID is a new animation ID, the animation including the frame controller is initialized. It resets the blend ratio to 0 and calculates the blend increment with 1 / (steps + 1). 
	*/

	//02019138
	void update(); //Updates the frame controller and increments the blend ratio. If the ratio exceeds 1.0 after update, it is capped at 1.0 and unregisters the animation.

	//0201925c
	void attachAnimation(BlendAnimation* anim); //If it's active, unregister it from the model and deactivate it

	//02019288
	void detachAnimation(BlendAnimation* anim); //Register anim for the model and activate it

};



//vtable 0203c4fc
/*
02019624: dtor
020195fc: dtor_free
02019944:
02019518:
020194f8:
020194e0:
*/
class ModelCA : public Model
{
public:

	FrameControl unk90;
	void* unk9c; //Animation file ptr
	NNSG3dAnmObj* unka0;
	u32 unka4; //Anim ID; type???

	//02019644
	ModelCA();

	//02019530
	bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID); //Loads the model from bmd and the animation from bca. Also allocates unka0 on heap. Default initializes the frame animation. Attaches the animation to the render object. Returns true if successful, false otherwise.

	//02019440
	void init(u32 animID, FrameControl::Type type, fx32 speed, u16 startFrame); //If animID equals the current animation ID, type and speed are applied to unk90. If not, the animation object is reset and is initialized with the given parameters.

	//Render updates frame controller

};




//vtable 0203c49c
/*
02018c1c: dtor
02018bfc: dtor_free
*/
class ComplexTexture
{
public:

	NNSG3dResTex* unk04;

	//02018c2c
	ComplexTexture();

	//02018bc8
	bool load(void* texFile); //Loads the texture from the file. Returns true if successful, false otherwise.

	//02018b98
	bool getTextureParams(u32* texParams, u32 texID); //Calls GFX::getTextureParams and returns whether parameter fetching was successful.
	
	//02018b68
	bool getTexturePaletteDestination(u32* palDest, u32 palID); //Calls GFX::getTexturePaletteDestination and returns whether address calculation was successful.

};


//vtable 0203c4ac
/*
02018f58: dtor
02018f38: dtor_free
*/
class TPModel
{
public:

	NNSG3dRenderObj* unk04;
	NNSG3dResMdl* unk08;
	NNSG3dResTex* unk0c;
	void* unk10; //Anim file
	NNSG3dAnmObj* unk14;
	u32 unk18; //Anim ID
	u16 unk1c; //Frames

	//02018f28: dtor1

	//02018f68
	TPModel();

	//02018f90
	TPModel(); //Used by subclasses

	//02018e74
	bool create(NNSG3dRenderObj* renderObject, void* animFile, u32 animID, NNSG3dResTex* texture); //Creates the texture SRT animation with the given parameters. Returns true if successful, false otherwise.

	//02018e28
	void setAnimation(u32 animID, u16 startFrame); //If animID doesn't equal the current animation ID, the new animation is loaded and attached if successful. The startFrame is set in both cases.

	//02018dd8
	bool initializeAnimation(u32 animID); //Sets the current animation to animID and initializes the animation object. Returns true if successful, false otherwise.

	//02018dc0
	void attachAnimation(); //Links the animation to the render object

	//02018da8
	void detachAnimation(); //Unlinks the animation from the render object

};



//vtable 0203c4cc
/*
02018d68: dtor
02018d40: dtor_free
*/
class MultiTexModel : public TPModel
{
public:

	FrameControl unk20;

	//02018d88
	MultiTexModel();

	//02018cf4
	bool create(NNSG3dRenderObj* model, void* animFile, u32 animID, NNSG3dResTex* texture); //Creates the texture SRT animation and sets up the frame controller with the given parameters. Returns true if successful, false otherwise.

	//02018c74
	void setAnimation(u32 animID, FrameControl::Type type, fx32 speed, u16 startFrame); //If animID doesn't equal the current animation ID, the new animation is loaded and attached if successful. In both cases the frame controller is reinitialized with type and spedd, startFrame is only set when the animation ID changed.

	//02018c54
	void update(); //Steps the frame controller and updates the animation accordingly

	//02018c3c
	void setFrame(u16 frame); //Sets the animation's frame and updates it accordingly

};



namespace GFX {

	//027e00c8
	extern NNS_G3dGlb global3DState; //Global 3D data uploaded to the GPU

	//02019b6c
	void initialize();			//Initializes the graphics engine

	//02019afc
	bool getTextureParams(NNSG3dResTex* texture, u32 texID, u32* texParams); //Obtains the texture's parameters and stores them in texParams. Returns whether texture params were fetched successfully.

	//02019a88
	bool getTexturePaletteDestination(NNSG3dResTex* texture, u32 palID, u32* palDest); //Calculates the texture's VRAM slot destination address and stores it in palDest. Returns whether address calculation was successful.

}



#endif	// NSMB_MODEL_INCLUDED
