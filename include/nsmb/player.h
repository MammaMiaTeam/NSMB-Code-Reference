#ifndef NSMB_PLAYER_H_
#define NSMB_PLAYER_H_

#include "nitro_if.h"
#include "nsmb/actor.h"



struct PlayerCapAnimation {

	u32 marioAnimID;
	u32 marioSmallAnimID;
	u32 luigiAnimID;
	u32 luigiSmallAnimID;
	u32 frameCtrlType;
	fx32 frameCtrlSpeed;
	u32 frameCtrlStart;

};




struct PlayerHeadAnimation {

	u32 animID;
	FrameCtrl::Type type;
	fx32 speed;
	u16 startFrame;

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
	static bool loadFiles();

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
	static bool loadFiles();

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
	void setBodyAnimation(void* anmResource, u32 blendSteps, FrameCtrl::Type type, fx32 speed, u16 startFrame);

	//0212ce00
	void switchBodyAnimations(s8 srcIndex, s8 destIndex);

	//0212cd64
	void setHeadAnimation(void* anmResource, FrameCtrl::Type type, fx32 speed, u16 startFrame);

	//0212ccf0
	void update();

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


class PendulumBase;

class PendulumController {
public:

	Player* owner;

	PendulumController* unk4;
	PendulumBase* unk8;
	PendulumBase* unkC;

	u32 unk10;
	u32 unk14;
	u8 unk18;
	u8 unk19;
	u8 unk1A;
	u8 unk1B;

};

class SpinState {
public:

	Vec3 position;
	int offset;
	int sideVelocity;
	u16 rotationTimer;
	u16 unk1E;
	bool spinning;
	bool enable; // maybe?
	u8 direction;

	// 02
	SpinState();

	// D0:
	// D1:
	virtual ~SpinState();

};

class MixColor {

	using rgb_t = struct { u16 r, g, b; };

public:

	rgb_t color;
	rgb_t target;
	rgb_t difference;

	//struct {
	//	u16 r, g, b;
	//} color, target, difference; 

	// 
	MixColor();

	// D0:
	// D1:
	virtual ~MixColor();
};

class Door {
};

struct PlayerPhysics {
	fx32 scale;
	fx32 walkingMaxSpeed;
	fx32 unk8;
	fx32 runningMaxSpeed;
	fx32 starRunningMaxSpeed;
	fx32 swimmingMaxSpeed;
	fx32 unk18;
	fx32 walkingUnderwaterMaxSpeed;
	fx32 jumpVelocity;
	fx32 unk24;
	fx32 quicksandJumpVelocity;
	fx32 quicksandSubmergeJumpdVelocity;
	fx32 unk30;
	fx32 unk34;
	fx32 width;
	fx32 height;
};

//fx32 playerPosX[2];
//fx32 playerPosY[2];
//fx32 cameraPosX[2];
//fx32 cameraPosY[2];
//
//static bool fun_0200adf8(Vec3& pos, PlayerRect& rect, int playerNo) {
//	if ((pos.x + rect.x + rect.halfWidth) - playerPosX[playerNo] > cameraPosX[playerNo] + rect.halfWidth * 2)
//		return true;
//
//	if ((-(pos.y + rect.y) + rect.halfHeight) + playerPosY[playerNo] > cameraPosY[playerNo] + rect.halfHeight * 2)
//		return true;
//
//	return false;
//}

class Class212f724 {
public:

	Vec3 unk0;

	// 0212b1a8
	Class212f724();

	// D0: 0212b160
	// D1: 0212b18c
	virtual ~Class212f724();

};

class ProgressBarObject {
public:

	StageActor* owner;
	void* progressPath; // LevelPath*

	s32 unk8; // prev distance
	u32 unkC;
	u32 unk10;
	u32 unk14;

	u8 unk18;
	u8 unk19;
	u8 viewID;
	u8 unk1B;

	u32 unk1C;

};

class PlayerBase : public StageActor {
public:

	struct Powerup {
		enum : u8 {
			Small,
			Super,
			Fire,
			Mega,
			Mini,
			Shell,

			Max
		};
	};

	PlayerModel model;

	StageActor* heldActor;
	MtxFx43 unk68C;
	PlayerPhysics* physics;
	FxRect modelSize;

	SpinState spinState;
	MixColor specular;
	MixColor ambient;
	Vec3 unk724;
	Vec3 unk734;
	Vec3 unk744;

	u32 unk754;
	u32 unk758;
	u32 unk75C;
	u32 unk760;
	u32 unk764;
	u32 unk768;

	u32 animID;

	u32 jumpKeysTimer;
	u32 unk774;

	union {
		u32 all;
		struct {
			u32 action1				: 1;	// 0x00000001 
			u32 action2				: 1;	// 0x00000002 
			u32 wallSlide			: 1;	// 0x00000004 set when sliding on a wall
			u32 action8				: 1;	// 0x00000008 
			u32 action10			: 1;	// 0x00000010 
			u32 wallJump			: 1;	// 0x00000020 set when wall-jumping
			u32 wallClip			: 1;	// 0x00000040 set when clipping with a solid object
			u32 throwItem			: 1;	// 0x00000080 set when throwing an item
			u32 action100			: 1;	// 0x00000100
			u32 action200			: 1;	// 0x00000200
			u32 action400			: 1;	// 0x00000400
			u32 action800			: 1;	// 0x00000800
			u32 action1000			: 1;	// 0x00001000
			u32 flagpoleGrab		: 1;	// 0x00002000 set when grabbing the flagpole
			u32 flagpoleSlide		: 1;	// 0x00004000 set when sliding on the flagpole
			u32 flagpoleEnd			: 1;	// 0x00008000 set when jumping off the flagpole
			u32 action10000			: 1;	// 0x00010000
			u32 action20000			: 1;	// 0x00020000
			u32 action40000			: 1;	// 0x00040000
			u32 action80000			: 1;	// 0x00080000
			u32 noGround			: 1;	// 0x00100000 set when not touching a ground
			u32 action200000		: 1;	// 0x00200000
			u32 inShell				: 1;	// 0x00400000 set when hidden in the shell
			u32 groundPoundFall		: 1;	// 0x00800000 set when falling from a ground pound
			u32 action1000000		: 1;	// 0x01000000
			u32 action2000000		: 1;	// 0x02000000
			u32 action4000000		: 1;	// 0x04000000
			u32 action8000000		: 1;	// 0x08000000
			u32 cutsceneFreeze		: 1;	// 0x10000000 set when frozen during boss cutscenes
			u32 action20000000		: 1;	// 0x20000000
			u32 action40000000		: 1;	// 0x40000000
			u32 spinning			: 1;	// 0x80000000 set when spinning
		};
	} action;

	union {
		u32 all;
		struct {
			u32 holdingItem			: 1;	// 0x00000001 set when holding an item (shell/trampoline/etc)
			u32 subAction2			: 1;	// 0x00000002 set when on a rope/in a pipe/hit by a falling snow object
			u32 pipeCannon			: 1;	// 0x00000004 set when launching from a pipe cannon
			u32 inEntrance			: 1;	// 0x00000008 set when using an entrance/warp
			u32 sliding				: 1;	// 0x00000010 
			u32 subAction20			: 1;	// 0x00000020 
			u32 airborne			: 1;	// 0x00000040 set when in air
			u32 releaseKeys			: 1;	// 0x00000080 set when standing on a ground
			u32 subAction100		: 1;	// 0x00000100 
			u32 subAction200		: 1;	// 0x00000200 
			u32 subAction400		: 1;	// 0x00000400 set when hit by a falling snow object/on a vine/rope
			u32 running				: 1;	// 0x00000800 set when on rope/in pipe/walljumping/running
			u32 disableCap			: 1;	// 0x00001000 set when the cap shouldn't be rendered
			u32 drillSpin			: 1;	// 0x00002000 set when performing drill spin
			u32 onSpinBlock			: 1;	// 0x00004000 set when standing on a spin block
			u32 subAction8000		: 1;	// 0x00008000 
			u32 subAction10000		: 1;	// 0x00010000 
			u32 subAction20000		: 1;	// 0x00020000 set when groundpounding/climbing/in pipe/walljumping/hit by a falling snow object/on a vine/rope/pole
			u32 subAction40000		: 1;	// 0x00040000 set when climbing vine/pole (not a swinging rope/vine)/in pipe (no horizontal movement)
			u32 subAction80000		: 1;	// 0x00080000 
			u32 onPipe				: 1;	// 0x00100000 set when standing on a pipe (maybe enabled near all valid pipes or even all valid entrances?)
			u32 inPipe				: 1;	// 0x00200000 set when in pipe (maybe other entrances?)
			u32 subAction400000		: 1;	// 0x00400000 
			u32 invincible			: 1;	// 0x00800000 set when invincible
			u32 subAction1000000	: 1;	// 0x01000000 set when hit by a falling snow object/on a pole (no horizontal movement)
			u32 subAction2000000	: 1;	// 0x02000000 set when shooting from a pipe cannon (1)
			u32 subAction4000000	: 1;	// 0x04000000 
			u32 subAction8000000	: 1;	// 0x08000000 
			u32 subAction10000000	: 1;	// 0x10000000 
			u32 subAction20000000	: 1;	// 0x20000000 set when shooting from a pipe cannon (2)
			u32 megaJump			: 1;	// 0x40000000 set when doing a mega mushroom jump
			u32 subAction80000000	: 1;	// 0x80000000 
		};
	} subAction;

	union {
		u32 all;
		struct {
			u32 entranceOut				: 1;	// 0x00000001 set when leaving an entrance
			u32 notShooting				: 1;	// 0x00000002 set when not shooting a fireball (weird state lul)
			u32 lowHitbox				: 1;	// 0x00000004 set when the hitbox height should be reduced (crouching/in shell/groundpounding/spinning)
			u32 physicsAction8			: 1;	// 0x00000008
			u32 physicsAction10			: 1;	// 0x00000010
			u32 starman					: 1;	// 0x00000020 set when star mode is enabled
			u32 physicsAction40			: 1;	// 0x00000040
			u32 physicsAction80			: 1;	// 0x00000080 set when idle/groundpounding/spin drilling
			u32 physicsAction100		: 1;	// 0x00000100
			u32 physicsAction200		: 1;	// 0x00000200 (old tallJump)
			u32 physicsAction400		: 1;	// 0x00000400 
			u32 physicsAction800		: 1;	// 0x00000800 set when hitting a ceiling/falling (ceiling + fall phase? as a leftover from sm64ds when doing a jump dive on a wall?), also when jumping from a moving rope/pole
			u32 physicsAction1000		: 1;	// 0x00001000 
			u32 tallJump				: 1;	// 0x00002000 set when the jump height should be increased (jumping out of water)
			u32 physicsAction4000		: 1;	// 0x00004000 
			u32 physicsAction8000		: 1;	// 0x00008000 
			u32 physicsAction10000		: 1;	// 0x00010000 set when hit by a falling snow object
			u32 waterOut				: 1;	// 0x00020000 set when emerging from water
			u32 waterOutJump			: 1;	// 0x00040000 set when jumping out of water
			u32 waterIn					: 1;	// 0x00080000 set when submerging in water
			u32 physicsAction100000		: 1;	// 0x00100000 set when not jumping (????)
			u32 physicsAction200000		: 1;	// 0x00200000 
			u32 walkingOnWater			: 1;	// 0x00400000 set when walking on water (mini mushroom)
			u32 physicsAction8000000	: 1;	// 0x00800000 
			u32 groundPoundPreLand		: 1;	// 0x01000000 set before landing from a ground pound
			u32 doorIn					: 1;	// 0x02000000 set when entering a door		(door A)
			u32 bossDoorIn				: 1;	// 0x04000000 set when entering a boss door	(door B)
			u32 swimming				: 1;	// 0x08000000 set when swimming
			u32 physicsAction10000000	: 1;	// 0x10000000 
			u32 physicsAction20000000	: 1;	// 0x20000000 
			u32 physicsAction40000000	: 1;	// 0x40000000 
			u32 physicsAction80000000	: 1;	// 0x80000000 
		};
	} physicsState;

	u32 unk784; // 8 = disable lookAt

	union {
		u32 all;
		struct {
			u32 ground				: 1;	// 0x00000001 set when colliding with a ground
			u32 ceiling				: 1;	// 0x00000002 set when colliding with a ceiling
			u32 pushWall			: 1;	// 0x00000004 set when pushing torwards a wall
			u32 collision8			: 1;	// 0x00000008 set when colliding with some kind of left wall
			u32 collision10			: 1;	// 0x00000010 set when colliding with some kind of right wall
			u32 water				: 1;	// 0x00000020 set when colliding with water
			u32 climbableLeft		: 1;	// 0x00000040 set when colliding with a climbable tile on the left side
			u32 climbableRight		: 1;	// 0x00000080 set when colliding with a climbable tile on the right side
			u32 collision100		: 1;	// 0x00000100 set when colliding with a climbable tile on the left side (2)
			u32 collision200		: 1;	// 0x00000200 set when colliding with a climbable tile on the right side (2)
			u32 wallLeft			: 1;	// 0x00000400 set when colliding with a wall on the left side
			u32 wallRight			: 1;	// 0x00000800 set when colliding with a wall on the right side
			u32 collision1000		: 1;	// 0x00001000 set when colliding with some kind of ground
			u32 hoverTileGround		: 1;	// 0x00002000 set when hovering/colliding with a tile ground
			u32 collision4000		: 1;	// 0x00004000 
			u32 colliderGround		: 1;	// 0x00008000 set when colliding with a non-tile ground (platform/collider)
			u32 quicksandTop		: 1;	// 0x00010000 set when colliding with a quicksand surface
			u32 quicksand			: 1;	// 0x00020000 set when colliding with quicksand (submerged)
			u32 collision40000		: 1;	// 0x00040000 
			u32 collision80000		: 1;	// 0x00080000 
			u32 collision100000		: 1;	// 0x00100000 
			u32 collision200000		: 1;	// 0x00200000 
			u32 liquid				: 1;	// 0x00400000 set when colliding with a liquid (submerged)
			u32 tightrope			: 1;	// 0x00800000 set when colliding with a tightrope
			u32 collision1000000	: 1;	// 0x01000000 
			u32 collision2000000	: 1;	// 0x02000000 
			u32 collision4000000	: 1;	// 0x04000000 
			u32 predictGround		: 1;	// 0x08000000 set a few frames before touching ground
			u32 collision10000000	: 1;	// 0x10000000 
			u32 collision20000000	: 1;	// 0x20000000 
			u32 collision40000000	: 1;	// 0x40000000 
			u32 collision80000000	: 1;	// 0x80000000 
		};
	} collision, lastCollision;

	u32 envState; // idk, star related
	u32 lastEnvState;
	u32 unk798;

	u16 unk79C;
	u8 unk79E;
	u8 unk79F;

	u16 keysHeld;
	u16 keysPressed;

	u32 unk7A4;

	u8 unk7A8;
	u8 unk7A9;
	u8 characterID;
	u8 powerupRuntime;		// the last powerup state before a new update cycle

	u8 powerupCurrent;		// the powerup state changed during an update cycle
	u8 powerupStart;		// the powerup state set when spawning the player
	u8 unk7AE;
	u8 unk7AF;

	u8 unk7B0;
	u8 unk7B1;
	u8 unk7B2;
	u8 unk7B3;

	u8 playerNo;
	u8 visibleFlag;
	u8 unk7B6;
	u8 scoreComboGfx;

	u8 scoreCombo;
	u8 scoreCombo2;
	u8 unk7BA;
	u8 unk7BB;

	u8 scoreComboSfx;
	u8 unk7BD;
	u8 unk7BE;
	u8 unk7BF; // "tripleJumpRelated2"

	u8 unk7C0;
	u8 unk7C1; // "timer2"
	u8 unk7C2;
	u8 unk7C3;

	// 0212c950
	void readKeys();

	// 0212c93c
	void releaseKeys();

	// 0212c91c
	void releaseHorizontalKeys();

	// 0212c90c
	u16 getDirectionalKeysHeld();

	// 0212c8fc
	u16 getDirectionalKeysPressed();

	// 0212c8ec
	u16 getUpKeyHeld();

	// 0212c8dc
	u16 getDownKeyHeld();

	// 0212c8cc
	u16 getLeftKeyHeld();

	// 0212c8bc
	u16 getRightKeyHeld();

	// 0212c8ac
	u16 getDownKeyPressed();

	// 0212c880
	u16 getRKeyPressed();

	// 0212c854
	u16 getRKeyHeld();

	// 0212c828
	u16 getJumpKeysPressed();

	// 0212c7fc
	u16 getJumpKeysHeld();

	// 0212c7d0
	u16 getRunKeysPressed();

	// 0212c7a4
	u16 getRunKeysHeld();

	// 0212c78c
	u16 getUpKeyHeldEx();

	// 0212c774
	u16 getDownKeyHeldEx();

	// 0212c768
	u16 getRunKeyHeld();

	// 0212c75c
	u16 getRunKeyPressed();

	// 0212c720
	u16 getActionKeysHeld();

	// 0212c6e4
	u16 getActionKeysPressed();

	// 0212c6b0
	u16 getCarryKeysHeld();

	// 0212c67c
	u16 getCarryKeysPressed();

	// 0212c648
	u16 getFireKeyPressed();

	// 0212c63c
	u16 getJumpKeyPressed();

	// 0212c630
	u16 getJumpKeyHeld();

	// 0212c61c
	u16 getHorizontalKeysHeld();

	// 0212c610
	u16 getCrouchKeyHeld();

	// 0212c5ec
	u16 getCrouchKeyPressedEx();

	// 0212c5c8
	u16 getCrouchKeyHeldEx();

	// 0212c5bc
	u16 downKeyHeld();

	// 0212c5b0
	u16 upKeyHeld();

	// 0212c5a4
	u16 rightKeyHeld();

	// 0212c598
	u16 leftKeyHeld();

	// 0212c56c
	u16 getGroundPoundCancelKeyHeldEx();

	// 0212c52c
	u16 getKeysPressed();

	// 0212c4ec
	BOOL getJumpPressedRingBuffer();


	// 0212c424
	PlayerBase();

	// D0: 0212c34c
	// D1: 0212c3bc
	// D2: 0212c2e4
	virtual ~PlayerBase();


	// 0212c27c
	s16 getRotationFromDirection(u8 direction);

	// 0212c200
	void saveCurrentPowerup();

	// 0212c1b8
	//void checkIfSecondPlayerExists(); 




};

class Player : public PlayerBase {

public:

	typedef s32(Player::*StateFunction)();

	Door* door;
	Door* doorBoss;
	s32* unk7CC;
	s32* unk7D0;

	LineSensorH topSensor;
	LineSensorH botSensor;
	LineSensorV sideSensor;
	LineSensorH unk804;

	ActiveCollider slidingCollider;
	PendulumController pendulum;
	Class212f724 unk8E0;
	ProgressBarObject progressBarObject;

	Vec3s unk914;
	Vec3s unk920;

	Vec3 unk92C;
	Vec3 unk93C;
	Vec3 unk94C;

	Vec2 unk95C;
	Vec2 unk968;
	Vec2 unk974;

	StateFunction moveState; // TODO: better name
	StateFunction unk988;
	StateFunction deathState; // TODO: better name
	StateFunction unk998; // TODO: better name
	StateFunction unk9A0; // TODO: better name

	u32 megaMushroomStars1EmitterID;
	u32 megaMushroomStars2EmitterID;

	u32 zLayer;
	u32 headAnimID;
	u32 unk9B8;
	u32 unk9BC;
	u32 lastAnimID; // last animation id?

	u32 unk9C4; // platform bitfield?
	u32 unk9C8[6];

	u32 unk9E0[8]; // various emitter IDs
	u32 unkA00[41]; // more emitter IDs

	u32 unkAA4[7];

	u32 unkAC0[3];
	u32 unkACC[3];

	fx32 bodyAnimSpeed;
	u32 unkADC;
	fx32 modelScale;
	u32 unkAE4[4];
	u32 unkAF4[7];
	u32 unkB10; // collider speed X
	u32 unkB14; // chunnk position X
	u32 unkB18[14];

	u16 unkB50;
	u16 unkB52; // jump keys pressed
	u16 unkB54; // rope related
	u16 unkB56; // padding?

	u32 unkB58[4];
	u16 unkB68;
	u16 unkB6A;
	u32 unkB6C;
	u16 unkB70;
	u16 unkB72;
	u32 unkB74;
	u16 unkB78; // "timer"
	u16 modelAngle; // "spriteCollisionAngle"
	u16 unkB7C[2];
	u16 unkB80; // "groundPoundRotateTimer"
	u16 unkB82[9];
	u32 unkB94;

	s16 lookAtRotation;

	u16 unkB9A;
	u8 unkB9C;
	u8 modelID;
	u8 unkB9E; // "moveStateMode"
	u8 unkB9F; // "notInPipeCannon"

	u8 consecutiveJumps;
	u8 jumpVariation;

	u8 unkBA2;
	u8 unkBA3;
	u16 unkBA4;
	u8 unkBA6;
	u8 unkBA7;
	u8 unkBA8;
	u8 unkBA9;
	u8 unkBAA;
	u8 unkBAB;
	u8 unkBAC;
	u8 unkBAD;
	u8 unkBAE;

	u8 currentModel;

	u8 unkBB0[6];

	u8 textureID;

	u8 runKeyTimer; // goes from 10 to 0
	u8 unkBB8; // "outOfPipeTimer" goes from 8 to 0, once the player is fully out
	u8 unkBB9;
	u8 carryKeyTimer; // goes from 8 to 0

	u8 unkBBB; // "walkRight"
	u8 unkBBC; // "walkRight"
	u8 unkBBD[6];
	u8 unkBC3; // "slowLedgeJumpMaybe"
	u8 unkBC4; // "groundpoundRelated"
	u8 unkBC5; // "walkLeftCounter"
	u8 unkBC6; // "walkRightCounter"
	u8 unkBC7;
	u8 groundPoundTimer; // goes from 0 to 3
	bool groundPoundFlag;
	u8 unkBCA;
	bool lookAtInProgress; // set to true when "LookingAtTarget" is enabled and the player's head rotation is being calculated




	//
	Player();

	//D0:
	//D1:
	virtual ~Player();
};




#endif // !NSMB_PLAYER_H_
