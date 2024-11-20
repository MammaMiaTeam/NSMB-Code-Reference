#pragma once

#include "view.hpp"
#include <nsmb/core/math/vector.hpp>


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
	virtual ~OrthoView();

};
NTR_SIZE_GUARD(OrthoView, 0x108);
