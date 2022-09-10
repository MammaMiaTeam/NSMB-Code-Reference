#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"
#include "nsmb/graphics/2d/oam.h"
#include "nsmb/physics/activecollider.h"
#include "nsmb/physics/collisionmgr.h"


// vtable at 02126784 (ov10)
class Fireball
{
public:

	using StateFunction = bool(Fireball::*)(void* arg);

	static constexpr u8 OwnerPlayer0 = 0;
	static constexpr u8 OwnerPlayer1 = 1;
	static constexpr u8 OwnerPiranha = 2;
	static constexpr u8 OwnerFireBro = 3;


	// 020E3C84
	Fireball();

	// D0: 020E3C0C
	// D1: 020E3C50
	virtual ~Fireball();


	// 020E3A8C
	bool create(s8 ownerType, const Vec3& position, u8 direction, const Vec3* unused, u8 id);
	// 020E3A3C
	void destroy();
	// 020E39DC
	void update();

	// 020E3488
	void extinguish();
	// 020E2A10
	void destroyEnemy();
	// 020E3BC4
	void updateVerticalVelocity();
	// 020E3B98
	void updateDrawPriority(const Vec3& position);
	// 020E30D8
	bool updatePlayerCollider();
	// 020E2DC4
	bool updateEnemyCollider();
	// 020E3428
	void applyBouncePlayer(u32 steepness, bool uphill);
	// 020E33C8
	void applyBounceEnemy(u32 steepness, bool uphill);

	// 020E3908
	bool switchState(StateFunction function, void* arg);

	// 020E34B4
	void createPlayer();
	// 020E3568
	bool playerState(void* arg);

	// 020E2FD8
	void createPiranhaPlant();
	// 020E2E1C
	bool piranhaPlantState(void* arg);

	// 020E2D4C
	void createFireBro();
	// 020E2A3C
	bool fireBroState(void* arg);

	// 020E3198
	static void playerActiveCallback(ActiveCollider& self, ActiveCollider& other);

	// 02121980
	static const fx32 enemyBounceVelocitiesY[2];
	// 02121958
	static const fx32 enemyBounceVelocitiesX[2];
	// 02121930
	static const fx32 playerBounceVelocitiesY[2];
	// 02121908
	static const fx32 playerBounceVelocitiesX[2];
	// 021218EC
	static const ActiveColliderInfo playerColliderInfo;
	// 021218D0
	static const ActiveColliderInfo enemyColliderInfo;
	// 021218C0
	static const FxRect activeBox;
	// 021218B4
	static const PointSensor sideSensor;
	// 021218A8
	static const PointSensor topSensor;
	// 0212189C
	static const PointSensor bottomSensor;
	// 02121894
	static const fx32 playerVelocitiesX[2];
	// 02121884
	static const fx32 fireBroVelocitiesX[2];
	// 0212187C
	static const fx32 piranhaVelocitiesY[2];
	// 0212188C
	static const fx32 piranhaVelocitiesX[2];
	// 02121878
	static const s16 rotationsY[2];

	// 0212989C
	static CollisionMgr collisionManagers[16];
	// 0212955C
	static PlatformMgr platformManagers[16];
	// 021294AC
	static ActiveCollider activeCollider;


	StateFunction updateFunction;

	Vec3 position;
	Vec3 lastPosition;
	Vec3 velocity;
	Vec3 scale;
	Vec3s rotation;					// Has no effect on the rendered sprite, fireballs are 2D

	OAM::Anim spriteAnimation;

	fx32 accelY;
	fx32 targetVelocityY;
	u32 unused78;
	u32 unused7C;
	bool active;
	s8 ownerType;
	s8 playerID;					// Set to -1 in Fireball() and destroy()
	s8 updateStep;
	u8 drawFlags;					// OAM::Flags
	u8 direction;					// Bit 0 = horizontal, bit 1 = vertical
	u8 id;
	u8 trailTimer;
	u8 viewID;

};
NTR_SIZE_GUARD(Fireball, 0x8C);


// vtable at 02126794 (ov10)
class FireballHandler
{
public:

	// 020E40A0
	FireballHandler();

	// D0: 020E4010
	// D1: 020E405C
	virtual ~FireballHandler();

	// 020E3E8C
	bool spawn(s8 ownerType, const Vec3& position, u8 direction, const Vec3* unused = nullptr);
	// 020E3EE0
	void destroyEnemy();
	// 020E3F1C
	void update();
	// 020E3F58
	void render();
	// 020E4008
	bool init();


	Fireball fireballs[16];

};
NTR_SIZE_GUARD(FireballHandler, 0x8C4);


namespace Fireballs {

	// 020E3CE4
	bool spawnFireBroFireball(const Vec3& position, u8 direction);
	// 020E3D4C
	bool spawnPiranhaPlantFireball(const Vec3& position, u8 direction, const Vec3* unused = nullptr);
	// 020E3D90
	bool spawnPlayerFireball(u8 playerID, const Vec3& position, u8 direction);
	// 020E3DEC
	bool spawn(s8 ownerType, const Vec3& position, u8 direction, const Vec3* unused = nullptr);
	// 020E3E24
	void destroyEnemyFireballs();

	// 020E3E3C
	void update();
	// 020E3E54
	void render();

	// 020E3E6C
	bool init();
	// 020E3E84
	bool loadResources();

	// 02129480
	extern s8 activeFireballs[4];
	// 02129484
	extern FireballHandler* fireballHandler;

}
