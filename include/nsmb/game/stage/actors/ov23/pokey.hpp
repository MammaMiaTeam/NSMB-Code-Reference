#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/model.hpp>

// vtable at 0213EBFC (ov23)
class Pokey : public StageEntity
{
public:

	using StateFunction = bool(Pokey::*)();

	s32 onCreate() override;
	s32 onDestroy() override;
	s32 onRender() override;
	void onCleanupResources() override;
	bool onPrepareResources() override;

	bool updateMain() override;
	bool updateDefeated() override;
	bool updateDefeatedMega() override;
	void updateFireballWiggle() override;

	void onEntityHit() override;
	void onFireballHit() override;
	void onStarmanHit() override;
	void onMegaHit() override;
	void onSpinDrillHit() override;
	void onBlueShellHit() override;

	bool isBodyPartInactive(u32 slot) const;
	void destroyBodyPart(ActiveCollider& collider);
	s32 getBodyPartSlot(ActiveCollider& collider) const;
	void damaged();
	void explodeMega();
	void explode();

	bool switchState(StateFunction function);
	void updateState();

	bool mainState();

	static bool loadResources();
	static void activeCallback(ActiveCollider& self, ActiveCollider& other);

	static constexpr u16 ObjectID = 98;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 232;

	static const ActorProfile profile;

	static const AcConfig acConfig;

	static const PointSensor bottomSensor;
	static const PointSensor sideSensor;
	static const s16 rotationsY[2];
	static const fx16 heightVelocitiesX[9][2];
	static const fx32 hitVelocities[9][2];


	Model bodyPartModels[9];
	Vec3 bodyPartPositions[9];
	ActiveCollider bodyPartColliders[9];

	StateFunction updateFunction;
	StateFunction lastUpdateFunction;

	AcConfig currentAcConfig;

	u16 removedBodyParts;
	u16 hiddenBodyParts;
	u16 fallingBodyParts;
	u16 activeBodyParts;

	bool groundHit;
	u8 initialHeight;
	s8 updateStep;
	s8 bodyPartHitSlot;

	Vec2 bodyPartVelocities[9];
	fx32 bodyPartPositionsY[9];
	bool bodyPartsDestroyed[9];
	u8 bodyPartWiggleTimers[9];
	s16 bodyPartRotations[9];


#if NTR_EXT_EXISTS(Pokey)
	#include NTR_EXT_INCLUDE(Pokey)
#endif

};
#if !NTR_EXT_EXISTS(Pokey)
NTR_SIZE_GUARD(Pokey, 0x10B0);
#endif
