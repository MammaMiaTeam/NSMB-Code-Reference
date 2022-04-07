#pragma once
#include "nsmb.h"


class BanzaiBillBlaster;


// vtable at 02151D80 (ov42)
class BulletBillBlaster : public StageEntity
{
public:

	using StateFunction = bool(BulletBillBlaster::*)();

	enum class ShootDirection : u32
	{
		Auto,	// Shoot bullets in the direction of the closest player
		Left,	// Shoot bullets to the left
		Right	// Shoot bullets to the right
	};

	// C1: 02148FB0
	// C2: 021490D4
	BulletBillBlaster();

	// D0: 02148D38
	// D1: 02148E78
	// D2: 02148C00
	virtual ~BulletBillBlaster();

	// 02147B48
	s32 onCreate() override;
	// 02147514
	s32 onDestroy() override;
	// 02147AF0
	s32 onUpdate() override;
	// 0214753C
	s32 onRender() override;
	// 02147538
	void onCleanupResources() override;
	// 02147EA0
	bool onPrepareResources() override;

	// 02147FEC
	bool updateDefeated() override;

	// 02148854
	void updateBulletShotScale();
	// 0214863C
	void updateShoot();

	// 02148994
	bool switchState(const StateFunction& function);
	// 0214894C
	void updateState();

	// 02148544
	bool mainState();

	// 02148B58
	static void topCollision(StageActor& self, StageActor& other);
	// 02148AB0
	static void sideCollision(StageActor& self, StageActor& other);

	// 02148A68
	static bool loadResources();

	static constexpr u16 objectID = 248;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 36;

	// 02151D74
	static const ActorProfile profile;

	// 0215182C
	static const u32 resourceHeapSizes[2];
	// 02151834
	static const fx32 verticalShootOffsets[2];
	// 0215183C
	static const fx32 shardAccelerationsX[2];
	// 02151844
	static const fx32 shardVelocitiesY[4];		// 4 random velocities
	// 02151854
	static const fx32 shardVelocitiesX[4][2];	// 4 random velocities

	// 02152818
	static const StateFunction sDestroyed;
	// 02152820
	static const StateFunction sMain;


	Model models[3];
	ModelAnm modelAnm;

	ColliderInfo colliderInfo;
	Collider collider;
	Vec3 colliderScale;
	
	Vec3 cannonPosition;
	Vec3 standPosition;
	Vec3 bodyPositions[16];
	
	Vec3 cannonVelocity;
	Vec3 standVelocity;
	Vec3 bodyVelocities[16];

	Vec3s cannonRotation;
	Vec3s standRotation;
	Vec3s bodyRotations[16];

	const StateFunction* updateFunction;

	Vec3 cannonScale;
	fx32 cannonScaleValue;
	fx32 cannonScaleTarget;
	fx32 cannonScaleFactor;

	fx32 shardAcceleration;

	u32 unusedA20;
	u32 bulletFlag;
	u32 shootCooldown;
	u32 height;
	ShootDirection shootDirection;
	u16 banzaiBillShot;
	u16 shardDestroyTimer;
	bool megaCollided;
	bool destroyInactiveDisable;
	u8 cannonScaleEndTimer;
	u8 bulletBillShotStep;
	u8 cannonScaleDirection;
	u8 unusedA3D;
	u8 megaCollisionDirection;
	s8 megaPlayerIDs[2];
	s8 updateStep;

};
NTR_SIZE_GUARD(BulletBillBlaster, 0xA44);


// vtable at 02151E94 (ov42)
class BanzaiBillBlaster : public BulletBillBlaster
{
public:

	// D0: 02149274
	// D1: 02149254
	virtual ~BanzaiBillBlaster();

	// 02148A20
	static bool loadResources();

	static constexpr u16 objectID = 249;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 37;

	// 02151D68
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(BanzaiBillBlaster, sizeof(BulletBillBlaster));
