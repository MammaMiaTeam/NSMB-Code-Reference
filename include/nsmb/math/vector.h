#pragma once
#include "nitro_if.h"
#include "math.h"


/*
*	3D Vector class
*/
class Vec3 : public VecFx32
{
public:

	__inline Vec3() {}
	virtual ~Vec3();

	void applyRotYZ(fx16 angle);				// Rotates the vector around the x-axis
	void applyRotXZ(fx16 angle);				// Rotates the vector around the y-axis
	void applyRotXY(fx16 angle);				// Rotates the vector around the z-axis
	bool normalize();							// If x, y and z are not zero, the vector is normalized and returns true.
	bool operator!=(const VecFx32& in);			// returns true if vectors are not equal
	bool operator==(const VecFx32& in);			// returns true if vectors are equal
	void operator*=(fx32 in);					// Scalar multiplication

	static void normalize(Vec3& out, Vec3& in);											// Normalizes in and out
	static void cross(Vec3& out, Vec3& out2, const VecFx32& a, const VecFx32& b);		// Performs a x b and stores the result in out and out2
	static void cross(Vec3& out, const Vec3& a, const VecFx32& b);						// Performs a x b and stores the result in out
	static fx32 distance(const Vec3& a, const VecFx32& b);								// Calculates the distance between a and b
	static Vec3& mul(Vec3& out, const Vec3& v, fx32 factor);							// Scales v by factor and stores the result in out
	static Vec3& sub(Vec3& out, const Vec3& a, const VecFx32& b);						// Calculates a - b
	static Vec3& add(Vec3& out, const Vec3& a, const VecFx32& b);						// Calculates a + b

	// __inline method re-creations.

	__inline Vec3(fx32 val) {
		x = y = z = val;
	}

	__inline Vec3(fx32 x, fx32 y, fx32 z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	__inline Vec3(const VecFx32& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	__inline static Vec3& div(Vec3& out, const VecFx32& lhs, fx32 rhs) {
		out = Vec3(Math::div(lhs.x, rhs), Math::div(lhs.y, rhs), Math::div(lhs.z, rhs));
		return out;
	}

	__inline static Vec3& lerp(const VecFx32& start, const VecFx32& end, fx32 step) {
		return Vec3(Math::lerpFx32(start.x, end.x, step), Math::lerpFx32(start.y, end.y, step), Math::lerpFx32(start.z, end.z, step))
	}


	__inline Vec3 operator+(const VecFx32& rhs) {
		Vec3 out;
		Vec3::add(out, *this, rhs);
		return out;
	}

	__inline Vec3 operator-(const VecFx32& rhs) {
		Vec3 out;
		Vec3::sub(out, *this, rhs);
		return out;
	}

	__inline Vec3 operator*(fx32 rhs) {
		Vec3 out;
		Vec3::mul(out, *this, rhs);
		return out;
	}

	__inline Vec3 operator/(fx32 rhs) {
		Vec3 out;
		Vec3::div(out, *this, rhs);
		return out;
	}


	__inline void operator+=(const VecFx32& rhs) {
		*this = *this + rhs;
	}

	__inline void operator-=(const VecFx32& rhs) {
		*this = *this - rhs;
	}

	__inline void operator/=(fx32 rhs) {
		*this = *this / rhs;
	}

	__inline Vec3 operator-() const {
		Vec3 v;
		v.x = -x;
		v.y = -y;
		v.z = -z;
		return v;
	}

	__inline fx32 length() {
		return VEC_Mag(this);
	}

	__inline void cross(const VecFx32& rhs) {
		Vec3::cross(*this, *this, rhs);
	}

	__inline fx32 distance(const VecFx32& rhs) {
		return Vec3::distance(*this, rhs);
	}

	__inline void add(const VecFx32& rhs) {
		Vec3::add(*this, *this, rhs);
	}

	__inline void sub(const VecFx32& rhs) {
		Vec3::sub(*this, *this, rhs);
	}

	__inline void mul(fx32 rhs) {
		Vec3::mul(*this, *this, rhs);
	}

	__inline void div(fx32 rhs) {
		Vec3::div(*this, *this, rhs);
	}

	__inline void clamp(const VecFx32& min, const VecFx32& max) {
		return Vec3(Math::clamp(x, min.x, max.x), Math::clamp(x, min.x, max.x), Math::clamp(x, min.x, max.x));
	}

	__inline void clamp(fx32 min, fx32 max) {
		return Vec3(Math::clamp(x, min, max), Math::clamp(y, min, max), Math::clamp(z, min, max));
	}
};



/*
*	2D Vector class
*/
class Vec2
{
public:

	fx32 x, y;

	__inline Vec2() {}
	virtual ~Vec2();

	bool normalize();							// If x, and y are not zero, the vector is normalized and returns true.
	fx64 magnitudeSquared();					// Returns the squared magnitude (length^2).
	fx32 length();								// Returns the vector's length (magnitude).
	bool operator!=(const VecFx32& in);			// Returns true if vectors are not equal.
	bool operator==(const VecFx32& in);			// Returns true if vectors are equal.
	void operator*=(fx32 in);					// Scalar multiplication.

	static void normalize(Vec2& out, const Vec2& in);						// Normalizes in and stores the result in out.
	static fx32 crossLength(const Vec2& a, const VecFx32& b);				// Emulates a 3D cross product and returns the z-component of the resulting vector.
	static fx32 distance(const Vec2& a, const VecFx32& b);					// returns the distance between a and b.
	static void div(Vec2& out, const Vec2& v, fx32 divisor);				// Divides v by divisor.
	static void mul(Vec2& out, const Vec2& v, fx32 factor);					// Multiplies v by factor.
	static void sub(Vec2& out, const Vec2& a, const VecFx32& b);			// Calculates a - b.
	static void add(Vec2& out, const Vec2& a, const VecFx32& b);			// Calculates a + b.



	// __inline methods re-creations.

	__inline Vec2(fx32 val) {
		x = y = val;
	}

	__inline Vec2(fx32 x, fx32 y) {
		this->x = x;
		this->y = y;
	}

	__inline Vec2(const Vec2& vec) {
		x = vec.x;
		y = vec.y;
	}



	__inline VecFx32 vecfx() const {
		return { x, y, 0 };
	}

	// !!! NOT SAFE !!!
	__inline const VecFx32& vecfx_cr() const {
		return *reinterpret_cast<const VecFx32*>(this);
	}



	__inline Vec2 operator+(const Vec2& rhs) {
		VecFx32 tmp = { rhs.x, rhs.y, 0 };
		Vec2 out;
		Vec2::add(out, *this, tmp);
		return out;
	}

	__inline Vec2 operator-(const Vec2& rhs) {
		VecFx32 tmp = { rhs.x, rhs.y, 0 };
		Vec2 out;
		Vec2::sub(out, *this, tmp);
		return out;
	}

	__inline Vec2 operator*(fx32 rhs) {
		Vec2 out;
		Vec2::mul(out, *this, rhs);
		return out;
	}

	__inline Vec2 operator/(fx32 rhs) {
		Vec2 out;
		Vec2::div(out, *this, rhs);
		return out;
	}


	__inline bool operator!=(const Vec2& in) {
		return *this != in.vecfx_cr();
	}

	__inline bool operator==(const Vec2& in) {
		return *this == in.vecfx_cr();
	}

	__inline void operator+=(const Vec2& rhs) {
		*this = *this + rhs;
	}

	__inline void operator-=(const Vec2& rhs) {
		*this = *this - rhs;
	}

	__inline void operator/=(fx32 rhs) {
		*this = *this / rhs;
	}

	__inline Vec2 operator-() const {
		Vec2 v;
		v.x = -x;
		v.y = -y;
		return v;
	}

	__inline s32 crossLength(const Vec2& rhs) {
		VecFx32 tmp = { rhs.x, rhs.y, 0 };
		return Vec2::crossLength(*this, tmp);
	}

	__inline fx32 distance(const Vec2& rhs) {
		VecFx32 tmp = { rhs.x, rhs.y, 0 };
		return Vec2::distance(*this, tmp);
	}

	__inline void add(const Vec2& rhs) {
		VecFx32 tmp = { rhs.x, rhs.y, 0 };
		Vec2::add(*this, *this, tmp);
	}

	__inline void sub(const Vec2& rhs) {
		VecFx32 tmp = { rhs.x, rhs.y, 0 };
		Vec2::sub(*this, *this, tmp);
	}

	__inline void mul(fx32 rhs) {
		Vec2::mul(*this, *this, rhs);
	}

	__inline void div(fx32 rhs) {
		Vec2::div(*this, *this, rhs);
	}

	__inline void clamp(const Vec2& min, const Vec2& max) {
		return Vec2(Math::clamp(x, min.x, max.x), Math::clamp(x, min.x, max.x));
	}

	__inline void clamp(fx32 min, fx32 max) {
		return Vec2(Math::clamp(x, min, max), Math::clamp(y, min, max));
	}
};



/*
*	3D Vector class (fx16 type)
*/
class Vec3s : public VecFx16
{
public:

	__inline Vec3s() {}
	virtual ~Vec3s();

	// __inline methods re-creations.

	__inline Vec3s(fx16 val) {
		x = y = z = val;
	}

	__inline Vec3s(fx16 x, fx16 y, fx16 z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	__inline static Vec3s& add(Vec3s& out, const VecFx16& lhs, const VecFx16& rhs) {
		out = Vec3s(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
		return out;
	}

	__inline static Vec3s& sub(Vec3s& out, const VecFx16& lhs, const VecFx16& rhs) {
		out = Vec3s(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
		return out;
	}

	__inline static Vec3s& mul(Vec3s& out, const VecFx16& lhs, fx32 rhs) {
		out = Vec3s(Math::mul(lhs.x, rhs), Math::mul(lhs.y, rhs), Math::mul(lhs.z, rhs));
		return out;
	}

	__inline static Vec3s& div(Vec3s& out, const VecFx16& lhs, fx32 rhs) {
		out = Vec3s(Math::div(lhs.x, rhs), Math::div(lhs.y, rhs), Math::div(lhs.z, rhs));
		return out;
	}


	__inline Vec3s operator+(const VecFx16& rhs) {
		Vec3s out;
		Vec3s::add(out, *this, rhs);
		return out;
	}

	__inline Vec3s operator-(const VecFx16& rhs) {
		Vec3s out;
		Vec3s::sub(out, *this, rhs);
		return out;
	}

	__inline Vec3s operator*(fx32 rhs) {
		Vec3s out;
		Vec3s::mul(out, *this, rhs);
		return out;
	}

	__inline Vec3s operator/(fx32 rhs) {
		Vec3s out;
		Vec3s::div(out, *this, rhs);
		return out;
	}


	__inline void operator+=(const VecFx16& rhs) {
		*this = *this + rhs;
	}

	__inline void operator-=(const VecFx16& rhs) {
		*this = *this - rhs;
	}

	__inline void operator*=(fx32 rhs) {
		*this = *this * rhs;
	}

	__inline void operator/=(fx32 rhs) {
		*this = *this / rhs;
	}

	__inline Vec3s operator-() const {
		Vec3s v;
		v.x = -x;
		v.y = -y;
		v.z = -z;
		return v;
	}

	__inline bool operator==(const Vec3s& rhs) {
		if (x == rhs.x && y == rhs.y && z == rhs.x) {
			return true;
		}

		return false;
	}

	__inline bool operator!=(const Vec3s& rhs) {
		if (x != rhs.x || y != rhs.y || z != rhs.x) {
			return true;
		}

		return false;
	}

	__inline void clamp(const VecFx16& min, const VecFx16& max) {
		return Vec2(Math::clamp(x, min.x, max.x), Math::clamp(x, min.x, max.x));
	}

	__inline void clamp(fx32 min, fx32 max) {
		return Vec2(Math::clamp(x, min, max), Math::clamp(y, min, max));
	}
};
