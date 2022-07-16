#pragma once
#include "nsmb.h"


// vtable at 0217988C (ov71)
class Splunkin : public StageEntity
{
public:

	using StateFunction = bool(Splunkin::*)();

	// D0: 021783F0
	// D1: 02178378
	virtual ~Splunkin();

	// 021786AC
	s32 onCreate() override;
	// 0217847C
	s32 onRender() override;
	// 02178470
	s32 onDestroy() override;
	// 02178478
	void onCleanupResources() override;
	// 02178FC4
	bool onPrepareResources() override;

	// 02178508
	bool updateMain() override;

	// 021789F0
	void onStomped() override;

	// 02178E64
	bool playerCollision(ActiveCollider& self, ActiveCollider& other) override;
	// 02178DAC
	void entityCollision(ActiveCollider& self, StageActor& actor) override;
	// 02178A64
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 02178534
	void updateCrackingFactor();
	// 02178550
	void updateCracking();
	// 021785B8
	void setCrackingScale();
	// 02178630
	void animateCracking();

	// 02178EF0
	bool switchState(StateFunction function);
	// 02178E90
	void updateState();

	// 0217892C
	bool walkState();
	// 02178824
	bool turnState();

	// 02178678
	static void setMaterialPalette(Model& model, u32 matID, u32 paletteID);

	// 0217905C
	static bool loadResources();

	static constexpr u16 objectID = 127;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 184;

	// 0x02179880
	static const ActorProfile profile;

	// 0x021792D4
	static const ActiveColliderInfo activeColliderInfo;

	// 0x021792C8
	static const PointSensor sideSensor;
	// 0x021792BC
	static const PointSensor topSensor;
	// 0x021792B0
	static const PointSensor bottomSensor;

	// 0x021792AC
	static const s16 turnRotations[2];
	// 0x021792A8
	static const s16 turnRotationSteps[2];
	// 0x021792A4
	static const u16 paletteOffsets[2];

	// 021799B8
	static u16 paletteBase;


	ModelAnm bodyModel;
	Animation crackPattern;

	u32 unused4BC;

	StateFunction updateFunction;
	s8 updateStep;

	u8 health;

	u8 crackingTimer;
	fx32 crackingScale;
	fx32 crackingFactor;

	fx32 walkSpeed;

};
NTR_SIZE_GUARD(Splunkin, 0x4D8);
