#pragma once
#include "nsmb.h"


// vtable at 02126BEC (ov10)
class Actor22 : public StageEntity
{
public:

	// D0: 020E93C4
	// D1: 020E9368
	virtual ~Actor22();

	static constexpr u16 objectID = 22;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 29;

	// 02126BE0
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(Actor22, sizeof(StageEntity));
