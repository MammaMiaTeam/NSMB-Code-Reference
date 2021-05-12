#pragma once
#include "nitro_if.h"
#include "nsmb/vector.h"
#include "nsmb/oam.h"

#define isDSiMode			((*((u8*)0x4004000)) & 1)

#define buttonsHeldAddr		((u16*)0x02087650)
#define buttonsPressedAddr	((u16*)0x02087652)
#define penDownAddr			((bool*)0x20888E5)
#define penXAddr			((u8*)0x20888E6)	
#define penYAddr			((u8*)0x20888E7)

#define PAD_TP				((u16)0x1000)														// lets us treat the touchpad as a normal key

#define buttonsHeld			(*buttonsHeldAddr)													// set until released
#define buttonsPressed		(*buttonsPressedAddr)												// cleared after one frame
#define buttonsDown			(buttonsHeld | buttonsPressed)										// both at the same time
#define buttonsUp			(~buttonsDown & (PAD_ALL_MASK | PAD_DETECT_FOLD_MASK | PAD_TP))		// buttons not down

#define penDown				(*penDownAddr)														// touchpad being touched
#define penX				(*penXAddr)															// calibrated touchpad X
#define penY				(*penYAddr)															// calibrated touchpad Y

extern "C" int strlen(const char* __s);

// 0200765c
GEN_SFUNC(void storeDataCache, const void* ptr, u32 size)

// 02007684
GEN_SFUNC(void flushDataCache, const void* ptr, u32 size)

// 02004c30
GEN_SFUNC(BOOL taskCleanup)


typedef void (*TaskFunc)(void*);

// 02004cb8
GEN_SFUNC(void runTask, TaskFunc func, void* arg, u32 prio, void* stack, u32 stackSize)


struct FxRect {
	fx32 x;
	fx32 y;
	fx32 halfWidth;
	fx32 halfHeight;
};

class Player;

struct StageBlocks {
	void* header;
	void* camera;
	void* background;
	void* tileset;
	void* foreground;
	void* entrances;
	void* sprites;
	void* views;
	void* zones;
	void* progressPaths;
	void* paths;
	void* pathNodes;
	void* progressPathNodes;
	void* spriteBanks;

	inline void* operator[] (int i) {
		SDK_ASSERT(i >= 0 && i < StageBlockID::Max);
		return reinterpret_cast<void**>(&header) + i;
	}
};

struct StageBlockID {
	enum : u32 {
		Header,
		Camera,
		Background,
		Tileset,
		Foreground,
		Entrances,
		Sprites,
		Views,
		Zones,
		ProgressPaths,
		Paths,
		PathNodes,
		ProgressPathNodes,
		SpriteBanks,

		Max
	};
};


class Fireball;
class FireballHandler;


namespace Game {

	// 02129484
	extern FireballHandler* fireballHandler;

	// 02085a88
	extern u32 visiblePlaneMain;

	// 020CA2E4
	extern u32 cameraY;

	// 020CA2EC
	extern u32 cameraX;

	// 02085A84
	extern u8 vsMode;

	// 0208af3c
	extern u64 events;

	// 02085A50
	extern bool luigiMode;

	// 02085a1c
	extern bool checkpointCollected;

	// 02085a9c
	extern u32 currentWorldmapNode;

	extern MtxFx43 modelMatrix;
	extern MtxFx43 viewMatrix;

	// 0208b168
	extern StageBlocks stageBlocks;

	// 0200514c
	void resetSystem(u32 param);

	// 0200421c
	GEN_SFUNC(bool drawBNCLSprite, u8 id, GXOamAttr* oamAttrs, u32 flags, u8 palette, u8 affineSet, Vec2* scale, s16 rot, s16(*rotCenter)[2], u32 settings, s32 x, s32 y)

	// 0200419c
	GEN_SFUNC(bool drawBNCLSpriteSub, u8 id, GXOamAttr* oamAttrs, u32 flags, u8 palette, u8 affineSet, Vec2* scale, s16 rot, s16(*rotCenter)[2], u32 settings, s32 x, s32 y)


	// 0x02004dfc
	GEN_SFUNC(void initExtendedIDs);

	// 0x020058c0
	GEN_SFUNC(void waitVBlankIntr)

	// 0x02004be0
	GEN_SFUNC(void disableVRAMBanks)

	// 0x0200696c
	void loadLevel(u16 scene, u32 vs, u8 group, u8 stage, u8 act, u8 playerNo, u8 playerMask, u8 character1, u8 character2, u8 powerup, u8 entrance, u8 flag, u8 unused1, u8 controlOptions, u8 unused2, u8 challengeMode, u32 rngSeed);

	// 0x0200563c
	u16 getBootScene();

	// 0x0200564c
	void setBootScene(u16 sceneID);


	// 020066f8
	GEN_SFUNC( void resetCheckpointStage )

	// 02006740
	GEN_SFUNC( void setCheckpointStage )

	// 02006790
	GEN_SFUNC( bool getCheckpointStage )

	// 020202a0
	u32 getPlayerCount();

	// 020202b0
	void setPlayerCount(u32 count);

	// 020205ec
	GEN_SFUNC( Player* getCurrentPlayer )

	// 02020608
	GEN_SFUNC( Player* getPlayer, long playerNo )

	// 02020618
	GEN_SFUNC( Player* setPlayer, long playerNo, Player* player)


	static bool getEvent(u8 id) {
		if (id >= 1 && id <= 64) {
			return events & (1ULL << (id - 1));
		}
		return false;
	}
	
	static void setEvent(u8 id) {
		if (id >= 1 && id <= 64) {
			events |= 1ULL << (id - 1);
		}
	}
	
	static void clearEvent(u8 id)	{
		if (id >= 1 && id <= 64) {
			events &= ~(1ULL << (id - 1));
		}
	}


	// 0200dee0
	GEN_SFUNC(void spriteBankOverlayProc, void* banks, bool load)


	inline void unloadSpriteBankOverlays(void* banks) {
		spriteBankOverlayProc(banks, false);
	}
	inline void loadSpriteBankOverlays(void* banks) {
		spriteBankOverlayProc(banks, true);
	}

	// 02020260
	GEN_SFUNC(u8 getPlayerCharacter, s32 playerNo)

	// 02020270
	GEN_SFUNC(void setPlayerCharacter, s32 playerNo, u8 characterID)

	// 02020570
	GEN_SFUNC(u8 getPlayerLives, s32 playerNo)

	// 02020580
	GEN_SFUNC(void setPlayerLives, s32 playerNo, s32 lives)

	// 020a04c0
	void adjustModelTransform(Vec3* pos, Vec3s* rot, u32 mode);

}

class Base;
class Object;
class Actor;
class StageActor;
class CollisionMgr;
class PlatformMgr;
class ActiveCollider;
class PlatformBase;
class BalancedPlatform;

struct CollisionSensor {
	u32 flags;		// 0 = point, 1 = line
};

struct PointSensor : CollisionSensor
{
	fx32 x;			// Negative = left
	fx32 y;			// Negative = down
};

struct LineSensorH : CollisionSensor
{
	fx32 left;
	fx32 right;
	fx32 y;			// Negative = down
};

struct LineSensorV : CollisionSensor
{
	fx32 top;
	fx32 bottom;
	fx32 x;			// Negative = left
};

class CollisionMgr {

public:
	// reference to parent
	StageActor* owner;

	// references to collision sensors
	CollisionSensor* botSensor;
	CollisionSensor* topSensor;
	CollisionSensor* sideSensor;

	u32 UNK;

	// references to parent properties 
	Vec3* parent_pos_ptr;
	Vec3* parent_velocity_ptr;
	u8* playerNumber;

	// reference to PlatformMgr
	PlatformMgr* pPlatformMgr;

	u32 unk1_6;
	u32 unk1_7;
	u32 xDeltaMaybe;
	u32 yDeltaMaybe;
	u32 unk1_10;
	u32 unk1_11;
	void* unkPTR;
	u32 unk1_13;
	u32 unk1_14;
	u32 unk1_15;
	u32 unk1_16;

	// physics
	Vec3 gravityParent;
	Vec2 parentPOS;
	Vec2 unkV3;

	// physics behaviors
	u32 collisionBitfield;
	u32 unk2_2;
	u32 botTileBehavior;

	// position of tile below actor
	u32 tileBelowY;

	// physics calculations
	u16 someOtherBits;
	u8 player;
	u8 unk2_4_1;
	u8 unk2_5;
	u8 unk2_5_1;
	u8 unk2_6;
	u8 unk2_6_1;
	u32 unk2_7;
	u16 setToZero;
	u8 newSmth;
	u8 oldSmth;
	u32 unk2_9;
	u32 unk2_10;
	u16 unk2_11;
	u16 unk2_12;
	u8 VelXMaybe;
	u8 slopeDirection;
	u8 solidTileBehavior;
	u8 parentDirection;
	u8 moreBits;
	u8 unk2_17;
	u8 unk2_18;
	u8 unk2_19;
	u8 someBits;
	u8 someDirectionMaybe;
	u8 unk2_22;
	u8 slopeDirectionMaybe;
	u8 slowMovementMaybe;
	u8 oldThing;
	u8 slopeRelated;
	u8 unk2_27;

	GEN_FUNC( CollisionMgr );

	GEN_FUNC( virtual ~CollisionMgr );

	// 020ab010
	GEN_FUNC( void init, StageActor* owner, CollisionSensor* botSensor, CollisionSensor* topSensor, CollisionSensor* sideSensor, u32 unk )
};

class PlatformMgr {
public:
	// reference to parent
	StageActor* owner;

	// reference to parent's position vector
	Vec3* parentPos;

	// Platform list
	PlatformMgr* next;
	PlatformBase* prev; // WTF is going on here????
	PlatformBase* obj;

	// reference to CollisionMgr
	CollisionMgr* pCollMgr;

	// physics calculations
	Vec2 collisionPositionMaybe;
	u32 distance;
	u16 angle;
	u16 unk1;

	u8 unk2[4];

	GEN_FUNC( PlatformMgr );

	GEN_FUNC( virtual ~PlatformMgr );

};


typedef void (*ActiveColliderCallback) (ActiveCollider* self, ActiveCollider* collision);

struct ActiveColliderInfo {
	fx32 offsetX;
	fx32 offsetY;
	fx32 sizeX;
	fx32 sizeY;

	u8 collisionGroup; // 0-9
	u8 damageEnemies;
	u16 behaviorB;

	s16 flagsA;
	s16 flagsB;

	ActiveColliderCallback callback;
};

class ActiveCollider {
public:

	enum Shape : u8 {
		Rectangle,
		Round,
		TrapezoidV,
		TrapezoidH,
	};

	StageActor* owner;
	u32 unk0;

	// list
	struct {
		ActiveCollider* prev;
		ActiveCollider* first;
	} list;

	// hitbox properties
	FxRect rect;

	// hitbox behaviors
	u8 collisionGroup;
	u8 damageEnemy;
	u16 behaviorB;
	u16 flagsA;
	u16 flagsB;

	// collision callback
	void* callback;

	// position info
	Vec2 position;

	s32 XcontactPos[10];
	s32 YcontactPos[10];

	// trapezoid properties
	struct {
		u32 topLeftX;
		u32 topRightX;
		u32 botLeftX;
		u32 botRightX;
	} trapezoid;

	// physics calculations
	u32 to_info_used;
	u16 collisionBehaviorA;
	u16 collisionFlags;

	bool backLayer;				// if set, the collider will only interact with other colliders that are behind the main layer

	u8 someCollision;
	u8 collisionResult;			// 0x2 is set when a collision occurs, 0x3 = stop updating
	u8 collisionPlayerNumber;

	// misc
	bool linked; // bool

	u8 unk9;
	u8 shape;
	u8 unk10;
	u16 oldCollisionBehaviorA;
	u16 unk12;

	// 020a4868
	GEN_FUNC( ActiveCollider )

	// D1: 020a484c
	// D0: 020a4820
	GEN_FUNC( virtual ~ActiveCollider )

	// 020a4808
	GEN_FUNC( void reset )

	// 020a47a0
	GEN_FUNC( void init, StageActor* owner, ActiveColliderInfo* info, bool backLayer)

	// 020a4758
	GEN_FUNC( void setPositionAroundPivot, u16 rotation, fx32 pivotX, fx32 pivotY )

	// 020a4714
	GEN_FUNC( void resetCollisionState )

	// 020a46bc
	GEN_FUNC( void link )

	// 020a4658
	GEN_FUNC( void unlink )

	// 020a44b0
	GEN_FUNC( void unk_020a44b0 )

	// 020a445c
	GEN_FUNC( void unk_020a445c, Vec3* position, ActiveColliderInfo* info, bool backLayer, u32 unk)

	// 020a4434
	GEN_FUNC( static void initSystem )

protected:

	// 01ffdd88
	GEN_FUNC( bool testCollisionRect, ActiveCollider* collision )

	// 020a4344
	GEN_FUNC( bool testCollisionRound, ActiveCollider* collision )

	// 020a4328
	//GEN_FUNC( bool unk_020a4328, ActiveCollider* collision )

	// 020a4264
	GEN_FUNC( bool testCollisionOtherVsVTrpz, ActiveCollider* collision )

	// 020a40a4
	GEN_FUNC( bool testCollisionVTrpzVsOther, ActiveCollider* collision )

	// 020a3fc4
	GEN_FUNC( bool testCollisionOtherVsHTrpz, ActiveCollider* collision )

	// 020a3e04
	GEN_FUNC( bool testCollisionHTrpzVsOther, ActiveCollider* collision )
};


enum PlatformType
{
	P_DEFAULT,		// normal
	P_RIGHT = 0,	// balanced on the right
	P_CENTER,		// balanced on the center
	P_LEFT,			// balanced on the left
	P_UNK1,			// idk
	P_UNK2,			// ^
	P_COMPLEX,		// used for tightropes
	P_ROUND			// round (undocumented)
};

class PlatformBase {
public:
	// reference to parent
	Base* owner;

	// list
	struct {
		PlatformBase* prev;
		PlatformBase* first;
	} list;

	// reference to parent's PlatformMgr
	PlatformMgr* manager;

	// physics calculations
	Vec2 pointEnd;
	Vec2 pointStart;
	Vec2 pointStep;
	Vec2 lastStart;

	fx32 length;
	fx32 force;

	s16 angle;
	u16 flags;

	u8 type;
	u8 unk51;
	bool linked;
	u8 groupID;

	u8 unk54[4];

	PlatformBase();
	virtual ~PlatformBase();

	virtual void update();
	virtual void resolveCollision();
	virtual void func5();

	void reset();
	void link();
	void unlink();
};

class SegmentPlatform : public PlatformBase
{
public:
	Vec2 start;
	Vec2 end;

	SegmentPlatform();
	inline virtual ~SegmentPlatform();

	void init(StageActor* owner, Vec2* a, Vec2* b);
	void init(StageActor* owner, fx32 ax, fx32 ay, fx32 bx, fx32 by);

	void setPoints(Vec2* a, Vec2* b);
	void setPoints(fx32 ax, fx32 ay, fx32 bx, fx32 by);

	void update() override;
};


struct RotatingPlatformInfo {
	fx32 x;
	fx32 y;
	fx32 height;
	fx32 right;
	fx32 left;
	s16 angle;
	u8 unused;
};

class RotatingPlatform : public PlatformBase
{
public:
	Vec2 center;
	fx32 height;
	fx32 right;
	fx32 left;

	RotatingPlatform();
	inline virtual ~RotatingPlatform();

	void init(StageActor* owner, fx32 x, fx32 y, fx32 height, fx32 right, fx32 left, s16 angle, u8 unk, Vec3* scale);
	void init(StageActor* owner, RotatingPlatformInfo* info, Vec3* scale);

	void setHeight(fx32 height, fx32 scale);
	void setRight(fx32 right);
	void setLeft(fx32 left);
	void setBase(fx32 left, fx32 right);

	void update() override;
};

class RoundPlatform : public PlatformBase {
public:
	Vec2 center;
	Vec2 unk64;
	Vec2 unk70;
	fx32 radius;
	fx32 unk80;
	fx32 unk84;
	s16 calcAngle;
	u8 unk8a;
	u8 unk8b;

	RoundPlatform();
	inline virtual ~RoundPlatform();

	void init(StageActor* actor, fx32 radius, fx32 centerX, fx32 centerY, fx32 uX, fx32 uY, s16 angle, s32 unk1, s32 unk2, bool externalCollision);

	void update() override;
	void resolveCollision() override;
	void func5() override;
};
