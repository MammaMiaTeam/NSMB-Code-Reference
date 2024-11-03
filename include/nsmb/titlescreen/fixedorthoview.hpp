#pragma once
#include "nsmb/graphics/util/view.hpp"
#include "nsmb/math/vector.hpp"

class FixedOrthoView : public View {
public:

	virtual ~FixedOrthoView();


	Vec3 target;
	Vec3 position;
	Vec3 up;
	Vec3s rotation;

};
NTR_SIZE_GUARD(FixedOrthoView, 0x108);
