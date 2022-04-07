#pragma once
#include "nsmb/entity/actor.h"


// vtable at 0203CF30 (arm9)
class alignas(4) StageController : public Actor {

public:

	// 0201FFC4
	sym StageController() __body

	// D0: 0201FF40
	// D1: 0201FF20
	sym inline virtual ~StageController() {}

	// 0201FF80
	sym virtual bool preUpdate() override __rbody


	u8 unk120; // preUpdate related

};
NTR_SIZE_GUARD(StageController, 0x124);
