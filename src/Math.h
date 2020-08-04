#ifndef NSMB_MATH_INCLUDED
#define NSMB_MATH_INCLUDED

#include "nitro_if.h"


namespace Math {

	//u32:02043380
	//u16:02043398
	//s16:020433b0
	//u8:020433c8
	//s8:020433e0
	extern template<typename T>
	T timerTick(T* timer);

	//020433f8
	//02043464
	//020434d8
	//s16:0204354c
	//020435a8

	//lerp:02043604

	//02043674

	//02043750
	bool inRange(s32 x, s32 a, s32 b);

	//02043790
	s16 distance(s16 a, s16 b);

	//020437a4
	//020437f4

	//020848e4
	fx16 atan2Table[1025];

	//02043b6c
	fx16 atan2(fx32 y, fx32 x);

	//02043d10 (global counter)

	//02043d30
	fx16 angle(const Vec3& a, const Vec3& b);//X and Z


}




#endif	// NSMB_MATH_INCLUDED
