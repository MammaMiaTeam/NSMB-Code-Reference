#pragma once
#include "view.h"
#include "nsmb/math/vector.h"


// ov10
class OrthoView : public View
{
public:

	Vec3 target;
	Vec3 position;
	Vec3 up;
	Vec3s rotation;

	//D0:020ce734
	//D1:020ce6dc
	sym virtual ~OrthoView() __body

};
NTR_SIZE_GUARD(OrthoView, 0x108);
