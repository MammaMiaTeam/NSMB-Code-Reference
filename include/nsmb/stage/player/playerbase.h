#pragma once
#include "nsmb/player/model.h"
#include "nsmb/stage/actor.h"
#include "nsmb/graphics/util/blendcolor.h"


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


enum class PowerupState : u8 {
	Small,
	Super,
	Fire,
	Mega,
	Mini,
	Shell,

	Unk6,	// Mega related???
	Unk7,	// ???????????????
};


class PlayerBase : public StageActor
{
public:

	PlayerModel model;

	StageActor* linkedActor;
	MtxFx43 unk68C;
	PlayerPhysics* physics;
	FxRect modelSize;

	SpinState spinState;
	BlendColor diffuse;
	BlendColor ambient;
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
			u32 throwActor			: 1;	// 0x00000080 set when throwing an actor
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
			u32 isGroundpounding	: 1;	// 0x00800000
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
			u32 holdingActor		: 1;	// 0x00000001 set when holding an actor (shell/trampoline/etc)
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
	u32 invincibleMusicID;

	u16 unk79C;
	u8 unk79E;
	u8 unk79F;

	u16 keysHeld;
	u16 keysPressed;

	u32 unk7A4;

	u8 unk7A8;
	u8 unk7A9;
	u8 characterID;
	PowerupState runtimePowerup;

	PowerupState currentPowerup;
	PowerupState previousPowerup;
	u8 unk7AE;
	u8 unk7AF;

	u8 unk7B0;
	u8 unk7B1;
	u8 unk7B2;
	u8 unk7B3;

	u8 playerID;
	u8 visibleFlag;
	u8 unk7B6;
	u8 scoreComboType;

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

	// 0212B26C
	void linkActor(StageActor& actor); // link actor

	// 0212BDE0
	void unlinkActorIfLinked(StageActor& actor); // unlink given actor if already linked

	// 0212c1b8
	//void checkIfSecondPlayerExists(); 

};
