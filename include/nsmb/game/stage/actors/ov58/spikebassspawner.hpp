#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/extra/bits.hpp>

// vtable at 021737b4 (ov58)
class SpikeBassSpawner : public StageEntity {
public:

	using StateFunction = bool(SpikeBassSpawner::*)();

	struct Settings : StrongBitFlag<u32> {
		u8 unused;
		u8 zoneID;
		u16 free : 16;
	};


	// D1: 021731bc
	// D0: 02173218
	virtual ~SpikeBassSpawner() override;

	// 02173294
	s32 onCreate() override;
	// 0217327c
	s32 onUpdate() override;

	// 02173424
	u32 spawn(); // returns spike bass GID if spawn is successful, otherwise 0

	// 02173528
	bool switchState(StateFunction function);
	// 021734f4
	void updateState();

	// 021732d4
	bool mainState();


	// 021735e8
	static bool loadResources();

	static constexpr u16 ObjectID = 157;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 183;

	// 021737a8
	static const ActorProfile profile;


	StateFunction updateFunction;
	u32 spikeBassGID;
	s16 spawnCooldown;
	u8 zoneID;
	s8 updateStep;

};
NTR_SIZE_GUARD(SpikeBassSpawner, 0x404);
