#pragma once
#include "misc.h"
#include "nsmb/player/model.h"
#include "nsmb/stage/actor.h"
#include "nsmb/graphics/util/blendcolor.h"


enum class PlayerStompType : u32
{

	None,
	Stomp,
	MiniStomp

};

enum class PlayerShellState {

	None,
	Idle,
	Sliding

};

enum class PlayerSpawnType : u8
{

	Normal,
	PipeUp,
	PipeDown,
	PipeLeft,
	PipeRight,
	Door,
	Falling,
	GroundPounding,
	Sliding,
	Swimming,
	TransitNormal,			// Same as normal
	TransitDoor,			// Same as normal, as this refers to the spawn type and not to a transition
	MvsLPipe,
	Jumping,
	Unknown14,
	Unknown15,
	Vine,
	MiniPipeUp,
	MiniPipeDown,
	MiniPipeLeft,
	MiniPipeRight,

};

enum class PlayerDamageType {

	Hit,
	Bumped,
	Lava,
	Electrocute,
	Poison,
	Death,
	Pit

};

enum class PlayerConstrainedMovement : u8
{

	None,
	Pushing,
	Pole,
	Shocked = 4,
	Damaged,
	Tornado,
	Cannon

};

enum class PlayerHeight {

	Mini,
	Small,
	Super,
	Mega

};

enum class PowerupState : s8
{

	Small,
	Super,
	Fire,
	Mega,
	Mini,
	Shell,

	Unk6,	// Mega related???
	Unk7,	// ???????????????

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

struct PlayerActionFlag : BitFlag<u32>
{

	u32 damaged				: 1;	// 0x00000001
	u32 starmanJump			: 1;	// 0x00000002
	u32 wallSlide			: 1;	// 0x00000004 set when sliding on a wall
	u32 flag8				: 1;	// 0x00000008
	u32 flag10				: 1;	// 0x00000010
	u32 wallJump			: 1;	// 0x00000020 set when wall-jumping
	u32 clipped				: 1;	// 0x00000040 set when clipping with a solid object
	u32 releasedActor		: 1;	// 0x00000080 set indefinitely after releasing a carried actor
	u32 lockCarriedActor	: 1;	// 0x00000100
	u32 flag200				: 1;	// 0x00000200
	u32 flag400				: 1;	// 0x00000400
	u32 flag800				: 1;	// 0x00000800
	u32 flag1000			: 1;	// 0x00001000
	u32 flagpoleGrab		: 1;	// 0x00002000 triggers the flagpole transition state
	u32 flagpoleSlide		: 1;	// 0x00004000 
	u32 flagpoleEnd			: 1;	// 0x00008000 set by the stage/flagpole when the flag reaches the bottom of the pole
	u32 climbing			: 1;	// 0x00010000
	u32 pushLeft			: 1;	// 0x00020000
	u32 pushRight			: 1;	// 0x00040000
	u32 bouncyBricksJump	: 1;	// 0x00080000
	u32 noGround			: 1;	// 0x00100000 set when not touching a ground
	u32 flag200000			: 1;	// 0x00200000
	u32 inShell				: 1;	// 0x00400000 set when hidden in the shell
	u32 groundpounding		: 1;	// 0x00800000
	u32 bowserJrBeaten		: 1;	// 0x01000000 triggers the bowserJrVictory transition state
	u32 flag2000000			: 1;	// 0x02000000
	u32 flag4000000			: 1;	// 0x04000000
	u32 flag8000000			: 1;	// 0x08000000
	u32 cutsceneFreeze		: 1;	// 0x10000000 set when frozen during boss cutscenes
	u32 flag20000000		: 1;	// 0x20000000
	u32 flag40000000		: 1;	// 0x40000000
	u32 spinning			: 1;	// 0x80000000 set when spinning

};
NTR_SIZE_GUARD(PlayerActionFlag, 4);

struct PlayerSubActionFlag : BitFlag<u32>
{

	u32 carrying				: 1;	// 0x00000001 set when carrying an actor (shell/trampoline/etc)
	u32 lockHorizontalMovement	: 1;	// 0x00000002 set when on a rope/in a pipe/hit by a falling snow object
	u32 pipeCannon				: 1;	// 0x00000004 set when launching from a pipe cannon
	u32 invisible				: 1;	// 0x00000008 set when using an entrance/warp/dying in a pit
	u32 sliding					: 1;	// 0x00000010
	u32 slideJump				: 1;	// 0x00000020
	u32 airborne				: 1;	// 0x00000040 set when in air
	u32 releaseKeys				: 1;	// 0x00000080 set when standing on a ground
	u32 turntable				: 1;	// 0x00000100
	u32 flag200					: 1;	// 0x00000200
	u32 fixDirection			: 1;	// 0x00000400 set when hit by a falling snow object/on a vine/rope/pipe cannon, cannot switch direction when walking/running
	u32 running					: 1;	// 0x00000800 set when on rope/in pipe/walljumping/running
	u32 disableCap				: 1;	// 0x00001000 set when the cap shouldn't be rendered
	u32 drillSpin				: 1;	// 0x00002000 set when performing drill spin
	u32 spinBlock				: 1;	// 0x00004000 set when standing on a spin block
	u32 flag8000				: 1;	// 0x00008000
	u32 flag10000				: 1;	// 0x00010000
	u32 groundPounding			: 1;	// 0x00020000 set when groundpounding/climbing/in pipe/walljumping/hit by a falling snow object/on a vine/rope/pole, jump height is reduced
	u32 flag40000				: 1;	// 0x00040000 set when climbing vine/pole (not a swinging rope/vine)/in pipe (no horizontal movement)
	u32 flag80000				: 1;	// 0x00080000
	u32 onPipeCannon			: 1;	// 0x00100000 set when standing on a pipe cannon
	u32 usingPipeCannon			: 1;	// 0x00200000 set when using a pipe cannon
	u32 flag400000				: 1;	// 0x00400000
	u32 invincible				: 1;	// 0x00800000 set when invincible
	u32 snowStuck				: 1;	// 0x01000000 set when hit by a falling snow object/on a pole (no horizontal movement)
	u32 flag2000000				: 1;	// 0x02000000 set when shooting from a pipe cannon (1)
	u32 bumped					: 1;	// 0x04000000
	u32 shockedLightningItem	: 1;	// 0x08000000
	u32 flag10000000			: 1;	// 0x10000000
	u32 flag20000000			: 1;	// 0x20000000 set when shooting from a pipe cannon (2)
	u32 megaJump				: 1;	// 0x40000000 set when doing a mega mushroom jump
	u32 flag80000000			: 1;	// 0x80000000

};
NTR_SIZE_GUARD(PlayerSubActionFlag, 4);

struct PlayerPhysicsFlag : BitFlag<u32>
{

	u32 entranceOut					: 1;	// 0x00000001 set when leaving an entrance
	u32 notShooting					: 1;	// 0x00000002 set when not shooting a fireball
	u32 lowHitbox					: 1;	// 0x00000004 set when the hitbox height should be reduced (crouching/in shell/groundpounding/spinning)
	u32 hangLedge					: 1;	// 0x00000008
	u32 hangUnused					: 1;	// 0x00000010
	u32 starman						: 1;	// 0x00000020 set when star mode is enabled
	u32 flag40						: 1;	// 0x00000040
	u32 flag80						: 1;	// 0x00000080 set when idle/groundpounding/spin drilling
	u32 flag100						: 1;	// 0x00000100
	u32 paralyzed					: 1;	// 0x00000200 maybe
	u32 bumped						: 1;	// 0x00000400 maybe
	u32 hitCeiling					: 1;	// 0x00000800 set when hitting a ceiling/falling (ceiling + fall phase? as a leftover from sm64ds when doing a jump dive on a wall?), also when jumping from a moving rope/pole
	u32 flag1000					: 1;	// 0x00001000
	u32 tallJump					: 1;	// 0x00002000 set when the jump height should be increased (jumping out of water)
	u32 climbableActor				: 1;	// 0x00004000
	u32 climbing					: 1;	// 0x00008000
	u32 buried						: 1;	// 0x00010000 set when hit by a falling snow object
	u32 waterOut					: 1;	// 0x00020000 set when emerging from water
	u32 waterTallJump				: 1;	// 0x00040000 set when jumping out of water
	u32 waterIn						: 1;	// 0x00080000 set when submerging in water
	u32 invalidateHorizontalKeys	: 1;	// 0x00100000 set when not jumping (????)
	u32 lakituCloud					: 1;	// 0x00200000
	u32 walkingOnWater				: 1;	// 0x00400000 set when walking on water (mini mushroom)
	u32 bossDefeated				: 1;	// 0x00800000 triggers the bossVictory transition state
	u32 groundPoundPreLand			: 1;	// 0x01000000 set before landing from a ground pound
	u32 standardDoorTransit			: 1;	// 0x02000000 
	u32 bossDoorTransit				: 1;	// 0x04000000 
	u32 swimming					: 1;	// 0x08000000 set when swimming
	u32 slipping					: 1;	// 0x10000000 set when slipping on ice
	u32 flag20000000				: 1;	// 0x20000000
	u32 electrocuted				: 1;	// 0x40000000 set when being electrocuted
	u32 flag80000000				: 1;	// 0x80000000

};
NTR_SIZE_GUARD(PlayerPhysicsFlag, 4);

struct PlayerTransitionFlag : BitFlag<u32>
{
	
	u32 finalBoss			: 1;	// 0x00000001
	u32 flag2				: 1;	// 0x00000002
	u32 flag4				: 1;	// 0x00000004
	u32 lookAtBoss			: 1;	// 0x00000008
	u32 flag10				: 1;	// 0x00000010
	u32 flag20				: 1;	// 0x00000020
	u32 megaShrink			: 1;	// 0x00000040
	u32 flag80				: 1;	// 0x00000080
	u32 flag100				: 1;	// 0x00000100
	u32 flag200				: 1;	// 0x00000200
	u32 flag400				: 1;	// 0x00000400
	u32 flag800				: 1;	// 0x00000800
	u32 flag1000			: 1;	// 0x00001000
	u32 flag2000			: 1;	// 0x00002000
	u32 flag4000			: 1;	// 0x00004000
	u32 flag8000			: 1;	// 0x00008000
	u32 flag10000			: 1;	// 0x00010000
	u32 flag20000			: 1;	// 0x00020000
	u32 flag40000			: 1;	// 0x00040000
	u32 flag80000			: 1;	// 0x00080000
	u32 flag100000			: 1;	// 0x00100000
	u32 flag200000			: 1;	// 0x00200000
	u32 flag400000			: 1;	// 0x00400000
	u32 flag800000			: 1;	// 0x00800000
	u32 flag1000000			: 1;	// 0x01000000
	u32 flag2000000			: 1;	// 0x02000000
	u32 flag4000000			: 1;	// 0x04000000
	u32 flag8000000			: 1;	// 0x08000000
	u32 flag10000000		: 1;	// 0x10000000
	u32 flag20000000		: 1;	// 0x20000000
	u32 flag40000000		: 1;	// 0x40000000
	u32 flag80000000		: 1;	// 0x80000000

};
NTR_SIZE_GUARD(PlayerTransitionFlag, 4);

struct PlayerCollisionFlag : BitFlag<u32>
{

	u32 ground					: 1;	// 0x00000001 set when colliding with a ground
	u32 ceiling					: 1;	// 0x00000002 set when colliding with a ceiling
	u32 pushWall				: 1;	// 0x00000004 set when pushing torwards a wall
	u32 fullWallLeft			: 1;	// 0x00000008 
	u32 fullWallRight			: 1;	// 0x00000010 
	u32 water					: 1;	// 0x00000020 set when colliding with water
	u32 climbableTopLeft		: 1;	// 0x00000040 
	u32 climbableTopRight		: 1;	// 0x00000080 
	u32 climbableBottomLeft		: 1;	// 0x00000100 
	u32 climbableBottomRight	: 1;	// 0x00000200 
	u32 wallLeft				: 1;	// 0x00000400 set when colliding with a wall on the left side
	u32 wallRight				: 1;	// 0x00000800 set when colliding with a wall on the right side
	u32 edgeGrab				: 1;	// 0x00001000 set when colliding with the edge of a ground tile
	u32 hoverTileGround			: 1;	// 0x00002000 set when hovering/colliding with a tile ground
	u32 slipperyGround			: 1;	// 0x00004000
	u32 colliderGround			: 1;	// 0x00008000 set when colliding with a non-tile ground (platform/collider)
	u32 quicksandTop			: 1;	// 0x00010000 set when colliding with a quicksand surface
	u32 quicksand				: 1;	// 0x00020000 set when colliding with quicksand (submerged)
	u32 rope					: 1;	// 0x00040000
	u32 flag80000				: 1;	// 0x00080000
	u32 collapsedStairs			: 1;	// 0x00100000
	u32 flag200000				: 1;	// 0x00200000 set when the ground modifier is set to 8
	u32 liquid					: 1;	// 0x00400000 set when colliding with a liquid (submerged)
	u32 tightrope				: 1;	// 0x00800000 set when colliding with a tightrope
	u32 ledge					: 1;	// 0x01000000
	u32 oneUpBrickHitAboveSuper	: 1;	// 0x02000000 set when groundpounding a one-up brick in a Super form (Super, Fire, Shell)
	u32 flag4000000				: 1;	// 0x04000000 set when the CollisionResult contains the value 0x20000000
	u32 predictGround			: 1;	// 0x08000000 set a few frames before touching ground
	u32 pole					: 1;	// 0x10000000
	u32 spikesLeft				: 1;	// 0x20000000
	u32 spikesRight				: 1;	// 0x40000000
	u32 flag80000000			: 1;	// 0x80000000 set when the CollisionResult contains the value 0x200000

};
NTR_SIZE_GUARD(PlayerCollisionFlag, 4);

struct PlayerEnvironmentFlag : BitFlag<u32>
{
	
	u32 slowGround			: 1;	// 0x00000001
	u32 sensorSubmerged		: 1;	// 0x00000002
	u32 activatedCeiling	: 1;	// 0x00000004
	u32 conveyorBeltLeft	: 1;	// 0x00000008
	u32 conveyorBeltRight	: 1;	// 0x00000010
	u32 snowyGround			: 1;	// 0x00000020
	u32 sandyGround			: 1;	// 0x00000040
	u32 flag80				: 1;	// 0x00000080 set when the ground modifier is set to 15
	u32 destroyedGround		: 1;	// 0x00000100
	u32 fullySubmerged		: 1;	// 0x00000200
	u32 climbableBottom		: 1;	// 0x00000400
	u32 climbableTop		: 1;	// 0x00000800
	u32 destroyedCeiling	: 1;	// 0x00001000
	u32 wrapLeft			: 1;	// 0x00002000
	u32 wrapRight			: 1;	// 0x00004000
	u32 flag8000			: 1;	// 0x00008000 unused
	u32 flag10000			: 1;	// 0x00010000 unused
	u32 flag20000			: 1;	// 0x00020000 unused
	u32 flag40000			: 1;	// 0x00040000 unused
	u32 flag80000			: 1;	// 0x00080000 unused
	u32 flag100000			: 1;	// 0x00100000 unused
	u32 flag200000			: 1;	// 0x00200000 unused
	u32 flag400000			: 1;	// 0x00400000 unused
	u32 flag800000			: 1;	// 0x00800000 unused
	u32 flag1000000			: 1;	// 0x01000000 unused
	u32 flag2000000			: 1;	// 0x02000000 unused
	u32 flag4000000			: 1;	// 0x04000000 unused
	u32 flag8000000			: 1;	// 0x08000000 unused
	u32 flag10000000		: 1;	// 0x10000000 unused
	u32 flag20000000		: 1;	// 0x20000000 unused
	u32 flag40000000		: 1;	// 0x40000000 unused
	u32 flag80000000		: 1;	// 0x80000000 unused

};
NTR_SIZE_GUARD(PlayerEnvironmentFlag, 4);


// vtable at 0212F72C (ov11)
class PlayerBase : public StageActor
{
public:

	void fetchKeys();
	void releaseKeys();
	void releaseHorizontalKeys();

	u16 getDirectionalKeysHeld() const;
	u16 getDirectionalKeysPressed() const;
	u16 getUpKeyHeld() const;
	u16 getDownKeyHeld() const;
	u16 getLeftKeyHeld() const;
	u16 getRightKeyHeld() const;
	u16 getDownKeyPressed() const;
	u16 getRKeyPressed() const;
	u16 getRKeyHeld() const;
	u16 getJumpKeysPressed() const;
	u16 getJumpKeysHeld() const;
	u16 getRunKeysPressed() const;
	u16 getRunKeysHeld() const;
	u16 getUpKeyHeldEx() const;
	u16 getDownKeyHeldEx() const;
	u16 getRunKeyHeld() const;
	u16 getRunKeyPressed() const;
	u16 getActionKeysHeld() const;
	u16 getActionKeysPressed() const;
	u16 getCarryKeysHeld() const;
	u16 getCarryKeysPressed() const;
	u16 getFireKeyPressed() const;
	u16 getJumpKeyPressed() const;
	u16 getJumpKeyHeld() const;
	u16 getHorizontalKeysHeld() const; // The result is right-shifted by 4 bits
	u16 getCrouchKeyHeld() const;
	u16 getCrouchKeyPressedEx() const;
	u16 getCrouchKeyHeldEx() const;
	u16 downKeyHeld() const;
	u16 upKeyHeld() const;
	u16 rightKeyHeld() const;
	u16 leftKeyHeld() const;
	u16 getGroundPoundCancelKeyHeldEx() const;
	u16 getKeysPressed() const;
	bool getBufferedJumpPressed() const;

	NTR_INLINE bool getBufferedJumpHeld() const {

		for (u32 i = 0; i < 4; i++) {
			if (jumpHeldRingBuffer[linkedPlayerID][i])
				return true;
		}

		return false;

	}

	PlayerBase();
	virtual ~PlayerBase();

	s16 getDirectionalRotation(u8 direction) const;

	void saveCurrentPowerup() const;

	void signalLocked();
	void signalUnlocked();
	void freezeStage();
	void unfreezeStage();

	virtual bool doJump(fx32 force, u16 duration, bool playSFX, bool noConsecutive, s8 variation);
	virtual bool doJumpEx(fx32 force, u16 duration, u8 lockHorizontalDuration, bool playSFX, bool noConsecutive, s8 variation);
	virtual bool doSpinJump(fx32 force);
	virtual bool doBounceWhirl();
	virtual bool doTornadoWhirl();

	virtual bool dealDamage(StageActor& actor, fx32 velocityX, fx32 velocityY, PlayerDamageType type);

	virtual bool tryCrouch();
	virtual bool tryBump(const Vec2& velocity);
	virtual bool tryPlayerBump(const Vec2& velocity);
	virtual bool doPlayerBump(const Vec2& velocity, bool groundPounded);
	virtual bool doBump(const Vec2& velocity);

	virtual bool carry(StageActor& actor);
	virtual bool hangMiniToCeiling(StageActor& actor);
	virtual bool dropMiniFromCeiling();
	virtual bool hangToCeiling(StageActor& actor);
	virtual bool dropFromCeiling();
	virtual bool waitInCannon(StageActor& cannon, const Vec3& position, s16 angleX, s16 angleY);
	virtual bool shootFromCannon(StageActor& cannon, fx32 curveForce, s16 curveAngle, s16 direction, bool32 worldCannon);
	virtual bool grabPendulum();

	virtual bool virt39(); // Empty
	virtual bool isNotClimbing();
	virtual bool trySlide();

	virtual void updateCollision(bool damagePlayer);
	virtual void updatePosition(const Vec3& position, s16 rotationY, u8 direction);

	virtual bool stomp();
	virtual bool tryEnterTransition();
	virtual bool leaveTransition();
	virtual void setPerspectiveTransform(fx32 scale, const Vec3s& rotation, const Vec3& position);
	virtual s32 virt48();
	virtual s32 doTurntableTransition();
	virtual void doVictoryTransition(u32 playerID);
	virtual void setVictoryTarget(fx32 x, fx32 y, fx32 z);
	virtual Vec3 getHandsPosition();
	virtual void doWarpZoneTransition();
	virtual void doDoorTransition(const Vec3& doorPosition);
	virtual void setSpinBlock(fx32 positionX, s16 angle);

	virtual bool getDoorTrigger();
	virtual bool virt57(); // Empty
	virtual bool virt58(); // Empty
	virtual bool getCannonTrigger();
	virtual void enterCannon(const Vec3& cannonPosition);
	virtual void virt61(const Vec3& position);
	virtual void enterPipeDown(const Vec3& pipePosition);

	virtual bool doLightningShock();
	virtual bool isControllable(); // Returns true if the player is not damaged/paralyzed or in a transition
	virtual bool paralyze();
	virtual void setJumpTables(bool higherJump);
	virtual bool bury();
	virtual bool trySwitchPowerupDirect(PowerupState powerup);
	virtual Vec3 getTopSensorPosition();
	virtual void onOneUpCollected();
	
	void spawnSnowParticles() const;

	bool doTallJump(fx32 force, u16 duration, bool playSFX, bool noConsecutive, s8 variation);
	bool doWaterTallJump(fx32 force, u16 duration, bool playSFX, bool noConsecutive, s8 variation);
	bool doBouncyBricksJump(fx32 force, u16 duration, bool playSFX, bool noConsecutive, s8 variation);

	void removeLinkedActor(StageActor& actor);

	bool limitedHorizontalWarp(fx32 distance);
	bool pushingHorizontalWarp(fx32 distance);
	bool safeHorizontalWarp(fx32 distance);
	bool safeVerticalWarp(fx32 distance);

	Vec3 getHeadPosition() const;
	PlayerShellState getShellState() const;
	bool getHigherJump() const;

	void startPowerupTimer();
	bool applyPowerup(PowerupState powerup);
	bool requestPowerupSwitch(PowerupState powerup);
	void powerupDummy(); // Empty

	void enableStarmanState();
	void disableStarmanState();
	void beginTransition();
	void endTransition();
	void applyStarman(u16 timer);

	bool playSFXContinuous(s32 sfxID, const Vec3* pos = nullptr) const;
	bool playSFXContinuous(s32 sfxID, const Vec3* pos, s32 arg) const;
	bool playSFXUnique(s32 sfxID, const Vec3* pos = nullptr) const;
	bool playSFXUnique(s32 sfxID, const Vec3* pos, s32 arg) const;
	void stopSFX(s32 sfxID) const;
	void stopBGM(s32 frames) const;
	void stopLocalBGM(s32 frames) const;

	void enableInvincibility(s32 bgmID);
	void disableInvincibility();

	void followCamera(u8 playerID);

	bool onDefeated();

	void setLinkedActor(StageActor& actor);

	void setPosition2D(const Vec3& position);

	fx32 processJumpVelocity(fx32 velocity) const;
	PlayerHeight getHeight() const;


	static const s16 ropeDirectionalRotationY[2];
	static const s16 megaDirectionalRotationY[2];
	static const s16 directionalRotationY[2];
	static const s16 shellDirectionalRotationY[2];

	static u32 jumpPressedRingBuffer[2][4];
	static u32 jumpHeldRingBuffer[2][4];


	PlayerModel model;
	StageActor* linkedActor;
	MtxFx43 unk68C;
	PlayerPhysics* physics;
	FxRect boundingBox;
	SpinState spinState;
	BlendColor diffuse;
	BlendColor ambient;
	Vec3 positionStep;
	Vec3 unk734;
	Vec3 unk744;

	fx32 colliderOffset;
	u32 unk758;
	u32 unk75C;
	u32 unk760;
	u32 unk764;
	fx32 liquidY;
	u32 animID;
	u32 jumpKeysTimer;
	u32 unk774;
	PlayerActionFlag actionFlag;
	PlayerSubActionFlag subActionFlag;
	PlayerPhysicsFlag physicsFlag;
	PlayerTransitionFlag transitionFlag;
	PlayerCollisionFlag collisionFlag;
	PlayerCollisionFlag lastCollisionFlag;
	PlayerEnvironmentFlag environmentFlag;
	PlayerEnvironmentFlag lastEnvironmentFlag;
	u32 invincibleMusicID;

	u16 damageCooldown;
	u8 unk79E;
	u8 unk79F;
	u16 keysHeld;
	u16 keysPressed;
	u16 unk7A4;
	u16 unk7A6;
	bool updateLocked;
	PlayerConstrainedMovement constrainedMovement;
	u8 characterID;
	PowerupState runtimePowerup;
	PowerupState currentPowerup;
	PowerupState previousPowerup;
	u8 unk7AE;
	u8 unk7AF;
	u8 transitioningFlag;								// Possibly a bool
	u8 unk7B1;
	u8 unk7B2;
	bool defeatedFlag;
	u8 playerID;
	bool visibleFlag;
	u8 unk7B6;
	s8 scoreComboType;
	s8 scoreCombo;
	u8 scoreCombo2;
	u8 unk7BA;
	u8 unk7BB;
	u8 scoreComboSFX;
	u8 unk7BD;
	u8 unk7BE;
	bool higherJumpFlag;
	u8 unk7C0;
	u8 unk7C1;
	u8 unk7C2;
	u8 unk7C3;

};
NTR_SIZE_GUARD(PlayerBase, 0x7C4);
