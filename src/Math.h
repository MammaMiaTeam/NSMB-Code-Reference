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
	void lerp(s16& start, s16 end, s16 ratio, s16 maxStep);

	//02043674
	s16 lerp(s16& start, s16 end, s16 ratio, s16 maxStep, s16 minStep);

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

	//0208b668
	u32 frameCounter;

	//0208b66c
	u32 unusedCounter;

	//02043d10
	void resetFrameCounters();

	//02043d30
	fx16 angle(const Vec3& a, const Vec3& b);//X and Z

	//2D:02043d5c
	bool lerp(Vec2& start, const Vec2& end, fx32 step);

	//3D:02043e30
	bool lerp(Vec3& start, const Vec3& end, fx32 step);

	//02043f10
	void lerp(Vec2& start, const Vec2& end, fx32 scale, fx32 maxStep);

	//02043fe0
	void lerp(Vec2& start, const Vec2& end, fx32 scale, fx32 maxStep, fx32 minStep);

	//02044120
	void lerp(Vec3& start, const Vec3& end, fx32 scale, fx32 maxStep, fx32 minStep);

	//02044280 (sub?)
	//void subtract();

	//020442b0
	u32 nextRandom(u32& value);

	//020442dc
	u32 generateSeed();


	//02044308 wtf


}




#endif	// NSMB_MATH_INCLUDED
