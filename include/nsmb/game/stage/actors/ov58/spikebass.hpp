#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/modelanm.hpp>
#include <nsmb/extra/bits.hpp>

// vtable at 0217368C (ov58)
class SpikeBass : public StageEntity {
public:

	using StateFunction = bool(SpikeBass::*)();

	struct Settings : StrongBitFlag<u32> {
		u8 unused0 			  : 4;
		bool spawnedBySpawner : 4;
		u32 unused8			  : 24;
	};

	// D1: 021726c0
	// D0: 02172728
	virtual ~SpikeBass() override;

	// 021729e8
	s32 onCreate() override;
	// 021727d0
	s32 onRender() override;
	// 02172798
	s32 onDestroy() override;

	// 02172ac0
	bool onPrepareResources() override;
	// 021727cc
	void onCleanupResources() override;

	// 021728c0
	bool updateMain() override;

	// 02172908
	void updateEffects();

	// 021730d8
	bool switchState(StateFunction function);
	// 0217309c
	void updateState();

	// 02172b4c
	bool jumpState();
	// 02172c9c
	bool beginJumpState();
	// 02172dd8
	bool swimState();

	// 02172b18
	static bool loadResources();

	static constexpr u16 ObjectID = 150;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 174;

	// 02173680
	static const ActorProfile profile;

	// 02173638
	static const AcConfig acConfig;
	// 02173630
	static const fx32 velocitiesX[2]; // [direction]


	ModelAnm model;
	StateFunction updateFunction;
	StateFunction prevUpdateFunction;
	u32 spawnerGID;
	fx32 jumpStartVelX;
	u8 jumpCooldown;
	bool diving; // when landing from a jump
	u8 turnCount;
	s8 updateStep;

};
NTR_SIZE_GUARD(SpikeBass, 0x4B8);
