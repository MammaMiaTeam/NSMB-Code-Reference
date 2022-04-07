#pragma once
#include "view.h"
#include "nsmb/math/vector.h"


//ov8
class PerspView : public View
{
public:

	Vec3 target;
	Vec3 position;
	Vec3 up;
	Vec3s rotation;

	//D0:0218cd58
	//D1:0218cd00
	sym virtual ~PerspView() __body

};
NTR_SIZE_GUARD(PerspView, 0x108);
