#pragma once

#include "anim.hpp"
#include "cap.hpp"
#include "shell.hpp"
#include <nsmb/extra/assert.hpp>
#include <nsmb/extra/bitmaskenum.hpp>


// vtable at 0212F860 (ov11)
class PlayerModel {
public:

	enum class ModelState : u8
	{

		Super,
		Small

	};

	enum class HeadState : u8
	{

		Cap,
		NoCap,
		Dead,
		DeadNoCap

	};

	enum class Flags : u8
	{

		None = 0,
		Unused = 0x1,
		RenderSeparateCap = 0x2,
		RenderNoCapHead = 0x4,
		RenderDeadHead = 0x8,
		RenderShell = 0x10,

	};

	struct ModelCollection {

		Model* body;
		Model* heads[4];

	};

	struct NodeTransforms {

		MtxFx43 rightWrist;		// Bone: wrist_r1
		MtxFx43 leftWrist;		// Bone: wrist_l1
		MtxFx43 rightAnkle;		// Bone: ankle_r1
		MtxFx43 leftAnkle;		// Bone: ankle_l1
		MtxFx43 face;			// Bone: face_1
		MtxFx43 body;			// Bone: spin
		MtxFx43 leftArm;		// Bone: arm_l2
		MtxFx43 rightArm;		// Bone: arm_r2
		MtxFx43 leftLeg;		// Bone: leg_l2
		MtxFx43 rightLeg;		// Bone: leg_r2

		NTR_INLINE MtxFx43& operator[](u32 index) {
			ntr_assert(index < 10, "Invalid node transform index [%d]", index);
			return (&rightWrist)[index];
		}

		NTR_INLINE const MtxFx43& operator[](u32 index) const {
			ntr_assert(index < 10, "Invalid node transform index [%d]", index);
			return (&rightWrist)[index];
		}

	};


	PlayerModel();
	virtual ~PlayerModel();

	bool create(u8 playerID, u32 animationFileID);
	bool loadBody(u32 animationFileID);
	bool loadHead();
	void setBodyModelCallback(NNSG3dSbcCallBackFunc* callback);
	void setBodyModelOwner(void* owner);

	void render(MtxFx43& bodyModelMatrix, Vec3& scale, s8 texPalette, BOOL skip, u32 diffuse, u32 ambient, BOOL toon);
	void enableBodyToon(Model& model);
	void enableHeadToon(Model& model);
	void disableBodyToon(Model& model);
	void disableHeadToon(Model& model);
	void setDeathTexImageParams(); // TODO: what does this actually do?

	void setBodyAnimation(void* anmResource, u32 blendSteps, FrameCtrl::Type type, fx32 speed, u16 startFrame);
	void switchBodyAnimations(u32 sourceModel, u32 targetModel);
	void setHeadAnimation(void* anmResource, FrameCtrl::Type type, fx32 speed, u16 startFrame);
	void update();
	bool animationFinished();
	void setCurrentAnimationFrame(u16 frame);
	u16 getCurrentAnimationFrame() const;
	fx32 getFullAnimationFrame() const;
	u16 getAnimationFrameCount() const;
	void setAnimationSpeed(fx32 speed);
	fx32 getAnimationSpeed() const;
	bool animationPassing(u16 targetFrame) const;
	void initPartialAnimation(void* anmResource, FrameCtrl::Type type, fx32 speed, u16 startFrame);
	void startPartialAnimation(u32 nodeDisableIndex);
	void endPartialAnimation();
	void updatePartialAnimation();
	void saveNodeTransforms();


	static PlayerHeadAnimation luigiHeadAnimations[9];
	static PlayerHeadAnimation marioHeadAnimations[9];
	static u32 bodyModelIDs[2];
	static u16 bodyPaletteOffsets[4];
	static u16 headPaletteOffsets[4]; // For head + cap
	static u32 bodyModelFileIDs[2];
	static u32 capHeadPaletteSlots[2][2];
	static u32 bodyPaletteSlots[2][2];
	static u32 deadHeadPaletteSlots[2][2];
	static u32 headModelIDs[2][2];
	static u32 headModelFileIDs[2][4];
	static u32 headPatternFileIDs[2];
	static PlayerHeadAnimation* headAnimations[2];
	static u32 deadBodyTextureSlots[2][2];
	static u32 deadHeadTextureSlots[2][2][4];


	void* currentBodyAnmResource;			// Current body animation resource
	void* lastBodyAnmResource;				// Last body animation resource
	void* partialBodyAnmResource;			// Partial body animation resource
	NNSG3dAnmObj* bodyAnimations[2];		// Blending body animations
	NNSG3dAnmObj* partialBodyAnimation;		// Partial body animation
	u16* bodyAnimationMapData;				// Initial body map data (bone -> model node)
	void* headAnmResource;					// Head animation resource
	NNSG3dAnmObj* headAnimation;			// Head animation
	FrameCtrl bodyFrameController;			// Body frame controller
	FrameCtrl partialBodyFrameController;	// Partial frame controller
	ModelCollection models[2];				// Super and small models
	FrameCtrl headFrameController;			// Head frame controller
	PlayerCap cap;							// Player cap (not attached to body/head)
	PlayerShell shell;						// Player shell
	NodeTransforms nodeTransforms;			// Node transforms of certain bones
	fx32 bodyAnmBlendRatio;					// Body animation blend ratio (between 0.0 and 1.0)
	fx32 bodyAnmBlendStep;					// Body animation step (increments the ratio per step)
	u32 activeAnimationIndex;				// Active body animation index (into bodyAnimations)
	u32 animationNodeDisableIndex;			// Node index determining partial animation boundaries: 0->(ANDI-1)=disables partial nodes; ANDI->(node count-1)=disables body nodes
	u32 partialBodyActive;					// 1 if partial animation is active, else 0
	u8 playerID;							// Player ID
	ModelState modelState;					// Model state
	HeadState headState;					// Head state
	Flags flags;							// Render flags

};
NTR_SIZE_GUARD(PlayerModel, 0x3C4);

NTR_CREATE_BITMASK_ENUM(PlayerModel::Flags);
