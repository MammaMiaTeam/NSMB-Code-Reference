#pragma once

#include <nsmb/core/entity/actor.hpp>

// vtable at 0203CF30 (arm9)
class alignas(4) StageController : public Actor {

public:

	// 0201FFC4
	StageController();

	// D0: 0201FF40
	// D1: 0201FF20
	inline virtual ~StageController() {}

	// 0201FF80
	virtual bool preUpdate() override;


	u8 unk120; // preUpdate related

};
NTR_SIZE_GUARD(StageController, 0x124);
