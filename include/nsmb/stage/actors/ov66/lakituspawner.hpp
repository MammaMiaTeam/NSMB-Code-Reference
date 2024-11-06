#pragma once
#include "nsmb.hpp"

// vtable at 02178954 (ov66)
class LakituSpawner : public StageEntity
{
public:

	using StateFunction = bool(LakituSpawner::*)();

	// D0: 021759A0
	// D1: 021759FC
	virtual ~LakituSpawner();

	// 02175B14
	s32 onCreate() override;
	// 02175A60
	s32 onUpdate() override;

	// 02175A7C
	void updateDestroy();

	// 02175F34
	void callState();
	// 02175F7C
	bool switchState(const StateFunction& function);
	// 02175B64
	bool mainState();

	// 02175D78
	void attachLakitu(); // sets spawned lakitu's unk2C6 to 1

	// 02175D8C
	void updateSpawner(Player* player, u32 lakituID);
	// 02175E28
	void spawnLakitu(Player* player);

	// 02175EC4
	bool targetAvailable(Player* player);
	// 02176008
	static bool loadResources();

	static constexpr u16 ObjectID = 59;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 73;

	// 02178948
	static const ActorProfile profile;

	// 02178C20
	static StateFunction sMain;


	const StateFunction* updateFunction;

	Lakitu* lakitus[2];
    u32 lakituGUIDs[2];
    u16 spawnCooldowns[2];
    bool multiTarget;
    u8 zoneID;
    u8 spinyType; 	// 0=Normal; 1=Rolling
    u8 unused40F;
    s8 updateStep;


#if NTR_EXT_EXISTS(LakituSpawner)
	#include NTR_EXT_INCLUDE(LakituSpawner)
#endif

};
#if !NTR_EXT_EXISTS(LakituSpawner)
NTR_SIZE_GUARD(LakituSpawner, 0x414);
#endif
