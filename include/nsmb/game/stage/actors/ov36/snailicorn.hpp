#pragma once

#include <nsmb/game/stage/entity3danm.hpp>

// vtable at 0214377C (ov36)
class Snailicorn : public StageEntity3DAnm {
public:

	using StateFunction = bool(Snailicorn::*)();

	// D1: 02141e80
	// D0: 02141ea0
	virtual ~Snailicorn();

	// 02141f40
	s32 onCreate() override;
	// 021421b0
	bool onPrepareResources() override;

	// 02141ec8
	bool updateMain() override;
	// 02143030
	void onSlidingHit() override;
	// 02143038
	void onMegaKicked() override;
	// 02143034
	void onGroundPound() override;
	// 02143380
	void entityCollision(ActiveCollider& self, StageActor& actor) override;
	// 0214303c
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 02142f74
	bool seesPlayer(); // returns true if closest player is on ground and in sense range

	// 02142fb8
	bool updateVisibility(); // destroys actor and returns true if outside of view

	// 0214302c
	void null(); // does nothing, but called whenever in a state and on the ground

	// 0214342c
	void updateState();
	// 02143474
	bool switchState(const StateFunction& function);

	// 02142e9c
	bool idleState();
	// 02142c74
	bool walkState();
	// 02142bd8
	bool playerHeardState(); // when player is sensed from behind
	// 02142ae4
	bool hopState();
	// 021428fc
	bool chargeState(); // run towards player
	// 02142724
	bool stopChargeState();
	// 021425bc
	bool turnState();
	// 02142420
	bool stompedState();
	// 021422c0
	bool stoppedState();
	// 02142204
	bool unusedState(); // active collider is unlinked, then rotates on x-axis to -90deg, then actor is destroyed

	// 02143500
	static bool loadResources();

	static constexpr u16 ObjectID = 91;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 127;

	// 02143770
	static const ActorProfile profile;

	// 02143590
	static const AcConfig acConfig;

	// 02143584
	static const PointSensor sideSensor;
	// 02143578
	static const PointSensor bottomSensor;

	// 02143568
	static const fx32 walkVelocitiesX[2]; // [direction]
	// 02143560
	static const fx32 chargeVelocitiesX[2]; // [direction]

	// 02143570
	static const fx32 chargeAccels[2]; // [slipperyFlag]

	// 021438a0
	static const StateFunction sIdle;
	// 021438a8
	static const StateFunction sWalk;
	// 021438e8
	static const StateFunction sPlayerHeard;
	// 021438e0
	static const StateFunction sHop;
	// 021438d8
	static const StateFunction sCharge;
	// 021438d0
	static const StateFunction sStopCharge;
	// 021438c8
	static const StateFunction sTurn;
	// 021438c0
	static const StateFunction sStomped;
	// 021438b8
	static const StateFunction sStopped;
	// 021438b0
	static const StateFunction sUnused;


	FxRect acRect; // represents the current active collider config rect; nintendo did not need to use this variable

	StateFunction updateFunction;

	fx32 animSpeed; // represents the current model animation speed; used in stopChargeState
	fx32 startPositionY; // set in onCreate but not used
	fx32 playerSenseRangeX; // player detection range on x-axis
	fx32 stompedSlideVelX; // x velocity after being stomped
	fx32 startStompedSlideAccel; // slide accel when first stomped
	fx32 stompedSlideAccel; // current stomped slide accel

	u16 stompReaction; // 0 = normal, 1 = unused (but there is code for it), 2 = ground pounded

	bool16 obstacleTurn; // true when turn is caused by edge or wall

	u16 postTurnSenseCooldown; 	 // player detection cooldown after turning; decremented in updateMain
	u16 postChargeSenseCooldown; // player detection cooldown after charging; decremented in updateMain
	u16 stoppedCooldown; // amount of time snail will be stopped in stoppedState; decremented in updateMain
	u16 commonCooldown; // used in various states for timing

	bool onSlipperyGround;
	bool wasOnSlipperyGround;

	s8 updateStep;

	u8 align4FB; // alignment


#if NTR_EXT_EXISTS(Snailicorn)
	#include NTR_EXT_INCLUDE(Snailicorn)
#endif

};
#if !NTR_EXT_EXISTS(Snailicorn)
NTR_SIZE_GUARD(Snailicorn, 0x4FC);
#endif
