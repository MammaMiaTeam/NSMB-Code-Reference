#pragma once
#include "actor.h"
#include "misc.h"
#include "player/player.h"


struct ObjectBank;


enum class CollisionSwitch : u16
{
	None = 0,
	// 1U << 0 - used in FenceKoopa
	InactiveFocus		= (1U << 1),
	NoLiquidParticles	= (1U << 2), // ??????????
	NoLevelBeaten		= (1U << 4),
	NoGroundPound		= (1U << 5),
	NoMegaMushroom		= (1U << 7),
	NoStarman			= (1U << 8),
	NoSliding			= (1U << 9),
	NoBlueShell			= (1U << 10),
	FenceSlam			= (1U << 11),
	SpinDrill			= (1U << 12),
	// 1U << 13 - used in Manhole
	NoFireball			= (1U << 14),
};
IMPL_ENUMCLASS_OPERATORS(CollisionSwitch);


enum class SpawnSettings : u16
{
	None = 0,
	SinglePlayerOnly	= (1U << 0),
	MvsLOnly			= (1U << 1),
	AlwaysLoad			= (1U << 2),
	IgnoreView			= (1U << 3),
};
IMPL_ENUMCLASS_OPERATORS(SpawnSettings);


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
	MegaMushroom		= (1U << 10),
	SpinDrill			= (1U << 11),
	Sliding				= (1U << 12),
	Stomp				= (1U << 13),
	GroundPound			= (1U << 14),
	BlueShell			= (1U << 15),
	FenceSlam			= (1U << 16),

};
IMPL_ENUMCLASS_OPERATORS(CollisionType);


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

	// StageEntity::collisionSwitch
	CollisionSwitch collisionSwitch;

	// StageEntity::spawnSettings
	SpawnSettings spawnSettings;


	constexpr ObjectInfo() :
		position{ 0, 0 },
		size{ 0, 0 },
		spawnOffset{ 0, 0 },
		viewOffset{ 0, 0 },
		collisionSwitch(CollisionSwitch::None),
		spawnSettings(SpawnSettings::None)
	{}


	constexpr ObjectInfo(
		s16 positionX, s16 positionY, 
		s16 renderSizeX = 0, s16 renderSizeY = 0,
		s16 spawnOffsetX = 0, s16 spawnOffsetY = 0,
		s16 viewOffsetX = 0, s16 viewOffsetY = 0,
		CollisionSwitch collisionSwitch = CollisionSwitch::None,
		SpawnSettings spawnSettings = SpawnSettings::None
	) :
		position{ positionX, positionY },
		size{ renderSizeX, renderSizeY },
		spawnOffset{ spawnOffsetX, spawnOffsetY },
		viewOffset{ viewOffsetX, viewOffsetY },
		collisionSwitch(collisionSwitch),
		spawnSettings(spawnSettings)
	{}

};


enum class SimplePlayerCollisionFlags : u16
{
	None			= 0,
	Player0			= 1 << 0,
	Player1			= 1 << 1,
	SpecialPlayer0	= 1 << 2,
	SpecialPlayer1	= 1 << 3,
};
IMPL_ENUMCLASS_OPERATORS(SimplePlayerCollisionFlags);


struct SimplePlayerCollision
{
	Player* player;
	fx32 x, y;
};

struct SimplePlayerSpecialCollision
{
	Player* player;
	fx32 x, y;
	u16 flags;
};


class alignas(4) StageEntity : public StageActor
{
public:

	enum class UpdateStateID : u32
	{
		Main,
		SubState1,
		Defeated,
		DefeatedMega,
		SubState4,
		Grabbed,
		SubState6,
		SubState7,
		SubState8,
		SubState9,
	};

	enum class CollisionResult
	{
		None			= 0,
		Bottom			= 1 << 0,
		Top				= 1 << 1,
		Sides			= 1 << 2,
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
	static s16 directionalDefeatedHVelocity[2];

	// 020c4ed8
	static fx32 layerPosition[2];

	// 020C1F4C
	static SimplePlayerCollisionFlags simplePlayerSpecialCollisionFlags[2];

	// 020C1F48
	static SimplePlayerCollisionFlags simplePlayerCollisionFlags[2];


	u16 unk2C0;
	CollisionSwitch collisionSwitch;
	SpawnSettings spawnSettings;
	u16 unk2C6;
	u8 hitCountdown;
	u8 userCountdown;
	u8 unk2CA;
	u8 unk2CB;
	u32 unk2CC;
	SimplePlayerCollision simplePlayerCollision[2];
	SimplePlayerSpecialCollision simplePlayerSpecialCollision[2];
	Vec3 unk308;
	Vec3 movementStrength;
	u32 unk328;
	u32 unk32C;

	u32 eventMask[2];

	struct EventIDs {
		u8 target;
		u8 trigger;
	} eventIDs;

	u16 unk33A;
	UpdateStateID updateStateID;
	u32 unk340;
	u32 playerID;
	u32 defeatSFX;
	u32 liquidWaveHeight;
	u32 bitfield;
	u32 unk354;

	// scale for wiggling effect
	Vec3 wiggleScale;

	// render/despawn box vectors
	Vec2 existSize;
	Vec2 renderSize;
	Vec2 viewOffset;

	// physics collision vectors
	Vec2 collisionSelfPos;
	Vec2 collisionActorPos;

	fx32 wiggleOscillator;

	u32 unk3A8;
	u32 unk3AC;
	CollisionType collisionType;

	fx32 unk3B4;
	u16 wiggleTimer;
	u16 unk3BA;
	u16 unk3BC;
	u16 unk3BE;
	u16 unk3C0;
	u16 playerCollisionCooldown[2];
	SimplePlayerCollisionFlags simplePlayerCollisionResult;

	u16* objectRespawnTimer;

	u8 defeatRelated;
	u8 unk3CD;
	u8 decrement;
	u8 unk3CF;
	u8 unk3D0;
	u8 unk3D1;
	u8 unk3D2;
	u8 unk3D3;

	u8* objectSpawnFlags; // (re)spawn flags: 1 = created/exists, 8 = permanently destroyed

	u8 playerDirection;
	u8 hitCombo;

	u8 scoreEnhancement;
	u8 unk3DB;
	bool spawnedByCreateActorMaybe; // bool
	u8 unk3DD;

	u8 blockHitDirection;

	u8 killedRelated;
	bool permanentDelete;
	u8 unk3E1;
	u8 usedInLiquid;
	u8 unk3E3;

	bool disableDefeatRoll; // bool
	bool invisible; // bool

	bool ciroImmobile;
	u8 unk3E7;
	u8 unk3E8;
	u8 unk3E9;

	u8 defeatedDirection;
	u8 freezeRelated;
	bool backLayer;
	u8 unk3ED;
	s8 functionStep; // generic function step (where is it used??)
	u8 facing; // 0 = down, 1 = up, 2 = left, 3 = right


	// 0209dee0
	sym StageEntity() __body



	sym virtual s32 onUpdate() override __rbody
	// 0209dab8
	sym virtual bool preUpdate() override __rbody
	// 0209da90
	sym virtual void postUpdate(BaseReturnState state) override __body
	// 0209da58
	sym virtual bool preRender() override __rbody



	// D1: 020986e0
	// D0: 02098730
	__inline virtual ~StageEntity() {}



	// 02098788
	// sym static ObjectBank* getObjectBank(u32 objectID) __rbody

	// 02098798
	// sym u32 getSpritePriority - ???
	// 
	// 02098814
	// sym Vec3 tryNormalizeVec3(const Vec3& v) const __rbody

	// 020988ac clear bit at 020ca2b8 (const)
	// 020988d0 set bit at 020ca2b8 (const)

	// 020988f0
	sym void assignView(const Vec3& position) __body

	// 02098908
	sym bool isPlayerInZone(const Player& player, u32 zoneID) const __rbody

	// 02098998
	// sym u32 stopPlayerInShell(const ActiveCollider& collider, Player& player) const; - ???

	// 02098c78
	sym static void damagePlayerCallback(ActiveCollider& self, ActiveCollider& other) __body

	// 02098dd8
	sym static bool isBelowCamera(fx32 positionY, ActiveCollider& collider, u8 playerID) __rbody

	inline static bool isAboveCamera(fx32 positionY, ActiveCollider& collider, u8 playerID) {
		return -(positionY + collider.hitbox.rect.y + collider.hitbox.rect.halfHeight) > Stage::cameraY[playerID];
	}

	// 02098e08
	sym bool setGroundPoundCollision(const Player& player) __rbody

	// 02098fbc
	sym bool checkSquished() const __rbody

	// 02099040
	sym CollisionMgr::CollisionResult updateSideSensors() __rbody

	// 020990d4
	sym CollisionMgr::CollisionResult updateBottomSensor() __rbody

	// 0209917c
	sym bool checkLavaCollision() const __rbody

	// 020991f8
	sym CollisionResult updateCollisionSensors() __rbody
	
	// 02099250
	sym bool checkPlayersInOffset(fx32 x, fx32 y) const __rbody

	// 02099354
	sym bool checkPlayersInOffset(fx32 x) const __rbody

	// 020993ec
	sym bool rotateToTarget(s16 target[2], s16 step[2]) __rbody

	// 02099440
	sym void applyFireballWiggle() __body

	// 02099590
	sym static u16 getActorID(u16 objectID) __rbody

	// 020995a4
	sym void setTimedEvent(u32 eventID, s32 time, bool enable, bool switchEvent = false, bool playSFX = false) __body

	// 02099884
	sym void destroy(bool permanent) __body

	// 020998e4
	sym void updateBounce(fx32 velocityStopY, fx32 amountX, fx32 amountY) __body

	// 0209997c
	sym static void damageEntityCallback(ActiveCollider& self, ActiveCollider& other) __body

	// 02099b6c
	sym static void shellCallback(ActiveCollider& self, ActiveCollider& other) __body

	// 02099fb4
	sym static void simplePlayerCallback(ActiveCollider& self, ActiveCollider& other) __body

	// 0209a070
	// sym static void spawnBrokenPipe(u8 a, u8 b, u8 c) __body

	// 0209a0e8
	sym static u32 getRandom() __rbody

	// 0209a0f4
	sym u32 tryAttachToPlayerHands(fx32 z, fx32 y, fx32 x) __rbody

	// 0209a144
	sym void attachToPlayerHands(fx32 z, fx32 y, fx32 x) __body	  

	// 0209a23c (TODO)
	sym u32 updateSolidActiveCollider(u32 unk1, u32 flags, u8 playerID) __rbody

	// 0209a4f0

	// 0209a5bc
	sym void onPlayerStomp(Player& player, fx32 jumpVelocity, bool noPoints) __body

	// 0209a80c
	sym PlayerStompType updatePlayerStomp(ActiveCollider& collider, fx32 jumpVelocity, u32 unk1, bool noPoints) __rbody

	// 0209a938
	sym void getScorePointsSetB(u32 type, fx32 x, fx32 y, s32 playerID) const __body

	// 0209a990
	sym static void getScorePointsSetB(const Vec3& position, u32 type, s32 playerID) __body

	// 0209aa04
	sym void getScorePointsSetC(u32 type, fx32 x, fx32 y, s32 playerID) const __body

	// 0209aa5c
	sym static void getScorePointsSetC(const Vec3& position, u32 type, s32 playerID) __body

	// 0209aad0
	sym static void spawnRedCoinNumber(const Vec3& position, u32 coins, s32 playerID) __body

	// 0209ab04
	sym static void getCollectablePoints(u32 type, s32 playerID) __body

	// 0209ab90
	sym void getScorePointsSetA(u32 type, fx32 x, fx32 y, s32 playerID) const __body

	// 0209ac0c
	sym static void getScorePointsSetA(const Vec3& position, u32 type, s32 playerID) __body

	// 0209ac8c
	sym u8 getVerticalDirectionToPlayer(const Vec3& position) const __rbody

	// 0209acd4
	sym u8 getHorizontalDirectionToPlayer(const Vec3& position) const __rbody

	// 0209adb0
	sym bool destroyInactive(u32 flags) __rbody

	// 0209ae88
	sym static bool isOutOfView(const Vec3& position, const FxRect& rect, u8 viewID) __rbody

	/*--- small break here (Stage/StageScene functions) ---*/

	// 0209c590
	sym static u32 checkLiquidCollision(const Vec3& position, const Vec3& lastPosition, fx32 waveHeight, bool playSFX = true) __rbody

	// 0209c6d4
	sym bool updateLiquidPhysics(const Vec3& position, fx32 defaultAccelY) __rbody

	// 0209c7a0
	sym void updateLiquidCollision(const Vec3& position, fx32 defaultAccelY) __body

	// 0209c820
	sym u32 updateLiquids(fx32 defaultAccelY) __rbody

	// 0209c85c
	sym void applyMovement() __body

	// 0209ccd0
	sym bool setBlueShellCollision(const Player& player) __rbody

	// 0209cfc4
	sym void setStompCollision(const Player& player) __body

	// 0209d0ec (-> virt48)
	// 0209d240 (-> virt47, missing the trigger)

	// 0209d3d0
	sym bool setMegaCollision(const Player& player) __rbody

	// 0209d694
	sym void spawnCoin() __body

	// 0209d708 (-> virt52)

	// 0209d774
	sym bool setSlidingCollision(const Player& player) __rbody

	// 0209d7e0
	sym bool setStarmanCollision(const Player& player) __rbody

	// 0209ff98

	// 020a0048
	sym bool tryGrab(Player& player) __rbody

	// 020a01b4
	sym void fenceTurning() __body

	// 020a020c (-> fenceDisableCollision + updateState4)



	// 020a03a4
	sym virtual bool updateMain() __body

	// 0209ad1c
	// returns true if rendering should be skipped
	sym virtual bool skipRender() __rbody


	// 020a039c
	sym virtual bool updateState1() __body
	// 020a0304
	sym virtual bool updateDefeated() __body
	// 020a0274
	sym virtual bool updateDefeatedMega() __body
	// 020a01ac
	sym virtual bool updateState4() __body
	// 0209fb3c
	// Tries to attach the entity to the linked player's hands (if any) and handles released/thrown behavior. Has hardcoded code for bob-ombs lmao
	sym virtual bool updateGrabbed() __body
	// 0209fa8c
	sym virtual bool updateState6() __body
	// 0209f824
	sym virtual bool updateState7() __body
	// 0209f6c4
	sym virtual bool updateState8() __body
	// 0209f0e4
	sym virtual bool updateState9() __body


	// 0209d9fc
	sym virtual void updateAnimation() __body



	// 0209faf4
	sym virtual void thrown() __body // on shell kicked?
	// 0209faac
	sym virtual void stopped() __body
	// 0209c974
	sym virtual void virt34() __body
	// 020a012c
	sym virtual void grabbed() __body
	// 020a00ac
	sym virtual void release() __body
	// 0209f574
	sym virtual void virt37(Player& player) __body // 'do fast speed'
	// 0209f3d8
	sym virtual void virt38() __body
	// 0209f354
	sym virtual void virt39() __body


	// 020994f8
	sym virtual void updateFireballWiggle() __body



	// 0209d988
	sym virtual void onBlockHit() __body
	// 0209d920
	sym virtual void onEntityHit() __body
	// 0209d84c
	sym virtual void onFireballHit() __body
	// 0209d568
	sym virtual void onStarmanHit() __body
	// 0209d43c
	sym virtual void onSlidingHit() __body
	// 0209d2a0
	sym virtual void onMegaHit() __body
	// 0209d158
	// Never called, apparently some mega kick leftover from the beta?
	sym virtual void onMegaKicked() __body
	// 0209d014
	sym virtual void onSpinDrillHit() __body
	// 0209cfc0
	sym virtual void onStomped() __body
	// 0209ce08
	sym virtual void onGroundPound() __body
	// 0209cbf8
	sym virtual void onBlueShellHit() __body
	// 0209cad0
	sym virtual void onFenceSlamHit() __body
	// 02098f7c
	sym virtual void onMegaGroundPound() __body
	// 02098e7c
	sym virtual void onStageBeaten(Player& player) __body
	// 0209cd3c
	sym virtual void onFatalDamage() __body
	// 0209cac4
	sym virtual void onMegaWalkShockwave() __body
	// 0209cac0
	// Never triggered, use onMegaGroundPound instead
	sym virtual void onMegaGroundPoundShockwave() __body
	// 02099168
	sym virtual void stopMovement() __body



	// 02098a94
	sym virtual bool playerCollision(ActiveCollider& self, ActiveCollider& other) __rbody
	// 02098a90
	sym virtual void entityCollision(ActiveCollider& self, StageActor& actor) __body
	// 02098a10
	sym virtual void damagePlayer(ActiveCollider& self, Player& player) __body



	// 0209c9d0
	sym virtual void defeat(fx32 velX, fx32 velY, fx32 accelY, u8 unk) __body
	// 0209c994
	sym virtual void defeatMega(fx32 velX, fx32 velY, fx32 accelY) __body



	// 020a0268
	sym virtual void fenceDisableCollision() __body // removes the AC callback
	// 020a0240
	sym virtual void fenceSwitchDirection() __body // changes the AC callback to 'damagePlayerCallback'


	// 0209a6d4
	sym virtual void doPlayerJump(Player& player, fx32 jumpVelocity) __body



	/*
	virtual void executeState0();					// -
	virtual bool shouldNotRender();					// -
	virtual void executeState1();					// -
	virtual void afterDeath();						// -
	virtual void deathRollState();					// -
	virtual void executeState4();					// -
	virtual void executeState5();					// -
	virtual void executeState6();					// -
	virtual void executeState7();					// -
	virtual void executeState8();					// -
	virtual void executeState9();					// -
	virtual void updateAnimation();					// virt 31
	virtual void virt32();							// -
	virtual void virt33();							// -
	virtual void virt34();							// -
	virtual void onlyEnemyGetHurtCallback();		// virt 35 (?)
	virtual void virt36();							// actors remove themselves from the player linked actor
	virtual void virt37();							// actors remove themselves from the player linked actor
	virtual void virt38();							// collisionMgr (bottom ones i think) related
	virtual void virt39();							// collisionMgr related
	virtual void updateWiggleScale();				// virt 40
	virtual void blockCallback();					// virt 41
	virtual void stageEntityCallback();				// virt 42
	virtual void onFireballHit();					// virt 43
	virtual void virt44();							// hit from slope sliding maybe - starCallback in Ed_ITs db but not sure
	virtual void virt45();							// slidingCallback in Ed_ITs db but not sure
	virtual void onMegaHit();						// virt 46
	virtual void onStarmanHit();					// virt 47
	virtual void virt48();							// -
	virtual void onStomped();						// virt 49
	virtual void onGroundpound();					// virt 50
	virtual void onPlayerShellHit();				// virt 51
	virtual void virt52();							// -
	virtual void onMegaGroundpound();				// virt 53
	virtual void onLevelBeaten();					// virt 54
	virtual void lavaCallback();					// virt 55
	virtual void virt56();							// -
	virtual void onBossDefeated();					// virt 57
	virtual void stopMovement();					// virt 58 (?)
	virtual void virt59();							// -
	virtual void virt60();							// -
	virtual void onPlayerCollision();				// virt 61
	virtual void onKilled();						// virt 62
	virtual void onKilledByMega();					// virt 63
	virtual void removeCallback();					// virt 64 (?)
	virtual void changeDirection();					// virt 65
	virtual void makePlayerJump();					// virt 66 (?)
	*/

	//// 0209C85C
	//GEN_FUNC( void applyMovement )

	//// 020991f8
	//GEN_FUNC( u32 updateTileCollision )

	//// 0209c820
	//GEN_FUNC( u32 updateLiquids, fx32 defaultAccelY )

	//// 0209adb0
	//GEN_FUNC( bool deleteIfOutOfRange, u32 flags )

	//bool isPlayerInOffset(fx32 xOff, fx32 yOff);
	//void dropCoins();

};
static_assert(sizeof(StageEntity) == 0x3F4, "");

IMPL_ENUMCLASS_OPERATORS(StageEntity::CollisionResult);
