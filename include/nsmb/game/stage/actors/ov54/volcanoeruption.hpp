#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/model.hpp>

// vtable at 0217013C (ov54)
class VolcanoEruption : public StageEntity
{
public:

	using StateFunction = bool(VolcanoEruption::*)();

	~VolcanoEruption() override;

	s32 onCreate() override;
	s32 onDestroy() override;
	s32 onRender() override;
	void onCleanupResources() override;
	bool onPrepareResources() override;

	bool updateMain() override;
	bool skipRender() override;
	void onBlockHit() override;
	void onStageBeaten(Player& player) override;

	s32 getRockSlot(ActiveCollider& collider) const;
	void spawnBrokenRock(s32 rockID);
	void spawnFallingRock(s32 rockID);
	void spawnEruptingRock(s32 rockID);
	s32 getFreeRockSlot() const;

	bool switchState(StateFunction func);
	bool updateState();

	bool eruptState();
	bool waitState();
	bool rocksFallingState();

	static VolcanoEruption* erupt(const Vec3& position, u8 viewID);

	static void activeCallback(ActiveCollider& self, ActiveCollider& other);
	static bool loadResources();

	static constexpr u16 ObjectID = 121;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 140;

	static const ActorProfile profile;
	static const AcConfig acConfig;
	static const PointSensor bottomSensorSmall;
	static const PointSensor bottomSensorBig;
	static const fx16 eruptionVelocitiesX[10];				// [rockID]
	static const fx32 fallVelocitiesY[3];					// [set]
	static const u8 eruptionVelocitySets[3][10];			// [set][rockID]
	static const u8 eruptionScaleSets[10][10];				// [set][rockID]
	static const u16 fallOffsetFactors[10][10];				// [set][rockID]


	Model rockModel;

	StateFunction updateFunction;

	ActiveCollider rockColliders[10];
	Vec2 rockPositions[10];
	Vec2 rockVelocities[10];
	Vec2 rockScales[10];
	Vec3s rockRotations[10];

	u16 bigRocks;
	u16 activeRocks;
	u16 hiddenRocks;
	u16 destroyedRocks;
	u16 fallingRocks;
	u8 rockSpawnCooldown;
	u8 eruptSpreadSet;
	u8 fallSpreadSet;
	u8 fallScalesSet;
	u8 fastBigRocksCount;
	s8 closestPlayerID;
	u8 rockDrawPriority[10];
	u8 rockDrawPrioTimer[10];
	s8 updateStep;


#if NTR_EXT_EXISTS(VolcanoEruption)
	#include NTR_EXT_INCLUDE(VolcanoEruption)
#endif

};
#if !NTR_EXT_EXISTS(VolcanoEruption)
NTR_SIZE_GUARD(VolcanoEruption, 0xD74);
#endif
