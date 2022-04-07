#pragma once
#include "nsmb/graphics/util/view.h"
#include "nsmb/math/vector.h"


//ov9
class FixedOrthoView : public View
{
public:

	Vec3 target;
	Vec3 position;
	Vec3 up;
	Vec3s rotation;

	//D0:0x020D3E4C
	//D1:0x020D3DF4
	virtual ~FixedOrthoView();

};
NTR_SIZE_GUARD(FixedOrthoView, 0x108);
