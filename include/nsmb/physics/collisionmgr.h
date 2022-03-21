#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"


class StageActor;
class PlatformMgr;
class Collider;


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

	enum class CollisionResult : u32
	{
		WallClipRight			= (1U << 0),
		WallClipLeft			= (1U << 1),
		WallRight				= (1U << 2),
		WallLeft				= (1U << 3),
		WallFullRight			= (1U << 4),
		WallFullLeft			= (1U << 5),

		Ground40				= (1U << 6),	// ???
		Unk80					= (1U << 7),	// ???????
		GroundTile				= (1U << 8),
		GroundSlope				= (1U << 9),
		GroundPlatform			= (1U << 10),
		Ground800				= (1U << 11), // ???
		GroundCollider			= (1U << 12),

		Ceiling					= (1U << 13),
		CeilingSlope			= (1U << 14),
		CeilingPartial			= (1U << 15),

		Unk10000				= (1U << 16),
		Unk20000				= (1U << 17),
		Unk40000				= (1U << 18),
		Unk80000				= (1U << 19),
		CeilingBlockDestroyed	= (1U << 20),
		Unk200000				= (1U << 21),
		Collectable				= (1U << 22),
		Unk800000				= (1U << 23),
		Unk1000000				= (1U << 24),
		Unk2000000				= (1U << 25),
		Unk4000000				= (1U << 26),
		Unk8000000				= (1U << 27),
		GroundBlockDestroyed	= (1U << 28),
		Breakable				= (1U << 29),
		NotifySolidOnTop		= (1U << 30),
		CeilingBlockActivated	= (1U << 31),


		WallRightAny			= WallClipRight	| WallRight	| WallFullRight,
		WallLeftAny				= WallClipLeft	| WallLeft	| WallFullLeft,
		WallAny					= WallRightAny | WallLeftAny,

		TileGroundAny			= Ground40 | GroundTile | GroundSlope | GroundCollider,
		ActorGroundAny			= Ground40 | GroundPlatform | Ground800 | GroundCollider,
		GroundAny				= ActorGroundAny | TileGroundAny,

		CeilingAny				= Ceiling | CeilingSlope | CeilingPartial,

		SolidAny				= WallAny | GroundAny | CeilingAny

	};

	enum class SlopeType : u8
	{
		Up1x1,
		Down1x1,
		Up2x1Part1,
		Up2x1Part2,
		Down2x1Part1,
		Down2x1Part2,
		Up1x2Part1,
		Up1x2Part2,
		Down1x2Part1,
		Down1x2Part2,
		Edge,
		Up4x1Part1,
		Up4x1Part2,
		Up4x1Part3,
		Up4x1Part4,
		Down4x1Part1,
		Down4x1Part2,
		Down4x1Part3,
		Down4x1Part4,
	};


	StageActor* owner;

	CollisionSensor* bottomSensor;
	CollisionSensor* topSensor;
	CollisionSensor* sideSensor;

	u32 unk14;

	Vec3* linkedPosition;
	Vec3* linkedVelocity;
	u8* linkedPlayerID;
	PlatformMgr* linkedPlatformMgr;

	CollisionMgr* next[3];

	Collider* head[3];
	Collider* colliders[3];

	u32 unk4C;
	u32 unk50;

	Vec3 appliedForce;
	Vec2 lastPosition;
	Vec2 positionStep;

	CollisionResult collisionResult;
	u32 unk80;
	u32 bottomTileBehavior;
	u32 tileBelowY;
	u16 surfaceAngle;
	u8 playerID;
	u8 unk8F;

	u16 tileX;
	u16 tileY;

	u16 tileX2;
	u16 tileY2;

	u16 bottomModifierFlags;
	u8 bottomModifier;
	u8 lastBottomModifier;

	u16 topModifierFlags;
	u8 topModifier;
	u8 lastTopModifier;

	u16 sideModifierFlags[2];
	u8 sideModifier[2];
	u8 lastSideModifier[2];

	u8 unkA8;
	SlopeType groundSlopeType;
	SlopeType ceilingSlopeType;

	u8 parentDirection;
	u8 moreBits;
	u8 surfaceDirection;
	u8 moveDirection;
	u8 unkAF;
	u8 someBits;	// harmfulFlags
	u8 harmfulTileType;
	u8 unkB2;
	u8 slopeDirectionMaybe;
	u8 slowMovementMaybe;
	u8 lastSlowMovementMaybe;
	u8 unkB6;
	u8 backLayerFlag;

	sym CollisionMgr() __body

	sym virtual ~CollisionMgr() __body

	// 020ab010
	// TODO: const CollisionSensor*?
	sym void init(StageActor* owner, CollisionSensor* botSensor, CollisionSensor* topSensor, CollisionSensor* sideSensor, u32 unk) __body

	// 01FFF93C
	CollisionResult updateBottomSensor(u32 unk);

	// 01FFE778
	CollisionResult updateSideSensors(fx32* velocityX, u32 sensorFlags);

	// 01FFE730
	CollisionResult updateSidePointSensor(PointSensor* sensor, u32 direction, u32 sensorFlags);

	// 01FFE660
	CollisionResult updateSideLineSensor(LineSensorV* sensor, u32 direction, u32 sensorFlags);

	// 020A917C
	CollisionResult updateGroundCollision();

	// 020A915C
	CollisionResult updateWallCollision(fx32* velocityX, u32 flags);

	// 020AA990
	CollisionResult updateTopSensor(u32 unk);

	// 020A6D18
	static u32 getBottomTileBehavior(fx32 x, fx32 y);

};

using CollisionMgrResult = CollisionMgr::CollisionResult;

IMPL_ENUMCLASS_OPERATORS(CollisionMgrResult);
