#pragma once
#include "nsmb/entity/object.h"


class View : public Object
{
public:

	MtxFx44 unk5C;
	MtxFx43 viewMatrix;

	//020a3abc
	sym virtual s32 onRender() override __rbody

	//D0:020a3a88
	//D1:020a3a5c
	sym virtual ~View() __body


};
NTR_SIZE_GUARD(View, 0xCC);
