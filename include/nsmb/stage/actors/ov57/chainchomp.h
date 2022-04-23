#pragma once
#include "nsmb.h"
#include "chainchompchain.h"


// vtable at 0217575C (ov57)
class ChainChomp : public StageEntity
{
public:

	using StateFunction = bool(ChainChomp::*)();

	
	// D0: 02173B70
	// D1: 02173A98
	virtual ~ChainChomp();

	// 02173F98
	s32 onCreate() override;
	// 02173E0C
	s32 onRender() override;
	// 0217534C
	bool onPrepareResources() override;

	// 02173EA4
	bool updateMain() override;

	// 02173CF4
	void onEntityHit() override;
	// 02173CC8
	void onStarmanHit() override;
	// 02173C70
	void onMegaHit() override;
	// 02173C9C
	void onBlueShellHit() override;

	// 02173D20
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 02174D58
	bool destroyInactive();
	// 02174E6C
	bool checkOutOfRange(const Vec3& position, const FxRect& rect);
	// 02174EBC
	void updateColliderRotation();
	// 02174F5C
	u16 calculateAimTarget() const;
	// 0217501C
	void despawn();
	// 021750B4
	void release();
	// 02175128
	void flagDefeated() const;
	// 02175158
	bool updateTurnRotation();

	// 02175268
	bool switchState(StateFunction function);
	// 0217522C
	void updateState();

	// 0217416C
	bool defeatedState();
	// 02174224
	bool releasedState();
	// 0217430C
	bool restState();
	// 02174698
	bool attackState();
	// 021748B4
	bool aimState();
	// 021749FC
	bool walkState();

	// 021753B8
	static bool loadResources();

	static constexpr u16 objectID = 45;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 59;

	// 02175750
	static const ActorProfile profile;

	// 0217550C
	static const ActiveColliderInfo activeColliderInfo;

	// 021754D4
	static const s16 rotationStepsY[2];
	// 021754D8
	static const fx32 defaultVerticalOffset;
	// 021754DC
	static const fx32 defaultColliderOffset;
	// 021754E0
	static const fx32 defaultGroundOffset;
	// 021754E4
	static const s16 rotationsY[2];
	// 021754E8
	static const fx16 playerBumpVelocities[2];
	// 021754EC
	static const fx32 defaultScale;
	// 021754F0
	static const fx32 defaultHomeOffsetY;
	// 021754F4
	static const fx32 releasedVelocitiesX[2];
	// 021754FC
	static const fx32 accelerationsX[2];
	// 02175504
	static const fx32 targetVelocitiesX[2];


	ChainChompChain chain;

	StateFunction updateFunction;

	ModelAnm model;

	Vec3 spawnPosition;
	Vec3 homePosition;
	fx32 groundPosition;
	fx32 colliderOffset;

	u16 aimRotation;
	u16 aimTarget;

	s8 updateStep;
	u8 attackTimer;
	bool chainTightFlag;
	bool restLandedFlag;
	bool aimingFlag;
	u8 jumpsLeft;
	u8 playerCollisionCooldown;

};
NTR_SIZE_GUARD(ChainChomp, 0x8A8);
