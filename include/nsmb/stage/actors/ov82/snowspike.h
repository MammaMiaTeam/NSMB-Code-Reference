#pragma once
#include "nsmb.h"


// vtable at 0217BAB4 (ov82)
class SnowSpike : public StageEntity
{
public:

	using StateFunction = bool(SnowSpike::*)();

	~SnowSpike() override;

	s32 onCreate() override;
	s32 onDestroy() override;
	s32 onRender() override;
	void onCleanupResources() override;
	bool onPrepareResources() override;

	bool updateMain() override;
	bool skipRender() override;
	void updateAnimation() override;
	void onStomped() override;
	void damagePlayer(ActiveCollider& self, Player& player) override;

	void destroyInactive();
	bool playerCollided(Player& player);

	bool switchState(StateFunction func);
	bool updateState();

	bool idleState();
	bool turnState();
	bool createSnowballState();
	bool grabSnowballState();
	bool throwSnowballState();

	static bool loadResources();

	static constexpr u16 objectID = 155;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 180;

	static const ActorProfile profile;
	static const ActiveColliderInfo activeColliderInfo;
	static const PointSensor sideSensor;
	static const PointSensor bottomSensor;
	static const PointSensor topSensor;
	static const VecFx32 armBoneOffset;
	static const fx32 snowballVelocitiesX[2];
	static const fx32 snowballMouthVelocitiesX[2];
	static const u32 armBoneIDs[2];
	static const s16 rotationsY[2];


	ModelAnm spikeModel;
	Model snowballModel;

	StateFunction updateFunction;
	StateFunction lastUpdateFunction;

	Vec3 mouthBonePos;
	Vec3 armBonePos;
	Vec3 snowballPos;
	Vec3 unk56C;
	Vec3 snowballScale;
	Vec2 snowballVelocity;

	s16 spikeTurnRot;
	bool spikeHidden;
	bool snowballVisible;
	s8 updateStep;

};
NTR_SIZE_GUARD(SnowSpike, 0x5A0);
