#ifndef NSMB_MODEL_H_
#define NSMB_MODEL_H_

#include "nitro_if.h"
#include "nsmb/vector.h"



//vtable 0203c4bc
class ModelBase 
{
public:

	NNSG3dRenderObj renderObj;

	//02019c08
	ModelBase();

	//D0:02019bd8
	//D1:02019bf8
	//D2:02019bc8
	virtual ~ModelBase();

	//02019b7c
	static NNSG3dResMdl* loadModel(void* bmd, u32 modelID, NNSG3dResTex** texture);	//Loads the model with ID modelID from the NSBMD-file pointed to by bmd and outputs texture (if a valid one has been found). returns a pointer to the model if successful, a nullptr otherwise.

};



//vtable 0203c51c
class Model : public ModelBase
{
public:

	NNSG3dResMdl* modelInfo;
	NNSG3dResTex* texture;

	union {
		struct {
			MtxFx33 baseTransform;
			VecFx32 translation;
		};
		MtxFx43 modelMatrix;
	};

	//C1:02019a30
	//C2:02019a5c
	Model();

	//D0:020199e8
	//D1:02019a10
	//D2:020199c8
	virtual ~Model() override;
	
	//02019944
	virtual void null();

	//020198c4
	virtual void render(const VecFx32* scale);

	//02019864
	virtual void render(const MtxFx43* transform, const VecFx32* scale);

	//02019858
	virtual void render();

	//02019948
	bool create(void* bmd, u32 modelID, u32 polygonID); //Loads the model with ID modelID from the bmd, assigns texture and model, sets the polygon ID and disables ambient/emission components. returns true if successful, false otherwise.

	//02019934
	void renderModel();

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
	NNSG3dResMatData* getMaterialData(u32 index); //returns a pointer to the model's material data with the given index (doesn't check for index out of bounds)

	//020197fc
	NNSG3dResMat* getMaterialCollection(); //returns a pointer to the model's material collection

	//020197e0
	s32 getMaterialIndex(const NNSG3dResName* name); //returns an index to the material given by name or -1 if no matching entry could be found

	//020197d4
	NNSG3dResNodeInfo* getNodeInfo(); //returns a pointer to the node info

	//020197bc
	s32 getNodeIndex(const NNSG3dResName* name); //returns an index to the node given by name or -1 if no matching entry could be found

	//02019740
	static bool getNodeMatrixInternal(NNSG3dResNodeInfo* nodeInfo, u32 nodeIndex, MtxFx43* mtx); //If the model's matrix is on the stack, it back-calculates the node's model matrix and stores it in mtx. returns true after operation, false if the matrix wasn't on stack.

	//0201972c
	bool getNodeMatrix(u32 nodeIndex, MtxFx43* mtx); //Calls getNodeMatrixInternal on the model's node info with index nodeIndex. The resulting matrix is stored in mtx and true is returned; on failure, false is returned.

	//020196dc
	bool getNodePosition(u32 nodeIndex, Vec3* position); //returns the translation component of the node matrix with index nodeIndex in position. returns true on success, false on failure.

	//0201967c
	bool restoreNodeMatrix(u32 nodeIndex); //Restores the node matrix with index nodeIndex. returns true if successful, false otherwise.
};



class FrameCtrl
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
	void init(u16 frames, FrameCtrl::Type type, fx32 speed, u16 startFrame); //Initializes the controller with the given parameters

	//0201fe88
	u16 getFrameCount(); //returns the frame count (truncated integer)

	//0201fe74
	void setAnimationType(FrameCtrl::Type type); //Sets the animation type

	//0201fe34
	bool finished(); //If speed is positive, it returns true if current frame exceeds frames - 1. If speed is negative, it returns true if currentFrame equals 0 or less.

	//0201fd1c
	bool passing(u16 targetFrame); //returns true if the next update passes targetFrame, false otherwise


	inline void setFrame(u16 frame) {
		currentFrame = frame << 12;
	}

	inline void setFrameCount(u16 count) {
		settings &= typeMask;
		settings |= (count << 12) & lastFrameMask;
	}

};




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
	BlendModelAnm();

	//D0:020193c0
	//D1:020193c0
	virtual ~BlendModelAnm() override;

	//02019214
	virtual void render(const VecFx32* scale) override;

	//020191cc
	virtual void render(const MtxFx43* transform, const VecFx32* scale) override;

	//0201918c
	virtual void render() override;

	//020192a8
	bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID); //Loads the model with the given params from the bmd. Allocates memory for both BlendAnimations, initializes the frame controller and registers the first animation. returns true if successful, false otherwise.

	//02018fb8
	void pushAnimation(u32 animID, u32 steps, FrameCtrl::Type type, fx32 speed, u16 startFrame);
	/*
		Pushes a new animation to blend to.
		If animID equals the current animation's ID, frame controller settings are applied only.
		If animID equals the last animation's ID which is not fully back-blended, the animation is blended back to itself.
		If animID is a new animation ID, the animation including the frame controller is initialized. It resets the blend ratio to 0 and calculates the blend increment with 1 / (steps + 1). 
	*/

	//02019138
	void update(); //Updates the frame controller and increments the blend ratio. If the ratio exceeds 1.0 after update, it is capped at 1.0 and unregisters the animation.

	//02019288
	void attachAnimation(BlendAnimation* anim); //If it's active, unregister it from the model and deactivate it

	//0201925c
	void detachAnimation(BlendAnimation* anim); //Register anim for the model and activate it

};



//vtable 0203c4fc
class ModelAnm : public Model
{
public:

	FrameCtrl frameController;
	void* animFile; //Animation file ptr
	NNSG3dAnmObj* animation;
	u32 animID; //Anim ID

	//02019644
	ModelAnm();

	//D0:020195fc
	//D1:02019624
	virtual ~ModelAnm() override;

	//02019518
	virtual void render(const VecFx32* scale) override;

	//020194f8
	virtual void render(const MtxFx43* transform, const VecFx32* scale) override;

	//020194e0
	virtual void render() override;

	//02019530
	bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID); //Loads the model from bmd and the animation from bca. Also allocates unka0 on heap. Default initializes the frame animation. Attaches the animation to the render object. returns true if successful, false otherwise.

	//02019440
	void init(u32 animID, FrameCtrl::Type type, fx32 speed, u16 startFrame); //If animID equals the current animation ID, type and speed are applied to the frame controller. If not, the animation object is reset and is initialized with the given parameters.


	inline void update() {
		frameController.update();
	}

	inline bool finished() {
		return frameController.finished();
	}

	inline void setFrame(u16 frame) {
		frameController.setFrame(frame);
	}

	inline u16 getFrame() {
		return frameController.currentFrame;
	}

	inline void setFrameCount(u16 count) {
		frameController.setFrameCount(count);
	}

	inline u16 getFrameCount() {
		return frameController.getFrameCount();
	}

};




//vtable 0203c49c
class Texture
{
public:

	NNSG3dResTex* texture;

	//02018c2c
	GEN_FUNC( Texture );

	//D0:02018bfc
	//D1:02018c1c
	GEN_FUNC(virtual ~Texture );

	//02018bc8
	GEN_FUNC( bool load,void* texFile); //Loads the texture from the file. returns true if successful, false otherwise.

	//02018b98
	GEN_FUNC( bool getTextureParams,u32* texParams, u32 texID); //Calls GFX::getTextureParams and returns whether parameter fetching was successful.
	
	//02018b68
	GEN_FUNC( bool getTexturePaletteDestination,u32* palDest, u32 palID); //Calls GFX::getTexturePaletteDestination and returns whether address calculation was successful.

};

struct TextureInfo {
	u32 texImageParam;
	u32 texPlttBase;
};

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
	Animation();

	//D0:02018f38
	//D1:02018f58
	//D2:02018f28
	virtual ~Animation();

	//02018e74
	bool create(NNSG3dRenderObj* model, void* animFile, u32 animID, NNSG3dResTex* texture); //Creates the animation with the given parameters. returns true if successful, false otherwise.

	//02018e28
	void init(u32 animID, u16 startFrame); //If animID doesn't equal the current animation ID, the new animation is loaded and attached if successful. The startFrame is set in both cases.

	//02018dd8
	bool reset(u32 animID); //Sets the current animation to animID and initializes the animation object. returns true if successful, false otherwise.

	//02018dc0
	void attach(); //Links the animation to the render object

	//02018da8
	void detach(); //Unlinks the animation from the render object

};



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

};



namespace GFX {

	//02019b6c
	void initialize();			//Initializes the graphics engine

	//02019afc
	bool getTextureParams(NNSG3dResTex* texture, u32 texID, u32* texParams); //Obtains the texture's parameters and stores them in texParams. returns whether texture params were fetched successfully.

	//02019a88
	bool getTexturePaletteDestination(NNSG3dResTex* texture, u32 palID, u32* palDest); //Calculates the texture's VRAM slot destination address and stores it in palDest. returns whether address calculation was successful.

	//020446b4
	void setRotationZ(MtxFx43* mtx, s16 angle);

	//020446f4
	void setRotationY(MtxFx43* mtx, s16 angle);

	//02044734
	void setRotationX(MtxFx43* mtx, s16 angle);

	//02044774
	void setRotation(MtxFx43* mtx, s16 angleX, s16 angleY, s16 angleZ);

	//02044814
	void setTranslation(MtxFx43* mtx, fx32 x, fx32 y, fx32 z);

	//0204485c
	void rotateZ(MtxFx43* mtx, s16 angle);

	//02044888
	void rotateY(MtxFx43* mtx, s16 angle);

	//020448b4
	void rotateX(MtxFx43* mtx, s16 angle);

	//020448e0
	void rotate(MtxFx43* mtx, s16 angleX, s16 angleY, s16 angleZ);

	//0204496c
	void rotateReversed(MtxFx43* mtx, s16 angleX, s16 angleY, s16 angleZ);

	//020449f8
	void scale(MtxFx43* mtx, fx32 scaleX, fx32 scaleY, fx32 scaleZ);

	//02044a24
	void translate(MtxFx43* mtx, fx32 transX, fx32 transY, fx32 transZ);

	inline void identity(MtxFx43* mtx) {
		MTX_Identity43(mtx);
	}

}



#endif // !NSMB_MODEL_H_
