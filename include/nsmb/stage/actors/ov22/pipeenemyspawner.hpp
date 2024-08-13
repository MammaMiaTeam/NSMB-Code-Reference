#pragma once
#include "nsmb.hpp"

// vtable at 0213C554 (ov22)
class PipeEnemySpawner : public StageEntity
{
public:

	using StateFunction = bool(PipeEnemySpawner::*)();

	enum class EnemyType : u32 {
		Goomba,
		BobOmb
	};

	// D0: 0213Bf5C
	// D1: 0213BF00
	virtual ~PipeEnemySpawner();

	// 0213BFD8
	s32 onCreate() override;

	// 0213BFC0
	s32 onUpdate() override;

	// 0213C3D0
	bool switchState(const StateFunction& function);
	// 0213C388
	void updateState();

	// 0213C034
	bool mainState();

	// 0213C2EC
	void spawnGoomba();
	// 0213C248
	void spawnBobOmb();

	static constexpr u16 objectID = 64;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 78;

	// 0213C548
	static const ActorProfile profile;

	// 0213C680
	static const StateFunction sMain;

	// 0213C4C0
	static const u16 goombaCooldowns[3]; // Indexed by spawnCounter
	// 0213C4C8
	static const fx32 goombaOffsetsX[4]; // Indexed by pipe direction 
	// 0213E4E8
	static const fx32 goombaOffsetsY[4];
	// 0213C4F8
	static const fx32 bobOmbOffsetsX[4];
	// 0213C4D8
	static const fx32 bobOmbOffsetsY[4];

	const StateFunction* updateFunction;

	EnemyType enemyType;
	u16 spawnCooldown;
	u16 spawnCounter;  
	s8 updateStep;

};
NTR_SIZE_GUARD(PipeEnemySpawner, 0x404);
