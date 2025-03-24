#pragma once

#include "actor.hpp"
#include "misc.hpp"
#include "player/common.hpp"

struct ObjectBank;
class Player;

enum class EntityProperties : u16
{
	None = 0,
	Immune				= (1U << 0),	// Immune to all collisions?
	InactiveFocus		= (1U << 1),	// Permanently destroy the object if inactive
	LiquidParticles		= (1U << 2),	// Spawn particles and play SFX on liquid collision
	NoLevelBeaten		= (1U << 4),	// Ignore defeat on level beaten
	NoGroundPound		= (1U << 5),	// Ignore groundpound collision
	NoMegaKick			= (1U << 6),	// Ignore mega player kick collision
	NoMega				= (1U << 7),	// Ignore mega player collision
	NoStarman			= (1U << 8),	// Ignore starman collision
	NoSliding			= (1U << 9),	// Ignore sliding player collision
	NoBlueShell			= (1U << 10),	// Ignore shell player collision
	FenceSlam			= (1U << 11),	// Enable fence slam collision
	SpinDrill			= (1U << 12),	// Enable spin drill collision
	// 1U << 13 - used in Manhole
	NoFireball			= (1U << 14),	// Ignore fireball collision
};
NTR_CREATE_BITMASK_ENUM(EntityProperties);


enum class SpawnSettings : u16
{
	None = 0,
	SinglePlayerOnly	= (1U << 0),
	MvsLOnly			= (1U << 1),
	AlwaysLoad			= (1U << 2),
	IgnoreView			= (1U << 3),
};
NTR_CREATE_BITMASK_ENUM(SpawnSettings);


enum class CollisionType : u32
{
	None = 0,
	Collisionless		= (1U << 0),

	// Mega Ground-Pound by player 0 while the entity is on the ground
	MGPGroundP0			= (1U << 1),

	// Mega Ground-Pound by player 1 while the entity is on the ground
	MGPGroundP1			= (1U << 2),

	// Mega Ground-Pound by player 0 while the entity is in midair
	MGPAirP0			= (1U << 3),

	// Mega Ground-Pound by player 1 while the entity is in midair
	MGPAirP1			= (1U << 4),

	Fireball			= (1U << 5),
	Entity				= (1U << 6),
	Block				= (1U << 7),
	StageBeaten			= (1U << 8),
	Starman				= (1U << 9),
	Mega				= (1U << 10),
	SpinDrill			= (1U << 11),
	Sliding				= (1U << 12),
	Stomp				= (1U << 13),
	GroundPound			= (1U << 14),
	BlueShell			= (1U << 15),
	FenceSlam			= (1U << 16),

};
NTR_CREATE_BITMASK_ENUM(CollisionType);


struct ObjectInfo
{
	struct { s16 x, y; }

	// Used to offset the sprite position in the stage
	position,

	// StageEntity::renderSize, StageEntity::existSize
	size,

	// Only used when assigning the view, does not affect the object's position
	spawnOffset,

	// StageEntity::viewOffset
	viewOffset;

	// StageEntity::properties
	EntityProperties properties;

	// StageEntity::spawnSettings
	SpawnSettings spawnSettings;


	constexpr ObjectInfo() :
		position{ 0, 0 },
		size{ 0, 0 },
		spawnOffset{ 0, 0 },
		viewOffset{ 0, 0 },
		properties(EntityProperties::None),
		spawnSettings(SpawnSettings::None)
	{}


	constexpr ObjectInfo(
		s16 positionX, s16 positionY,
		s16 renderSizeX = 0, s16 renderSizeY = 0,
		s16 spawnOffsetX = 0, s16 spawnOffsetY = 0,
		s16 viewOffsetX = 0, s16 viewOffsetY = 0,
		EntityProperties properties = EntityProperties::None,
		SpawnSettings spawnSettings = SpawnSettings::None
	) :
		position{ positionX, positionY },
		size{ renderSizeX, renderSizeY },
		spawnOffset{ spawnOffsetX, spawnOffsetY },
		viewOffset{ viewOffsetX, viewOffsetY },
		properties(properties),
		spawnSettings(spawnSettings)
	{}

};


enum class SimplePlayerCollisionFlags : u16 {
	None			= 0x0,
	Player0			= 0x1,
	Player1			= 0x2,
	SpecialPlayer0	= 0x10,
	SpecialPlayer1	= 0x20
};
NTR_CREATE_BITMASK_ENUM(SimplePlayerCollisionFlags);


struct SimplePlayerCollision {
	Player* player;
	fx32 dx, dy;
};

struct SimplePlayerSpecialCollision {
	Player* player;
	fx32 dx, dy;
	u16 flags;
};

struct EventMask {
	u32 data[2];
};

class alignas(4) StageEntity : public StageActor
{
public:

	enum class UpdateStateID : u32 {
		Main,
		State1,
		Defeated,
		DefeatedMega,
		FenceTurning,
		Carried,
		Released,
		Dropped,
		DroppedHeavy,
		Rolling,
	};

	enum class ScoreType : u8 {
		Regular,  // Only works in singleplayer
		Enhanced,
		None      // Used by StarCoin
	};

	enum class CarriedAction : u32 {
		Released = 0x1,
		Thrown = 0x2
	};

	enum class ReleaseMode : u16
	{
		Release,
		DropLight,
		DropHeavy
	};

	enum class CollisionResponse
	{

		None			= 0,
		Bottom			= 0x1,
		Top				= 0x2,
		Sides			= 0x4,

		Any				= Bottom | Top | Sides

	};

	// 020c4ec0
	static u8 layerFlag[2];

	// 020c4ec4
	static s8 unitDirection[2];

	// 020c4ec8
	static s16 directionalRotationY[2];

	// 020c4ecc
	// static s16 unkRotationY[2];

	// 020c4ed0
	static s16 directionalRotationYVelocity[2];

	// 020c4ed4
	static fx16 directionalDefeatedHVelocity[2];

	// 020c4ed8
	static fx32 layerPosition[2];

	// 020C1F4C
	static SimplePlayerCollisionFlags simplePlayerSpecialCollisionFlags[2];

	// 020C1F48
	static SimplePlayerCollisionFlags simplePlayerCollisionFlags[2];


	u8 unused2C0;
	u8 align2C1; // Alignment

	EntityProperties properties;
	SpawnSettings spawnSettings;
	u16 inactiveDestroyFlag;

	u8 cooldownA;
	u8 cooldownB;
	u8 align2CA; // Alignment
	u8 align2CB; // Alignment

	u32 unused2CC;

	SimplePlayerCollision simplePlayerCollision[2];
	SimplePlayerSpecialCollision simplePlayerSpecialCollision[2];

	Vec3 unused308;
	Vec3 externalForce;
	fx32 releaseForceX;
	fx32 releaseForceY;

	EventMask eventMask;
	u8 events[2];

	u8 align33A; // Alignment
	u8 align33B; // Alignment

	UpdateStateID updateStateID;
	u32 unk340;
	u32 spawnPlayerID;
	u32 defeatSFX;
	u32 liquidWaveHeight;
	CarriedAction carriedAction;
	u32 collisionData;

	Vec3 wiggleScale;

	Vec2 activeSize;
	Vec2 renderSize;
	Vec2 viewOffset;

	Vec2 collisionSelfPos;
	Vec2 collisionActorPos;

	fx32 wiggleFactor;
	u32 unused3A8;
	u32 unused3AC;
	CollisionType collisionType;
	fx32 kickedInWallDistance;

	u16 wiggleTimer;
	u16 liquidFlag;

	// Behavior on entity released (note that only Bob-Ombs and trampolines will trigger the player drop animation)
	ReleaseMode releaseMode;
	u16 thrownFlag;

	u16 unused3C0;
	u16 playerCollisionCooldown[2];
	SimplePlayerCollisionFlags simplePlayerCollisionResult;

	u16* objectRespawnTimer;

	u8 defeatedLeftLiquid;
	u8 defeatedInLiquid;
	u8 manualTimerA; // not ticked automatically
	u8 unk3CF;
	u8 cooldownC; // 3rd cooldown
	u8 align3D1; // Alignment
	u8 align3D2; // Alignment
	u8 align3D3; // Alignment

	u8* objectSpawnFlags; // (re)spawn flags: 1 = created/exists, 8 = permanently destroyed

	u8 playerDirection;
	u8 scoreCombo;
	ScoreType scoreType;
	bool kickedFaster;
	bool unused3DC;
	u8 unused3DD;
	u8 blockHitDirection;
	u8 defeatedArg;
	bool permanentDestroy;
	u8 unused3E1;
	bool forceUpdate;
	s8 unused3E3;
	bool relativeDefeatSpin;
	bool forceRender;
	bool quicksandFlag;
	bool slipperyFlag;
	u8 stompTriggerHeight;
	u8 unused3E9;
	u8 collisionDirection;
	bool freezeFlag;
	bool backLayer;
	bool kickedInWall;
	s8 functionStep; // generic function step, used in InvisiblePodoboo



	NTR_INLINE s8 cycleScoreCombo() {

		if (scoreCombo < 8)
			scoreCombo++;

		return scoreCombo;

	}


	// 0209dee0
	StageEntity();



	virtual s32 onUpdate() override;
	// 0209dab8
	virtual bool preUpdate() override;
	// 0209da90
	virtual void postUpdate(BaseReturnState state) override;
	// 0209da58
	virtual bool preRender() override;



	// D1: 020986e0
	// D0: 02098730
	NTR_INLINE virtual ~StageEntity() {}



	// 02098788
	// static ObjectBank* getObjectBank(u32 objectID) ;

	// 02098798
	// u32 getSpritePriority - ???
	//
	// 02098814
	// Vec3 tryNormalizeVec3(const Vec3& v) const ;

	// 020988ac clear bit at 020ca2b8 (const)
	// 020988d0 set bit at 020ca2b8 (const)

	// 020988f0
	void assignView(const Vec3& position);

	// 02098908
	bool isPlayerInZone(const Player& player, u32 zoneID) const;

	// 02098998
	// u32 stopPlayerInShell(const ActiveCollider& collider, Player& player) const; - ???

	// 02098c78
	static void damagePlayerCallback(ActiveCollider& self, ActiveCollider& other);

	// 02098dd8
	static bool isBelowCamera(fx32 positionY, ActiveCollider& collider, u8 playerID);

	NTR_INLINE static bool isAboveCamera(fx32 positionY, ActiveCollider& collider, u8 playerID) {
		return -(positionY + collider.hitbox.rect.y + collider.hitbox.rect.halfHeight) > Stage::cameraY[playerID];
	}

	// 02098e08
	bool setGroundPoundCollision(const Player& player);

	// 02098fbc
	bool checkCrushed() const;

	NTR_INLINE CollisionMgrResult updateTopSensor() {
		return collisionMgr.updateTopSensor(collisionMgr.collisionResult);
	}

	NTR_INLINE CollisionMgrResult updateTopSensor(CollisionMgrResult bottomResult) {
		return collisionMgr.updateTopSensor(bottomResult);
	}

	// 02099040
	CollisionMgrResult updateSideSensors();

	// 020990d4
	CollisionMgrResult updateBottomSensor();

	// 0209917c
	bool checkLavaCollision() const;

	// 020991f8
	CollisionResponse updateCollisionSensors();

	// 02099250
	bool checkPlayersInRange(fx32 x, fx32 y) const;

	// 02099354
	bool checkPlayersInRange(fx32 x) const;

	// 020993ec
	bool rotateToTarget(s16 target[2], s16 step[2]);

	// 02099440
	void applyFireballWiggle();

	// 02099590
	static u16 getActorID(u16 objectID);

	// 020995a4
	void setTimedEvent(u32 eventID, s32 time, bool enable, bool switchEvent = false, bool playSFX = false);

	// 02099884
	void destroy(bool permanent);

	// 020998e4
	void updateBounce(fx32 thresholdY, fx32 amountX, fx32 amountY);

	// 0209997c
	static void damageEntityCallback(ActiveCollider& self, ActiveCollider& other);

	// 02099b6c
	static void shellCallback(ActiveCollider& self, ActiveCollider& other);

	// 02099fb4
	static void simplePlayerCallback(ActiveCollider& self, ActiveCollider& other);

	// 0209a070
	// static void spawnBrokenPipe(u8 a, u8 b, u8 c) ;

	// 0209a0e8
	static u32 getRandom();

	// 0209a0f4
	u32 tryAttachToPlayerHands(fx32 z, fx32 y, fx32 x);

	// 0209a144
	void attachToPlayerHands(fx32 z, fx32 y, fx32 x);

	// 0209a23c (TODO)
	u32 updateSolidActiveCollider(bool push, u32 flags, u8 playerID);

	// 0209a4f0
	bool canPlayerStomp(ActiveCollider& collider, Player& player, bool allowClippedJump);

	// 0209a5bc
	void onPlayerStomp(Player& player, fx32 jumpVelocity, bool noPoints);

	// 0209a80c
	PlayerStompType updatePlayerStomp(ActiveCollider& collider, fx32 jumpVelocity, bool allowClippedJump, bool noPoints);

	// Stage Beaten :  800, 1000, 2000, 4000, 8000, 1-UP, 1-UP, 1-UP, 1-UP, 1-UP

	// 0209a938
	void getScorePointsStageBeaten(u32 type, fx32 x, fx32 y, s32 playerID) const;

	// 0209a990
	static void getScorePointsStageBeaten(const Vec3& position, u32 type, s32 playerID);

	// Enhanced     : 1000, 1000, 2000, 4000, 8000, 1-UP, 1-UP, 1-UP, 1-UP, 1-UP

	// 0209aa04
	void getScorePointsEnhanced(u32 type, fx32 x, fx32 y, s32 playerID) const;

	// 0209aa5c
	static void getScorePointsEnhanced(const Vec3& position, u32 type, s32 playerID);

	// 0209aad0
	static void spawnRedCoinNumber(const Vec3& position, u32 coins, s32 playerID);

	// 0209ab04
	static void getCollectablePoints(u32 type, s32 playerID);

	// Regular      :  100,  200,  400,  800, 1000, 2000, 4000, 8000, 1-UP,   10
	// Regular score only works in singleplayer

	// 0209ab90
	void getScorePointsRegular(u32 type, fx32 x, fx32 y, s32 playerID) const;

	// 0209ac0c
	static void getScorePointsRegular(const Vec3& position, u32 type, s32 playerID);

	// 0209ac8c
	u8 getVerticalDirectionToPlayer(const Vec3& position) const;

	NTR_INLINE u8 getVerticalDirectionToPlayer() const {
		return getVerticalDirectionToPlayer(position);
	}

	// 0209acd4
	u8 getHorizontalDirectionToPlayer(const Vec3& position) const;

	NTR_INLINE u8 getHorizontalDirectionToPlayer() const {
		return getHorizontalDirectionToPlayer(position);
	}

	// 0209adb0
	bool destroyInactive(u32 flags);

	// 0209ae88
	static bool isOutOfView(const Vec3& position, const FxRect& boundingBox, u8 viewID);

	/*--- small break here (Stage/StageScene functions) ---*/

	// 0209c590
	static u32 checkLiquidCollision(const Vec3& position, const Vec3& lastPosition, fx32 waveHeight, bool playSFX = true);

	// 0209c6d4
	bool updateLiquidPhysics(const Vec3& position, fx32 defaultAccelY);

	// 0209c7a0
	void updateLiquidCollision(const Vec3& position, fx32 defaultAccelY);

	// 0209c820
	u32 updateLiquids(fx32 defaultAccelY);

	// 0209c85c
	void applyMovement();

	// 0209ccd0
	bool setBlueShellCollision(const Player& player);

	// 0209cfc4
	void setStompCollision(const Player& player);

	// 0209d0ec
	bool setSpinDrillCollision(const Player& player);

	// 0209d240
	bool setMegaKickCollision(const Player& player);

	// 0209d3d0
	bool setMegaCollision(const Player& player);

	// 0209d694
	void spawnCoin();

	// 0209d708
	bool setFenceSlamCollision(const Player& player);

	// 0209d774
	bool setSlidingCollision(const Player& player);

	// 0209d7e0
	bool setStarmanCollision(const Player& player);

	// 0209ff98
	bool updateCarriedCollision();

	// 020a0048
	bool tryGrab(Player& player);

	// 020a01b4
	void switchFenceLayer();

	// 020a020c
	void fenceTurning();



	// 020a03a4
	virtual bool updateMain();

	// 0209ad1c
	// Returns true if rendering should be skipped
	virtual bool skipRender();

	// 020a039c
	virtual bool updateState1();
	// 020a0304
	virtual bool updateDefeated();
	// 020a0274
	virtual bool updateDefeatedMega();
	// 020a01ac
	virtual bool updateFenceTurning();
	// 0209fb3c
	// Tries to attach the entity to the linked player's hands (if any) and handles released/thrown behavior. Has hardcoded code for bob-ombs lmao
	virtual bool updateCarried();
	// 0209fa8c
	virtual bool updateReleased();
	// 0209f824
	virtual bool updateDropped();
	// 0209f6c4
	virtual bool updateDroppedHeavy();
	// 0209f0e4
	virtual bool updateRolling();

	// 0209d9fc
	virtual void updateAnimation();

	// 0209faf4
	virtual void thrown();
	// 0209faac
	virtual void thrownStop();
	// 0209c974
	virtual void virt34();
	// 020a012c
	virtual void grabbed();
	// 020a00ac
	virtual void released();
	// 0209f574
	virtual void shellStarted(Player& player);
	// 0209f3d8
	virtual void shellKicked();
	// 0209f354
	virtual void shellStopped();

	// 020994f8
	virtual void updateFireballWiggle();

	// 0209d988
	virtual void onBlockHit();
	// 0209d920
	virtual void onEntityHit();
	// 0209d84c
	virtual void onFireballHit();
	// 0209d568
	virtual void onStarmanHit();
	// 0209d43c
	virtual void onSlidingHit();
	// 0209d2a0
	virtual void onMegaHit();
	// 0209d158
	// Never called, apparently some mega kick leftover from the beta?
	virtual void onMegaKicked();
	// 0209d014
	virtual void onSpinDrillHit();
	// 0209cfc0
	virtual void onStomped();
	// 0209ce08
	virtual void onGroundPound();
	// 0209cbf8
	virtual void onBlueShellHit();
	// 0209cad0
	virtual void onFenceSlamHit();
	// 02098f7c
	virtual void onMegaGroundPound();
	// 02098e7c
	virtual void onStageBeaten(Player& player);
	// 0209cd3c
	virtual void onFatalDamage();
	// 0209cac4
	virtual void onMegaWalkShockwave();
	// 0209cac0
	// Never triggered, use onMegaGroundPound instead
	virtual void onMegaGroundPoundShockwave();
	// 02099168
	virtual void stopMovement();

	// 02098a94
	virtual bool playerCollision(ActiveCollider& self, ActiveCollider& other);
	// 02098a90
	virtual void entityCollision(ActiveCollider& self, StageActor& actor);
	// 02098a10
	virtual void damagePlayer(ActiveCollider& self, Player& player);

	// 0209c9d0
	virtual void defeat(fx32 velX, fx32 velY, fx32 accelY, u8 arg);
	// 0209c994
	virtual void defeatMega(fx32 velX, fx32 velY, fx32 accelY);

	// 020a0268
	virtual void fenceDisableCollision();
	// 020a0240
	virtual void fenceSwitchDirection();


	// 0209a6d4
	virtual void doPlayerJump(Player& player, fx32 jumpVelocity);

};
NTR_SIZE_GUARD(StageEntity, 0x3F4);

NTR_CREATE_BITMASK_ENUM(StageEntity::CarriedAction);
NTR_CREATE_BITMASK_ENUM(StageEntity::CollisionResponse);
