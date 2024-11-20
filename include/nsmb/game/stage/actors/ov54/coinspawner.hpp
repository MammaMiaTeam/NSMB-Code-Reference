#pragma once

#include <nsmb/game/stage/entity.hpp>

// vtable at 0216D4E8 (ov54)
class CoinSpawner : public StageEntity
{
public:

	using StateFunction = bool(CoinSpawner::*)();

	// D0: 02156DF0
	// D1: 02156D94
	virtual ~CoinSpawner();

	// 02156E74
	s32 onCreate() override;

	// 02156E54
	bool updateMain() override;

	// 02157128
	bool switchState(const StateFunction& function);
	// 021570E0
	void updateState();

	// 02156F44
	bool mainState();

	static constexpr u16 ObjectID = 92;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 119;

	// 0216D4DC
	static const ActorProfile profile;

	// 02171770
	static const StateFunction sMain;


	const StateFunction* updateFunction;

	bool32 musicTriggered;
	u32 coinsLeft;
	u32 coinCount;
	u32 coinSpeed;
	bool32 triggerSpawn;

	s8 updateStep;


#if NTR_EXT_EXISTS(CoinSpawner)
	#include NTR_EXT_INCLUDE(CoinSpawner)
#endif

};
#if !NTR_EXT_EXISTS(CoinSpawner)
NTR_SIZE_GUARD(CoinSpawner, 0x410);
#endif
