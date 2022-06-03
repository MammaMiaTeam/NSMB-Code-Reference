#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"
#include "nsmb/graphics/3d/model.h"
#include "nsmb/system/memory.h"


constexpr u32 ProjectileTypes = 5;


namespace ProjectileType {

	constexpr s8 Boomerang       = 0;
	constexpr s8 Hammer          = 1;
	constexpr s8 Sledgehammer    = 2;
	constexpr s8 MummipokeyStone = 3;
	constexpr s8 DryBowserBone   = 4;

};


// vtable at 02126A6C (ov10)
class Projectile
{
public:

	using StateFunction = bool(Projectile::*)();

	enum class CollisionSide : u8
	{
		None,
		Ground,
		Ceiling,
		Wall
	};


	// 020E7450
	Projectile();

	// D0: 020E73E0
	// D1: 020E7420
	virtual ~Projectile();


	// 020E71D8
	bool spawn(s8 type, const Vec3& position, u16 timer, s32 param, const Vec3* scale, const Vec3s* rotation);
	// 020E72F0
	bool spawn(s8 type, const Vec3& position, u16 timer, u8 direction, const Vec3* scale);
	// 020E7188
	void destroy();
	// 020E6F78
	bool switchUpdate(StateFunction function);
	// 020E7038
	void update();
	// 020E7084
	bool switchRender(StateFunction function);
	// 020E7144
	void render();

	// 020E6F30
	void updateVerticalVelocity();
	// 020E6F0C
	void applyVelocity();

	// 020E787C
	bool createBoomerang();
	// 020E7864
	bool renderBoomerang();
	// 020E7630
	bool updateBoomerang();
	// 020E7490
	bool updateBoomerangCollider();
	// 020E7AC4
	static void boomerangActiveCallback(ActiveCollider& self, ActiveCollider& other);

	// 020E7CE4
	bool createHammer();
	// 020E7CCC
	bool renderHammer();
	// 020E7BB4
	bool updateHammer();
	// 020E7AE8
	bool updateHammerCollider();

	// 020E812C
	bool createSledgehammer();
	// 020E8100
	bool renderSledgehammer();
	// 020E800C
	bool updateSledgehammer();
	// 020E7F00
	bool updateSledgehammerCollider();

	// 020E8930
	bool createMummipokeyStone();
	// 020E8904
	bool renderMummipokeyStone();
	// 020E85F0
	bool updateMummipokeyStone();
	// 020E8410
	bool updateMummipokeyStoneCollider();
	// 020E8354
	CollisionSide updateMummipokeyStoneCollisionMgr();

	// 020E8DF4
	bool createDryBowserBone();
	// 020E8DC8
	bool renderDryBowserBone();
	// 020E8C80
	bool updateDryBowserBone();
	// 020E8B74
	bool updateDryBowserBoneCollider();


	// 02121D2C
	static const fx32 boomerangAccelerationsX[2];
	// 02121D14
	static const fx32 boomerangAccelerationsY[2];
	// 02121D24
	static const fx32 boomerangVelocitiesX[2];
	// 02121D1C
	static const fx32 boomerangVelocitiesY[2];
	// 02121D34
	static const u32 boomerangDirections[2];
	// 02121D3C
	static const FxRect boomerangActiveBox;
	// 02121D4C
	static const ActiveColliderInfo boomerangColliderInfos[4];

	// 02121DBC
	static const s16 hammerRotationsY[2];
	// 02121DC0
	static const fx32 hammerVelocitiesX[2];
	// 02121DC8
	static const FxRect hammerActiveBox;
	// 02121DD8
	static const ActiveColliderInfo hammerColliderInfo;

	// 02121DF4
	static const fx32 sledgehammerVelocitiesX[2];
	// 02121DFC
	static const FxRect sledgehammerActiveBox;
	// 02121E0C
	static const ActiveColliderInfo sledgehammerColliderInfos[2];

	// 02121E44
	static const PointSensor mummipokeyStoneSideSensor;
	// 02121E50
	static const PointSensor mummipokeyStoneTopSensor;
	//  02121E5C
	static const PointSensor mummipokeyStoneBottomSensor;
	// 02121E68
	static const FxRect mummipokeyStoneActiveBox;
	// 02121E78
	static const ActiveColliderInfo mummipokeyStoneColliderInfo;

	// 02121E94
	static const FxRect dryBowserBoneActiveBox;
	// 02121EA4
	static const ActiveColliderInfo dryBowserBoneColliderInfo;

	// 0212A6A8
	static const StateFunction createTable[ProjectileTypes];
	// 0212A6D0
	static PlatformMgr platformManager;
	// 0212A704
	static ActiveCollider activeCollider;
	// 0212A7B4
	static CollisionMgr collisionManager;


	StateFunction renderFunction;
	StateFunction updateFunction;

	u32 unused14[6];

	Vec3 position;
	Vec3 velocity;
	Vec3 scale;
	Vec3s rotation;

	u32 unused68[2];

	fx32 targetVelocityY;
	fx32 accelY;
	u32 unused78;

	u32 userWords[8];
	u16 userShorts[4];
	u16 userTimers[2];

	bool active;
	s8 type;
	s8 modelID;
	u8 direction;
	s32 param;
	u8 playerID;
	s8 renderStep;
	s8 updateStep;
	u8 viewID;

};
NTR_SIZE_GUARD(Projectile, 0xB4);


// vtable at 02126A7C (ov10)
class ProjectileModel
{
public:

	// 020E6EFC
	ProjectileModel();

	// D0: 020E6ECC
	// D1: 020E6EEC
	// D2: 020E6EBC
	virtual ~ProjectileModel();

	// 020E6EB4
	virtual bool create();

	// 020E6EB0
	virtual void render(Projectile& projectile);

};


// vtable at 02126AA4 (ov10)
class BoomerangModel : public ProjectileModel
{
public:

	// 020E7A9C
	BoomerangModel();

	// D0: 020E7A3C
	// D1: 020E7A70
	virtual ~BoomerangModel();

	// 020E79DC
	virtual bool create() override;

	// 020E78B8
	virtual void render(Projectile& projectile) override;


	Model model;

};


// vtable at 02126ACC (ov10)
class HammerModel : public ProjectileModel
{
public:

	// 020E7ED8
	HammerModel();

	// D0: 020E7E78
	// D1: 020E7EAC
	virtual ~HammerModel();

	// 020E7E18
	virtual bool create() override;

	// 020E7D20
	virtual void render(Projectile& projectile) override;


	Model model;

};


// vtable at 02126AF4 (ov10)
class SledgehammerModel : public ProjectileModel
{
public:

	// 020E832C
	SledgehammerModel();

	// D0: 020E82CC
	// D1: 020E8300
	virtual ~SledgehammerModel();

	// 020E828C
	virtual bool create() override;

	// 020E8168
	virtual void render(Projectile& projectile) override;


	Model model;

};


// vtable at 02126B1C (ov10)
class MummipokeyStoneModel : public ProjectileModel
{
public:

	// 020E8B4C
	MummipokeyStoneModel();

	// D0: 020E8AEC
	// D1: 020E8B20
	virtual ~MummipokeyStoneModel();

	// 020E8A8C
	virtual bool create() override;

	// 020E896C
	virtual void render(Projectile& projectile) override;


	Model model;

};


// vtable at 02126B44 (ov10)
class DryBowserBoneModel : public ProjectileModel
{
public:

	// 020E8FF0
	DryBowserBoneModel();

	// D0: 020E8F90
	// D1: 020E8FC4
	virtual ~DryBowserBoneModel();

	// 020E8F50
	virtual bool create() override;

	// 020E8E30
	virtual void render(Projectile& projectile) override;


	Model model;

};


// vtable at 02126A5C (ov10)
class ProjectileHandler
{
public:

	// 020E6E34
	ProjectileHandler();

	// D0: 020E6DA4
	// D1: 020E6DF0
	virtual ~ProjectileHandler();

	// 020E6B60
	bool spawn(s8 type, const Vec3& position, u16 timer, s32 param, const Vec3* scale, const Vec3s* rotation);
	// 020E6BBC
	bool spawn(s8 type, const Vec3& position, u16 timer, u8 direction, const Vec3* scale);

	// 020E6ABC
	void update();
	// 020E6AF8
	void renderSingle(Projectile& projectile);
	// 020E6B24
	void render();

	// 020E6C10
	bool init();
	// 020E6A40
	void destroy();


	Projectile projectiles[32];
	ProjectileModel* models[ProjectileTypes];
	Heap* modelHeap;

};
NTR_SIZE_GUARD(ProjectileHandler, 0x169C);


namespace Projectiles {

	// 020E6964
	bool spawn(s8 type, const Vec3& position, u16 timer, s32 param, const Vec3* scale, const Vec3s* rotation);
	// 020E69A4
	bool spawn(s8 type, const Vec3& position, u16 timer, u8 direction, const Vec3* scale);

	// 020E69DC
	void update();
	//020E69F4
	void renderSingle(Projectile& projectile);
	// 020E6A10
	void render();

	// 020E6A28
	bool init();
	// 020E694C
	void destroy();

	// 0212A680
	extern ProjectileHandler* projectileHandler;

}
