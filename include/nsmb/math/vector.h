#pragma once
#include "nitro_if.h"
#include "ntr_assert.h"
#include "nodiscard.h"
#include "math.h"


namespace Math {

	// 02046030
	s32 sqrt64(s64 value);

}

/*
*	3D Vector class
*/
class Vec3 : public VecFx32
{
public:

	// C2: 02003180
	constexpr Vec3() : VecFx32{} {}

	constexpr Vec3(fx32 v) : VecFx32{} {
		this->x = v;
		this->y = v;
		this->z = v;
	}

	constexpr Vec3(fx32 x, fx32 y, fx32 z) : VecFx32{} {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	constexpr Vec3(const VecFx32& vec) : VecFx32(vec) {}

	constexpr Vec3(const VecFx16& vec) : VecFx32{} {
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}

	// D0: 02003190
	// D1: 02003080
	constexpr virtual ~Vec3() {}



	constexpr void set(fx32 v) {
		this->x = v;
		this->y = v;
		this->z = v;
	}

	constexpr void set(fx32 x, fx32 y, fx32 z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	constexpr void set(const VecFx32& vec) {
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}

	constexpr void set(const VecFx16& vec) {
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}



	constexpr bool isNull() const {
		return x == 0 && y == 0 && z == 0;
	}



	constexpr Vec3& add(const VecFx32& rhs) {
		return *this += rhs;
	}

	constexpr Vec3& sub(const VecFx32& rhs) {
		return *this -= rhs;
	}

	constexpr Vec3& mul(fx32 rhs) {

		if_consteval {

			x = Math::mul(x, rhs);
			y = Math::mul(y, rhs);
			z = Math::mul(z, rhs);

			return *this;
		}
		else {
			return *this *= rhs;
		}

	}

	constexpr Vec3& div(fx32 rhs) {
		return *this /= rhs;
	}

	// 02045BDC
	ntr_nodisc static Vec3 add(const Vec3& a, const VecFx32& b);
	// 02045B90
	ntr_nodisc static Vec3 sub(const Vec3& a, const VecFx32& b);
	// 02045B24
	ntr_nodisc static Vec3 mul(const Vec3& vec, fx32 factor);

	ntr_nodisc constexpr Vec3 div(const Vec3& vec, fx32 factor) {

		//ntr_assert(factor != 0, "Tried to divide vector by zero");

		Vec3 out;

		out.x = Math::div(vec.x, factor);
		out.y = Math::div(vec.y, factor);
		out.z = Math::div(vec.z, factor);

		return out;

	}



	ntr_nodisc constexpr Vec3 operator+(const VecFx32& rhs) const {

		Vec3 out = *this;

		out.add(rhs);

		return out;

	}

	ntr_nodisc constexpr Vec3 operator-(const VecFx32& rhs) const {

		Vec3 out = *this;

		out.sub(rhs);

		return out;

	}

	ntr_nodisc constexpr Vec3 operator*(fx32 rhs) const {

		Vec3 out = *this;

		out.mul(rhs);

		return out;

	}

	ntr_nodisc constexpr Vec3 operator/(fx32 rhs) const {

		Vec3 out = *this;

		out.div(rhs);

		return out;

	}

	constexpr Vec3& operator+=(const VecFx32& rhs) {

		x += rhs.x;
		y += rhs.y;
		z += rhs.z;

		return *this;

	}

	constexpr Vec3& operator-=(const VecFx32& rhs) {
		
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;

		return *this;

	}

	// 02045ABC
	Vec3& operator*=(fx32 rhs);

	constexpr Vec3& operator/=(fx32 rhs) {

		//ntr_assert(rhs != 0, "Tried to divide vector by zero");

		x = Math::div(x, rhs);
		y = Math::div(y, rhs);
		z = Math::div(z, rhs);

		return *this;

	}

	ntr_nodisc constexpr Vec3 operator-() const {
		return Vec3(-x, -y, -z);
	}

	// 02045A80
	bool operator==(const VecFx32& rhs) const;
	// 02045A40
	bool operator!=(const VecFx32& rhs) const;



	ntr_nodisc inline fx32 length() const {
		return VEC_Mag(this);
	}

	// 020459FC
	ntr_nodisc fx32 distance(const VecFx32& other) const; // Calculates the distance from the vector to another one
	// 020459AC
	Vec3 cross(const VecFx32& other) const; // Performs the cross product between the vector and another one, then returns it
	// 02045958
	Vec3 cross(const VecFx32& a, const VecFx32& b); // Performs a x b storing the result in the vector and returning it

	NTR_INLINE fx32 dot(const VecFx32& other) const {
		return VEC_DotProduct(this, &other);
	}

	// 02045908
	ntr_nodisc Vec3 normalize(); // Normalizes the vector and returns it
	// 020458B0
	bool normalizeSafe(); // Normalizes the vector if not null

	inline Vec3 normalized() const {

		Vec3 out = *this;

		ntr_ignore = out.normalize();

		return out;

	}



	// 02045C28
	void applyRotXY(s16 angle); // Rotates the vector around the z-axis
	// 02045808
	void applyRotYZ(s16 angle); // Rotates the vector around the x-axis
	// 02045760
	void applyRotXZ(s16 angle); // Rotates the vector around the y-axis



	inline void lerp(const VecFx32& end, fx32 step) {

		x = Math::lerpFx(x, end.x, step);
		y = Math::lerpFx(y, end.y, step);
		z = Math::lerpFx(z, end.z, step);

	}

	inline static Vec3 lerp(const VecFx32& start, const VecFx32& end, fx32 step) {

		Vec3 out = start;

		out.lerp(end, step);

		return out;

	}

};
NTR_SIZE_GUARD(Vec3, 0x10);

/*
*	2D Vector class
*/
class Vec2
{
public:

	// C2: 02003160
	constexpr Vec2() :
		x(0), y(0)
	{}

	constexpr Vec2(fx32 v) :
		x(v), y(v)
	{}

	constexpr Vec2(fx32 x, fx32 y) :
		x(x), y(y)
	{}

	constexpr Vec2(const VecFx32& vec) :
		x(vec.x), y(vec.y)
	{}

	constexpr Vec2(const FxRect& rect) :
		x(rect.x), y(rect.y)
	{}

	// D0: 020031d0
	// D1: 020030d8
	constexpr virtual ~Vec2() {}



	constexpr void set(fx32 v) {
		this->x = v;
		this->y = v;
	}

	constexpr void set(fx32 x, fx32 y) {
		this->x = x;
		this->y = y;
	}

	constexpr void set(const VecFx32& vec) {
		this->x = vec.x;
		this->y = vec.y;
	}

	constexpr void set(const VecFx16& vec) {
		this->x = vec.x;
		this->y = vec.y;
	}



	constexpr bool isNull() const {
		return x == 0 && y == 0;
	}



	constexpr Vec2& add(const FxRect& rhs) {
		return *this += rhs;
	}

	constexpr Vec2& add(const VecFx32& rhs) {
		return *this += rhs;
	}

	constexpr Vec2& sub(const VecFx32& rhs) {
		return *this -= rhs;
	}

	constexpr Vec2& mul(fx32 rhs) {

		if_consteval {

			x = Math::mul(x, rhs);
			y = Math::mul(y, rhs);

			return *this;
		}
		else {
			return *this *= rhs;
		}

	}

	constexpr Vec2& div(fx32 rhs) {
		return *this /= rhs;
	}

	// 02045FF4
	static Vec2 add(const Vec2& a, const VecFx32& b);
	// 02045FB8
	static Vec2 sub(const Vec2& a, const VecFx32& b);
	// 02045F60
	static Vec2 mul(const Vec2& vec, fx32 factor);
	// 02045E88
	static Vec2 div(const Vec2& vec, fx32 factor);



	constexpr Vec2 operator+(const FxRect& rhs) const {

		Vec2 out = *this;

		out.add(rhs);

		return out;

	}

	constexpr Vec2 operator+(const VecFx32& rhs) const {

		Vec2 out = *this;

		out.add(rhs);

		return out;

	}

	constexpr Vec2 operator-(const VecFx32& rhs) const {

		Vec2 out = *this;

		out.sub(rhs);

		return out;

	}

	constexpr Vec2 operator*(fx32 rhs) const {

		Vec2 out = *this;

		out.mul(rhs);

		return out;

	}

	constexpr Vec2 operator/(fx32 rhs) const {

		Vec2 out = *this;

		out.div(rhs);

		return out;

	}

	constexpr Vec2& operator+=(const FxRect& rhs) {

		x += rhs.x;
		y += rhs.y;

		return *this;

	}

	constexpr Vec2& operator+=(const VecFx32& rhs) {

		x += rhs.x;
		y += rhs.y;

		return *this;

	}

	constexpr Vec2& operator-=(const VecFx32& rhs) {

		x -= rhs.x;
		y -= rhs.y;

		return *this;

	}

	// 02045F14
	Vec2& operator*=(fx32 rhs);

	constexpr Vec2& operator/=(fx32 rhs) {

		//ntr_assert(rhs != 0, "Tried to divide vector by zero");

		x = Math::div(x, rhs);
		y = Math::div(y, rhs);

		return *this;

	}

	constexpr Vec2 operator-() const {
		return Vec2(-x, -y);
	}

	// 02045E5C
	bool operator==(const VecFx32& rhs) const;
	// 02045E2C
	bool operator!=(const VecFx32& rhs) const;



	// 02045E10
	ntr_nodisc fx32 length() const; // Calculates the magnitude of the vector
	// 02045DDC
	ntr_nodisc fx32 distance(const VecFx32& other) const; // Calculates the distance from the vector to another one
	// 02045DBC
	fx64 magnitudeSquared() const; // Returns the squared magnitude (length^2)
	// 02045D74
	fx32 crossLength(const Vec2& other) const; // Emulates a 3D cross product and returns the Z component of the resulting vector
	// 02045D1C
	ntr_nodisc Vec2 normalize(); // Normalizes the vector and returns it
	// 02045CD0
	bool normalizeSafe(); // Normalizes the vector if not null

	inline Vec2 normalized() const {

		Vec2 out = *this;

		ntr_ignore = out.normalize();

		return out;

	}



	inline void lerp(const VecFx32& end, fx32 step) {

		x = Math::lerpFx(x, end.x, step);
		y = Math::lerpFx(y, end.y, step);

	}

	inline static Vec2 lerp(const VecFx32& start, const VecFx32& end, fx32 step) {

		Vec2 out = start;

		out.lerp(end, step);

		return out;

	}



	constexpr VecFx32 vecfx() const {

		VecFx32 out;

		out.x = x;
		out.y = y;
		out.z = 0;

		return out;

	}
	
	//  !!! NOT SAFE !!! oh well nintendo used them anyway

	// New
	inline const VecFx32& vecfx_cr() const {
		return *reinterpret_cast<const VecFx32*>(&x);
	}

	// New
	inline operator const VecFx32& () const {
		return *reinterpret_cast<const VecFx32*>(&x);
	}

	// New
	inline operator VecFx32& () {
		return *reinterpret_cast<VecFx32*>(&x);
	}


	fx32 x, y;

};
NTR_SIZE_GUARD(Vec2, 0xC);

/*
*	3D Vector class (fx16 type)
*/
class Vec3s : public VecFx16
{
public:

	// C2: 02003170
	constexpr Vec3s() : VecFx16{} {}

	constexpr Vec3s(fx16 v) : VecFx16{} {
		this->x = v;
		this->y = v;
		this->z = v;
	}

	constexpr Vec3s(fx16 x, fx16 y, fx16 z) : VecFx16{} {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	constexpr Vec3s(const VecFx16& vec) : VecFx16(vec) {}

	// D0: 020031b0
	// D1: 02003070
	constexpr virtual ~Vec3s() {}



	constexpr void set(fx16 v) {
		this->x = v;
		this->y = v;
		this->z = v;
	}

	constexpr void set(fx16 x, fx16 y, fx16 z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	constexpr void set(const VecFx16& vec) {
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}



	constexpr bool isNull() const {
		return x == 0 && y == 0 && z == 0;
	}



	constexpr Vec3s& add(const VecFx16& rhs) {
		return *this += rhs;
	}

	constexpr Vec3s& sub(const VecFx16& rhs) {
		return *this -= rhs;
	}

	constexpr Vec3s& mul(fx16 rhs) {
		return *this *= rhs;
	}

	constexpr Vec3s& div(fx16 rhs) {
		return *this /= rhs;
	}

	ntr_nodisc constexpr static Vec3s add(const Vec3s& a, const VecFx16& b) {
		return Vec3s(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	ntr_nodisc constexpr static Vec3s sub(const Vec3s& a, const VecFx16& b) {
		return Vec3s(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	ntr_nodisc constexpr static Vec3s mul(const Vec3s& vec, fx16 factor) {

		Vec3s out;

		out.x = Math::mul(vec.x, factor);
		out.y = Math::mul(vec.y, factor);
		out.z = Math::mul(vec.z, factor);

		return out;

	}

	ntr_nodisc constexpr static Vec3s div(const Vec3s& vec, fx16 factor) {

		//ntr_assert(factor != 0, "Tried to divide vector by zero");

		Vec3s out;

		out.x = Math::div(vec.x, factor);
		out.y = Math::div(vec.y, factor);
		out.z = Math::div(vec.z, factor);

		return out;

	}



	ntr_nodisc constexpr Vec3s operator+(const VecFx16& rhs) const {

		Vec3s out = *this;

		out.add(rhs);

		return out;

	}

	ntr_nodisc constexpr Vec3s operator-(const VecFx16& rhs) const {

		Vec3s out = *this;

		out.sub(rhs);

		return out;

	}

	ntr_nodisc constexpr Vec3s operator*(fx16 rhs) const {

		Vec3s out = *this;

		out.mul(rhs);

		return out;

	}

	ntr_nodisc constexpr Vec3s operator/(fx16 rhs) const {

		Vec3s out = *this;

		out.div(rhs);

		return out;

	}

	constexpr Vec3s& operator+=(const VecFx16& rhs) {

		x += rhs.x;
		y += rhs.y;
		z += rhs.z;

		return *this;

	}

	constexpr Vec3s& operator-=(const VecFx16& rhs) {

		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;

		return *this;

	}

	constexpr Vec3s& operator*=(fx16 rhs) {

		x = Math::mul(x, rhs);
		y = Math::mul(y, rhs);
		z = Math::mul(z, rhs);

		return *this;

	}

	constexpr Vec3s& operator/=(fx16 rhs) {

		//ntr_assert(rhs != 0, "Tried to divide vector by zero");

		x = Math::div(x, rhs);
		y = Math::div(y, rhs);
		z = Math::div(z, rhs);

		return *this;

	}

	ntr_nodisc constexpr Vec3s operator-() const {
		return Vec3s(-x, -y, -z);
	}

	constexpr bool operator==(const VecFx16& rhs) const {
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	constexpr bool operator!=(const VecFx16& rhs) const {
		return x != rhs.x || y != rhs.y || z != rhs.z;
	}


};

