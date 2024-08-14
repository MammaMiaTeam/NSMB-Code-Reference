#pragma once
#include "nsmb.hpp"


// vtable at 0218E1FC (ov121)
class SpikedBallTrigger : public StageEntity
{
public:

	// D0: 0218DD74
	// D1: 0218DD18
	virtual ~SpikedBallTrigger();

	// 0218DE74
	s32 onCreate() override;
	// 0218DDD8
	s32 onDestroy() override;
	// 0218DDE0
	void onCleanupResources() override;

	// 0218DDE4
	bool updateMain() override;

	static constexpr u16 ObjectID = 104;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 225;

	// 0218E1F0
	static const ActorProfile profile;


	u8 spikedBallID;
	u32 unused3F4;

};
NTR_SIZE_GUARD(SpikedBallTrigger, 0x3F8);
