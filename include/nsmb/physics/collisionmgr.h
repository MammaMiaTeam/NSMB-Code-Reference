#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"
#include "nsmb/util.h"


enum class ActorType : u8;
class Player;
class StageActor;
class PlatformMgr;
class Collider;


enum class DamageTileType : s8
{

	None = -1,
	SpikesLeft,
	SpikesRight,
	SpikesUp,
	SpikesDown,
	Lava,
	Poison,
	Crushed,
	Hit

};

enum class DamageTileFlags : u8
{

	None,
	Bottom	= 0x01,
	Top		= 0x02,
	Right	= 0x04,
	Left	= 0x08,
	Immune	= 0x80

};

IMPL_ENUMCLASS_OPERATORS(DamageTileFlags);

// TODO: move somewhere else (liquid.h)
enum class LiquidType
{

	None,
	Water,
	Lava,
	JungleFG,
	Poison

};

enum class TileModifier : u8
{

	None,
	Ice,
	Snow,
	Quicksand,
	ConveyorBeltRight,
	ConveyorBeltLeft,
	Rope,
	SideSpikesStairs,
	Unknown8,
	Ledge,
	Pole,
	NoSliding,
	Slow,
	Unknown13,
	Sand,
	Unknown15

};

IMPL_ENUMCLASS_OPERATORS(TileModifier);

struct TileType
{
	using Modifier = TileModifier;

	static constexpr u32 Solid					= 0x00010000;
	static constexpr u32 Coin					= 0x00020000;
	static constexpr u32 QuestionBlock			= 0x00040000;
	static constexpr u32 BreakableBlock			= 0x00080000;
	static constexpr u32 BrickBlock				= 0x00100000;
	static constexpr u32 Slope					= 0x00200000;
	static constexpr u32 CeilingSlope			= 0x00400000;
	static constexpr u32 Entrance				= 0x01000000;
	static constexpr u32 Water					= 0x02000000;
	static constexpr u32 Climbable				= 0x04000000;
	static constexpr u32 PartialSolid			= 0x08000000;
	static constexpr u32 Harmful				= 0x10000000;
	static constexpr u32 InvisibleBlock			= 0x20000000;
	static constexpr u32 SolidOnBottom			= 0x40000000;
	static constexpr u32 SolidOnTop				= 0x80000000;

	static constexpr u32 ModifierMask			= 0x0000F000;
	static constexpr u32 ModifierShift			= 12;

	static constexpr u32 SolidMask				= Solid | BreakableBlock | BrickBlock | 0x80 | PartialSolid;
	static constexpr u32 SolidMaskBottom		= SolidMask | SolidOnBottom;
	static constexpr u32 SolidMaskTop			= SolidMask | SolidOnTop;
	static constexpr u32 StorageBlockMask		= QuestionBlock | BrickBlock;

	static constexpr u32 StorageContentsMask	= 0x00000C3F;

	// Entrance types
	static constexpr u32 Pipe					= Solid | Entrance;
	static constexpr u32 PipeJoint				= Pipe | 31;


	constexpr TileType() : value(0) {}
	constexpr TileType(u32 value) : value(value) {}

	constexpr static TileType fromModifier(Modifier modifier) {
		return TileType(u32(modifier) << ModifierShift);
	}

	constexpr Modifier getModifier() const {
		return Modifier((value & ModifierMask) >> ModifierShift);
	}

	constexpr void setModifier(Modifier modifier) {
		value = (value & ~ModifierMask) | (u32(modifier) << ModifierShift);
	}

	constexpr operator u32() const {
		return value;
	}


	u32 value;

};


class BlockTrigger {
public:

	NTR_INLINE bool valid() {
		return tileType != 0;
	}

	NTR_INLINE void triggerQuestionBlock() {

		ntr_force_assert("Not implemented");

		// TODO!!
		if (tileType & TileType::QuestionBlock) {
			//Stage::hitBlock(...)
		}

		tileType = 0;

	}

	fx32 x, y;
	TileType tileType;

};


class CollisionMgr {
public:

	// SurfaceDirection
	static constexpr u8 Up		= 0;
	static constexpr u8 Left	= 1;
	static constexpr u8 Down	= 2;
	static constexpr u8 Right	= 3;

	enum class Modifier : u8
	{

		ConveyorBeltRight,
		ConveyorBeltLeft,
		Rope,
		None,
		Quicksand,
		Ice,
		SideSpikesStairs,
		Unknown8,
		Ledge,
		Pole,
		NoSliding,
		Slow,
		Unknown13,
		Snow,
		Sand,
		Unknown15

	};

	enum class Result : u32
	{

		None = 0,

		WallClipRight			= (1U << 0),
		WallClipLeft			= (1U << 1),
		WallRight				= (1U << 2),
		WallLeft				= (1U << 3),
		WallFullRight			= (1U << 4),
		WallFullLeft			= (1U << 5),

		Ground40				= (1U << 6), // Set by Colliders with optionFlag set to 128
		Unk80					= (1U << 7), // ???????
		GroundTile				= (1U << 8),
		GroundSlope				= (1U << 9),
		GroundPlatform			= (1U << 10),
		GroundDeforming			= (1U << 11), // Tightrope, but also any other DeformingPlatform
		GroundCollider			= (1U << 12),

		Ceiling					= (1U << 13),
		CeilingSlope			= (1U << 14),
		CeilingPartial			= (1U << 15),

		ClimbableTopLeft		= (1U << 16),
		ClimbableTopRight		= (1U << 17),
		ClimbableBottomLeft		= (1U << 18),
		ClimbableBottomRight	= (1U << 19),
		CeilingBlockDestroyed	= (1U << 20),
		Unk200000				= (1U << 21),
		Collectable				= (1U << 22),
		Pole					= (1U << 23),
		OneUpBrickHitAboveSuper	= (1U << 24), // Just why does this exist
		Unk2000000				= (1U << 25),
		Tightrope				= (1U << 26), // I have a feeling this is also set by any other DeformingPlatform
		Unk8000000				= (1U << 27),
		BrickHitSuper			= (1U << 28), // Ground only?
		Breakable				= (1U << 29), // Where is this set?
		NotifySolidOnTop		= (1U << 30),
		NotifyBlockActivated	= (1U << 31), // Ceiling only?


		WallRightAny			= WallClipRight	| WallRight	| WallFullRight,
		WallLeftAny				= WallClipLeft	| WallLeft	| WallFullLeft,
		WallAny					= WallRightAny | WallLeftAny,

		TileGroundAny			= Ground40 | GroundTile | GroundSlope,
		ActorGroundAny			= Ground40 | GroundPlatform | GroundDeforming | GroundCollider,
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
		Down4x1Part4

	};

	enum class SlopeDirection : u32
	{

		Descending,
		Ascending,
		Invalid

	};

	enum class RaycastDirection : u8
	{

		Down,
		Up,
		Right,
		Left

	};

	enum class SensorFlags : u32
	{

		None = 0,
		Line						= 1U << 0,
		IgnoreColliders				= 1U << 9,
		FlipSlopes					= 1U << 10,
		DestroyPipesBottom			= 1U << 11, // TODO
		DestroyPipesTop				= 1U << 12, // TODO
		DestroyTiles				= 1U << 13,
		DestroyTilesUnk				= 1U << 14, // TODO
		SlopeUnkBehavior			= 1U << 15, // TODO
		IgnoreConveyorBelts			= 1U << 16,
		IgnoreQuicksand				= 1U << 17,
		ActivateCoinsFromBelow		= 1U << 19,
		ActivateCoins				= 1U << 20,
		ActivateCoinOutlines		= 1U << 21,
		ActivateQuestionBlocks		= 1U << 22,
		ActivateFallingBlocks		= 1U << 23,
		ActivateBricksSmall			= 1U << 24,
		ActivateBricksSuper			= 1U << 25,
		PlayMegaDestructionSFX		= 1U << 26,
		ActivateEmptyBricksUnk		= 1U << 27, // TODO
		PassThroughDestroyedTiles	= 1U << 28,
		SlopeCheck					= 1U << 29, // TODO
		IgnoreFallingBlockOrSlopes	= 1U << 30, // TODO
		IgnoreSlopesUnk				= 1U << 31, // TODO

	};

	struct Sensor {

		constexpr Sensor(SensorFlags flags) :
			flags(flags)
		{}

		SensorFlags flags;

	};
	
	struct PointSensor : Sensor
	{
		constexpr PointSensor(fx32 x = 0, fx32 y = 0, SensorFlags flags = SensorFlags::None);

		fx32 x;			// Negative = left
		fx32 y;			// Negative = down

	};
	
	struct LineSensorH : Sensor
	{
		constexpr LineSensorH(fx32 left = 0, fx32 right = 0, fx32 y = 0, SensorFlags flags = SensorFlags::Line);

		fx32 left;
		fx32 right;
		fx32 y;			// Negative = down

	};
		
	struct LineSensorV : Sensor
	{
		constexpr LineSensorV(fx32 top = 0, fx32 bottom = 0, fx32 x = 0, SensorFlags flags = SensorFlags::Line);

		fx32 top;
		fx32 bottom;
		fx32 x;			// Negative = left

	};

	using SolverFunction = Result(CollisionMgr::*)(SensorFlags flags, fx32 wrapOffset);
	using SideSolverFunction = Result(CollisionMgr::*)(SensorFlags flags, u8 direction, fx32 wrapOffset);
	using AttachedFunction = Result(CollisionMgr::*)();
	using ModifierFunction = void(CollisionMgr::*)();


	// 020ACCE4
	static void setupColliderInterworking();

	// 020ACC78
	Result updateColliderTopWrap(SensorFlags flags, fx32 wrapOffset = 0);
	// 020AC7BC
	Result updateColliderTop(SensorFlags flags, fx32 wrapOffset = 0);
	// 020AC750
	Result updateColliderBottomWrap(SensorFlags flags, fx32 wrapOffset = 0);
	// 020AC288
	Result updateColliderBottom(SensorFlags flags, fx32 wrapOffset = 0);
	// 020AC21C
	Result updateColliderSideWrap(SensorFlags flags, u8 direction, fx32 wrapOffset = 0);
	// 020ABCFC
	Result updateColliderSide(SensorFlags flags, u8 direction, fx32 wrapOffset = 0);
	// 020ABC90
	Result updateColliderSideWrapUnused(SensorFlags flags, u8 direction, fx32 wrapOffset = 0);
	// 020ABA68
	Result updateColliderSideUnused(SensorFlags flags, u8 direction, fx32 wrapOffset = 0);


	// 020ABA48
	void releaseColliders();
	// 020AB9AC
	void acquireColliders();


	// 020AB13C
	CollisionMgr();

	// D0: 020AB0D4
	// D1: 020AB110
	virtual ~CollisionMgr();


	// 020AB0B0
	void reset();
	// 020AB05C
	void clearCollision();
	// 020AB010
	void init(StageActor* owner, const Sensor* bottomSensor, const Sensor* topSensor, const Sensor* sideSensor, const LineSensorV* climbSensor = nullptr);
	// 020AAFC0
	void init(Vec3* position, Vec3* velocity, s8* playerID, const Sensor* bottomSensor, const Sensor* topSensor, const Sensor* sideSensor, const LineSensorV* climbSensor = nullptr);
	// 020AAF30
	bool getBottomSensorSize(Vec3& size);
	// 020AAEA0
	bool getTopSensorSize(Vec3& size);
	// 020AADF8
	bool getSideSensorSize(Vec3& size, u8 direction);


	// 020AAD48
	void collectCoin(u32 x, u32 y, TileType type, const Vec3& position);
	// 020AAD00
	static void spawnCoinParticles(const Vec3& position, TileType type);



	// 01FFE0A8
	void switchSideModifier(TileType type, u8 direction);
	// 01FFE0E4
	Result sideSensorScan(fx32 x, fx32 y, SensorFlags flags, u8 moveDirection, u8 sensorDirection);
	// 01FFE660
	Result updateSideSensorLine(const LineSensorV& sensor, u8 direction, SensorFlags flags);
	// 01FFE730
	Result updateSideSensorPoint(const PointSensor& sensor, u8 direction, SensorFlags flags);
	// 01FFE778
	Result updateSideSensors(fx32* velocityX = nullptr, SensorFlags flags = SensorFlags::None);



	// 01FFE8E0
	Result bottomSensorScanSlope(SensorFlags flags, bool unk);
	// 01FFEFF4
	Result bottomSensorBlockScan(fx32 x, fx32 y, SensorFlags flags, BlockTrigger* trigger);
	// 01FFF290
	Result bottomSensorScan(fx32 x, fx32 y, SensorFlags flags);
	// 01FFF700
	Result updateBottomSensorLine(const LineSensorH& sensor, SensorFlags flags);
	// 01FFF86C
	Result updateBottomSensorPoint(const PointSensor& sensor, SensorFlags flags);
	// 01FFF93C
	Result updateBottomSensor(bool unk);
	// 020AABFC
	Result calculateSlopeCollision(TileType type, SensorFlags flags);
	// 020AABE4
	bool switchBottomModifierNoStairs(TileType type);
	// 020AABA8
	bool switchBottomModifier(TileType type);
	// 020AAB74
	bool setBottomModifier(TileModifier modifier);
	// 020AAB70
	void modifierNone();
	// 020AAB44
	void modifierQuicksand();
	// 020AAB18
	void modifierConveyorBeltRight();
	// 020AAAE4
	void modifierConveyorBeltLeft();


	// 020AA990
	Result updateTopSensor(Result bottomResult = Result::None);
	// 020AA8AC
	Result updateTopSensorPoint(const PointSensor& sensor, SensorFlags flags);
	// 020AA6E0
	Result updateTopSensorLine(const LineSensorH& sensor, SensorFlags flags);
	// 020AA3C4
	Result topSensorScan(fx32 x, fx32 y, SensorFlags flags);
	// 020AA11C
	Result topSensorBlockScan(fx32 x, fx32 y, SensorFlags flags, BlockTrigger* trigger);
	// 020AA09C
	void topSensorAdjustPosition(Result result, fx32 y, SensorFlags flags);
	// 020A9F28
	Result topSensorScanSlope(SensorFlags flags);
	// 020A9DD0
	Result topSensorScanSlopeInverted(SensorFlags flags);
	// 020A9DA4
	void switchTopModifier(TileType type);


	// 020A9D3C
	static bool cacheTilePosition(u16 x, u16 y);
	// 020A9CF4
	static TileType getTileTypeAbs(u16 x, u16 y);


	// 020A9C8C
	Result updatePlayerGroundCollision();
	// 020A9A58
	Result updatePlayerHorizontal(Player& player);
	// 020A94C8
	Result updatePlayerVertical(Player& player);
	// 020A92C0
	Result updatePlayer(Player& player);
	// 020A91DC
	Result scanPlayerClimbable(fx32 top, fx32 bottom, fx32 right, fx32 left);


	// 020A917C
	Result updateGroundCollision();
	// 020A915C
	Result updateWallCollision(fx32* velocityX = nullptr, SensorFlags flags = SensorFlags::None);
	// 020A9090
	Result updateCombined(Vec3* position, Vec3* velocity, s8* playerID, const Sensor* bottomSensor, const Sensor* topSensor, const Sensor* sideSensor, PlatformMgr* platformMgr, u8 platformGroupID);


	// 020A9058
	void restoreSurfaceDirection(u8 unk, u8 moveDirection);
	// 020A9030
	void attachToTile(u8 surfaceDirection, u8 moveDirection);
	// 020A8DE8
	void updateAttachedDirection();
	// 020A8D20
	void updateAttached();
	// 020A8C70
	Result updateAttachedUpScan();
	// 020A8A44
	Result updateAttachedUpMove();
	// 020A8964
	Result updateAttachedDownScan();
	// 020A8728
	Result updateAttachedDownMove();
	// 020A8680
	Result updateAttachedLeftScan();
	// 020A8474
	Result updateAttachedLeftMove();
	// 020A83AC
	Result updateAttachedRightScan();
	// 020A8198
	Result updateAttachedRightMove();
	// 020A8170
	void setAttachedTile(fx32 x, fx32 y);
	// 020A8154
	void setAttachedTileAbs(u16 x, u16 y);


	// 020A8140
	TileModifier getBottomModifierType() const;
	// 020A812C
	TileModifier getTopModifierType() const;
	// 020A8114
	TileModifier getSideModifierType(u8 direction) const;


	// 020A8078
	SlopeType getGroundSlope() const;
	// 020A805C
	u32 getGroundSteepness() const;
	// 020A7FF8
	static u32 getSteepnessLevel(s16 angle);
	// 020A7FD4
	bool isGroundUphillAbs() const;
	// 020A7FB4
	bool isGroundUphill(u8 direction) const;
	// 020A7F7C
	SlopeDirection getSlopeDirection(bool flipped, SlopeType type) const;

	// 020A7F5C
	// fx32 getGroundFriction() friction???

	// 020A7ECC
	s16 getGroundAngleAbs(bool flipped) const;
	// 020A7EA8
	s16 getGroundAngle(u8 direction) const;

	// 020A7E44
	// fx32 getGroundVelocity() ?????
	// 020A7E20
	// fx32 getGroundRunVelocity() ????????????


	// 020A7C34
	u32 accessPipeUp(Vec3* position) const;
	// 020A7A4C
	u32 accessPipeDown(Vec3& position) const;
	// 020A7818
	u32 accessPipeSides(Vec3& position) const;
	// 020A76EC
	u32 accessDoor(Vec3& position) const;


	// 020A76D4
	static TileType getSolidTileType(fx32 x, fx32 y);
	// 020A7684
	static bool scanPointSolid(fx32 x, fx32 y);
	// 020A764C
	static TileType getFilteredTileType(fx32 x, fx32 y, TileType filter);
	// 020A75CC
	static TileType scanSolidTile(fx32 x, fx32 y);
	// 020A70A0
	// activeColliderDestroyBlocks()
	// 020A6F50
	static TileType raycastSolidTiles(fx32 x, fx32 y, fx32 length, RaycastDirection direction);
	// 020A6E70
	static LiquidType getLiquidCollision(fx32 x, fx32 y, fx32* targetY, s32 playerID);
	// 020A6D3C
	static bool raycastSolidTileDown(const Vec3& position, Vec3& target);
	// 020A6D18
	static TileType getTileType(fx32 x, fx32 y);
	// 020A6CE4
	static bool compareTileModifier(fx32 x, fx32 y, TileModifier modifier);


	// 020A6CBC
	// calcVerticalVelocity()


	// 020A6CA8
	ActorType getOwnerType() const;
	// 020A6C9C
	Result getActorGroundCollision() const;
	// 020A6C68
	bool isSlopeSteep() const;
	// 020A6C34
	// identical to isSlopeSteep()
	bool isGroundSteep() const;
	// 020A6C28
	Result getGroundSlopeCollision() const;

	// 020A6BD0
	// bool canSlide45Slope() ??????????????

	constexpr static Result getWallMask(u8 direction) {
		return Result(u32(Result::WallRightAny) << direction);
	}

	static const AttachedFunction attachedScanTable[4];
	static const AttachedFunction attachedMoveTable[4];
	static const ModifierFunction bottomSensorModifiers[16];
	static const ModifierFunction dummyModifier;
	static const SolverFunction colliderSolversTop[3];
	static const SideSolverFunction colliderSolversSide[3];
	static const SolverFunction colliderSolversBottom[3];
	static const SideSolverFunction colliderSolversUnusedSide[3];

	static u16 cachedTileX;
	static u16 cachedTileY;
	static SolverFunction bottomSensorSolver;
	static SideSolverFunction unusedSideSolver;
	static SideSolverFunction sideSensorSolver;
	static SolverFunction topSensorSolver;

	StageActor* owner;

	const Sensor* bottomSensor;
	const Sensor* topSensor;
	const Sensor* sideSensor;
	const LineSensorV* climbSensor;

	Vec3* linkedPosition;
	Vec3* linkedVelocity;
	s8* linkedPlayerID;
	PlatformMgr* linkedPlatformMgr;

	CollisionMgr* next[3];

	Collider* head[3];
	Collider* colliders[3];

	u32 unk4C;
	fx32 colliderTopDeltaX;

	Vec3 appliedForce;
	Vec2 lastPosition;
	Vec2 positionStep;

	Result collisionResult;
	Result bottomResult;
	TileType bottomTileType;
	fx32 bottomTileY;
	s16 surfaceAngle;
	u8 playerID;
	u8 unk8F;

	u16 attachedTileX;
	u16 attachedTileY;
	u16 slopeTileX;
	u16 slopeTileY;

	u16 bottomModifierFlags;
	Modifier bottomModifier;
	Modifier lastBottomModifier;

	u16 topModifierFlags;
	Modifier topModifier;
	Modifier lastTopModifier;

	u16 sideModifierFlags[2];
	Modifier sideModifier[2];
	Modifier lastSideModifier[2];

	u8 unkA8;
	SlopeType groundSlopeType;
	SlopeType ceilingSlopeType;

	u8 climbableType;					// 0 = vine, 1 = fence
	u8 moreBits;
	u8 surfaceDirection;
	u8 moveDirection;
	u8 unkAF;
	DamageTileFlags damageFlags;
	DamageTileType damageTileType;
	u8 unkB2;
	u8 slopeDirectionMaybe;
	u8 slowMovementMaybe;
	u8 lastSlowMovementMaybe;
	u8 unkB6;
	u8 layerID;

};
NTR_SIZE_GUARD(CollisionMgr, 0xB8);


using CollisionMgrResult	= CollisionMgr::Result;
using SlopeType				= CollisionMgr::SlopeType;
using SlopeDirection		= CollisionMgr::SlopeDirection;
using RaycastDirection		= CollisionMgr::RaycastDirection;
using SensorFlags			= CollisionMgr::SensorFlags;
using Sensor				= CollisionMgr::Sensor;
using PointSensor			= CollisionMgr::PointSensor;
using LineSensorH			= CollisionMgr::LineSensorH;
using LineSensorV			= CollisionMgr::LineSensorV;


IMPL_ENUMCLASS_OPERATORS(CollisionMgrResult);
IMPL_ENUMCLASS_OPERATORS(SensorFlags);


constexpr PointSensor::PointSensor(fx32 x, fx32 y, SensorFlags flags) :
	Sensor(flags & ~SensorFlags::Line),
	x(x), y(y)
{}

constexpr LineSensorH::LineSensorH(fx32 left, fx32 right, fx32 y, SensorFlags flags) :
	Sensor(flags | SensorFlags::Line),
	left(left), right(right), y(y)
{}

constexpr LineSensorV::LineSensorV(fx32 top, fx32 bottom, fx32 x, SensorFlags flags) :
	Sensor(flags | SensorFlags::Line),
	top(top), bottom(bottom), x(x)
{}
