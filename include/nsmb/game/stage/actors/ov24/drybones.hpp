#pragma once

#include <nsmb/game/stage/entity3danm.hpp>
#include <nsmb/game/physics/platformmgr.hpp>

// vtable at 0213F468 (ov24)
class DryBones : public StageEntity3DAnm {
public:

	using StateFunction = bool(DryBones::*)();

	enum class CollisionFlags : u32 {

		None = 0,

		Bottom 	= (1U << 0),
		Top 	= (1U << 1),
		Side 	= (1U << 2),

		All = Bottom | Top | Side

	};


	// D1: 0213bf00
	// D0: 0213bf78
	virtual ~DryBones();

	// 0213c240
	s32 onCreate() override;
	// 0213c084
	s32 onDestroy() override;
	// 0213c054
	bool preUpdate() override;
	// 0213bff8
	void postUpdate(BaseReturnState state) override;
	// 0213c5bc
	bool onPrepareResources() override;
	// 0213c1c4
	bool updateMain() override;
	// 0213d280
	void onStarmanHit() override;
	// 0213d27c
	void onStomped() override;
	// 0213d28c
	void onGroundPound() override;
	// 0213d624
	void entityCollision(ActiveCollider& self, StageActor& actor) override;
	// 0213d3fc
	void damagePlayer(ActiveCollider& self, Player& player) override;
	// 0213c08c
	void postRender3D() override;

	// 0213c520
	void setModelCallback(void* cb);
	// 0213c548
	static void modelCallback(NNSG3dRS* rs);
	// 0213c5b4
	void setModelOwner(void* ptr);

	// 0213c664
	bool updateVisibility();
	// 0213cc5c
	void updateDetachedHead(); // if toppled calls updateDetachedHeadPhysics after the 7th model animation frame
	// 0213cd4c
	void updateDetachedHeadPhysics();

	// 0213d6dc
	bool switchState(const StateFunction& function);
	// 0213d694
	void updateState();

	// 0213c710
	bool reviveState();
	// 0213cadc
	bool deadState();
	// 0213cb80
	bool toppleState();
	// 0213cea4
	bool stunnedState();
	// 0213cfbc
	bool turnState();
	// 0213d070
	bool walkState();

	// 0213d1e8
	CollisionFlags updateSensors(); // updates sensors and returns which are touched

	// 0213d768
	static bool loadResources();

	static constexpr u16 ObjectID = 55;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 69;

	// 0213f450
	static const ActorProfile profile;

	// 0213f178
	static const AcConfig acConfig;

	// 0213f0fc
	static const PointSensor bottomSensor;
	// 0213f108
	static const PointSensor sideSensor;

	// 0213f120
	static const PointSensor headBottomSensor;
	// 0213f12c
	static const PointSensor headTopSensor;
	// 0213f138
	static const PointSensor headSideSensor;

	// 0213f0d8
	static const s16 rotationSpeeds[2]; // [direction]
	// 0213f0dc
	static const s16 rotationsY[2];		// ^^
	// 0213f0e0
	static const s16 headRotationsX[2];
	// 0213f0e4
	static const fx32 headOffsetsX[2];
	// 0213f0ec
	static const fx32 velocitiesX[2];
	// 0213f0f4
	static const fx32 headVelocitiesX[2];

	// 0213f144
	static const s16 stunnedHeadRotationTargetsZ[18]; // [stunnedStep]
	// 0213f194
	static const s16 stunnedHeadRotationSpeedsZ[12]; // [stunnedStep]

	// 0213fa60
	static const StateFunction sDead;
	// 0213fa68
	static const StateFunction sRevive;
	// 0213fa70
	static const StateFunction sStunned;
	// 0213fa78
	static const StateFunction sTopple;
	// 0213fa80
	static const StateFunction sTurn;
	// 0213fa88
	static const StateFunction sWalk;


	ModelAnm headModel;
	CollisionMgr headCollisionMgr;
	PlatformMgr headPlatformMgr;
	Vec3 headPosition;
	Vec3 headVelocity;
	Vec3 neckNodePosition;
	Vec3 detachedHeadExternalForce;
	Vec3s detachedHeadRotation;

	StateFunction* updateFunction;
	StateFunction* prevUpdateFunction;

	fx32 detachedHeadOffsetY;

	fx32 conveyorSpeed;			// for conveyor belt movement

	s16 headRotationZ;
	bool16 longerDeath;			// if true reviveTimer is set to 192 instead of 128 in deadState
	u16 reviveTimer;			// decremented in deathState until 0, then state is switched to revive
	fx16 detachedHeadRotVelX;

	bool16 onConveyor;			// on conveyor belt
	bool16 onGround;
	bool16 reviving;			// if bones being put back together
	bool16 big;					// if big dry bones
	u16 stunnedStep;
	bool toppled;
	u8 unk6BF;					// set to 0 (at 021f05bc) but not used??
	bool detachedHeadStopped;	// false if moving back to dry bones neck in reviveState
	bool renderDetachedHead;
	u8 detachedHeadBounces;		// times detached head has bounced
	bool headAttached;
	u8 reviveStep;
	bool stunned;				// big dry bones stun when stomped

	s8 updateStep;
	u8 align6C7;	// alignment

#if NTR_EXT_EXISTS(DryBones)
	#include NTR_EXT_INCLUDE(DryBones)
#endif

};
#if !NTR_EXT_EXISTS(DryBones)
NTR_SIZE_GUARD(DryBones, 0x6C8);
#endif

NTR_CREATE_BITMASK_ENUM(DryBones::CollisionFlags);


// vtable at 0213f588 (ov24)
class BigDryBones : public DryBones {
public:

	// D1: 0213d8d0
	// D0: 0213d954
	virtual ~BigDryBones();

	static constexpr u16 ObjectID = 56;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 70;

	// 0213f45c
	static const ActorProfile profile;

	// 0213f15c
	static const AcConfig acConfig;

	// 0213f114
	static const PointSensor sideSensor;


#if NTR_EXT_EXISTS(BigDryBones)
	#include NTR_EXT_INCLUDE(BigDryBones)
#endif

};
#if !NTR_EXT_EXISTS(BigDryBones)
NTR_SIZE_GUARD(BigDryBones, sizeof(DryBones));
#endif
