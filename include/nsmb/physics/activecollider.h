#pragma once
#include "nitro_if.h"
#include "nsmb/math/math.h"
#include "nsmb/math/vector.h"


enum class CollisionGroup : u8
{
	Player,			// player
	PlayerSpecial,	// player sliding, slamming a fence, mega mushroom
	Group2,
	Group3,
	Entity,			// koopa, goomba, trampoline, thwomp, bumper, etc...
	Hostile,		// lakitu, (fire) piranha plant, spike bass, flame chomp, fire snake, big cheep cheep, cheep cheep, blooper (spawned?), chain chomp (no log), cheep skipper(?????) (spawnable enemies OR enemies that spawn something (what does the spike bass spawn though)) ... they do have something in common, they all try to attack the player (some follow the player (blooper, flame chomp, cheep cheep variations, fire snake), some attack him directly (lakitu, chain chomp, piranha plants, boss bass, cheep skipper))
	Item,			// items, star coin, boss key, mvsl battle star, 'lakithunder effects'??
	Fireball,		// fireball
	Bullet,			// bullet bill/banzai bill
	Debris,			// volcano debris
};
IMPL_ENUMCLASS_OPERATORS(CollisionGroup);


enum class CollisionFlag : u8
{
	None,			// none
	Fireball,		// fireball
	Flag2,			// checked by castle enemies (Thwomp, Dry Bones, FireBar), fishes and possibly other stuff
	Flag3,
	Flag4,
	Sliding,		// player sliding
	Flag6,
	Flag7,
	Flag8,
	SlamFence,		// player slamming a fence
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


#define MAKE_GROUP_MASK(...)	static_cast<u16>(__mask_or(__VA_ARGS__))
#define MAKE_FLAG_MASK(...)		static_cast<u16>(__mask_or(__VA_ARGS__))
#define MAKE_FLAG_MASK_EX(...)	static_cast<u16>(~__mask_or(CollisionFlag::None, __VA_ARGS__))


class StageActor;
class Player;
class ActiveCollider;


using ActiveColliderCallback = void(*)(ActiveCollider&, ActiveCollider&);


struct ActiveColliderInfo
{
	// Options
	static constexpr u16 NoIntersection = 1 << 0;

	FxRect rect;

	CollisionGroup selfGroup;
	CollisionFlag selfFlag;
	u16 checkGroupMask;
	u16 checkFlagMask;
	u16 options;

	ActiveColliderCallback callback;
};
NTR_SIZE_GUARD(ActiveColliderInfo, 0x1C);


enum class ActiveColliderShape : u8 {

	Rectangle,
	Round,
	TrapezoidV,
	TrapezoidH

};


class ActiveCollider {
public:

	static constexpr u32 GroupCount = 10;

	using Shape = ActiveColliderShape;

	StageActor* owner;
	u32 unk0;

	ActiveCollider* prev;
	ActiveCollider* next;

	// hitbox info
	ActiveColliderInfo hitbox;

	Vec2 collisionCenter;
	fx32 collisionPointX[GroupCount];
	fx32 collisionPointY[GroupCount];

	// trapezoid properties
	struct {
		u32 topLeftX;
		u32 topRightX;
		u32 botLeftX;
		u32 botRightX;
	} trapezoid;

	// physics calculations
	u32 toUnk354;
	u16 collidedGroups;
	u16 collidedFlags;

	u8 layerID;					// -1 = ignored, 0 = interact with front layer, 1 = interact with back layer
	u8 defaultCollisionFlags;
	u8 collisionResult;			// 0x2 is set when a collision occurs, 0x3 = stop updating
	u8 collidedPlayerID;

	// misc
	bool linked;

	u8 unk9;
	Shape shape;
	u8 unk10;
	u16 lastCollidedGroups;
	u16 unk12;


	static ActiveCollider* listHead;
	static ActiveCollider* listTail;

	// 020a4868
	sym ActiveCollider() __body

	// D1: 020a484c
	// D0: 020a4820
	sym virtual ~ActiveCollider() __body

	// 020a4808
	sym void reset() __body

	// 020a47a0
	sym void init(StageActor* owner, const ActiveColliderInfo& info, u8 layerID = 0) __body

	// 020a4758
	sym void setPositionAroundPivot(u16 rotation, fx32 pivotX, fx32 pivotY) __body

	// 020a4714
	sym void clearCollision() __body

	// 020a46bc
	sym void link() __body

	// 020a4658
	sym void unlink() __body

	// 020a44b0
	sym void manualUpdate() __body

	// 020a445c
	sym void unk_020a445c(const Vec3& position, const ActiveColliderInfo& info, u8 layerID) __body

	// 020a4434
	sym static void initSystem() __body
		
	// 020A3D68
	Player* getPlayer() const;

	// Assumed from 020E3824 (ov10)
	NTR_INLINE u8 getPlayerID() const;

	NTR_INLINE fx32 getCollisionPointX(CollisionGroup group) const {
		return collisionPointX[u32(group)];
	}

	NTR_INLINE fx32 getCollisionPointY(CollisionGroup group) const {
		return collisionPointY[u32(group)];
	}

	NTR_INLINE bool checkCollidedGroup(CollisionGroup group) const {
		return collidedGroups & (1 << u32(group));
	}

	NTR_INLINE bool checkCollidedFlag(CollisionFlag flag) const {
		return collidedFlags & (1 << u32(flag));
	}

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
NTR_SIZE_GUARD(ActiveCollider, 0xB0);
