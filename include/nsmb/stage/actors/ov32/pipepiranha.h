#pragma once
#include "nsmb.h"


// vtable at 021439F8 (ov32)
class PipePiranha : public StageEntity
{
public:

	using StateFunction = bool(PipePiranha::*)();

	static constexpr u8 PipeUp    = 0;
	static constexpr u8 PipeDown  = 1;
	static constexpr u8 PipeRight = 2;
	static constexpr u8 PipeLeft  = 3;


	// D0: 02141F10
	// D1: 02141E80
	virtual ~PipePiranha();

	// 02142654
	s32 onCreate() override;
	// 02142440
	s32 onDestroy() override;
	// 02142468
	s32 onRender() override;
	// 02142464
	void onCleanupResources() override;
	// 02143620
	bool onPrepareResources() override;

	// 021425D4
	bool updateMain() override;
	// 02141FAC
	bool skipRender() override;

	// 02141FA8
	void onBlockHit() override;
	// 021422D4
	void onEntityHit() override;
	// 0214239C
	void onFireballHit() override;
	// 021421FC
	void onStarmanHit() override;
	// 02142118
	void onMegaHit() override;
	// 021421E0
	void onMegaKicked() override;
	// 02142300
	void onSpinDrillHit() override;
	// 0214206C
	void onBlueShellHit() override;

	// 0214257C
	static void modelCallback(NNSG3dRS* rs);

	NTR_INLINE void setModelCallback(NNSG3dSbcCallBackFunc cb) {
		model.setCommandCallback(cb, 0, NNS_G3D_SBC_NODEDESC, NNS_G3D_SBC_CALLBACK_TIMING_B);
	}

	NTR_INLINE void setModelOwner(void* ptr) {
		model.setOwner(ptr);
	}

	// 02143468
	void setDirection();
	// 021433C4
	bool updateSpinRotation();
	// 02143324
	void spawnFireball();
	// 021432A8
	void fetchNeckPosition();
	// 02142E88
	void fetchSpinDirection();
	// 02142DEC
	void updateNeckRotation();
	// 02141FD4
	void spawnCoin();

	// 022030BC
	bool switchState(StateFunction function);
	// 021434D4
	void updateState();

	// 021430D8
	bool waitState();
	// 02142EBC
	bool leavePipeState();
	// 02142BB8
	bool attackState();
	// 02142938
	bool enterPipeState();
	// 0214288C
	bool defeatedState();

	// 02143678
	static bool loadResources();

	// 02143938
	static const s16 neckTargetAngles[4][2][2];
	// 0214391C
	static const ActiveColliderInfo activeColliderInfo;
	// 0214390C
	static const fx32 coinVelocitiesY[4];
	// 021438FC
	static const fx32 centerOffsetsX[4];
	// 021438EC
	static const fx32 pipeOffsetsY[4];
	// 021438DC
	static const fx32 pipeOffsetsX[4];
	// 021438CC
	static const fx32 centerOffsetsY[4];
	// 021438BC
	static const fx32 headHitboxOffsetsY[4];
	// 021438AC
	static const fx32 coinVelocitiesX[4];
	// 0214389C
	static const fx32 headHitboxOffsetsX[4];
	// 0214388C
	static const fx32 exitOffsetsY[4];
	// 0214387C
	static const fx32 exitOffsetsX[4];
	// 02143870
	static const VecFx32 mouthOffset;
	// 02143868
	static const fx32 pipeVelocities[2];
	// 02143860
	static const u32 idleAnimationIDs[2];
	// 02143858
	static const s16 rotationsZ[4];
	// 02143854
	static const s16 rotationsY[2];
	// 02143850
	static const s16 rotationYSteps[2];
	// 0214384C
	static const s16 attackDurations[2];


	ModelAnm model;

	StateFunction updateFunction;

	Vec3 mouthPosition;
	Vec3 stemPosition;
	Vec2 exitPosition;
	Vec2 pipePosition;

	ActiveCollider stemCollider;

	fx32 pipeTarget;
	s16 transitCooldown;
	s16 fireballSpawned;
	s16 neckRotation;
	u8 firePiranhaFlag;
	u8 lookDirection;
	u8 pipeDirection;
	bool invisibleFlag;
	u8 spinDirection;
	s8 updateStep;

};
NTR_SIZE_GUARD(PipePiranha, 0x59C);


class PiranhaUp : public PipePiranha
{
public:

	static constexpr u16 objectID = 23;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 31;

	// 021439C8
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(PiranhaUp, sizeof(PipePiranha));


class PiranhaDown : public PipePiranha
{
public:

	static constexpr u16 objectID = 24;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 32;

	// 021439D4
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(PiranhaDown, sizeof(PipePiranha));


class PiranhaRight : public PipePiranha
{
public:

	static constexpr u16 objectID = 25;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 33;

	// 021439E0
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(PiranhaRight, sizeof(PipePiranha));


class PiranhaLeft : public PipePiranha
{
public:

	static constexpr u16 objectID = 26;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 34;

	// 021439EC
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(PiranhaLeft, sizeof(PipePiranha));
