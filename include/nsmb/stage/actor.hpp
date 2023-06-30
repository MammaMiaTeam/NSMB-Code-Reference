#pragma once
#include "nsmb/entity/actor.hpp"
#include "nsmb/physics/activecollider.hpp"
#include "nsmb/physics/collisionmgr.hpp"
#include "nsmb/physics/platformmgr.hpp"


class Player;


class StageActor : public Actor
{
public:
	
	enum class ColliderPushSide : u8
	{

		None	= 0,
		Left	= 0x1,
		Right	= 0x2,
		Down	= 0x4,
		Up		= 0x8

	};

	enum class ReleaseMode : u8
	{

		None,
		Drop,
		Throw

	};

	ActiveCollider activeCollider;
	CollisionMgr collisionMgr;
	PlatformMgr platformMgr;

	ReleaseMode releaseMode;
	u8 direction;
	u8 viewID;
	ColliderPushSide colliderPushSides;
	BOOL preUpdatePassed;

	//020a127c
	StageActor();

	//D0:020a11ec
	//D1:020a1238
	//D2:020a11a8
	virtual ~StageActor();

	//020a1154
	virtual bool preUpdate() override;

	//020a10f0
	virtual void postUpdate(BaseReturnState state) override;


	// 020a10a0
	// returns whether the actor is located inside an active view (a view that contains at least one player)
	bool isInActiveView() const;

	// 020a06dc
	// returns whether the actor is vertically outside of the stage camera
	bool isOutOfViewVertical() const;

	// 020a069c
	// Returns the closest player to the entity (and writes back the distance)
	Player* getClosestPlayer(s32* distanceX, s32* distanceY) const;

	// 020a05f8
	// Returns the closest player to the entity (and writes back the distance) - no stage wrapping
	static Player* getClosestPlayerNoWrap(u32 x, u32 y, s32* distanceX, s32* distanceY);

	// 020a0500
	// Returns the closest player to the entity (and writes back the distance) - with stage wrapping
	static Player* getClosestPlayerWrap(u32 x, u32 y, s32* distanceX, s32* distanceY);

	// 020a04e4
	// Sets the function used to retrieve the closest to the player
	static void setGetClosestPlayerFunction(u32 wrapType);


	// 020a04c0
	// Wraps the position around the borders in case the stage has wrapping enabled (rotation argument is unused)
	static void wrapPosition(Vec3& position, Vec3s& rotation, bool wrapLeft = true);

	// Wraps the position around the borders in case the stage has wrapping enabled (removes the need to use the rotation argument)
	NTR_INLINE void wrapPosition(Vec3& position, bool wrapLeft = true) {
		Vec3s rot = rotation;
		wrapPosition(position, rot, wrapLeft);
	}

	// 020a04b4
	// Sets the function used to wrap a position vector
	static void setWrapPositionFunction(u32 wrapType);


	
	// 020a047c
	// returns true if the actor's X position is less than the target's X position
	bool isBehindTarget(const StageActor& target) const;

	// 020a0444
	// returns true if the actor's X position is greater than or equal to the target's X position
	bool isInFrontOfTarget(const StageActor& target) const;

	// 020a0434
	// returns true if self is less than target (no stage wrapping)
	static bool isBehindTargetNoWrap(fx32 self, fx32 target);

	// 020a03e8
	// returns true if self is less than target (with stage wrapping)
	static bool isBehindTargetWrap(fx32 self, fx32 target);

	// 020a03cc
	// Sets the function used to calculate whether an actor is behind another one
	static void setIsBehindTargetFunction(u32 wrapType);



	// 020a03ac
	// Initializes the functions used in various position calculations
	static void initWrapFunctions(u32 wrapType);

};
NTR_SIZE_GUARD(StageActor, 0x2C4);

NTR_CREATE_BITMASK_ENUM(StageActor::ColliderPushSide);
