#pragma once
#include "nitro_if.h"
#include "nsmb/math/math.h"
#include "nsmb/math/vector.h"


enum class CollisionGroup : u8
{
	Player,		// player
	Sliding,	// player (when sliding)
	Group2,
	Group3,
	Entity,		// koopa, goomba, trampoline, thwomp, bumper, etc...
	Hostile,	// lakitu, (fire) piranha plant, spike bass, flame chomp, fire snake, big cheep cheep, cheep cheep, blooper (spawned?), chain chomp (no log), cheep skipper(?????) (spawnable enemies OR enemies that spawn something (what does the spike bass spawn though)) ... they do have something in common, they all try to attack the player (some follow the player (blooper, flame chomp, cheep cheep variations, fire snake), some attack him directly (lakitu, chain chomp, piranha plants, boss bass, cheep skipper))
	Item,		// items, star coin, boss key, mvsl battle star, 'lakithunder effects'??
	Fireball,	// fireball
	Bullet,		// bullet bill/banzai bill
	Debris,		// volcano debris
	Group10,
	Group11,
	Group12,
	Group13,
	Group14,
	Group15,
};
IMPL_ENUMCLASS_OPERATORS(CollisionGroup);


enum class CollisionFlag : u8
{
	None,			// none
	Fireball,		// fireball
	Flag2,
	Flag3,
	Flag4,
	Sliding,		// player (when sliding)
	Flag6,
	Flag7,
	Flag8,
	Flag9,
	DamageEntity,	// snowball, spiked ball
	Flag11,
	Flag12,
	Flag13,
	Flag14,
	Flag15,
};
IMPL_ENUMCLASS_OPERATORS(CollisionFlag);


namespace
{
	template<class T>
	constexpr auto __mask_or(T a) {
		return 1U << a;
	}

	template<class T, class... Args>
	constexpr auto __mask_or(T a, Args&&... args) {
		return (1U << a) | __mask_or(args...);
	}
}


#define MAKE_GROUP_MASK(...) static_cast<u16>(__mask_or(__VA_ARGS__))
#define MAKE_FLAG_MASK(...) static_cast<u16>(~__mask_or(CollisionFlag::None, __VA_ARGS__))


class StageActor;
class ActiveCollider;


using ActiveColliderCallback = void(*)(ActiveCollider&, ActiveCollider&);


struct ActiveColliderInfo
{
	fx32 offsetX;
	fx32 offsetY;
	fx32 sizeX;
	fx32 sizeY;

	CollisionGroup selfGroupID;
	CollisionFlag selfFlagID;
	u16 checkGroupMask;
	u16 checkFlagMask;
	u16 itemRelated;

	ActiveColliderCallback callback;
};


class ActiveCollider {
public:

	enum class Shape : u8 {
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
	CollisionGroup selfGroup;
	CollisionFlag selfFlag;
	u16 checkGroupMask;
	u16 checkFlagMask;
	u16 itemRelated;

	// collision callback
	void* callback;

	// position info
	Vec2 position;

	fx32 XcontactPos[10];
	fx32 YcontactPos[10];

	// trapezoid properties
	struct {
		u32 topLeftX;
		u32 topRightX;
		u32 botLeftX;
		u32 botRightX;
	} trapezoid;

	// physics calculations
	u32 to_info_used;
	u16 collidedGroups;
	u16 collidedFlags;

	bool backLayer;				// if set, the collider will only interact with other colliders that are behind the main layer

	u8 defaultCollisionFlags;
	u8 collisionResult;			// 0x2 is set when a collision occurs, 0x3 = stop updating
	u8 collidedPlayerID;

	// misc
	bool linked;

	u8 unk9;
	Shape shape;
	u8 unk10;
	u16 prevCollidedGroups;
	u16 unk12;

	// 020a4868
	sym ActiveCollider() __body

	// D1: 020a484c
	// D0: 020a4820
	sym virtual ~ActiveCollider() __body

	// 020a4808
	sym void reset() __body

	// 020a47a0
	sym void init(StageActor* owner, const ActiveColliderInfo& info, bool backLayer) __body

	// 020a4758
	sym void setPositionAroundPivot(u16 rotation, fx32 pivotX, fx32 pivotY) __body

	// 020a4714
	sym void resetCollisionState() __body

	// 020a46bc
	sym void link() __body

	// 020a4658
	sym void unlink() __body

	// 020a44b0
	sym void manualUpdate() __body

	// 020a445c
	sym void unk_020a445c(const Vec3& position, const ActiveColliderInfo& info, bool backLayer, u32 unk) __body

	// 020a4434
	sym static void initSystem() __body

protected:

	// 01ffdd88
	sym bool testCollisionRect(ActiveCollider* collision) __rbody

	// 020a4344
	sym bool testCollisionRound(ActiveCollider* collision) __rbody

	// 020a4328
	//sym bool unk_020a4328(ActiveCollider* collision() __rbody

	// 020a4264
	sym bool testCollisionOtherVsVTrpz(ActiveCollider* collision) __rbody

	// 020a40a4
	sym bool testCollisionVTrpzVsOther(ActiveCollider* collision) __rbody

	// 020a3fc4
	sym bool testCollisionOtherVsHTrpz(ActiveCollider* collision) __rbody

	// 020a3e04
	sym bool testCollisionHTrpzVsOther(ActiveCollider* collision) __rbody
};