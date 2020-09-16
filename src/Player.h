#ifndef NSMB_PLAYER_INCLUDED
#define NSMB_PLAYER_INCLUDED

#include "Actor.h"



struct PlayerCapAnimation {

	u32 marioAnimID;
	u32 marioSmallAnimID;
	u32 luigiAnimID;
	u32 luigiSmallAnimID;
	u32 frameCtrlType;
	fx32 frameCtrlSpeed;
	u32 frameCtrlStart;

};



//vtable 0212f8b8
class PlayerCap
{
public:

	Model model;
	Animation animation;
	FrameCtrl frameController;
	u8 playerID;
	u8 animType;

	//0212f8e0
	static u16 texPaletteBase[2];

	//0212f8e4
	static u32 texImageParam[2];

	//0212e5a4
	static u32 modelFileIDs[2];

	//0212e5b4
	static PlayerCapAnimation capAnimations[9];

	//0212e5ac
	static u16 texPaletteOffset[4];

	//0212df20
	PlayerCap();

	//D0:0212dec0
	//D1:0212def4
	virtual ~PlayerCap();

	//0212de44
	bool create(u8 playerID);

	//0212dce4
	bool render(bool skip, fx32 frame, s8 texPalette, GXRgb diffuse, GXRgb ambient, bool toon);

	//0212dc68
	void setAnimation(u8 animType, bool smallPlayer);

	//0212df4c
	static bool loadTextureSettings();

};



//vtable 0212f8c8
class PlayerShell
{
public:

	Model model;

	//0212f8ec
	static u16 texPaletteBase;

	//0212f8f0
	static u32 texImageParam;

	//0212e180
	PlayerShell();

	//D0:0212e130
	//D1:0212e15c
	virtual ~PlayerShell();

	//0212e0f8
	bool create();

	//0212e020
	bool render(bool skip, s8 texPalette, GXRgb diffuse, GXRgb ambient, bool toon);

	//0212e1a4
	static bool loadTextureSettings();

};



class Player;


//vtable 0212f868
class PlayerModel
{
public:

	void* currentBodyAnmResource;			//Current body animation resource
	void* lastBodyAnmResource;				//Last body animation resource
	void* partialBodyAnmResource;			//Partial body animation resource
	NNSG3dAnmObj* bodyAnimations[2];		//Blending body animations
	NNSG3dAnmObj* partialBodyAnimation;		//Partial body animation
	u16* bodyAnimationMapData;				//Initial body map data (bone -> model node)
	void* headAnmResource;					//Head animation resource
	NNSG3dAnmObj* headAnimation;			//Head animation
	FrameCtrl bodyFrameController;			//Body frame controller
	FrameCtrl partialBodyFrameController;	//Partial frame controller
	Model* bodyModel;						//Body model
	Model* headModels[4];					//Head models
	Model* smallBodyModel;					//Small body model
	Model* smallHeadModels[4];				//Small head models
	FrameCtrl headFrameController;			//Head frame controller
	PlayerCap cap;							//Player cap (not attached to body/head)
	PlayerShell shell;						//Player shell
	MtxFx43 nodeTransforms[10];				//Node transforms of certain bones
	fx32 bodyAnmBlendRatio;					//Body animation blend ratio (between 0.0 and 1.0)
	fx32 bodyAnmBlendStep;					//Body animation step (increments the ratio per step)
	u32 activeAnimationIndex;				//Active body animation index (into bodyAnimations)
	u32 animationNodeDisableIndex;			//Node index determining partial animation boundaries: 0->(ANDI-1)=disables partial nodes; ANDI->(node count-1)=disables body nodes
	u32 partialBodyActive;					//1 if partial animation is active, else 0
	u8 playerID;							//Player ID
	u8 modelState;							//Model state: 0=normal,1=small
	u8 headState;							//Head state: 0=cap,1=nocap,2=dead,3=dead+nocap
	u8 flags;								/* Flags:
												0x1: Unused
												0x2: Render separate cap
												0x4: Render nocap head variant
												0x8: Render dead head variant
												0x10: Render shell
											*/

	//0212e524
	static u32 bodyModelIDs[2];

	//0212e53c
	static u32 bodyModelFileIDs[2];

	//0212e584
	static u32 headModelFileIDs[2][4];

	//0212e574
	static u32 headModelIDs[2][2];

	//0212e228
	static u32 headPatternFileIDs[2];

	//0212e52c
	static u16 bodyTexPaletteOffset[4];

	//0212e534
	static u16 headTexPaletteOffset[4];//For head + cap

	//0212f850
	static u32 deadBodyTexImageParamIndices[2][2];

	//0212f870
	static u32 deadHeadTexImageParamIndices[2][2][4];



	//0212dbd8
	PlayerModel();

	//D0:0212db78
	//D1:0212dbac
	virtual ~PlayerModel();

	//0212db00
	bool create(u8 playerID, u32 animationFileID);

	//0212d8b0
	bool loadBody(u32 animationFileID);

	//0212d710
	bool loadHead();

	//0212d6c0
	void setBodyModelCallback(NNSG3dSbcCallBackFunc* callback);

	//0212d6a0
	void setPlayerPointer(Player* player);

	//0212d154
	void render(MtxFx43* bodyModelMatrix, Vec3* scale, s8 texPalette, bool skip, GXRgb diffuse, GXRgb ambient, bool toon);

	//0212d140
	void enableBodyToon();

	//0212d12c
	void enableHeadToon();

	//0212d118
	void disableBodyToon();

	//0212d104
	void disableHeadToon();

	//0212cfe4
	void setDeathTexImageParams();

	//0212ce50
	void setBodyAnimation(void* anmResource, u32 steps, FrameCtrl::Type type, fx32 speed, u16 startFrame);

	//0212ce00
	void switchBodyAnimations(s8 srcIndex, s8 destIndex);

	//0212cd64
	void setHeadAnimation(void* anmResource, FrameCtrl::Type type, fx32 speed, u16 startFrame);

	//0212ccf0
	void updateAnimations();

	//0212cce0
	bool animationFinished();

	//0212ccd4
	void setCurrentAnimationFrame(u16 frame);

	//0212ccc4
	u16 getCurrentAnimationFrame();

	//0212ccbc
	fx32 getRawAnimationFrame();

	//0212ccac
	u16 getAnimationFrameCount();

	//0212cca4
	void setAnimationSpeed(fx32 speed);

	//0212cc9c
	fx32 getAnimationSpeed();

	//0212cc8c
	bool animationPassing(u16 targetFrame);

	//0212cbe8
	void initPartialAnimation(void* anmResource, FrameCtrl::Type type, fx32 speed, u16 startFrame);

	//0212cb28
	void startPartialAnimation(u32 nodeDisableIndex);

	//0212ca98
	void endPartialAnimation();

	//0212ca78
	void updatePartialAnimation();

	//0212c98c
	void saveNodeTransforms();


};



#endif  // NSMB_PLAYER_INCLUDED
