#pragma once

#include <nsmb/core/math/math.hpp>
#include <nsmb/core/math/vector.hpp>
#include <nsmb/extra/bitmaskenum.hpp>
#include <nsmb/extra/bits.hpp>
#include <nsmb/game/game.hpp>

class StageActor;
class Player;
class ActiveCollider;

using AcCallback = void(*)(ActiveCollider&, ActiveCollider&);

enum class AcGroup : u8 {
	Player,			// Player.
	PlayerSpecial,	// Player sliding, slamming a fence, mega mushroom.
	Group2,			// These two were probably planned for separated Player 2 groups.
	Group3,			// ^^^
	Entity,			// Koopa, Goomba, Trampoline, Thwomp, Bumper, etc...
	Chasing,		// Lakitu, (Fire) Piranha Plant, Spike Bass, Flame Chomp, Fire Snake, Big Cheep Cheep, Cheep Cheep, Blooper, Chain Chomp, Cheep Skipper.
	Item,			// Items, Star Coin, Boss Key, VS Battle Star, 'Lakithunder Effects'??
	Fireball,		// Fireball
	Bullet,			// Bullet Bill/Banzai Bill
	Debris,			// Volcano Debris
	Max
};
NTR_CREATE_BITMASK_ENUM(AcGroup);

/*
	Notes about AcGroup 5 ('Chasing', previously 'Hostile')

 	Used by spawnable enemies (coincidence?) OR enemies that spawn something (targeted projectiles).
	They do have something in common though, they all try to attack the player:
	- Some follow the player (blooper, flame chomp, cheep cheep variations, fire snake)
	- Some attack him directly (lakitu, chain chomp, piranha plants, boss bass, cheep skipper)

*/

enum class AcAttack : u8 {
	None,
	Fireball,		// fireball
	Flag2,			// checked by castle enemies (Thwomp, Dry Bones, FireBar, Podoboo), Boo, fish enemies and possibly other stuff
	Flag3,
	Flag4,
	Sliding,		// player sliding
	Flag6,
	Flag7,
	Flag8,
	SlamFence,		// player slamming a fence
	EntityAsWeapon,	// EAW: snowball, spiked ball, held/thrown entities, exploding bob-omb, etc
	Flag11,
	Flag12,
	Flag13,
	Flag14,
	Flag15,
	Max
};
NTR_CREATE_BITMASK_ENUM(AcAttack);

#define AC_GROUP_MASK(...)		static_cast<u16>(Bits::bitmask(__VA_ARGS__))
#define AC_ATTACK_MASK_INC(...)	static_cast<u16>(Bits::bitmask(__VA_ARGS__))
#define AC_ATTACK_MASK_EXC(...)	static_cast<u16>(~Bits::bitmask(AcAttack::None, __VA_ARGS__))

constexpr u32 AcGroupCount = scast<u32>(AcGroup::Max);
constexpr u32 AcAttackCount = scast<u32>(AcAttack::Max);

struct AcConfig {

	enum Option {
		FastIntersection = 0x0001,		// Skips intersection distance/point calculations (Rect only).
		Unknown2 = 0x0002,
		BypassDamage = 0x8000			// Entity As Weapons (EAW, such as entities held, shells thrown or Bob-Ombs exploding) will not deal damage on the entity that has this option set.
	};


	FxRect rect;
	AcGroup group;						// Group that the ActiveCollider will resemble.
	AcAttack attack;					// Attack that the ActiveCollider will perform.
	u16 detectGroups;					// Groups that the ActiveCollider will react to.
	u16 detectAttacks;					// Attacks that the ActiveCollider will respond to.
	u16 options;						// Various options for intersection and response configuration.
	AcCallback callback;

};
NTR_SIZE_GUARD(AcConfig, 0x1C);

class ActiveCollider {
public:

	using CheckFunction = bool(*)(ActiveCollider& a, ActiveCollider& b);

	enum class Shape : u8 {
		Rectangle,
		Round,
		TrapezoidH,
		TrapezoidV,
		Max
	};

	enum Layer : u8 {
		Ignored = 0xFF,
		Front = 0,
		Back
	};

	enum CollisionFlags : u8 {
		Active = 0x01,
		Passive = 0x02
	};

	enum CollisionState : u8 {
		IgnoreCollision = 0x01,
		Collided = 0x02
	};

	static constexpr u32 ShapeCount = u32(Shape::Max);


	ActiveCollider();

	virtual ~ActiveCollider();


	void clearLink();

	void init(StageActor* owner, const AcConfig& config, u8 layerID = Layer::Front);

	void rotatePosition(s16 angle, fx32 x, fx32 y);

	void clearCollision();

	void link();

	void unlink();


	u16 processSingle();

	u16 processAnonymous(const Vec3& position, const AcConfig& config, u8 layerID);

	// ITCM
	static void processAll();


	static void initSystem();

	// ITCM
	static bool checkRectRect(ActiveCollider& a, ActiveCollider& b);

	// ITCM
	static bool checkRectRectWrap(ActiveCollider& a, ActiveCollider& b);

	// ITCM
	static bool checkRectRectWrapCore(ActiveCollider& a, ActiveCollider& b, fx32 ax, fx32 bx);

	static bool checkRoundRound(ActiveCollider& a, ActiveCollider& b);

	static bool checkTrapHorizontallyInside(fx32 trapLeft, fx32 trapRight, fx32 otherLeft, fx32 otherRight);

	static u32 checkTrapHorizontalSlope(fx32 trapLeft, fx32 trapLeftSide, fx32 trapRight, fx32 trapRightSide, fx32 otherX, fx32 otherY);

	static bool checkOtherTrapH(ActiveCollider& a, ActiveCollider& b);

	static bool checkTrapHOther(ActiveCollider& a, ActiveCollider& b);

	static bool checkTrapVerticallyInside(fx32 trapTop, fx32 trapBottom, fx32 otherTop, fx32 otherBottom);

	static u32 checkTrapVerticalSlope(fx32 trapTopSide, fx32 trapTop, fx32 trapBottomSide, fx32 trapBottom, fx32 otherX, fx32 otherY);

	static bool checkOtherTrapV(ActiveCollider& a, ActiveCollider& b);

	static bool checkTrapVOther(ActiveCollider& a, ActiveCollider& b);

	static void initFunctions(u32 wrapType);


	Player* getPlayer() const;

	bool checkRectIntersection(ActiveCollider& other) const;


	// Assumed from 020E3824 (ov10)
	NTR_INLINE u8 getPlayerID() const;


	constexpr fx32 getCollisionPointX(AcGroup group) const {
		return intersectionDistX[u32(group)];
	}

	constexpr fx32 getCollisionPointY(AcGroup group) const {
		return intersectionDistY[u32(group)];
	}

	constexpr bool checkCollidedGroup(AcGroup group) const {
		return collidedGroups & (1 << u32(group));
	}

	constexpr bool checkCollidedFlag(AcAttack attack) const {
		return collidedAttacks & (1 << u32(attack));
	}

	constexpr u16 getUserData() const {
		return userData;
	}

	constexpr void setUserData(u16 data) {
		userData = data;
	}

	constexpr u32 getSharedData() const {
		return sharedData;
	}

	constexpr void setSharedData(u32 data) {
		sharedData = data;
	}


	static ActiveCollider* listHead;
	static ActiveCollider* listTail;
	static CheckFunction checkFuncTable[ShapeCount * ShapeCount];

	static const CheckFunction checkFuncRect[WrapType::Count];


	StageActor* owner;
	u16 userData;
	u16 unusedA;

	ActiveCollider* prev;
	ActiveCollider* next;

	AcConfig config;

	Vec2 intersectionCenter;
	fx32 intersectionDistX[AcGroupCount];
	fx32 intersectionDistY[AcGroupCount];

	// Trapezoid properties
	union {

		struct {
			fx32 topLeft;
			fx32 topRight;
			fx32 botLeft;
			fx32 botRight;
		} trapV;

		struct {
			fx32 topLeft;
			fx32 botLeft;
			fx32 topRight;
			fx32 botRight;
		} trapH;

	};

	u32 sharedData;
	u16 collidedGroups;
	u16 collidedAttacks;
	u8 layerID;
	u8 collisionFlags;
	u8 collisionState;
	u8 collidedPlayerID;
	bool linked;
	u8 unkA9; // Set to 0 when unlinked
	Shape shape;
	u8 unkAB;
	u16 collidedGroupsPrev;
	u16 unkAE;

};
NTR_SIZE_GUARD(ActiveCollider, 0xB0);

using AcShape = ActiveCollider::Shape;
using AcLayer = ActiveCollider::Layer;
