#pragma once
#include "nsmb.h"


class BanzaiBill;


// vtable at 02151FC8 (ov42)
class BulletBill : public StageEntity
{
public:

	using StateFunction = bool(BulletBill::*)();

	enum class DirectionType : u32
	{
		Auto,				// Towards the closest player
		Fixed,				// Fixed (left/right)
		RotatedRight,		// Rotated right
		RotatedLeft,		// Rotated left
		RotatedDown,		// Rotated down
		RotatedUp,			// Rotated up
		RotatedDownLeft,	// Rotated down-left
		RotatedDownRight,	// Rotated down-right
		RotatedUpLeft,		// Rotated up-left
		RotatedUpRight,		// Rotated up-right
	};

	enum class PlatformCollisionType : u32
	{
		None,				// No platform collision
		Player,				// Player collision
		Entity,				// Entity collision (koopa/spiny/buzzy beetle shell)
		Fireball			// Fireball collision
	};

	inline BulletBill() {}

	// D0: 0214933C
	// D1: 0214929C
	inline virtual ~BulletBill() {}

	// 0214968C
	s32 onCreate() override;
	// 021494A8
	s32 onDestroy() override;
	// 02149508
	s32 onRender() override;
	// 02149504
	void onCleanupResources() override;
	// 02149A78
	bool onPrepareResources() override;

	// 021495F4
	bool updateMain() override;

	// 0214A358
	void onEntityHit() override;
	// 0214A364
	void onMegaHit() override;
	// 0214A3BC
	void onStomped() override;
	// 0214A184
	void onGroundPound() override;
	// 0214A550
	void onStageBeaten(Player& player) override;

	// 0214A44C
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 0214A668
	void doPlayerJump(Player& player, fx32 jumpVelocity) override;

	// 02149F0C
	bool updateBanzaiPlatform();
	// 02149E8C
	void setupBanzaiPlatform();
	// 02149E6C
	void updateBanzaiStretch();
	// 02149D68
	void updateBulletRoll();

	// 0214A824
	bool switchState(const StateFunction& function);
	// 0214A7DC
	void updateState();

	// 02149AF0
	bool mainState();

	// 02149424
	static BulletBill* spawnBulletBill(const Vec3& position, u32 settings, u32 max = 0);
	// 021493E4
	static BanzaiBill* spawnBanzaiBill(const Vec3& position, u32 settings);

	// 0214A8D4
	static bool loadResources();

	static constexpr u16 objectID = 27;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 38;

	// 02151FB0
	static const ActorProfile profile;

	// 021518DC
	static const ActiveColliderInfo activeColliderInfo;

	// 021518B0
	static const s16 rotationsX[8];
	// 02151874
	static const s16 rotationsY[2];
	// 02151878
	static const s16 bulletRollSteps[2];
	// 0215187C
	static const s16 bulletRollTargets[2];
	// 02151918
	static const fx32 banzaiPlatformPoints[2][4];
	// 02151890
	static const fx32 banzaiSmokeOffsets[2];
	// 02151898
	static const fx32 bulletSmokeOffsets[2];
	// 021518A0
	static const u8 bulletRollSequence[16];
	// 02151880
	static const fx32 targetVelocitiesX[2];
	// 02151888
	static const fx32 velocitiesX[2];
	// 021518F8
	static const fx32 rotatedVelocitiesY[8];
	// 02151938
	static const fx32 rotatedVelocitiesX[8];

	// 02152828
	static const StateFunction sMain;


	Model model;
	
	SegmentPlatform banzaiPlatform;			// Banzai Bill trapezoid platform
	ActiveCollider banzaiCollider;			// Banzai Bill trapezoid collider

	FxRect hitboxRect;						// Hitbox rectangle
	FxRect unused5B4;						// Unused rectangle

	const StateFunction* updateFunction;

	u32 bulletFlag;							// 0 = Banzai Bill, 1 = Bullet Bill
	EmitterT smokeEmitterID;				// Smoke particle emitter
	u32 followCameraFlag;					// Follows the camera horizontally if not 0

	u16 smokeSpawnCooldown;					// Cooldown set to 64 frames (8 for Bullet Bills). When this reaches zero smoke particles start spawning
	u16 smokePriorityTimer;					// Cooldown set to 64 frames (16 for Bullet Bills). When this reaches zero smoke particles spawn with a lower Z priority (128 instead of 64)
	u16 bulletRollDirection;				// Bullet bill roll direction. 0 = clockwise, 1 = counterclockwise
	u16 banzaiStretchCooldown;				// Cooldown set to 64 frames (8 for Bullet Bills). When this reaches zero Banzai Bills begin stretching (Z) to reach unit scale (Y). Possibly unused
	u16 playerDamageCooldown;				// Cooldown set to 24 frames after hurting player. When this reaches zero the Banzai Bill platform is reactivated
	u16 banzaiPhysicsCreated;				// Set to 1 after creating Banzai Bill platform and collider
	u16 unused5E0;							// Unused
	u8 bulletRollSequenceIndex;				// Bullet Bill roll animation sequence step
	s8 updateStep;

};
NTR_SIZE_GUARD(BulletBill, 0x5E4);


// vtable at 021520DC (ov42)
class BanzaiBill : public BulletBill
{
public:

	// D0: 0214AA60
	// D1: 0214A9B4
	virtual ~BanzaiBill();

	// 0214A8B0
	static bool loadResources();

	static constexpr u16 objectID = 238;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 39;

	// 02151FBC
	static const ActorProfile profile;

	// 021518C0
	static const ActiveColliderInfo activeColliderInfo;

};
NTR_SIZE_GUARD(BanzaiBill, sizeof(BulletBill));
