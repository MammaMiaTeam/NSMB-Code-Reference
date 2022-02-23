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
		WallOverlapRight		= (1U << 0),
		WallOverlapLeft			= (1U << 1),
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
		Ceiling4000				= (1U << 14), // ???
		Ceiling8000				= (1U << 15), // ???

		Unk10000				= (1U << 16),
		Unk20000				= (1U << 17),
		Unk40000				= (1U << 18),
		Unk80000				= (1U << 19),
		Unk100000				= (1U << 20), // ???????
		Unk200000				= (1U << 21),
		Collectable				= (1U << 22),
		Unk800000				= (1U << 23),
		Unk1000000				= (1U << 24),
		Unk2000000				= (1U << 25),
		Unk4000000				= (1U << 26),
		Unk8000000				= (1U << 27),
		Unk10000000				= (1U << 28),
		Breakable				= (1U << 29),
		Unk40000000				= (1U << 30),
		Unk80000000				= (1U << 31),


		WallRightAny			= WallOverlapRight	| WallRight	| WallFullRight,
		WallLeftAny				= WallOverlapLeft	| WallLeft	| WallFullLeft,

		ActorGroundAny			= Ground40 | GroundPlatform | Ground800 | GroundCollider,
		TileGroundAny			= Ground40 | GroundTile | GroundSlope | GroundCollider,
		GroundAny				= ActorGroundAny | TileGroundAny,

		CeilingAny				= Ceiling | Ceiling4000 | Ceiling8000,

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


	// reference to parent
	StageActor* owner;

	// references to collision sensors
	CollisionSensor* botSensor;
	CollisionSensor* topSensor;
	CollisionSensor* sideSensor;

	u32 unk14;

	// references to parent properties 
	Vec3* ownerPosition;
	Vec3* ownerVelocity;
	u8* ownerPlayerID;

	// reference to PlatformMgr
	PlatformMgr* pPlatformMgr;

	u32 unk28;
	u32 unk2C;
	u32 xDeltaMaybe;
	u32 yDeltaMaybe;
	u32 unk38;
	u32 unk3C;
	void* unk40; // anonSolidTop?
	Collider* anonSolidBottom;
	Collider* anonSolidSide;
	u32 unk4C;
	u32 unk50;

	// physics
	Vec3 gravityParent;
	Vec2 parentPOS;
	Vec2 unkV3;

	// physics behaviors
	CollisionResult collisionResult;
	u32 unk2_2;
	u32 botTileBehavior;

	// position of tile below actor
	u32 tileBelowY;

	// physics calculations
	u16 someOtherBits;
	u8 playerID;
	u8 unk8F;
	u8 unk90;
	u8 unk91;
	u8 unk92;
	u8 unk93;

	s16 tileX;
	s16 tileY;

	u16 unk98;
	u8 smth;
	u8 oldSmth;
	u32 unk9C;
	u32 unkA0;
	u8 unkA4[2];
	u8 oldUnkA4[2];
	u8 velXMaybe;
	SlopeType slopeType;
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
	CollisionResult updateWallCollision();

};

IMPL_ENUMCLASS_OPERATORS(CollisionMgr::CollisionResult);
