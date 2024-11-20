#pragma once

#include <nsmb/core/entity/object.hpp>

class View : public Object
{
public:

	MtxFx44 unk5C;
	MtxFx43 viewMatrix;

	//020a3abc
	virtual s32 onRender() override;

	//D0:020a3a88
	//D1:020a3a5c
	virtual ~View();


};
NTR_SIZE_GUARD(View, 0xCC);
