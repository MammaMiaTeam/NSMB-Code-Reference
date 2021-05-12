#ifndef NSMB_VECTOR_H_
#define NSMB_VECTOR_H_

#include "nitro_if.h"


/*
	3D Vector class
*/
class Vec3
{
public:

	fx32 x, y, z;

	inline Vec3() {}
	virtual ~Vec3();

	void applyRotYZ(fx16 angle);				// Rotates the vector around the x-axis
	void applyRotXZ(fx16 angle);				// Rotates the vector around the y-axis
	void applyRotXY(fx16 angle);				// Rotates the vector around the z-axis
	bool normalize();							// If x, y and z are not zero, the vector is normalized and returns true.
	bool operator!=(const VecFx32& in);			// Returns true if vectors are not equal
	bool operator==(const VecFx32& in);			// Returns true if vectors are equal
	void operator*=(fx32 in);					// Scalar multiplication

	static void normalize(Vec3& out, Vec3& in);											// Normalizes in and out
	static void cross(Vec3& out, Vec3& out2, const VecFx32& a, const VecFx32& b);		// Performs a x b and stores the result in out and out2
	static void cross(Vec3& out, const Vec3& a, const VecFx32& b);						// Performs a x b and stores the result in out
	static fx32 distance(const Vec3& a, const VecFx32& b);								// Calculates the distance between a and b
	static Vec3& mul(Vec3& out, const Vec3& v, fx32 factor);							// Scales v by factor and stores the result in out
	static Vec3& sub(Vec3& out, const Vec3& a, const VecFx32& b);						// Calculates a - b
	static Vec3& add(Vec3& out, const Vec3& a, const VecFx32& b);						// Calculates a + b

	// C vectors conversions.

	operator VecFx32& () { return *reinterpret_cast<VecFx32*>(&x); }
	operator const VecFx32& () const { return *reinterpret_cast<const VecFx32*>(&x); }

	inline VecFx32* vecfx() {
		return reinterpret_cast<VecFx32*>(&this->x);
	}

	// Inline method re-creations.

	inline Vec3(fx32 val) {
		x = y = z = val;
	}

	inline Vec3(fx32 x, fx32 y, fx32 z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	inline Vec3(const VecFx32& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	inline static Vec3& div(Vec3& out, const VecFx32& lhs, fx32 rhs) {
		out = Vec3(FX_Div(lhs.x, rhs), FX_Div(lhs.y, rhs), FX_Div(lhs.z, rhs));
		return out;
	}


	inline Vec3 operator+(const VecFx32& rhs) {
		Vec3 out;
		Vec3::add(out, *this, rhs);
		return out;
	}

	inline Vec3 operator-(const VecFx32& rhs) {
		Vec3 out;
		Vec3::sub(out, *this, rhs);
		return out;
	}

	inline Vec3 operator*(fx32 rhs) {
		Vec3 out;
		Vec3::mul(out, *this, rhs);
		return out;
	}

	inline Vec3 operator/(fx32 rhs) {
		Vec3 out;
		Vec3::div(out, *this, rhs);
		return out;
	}


	inline void operator+=(const VecFx32& rhs) {
		*this = *this + rhs;
	}

	inline void operator-=(const VecFx32& rhs) {
		*this = *this - rhs;
	}

	inline void operator/=(fx32 rhs) {
		*this = *this / rhs;
	}

	inline Vec3 operator-() const {
		Vec3 v;
		v.x = -x;
		v.y = -y;
		v.z = -z;
		return v;
	}

	inline fx32 length() {
		return VEC_Mag(this->vecfx());
	}

	inline void cross(const VecFx32& rhs) {
		Vec3::cross(*this, *this, rhs);
	}

	inline fx32 distance(const VecFx32& rhs) {
		return Vec3::distance(*this, rhs);
	}

	inline void add(const VecFx32& rhs) {
		Vec3::add(*this, *this, rhs);
	}

	inline void sub(const VecFx32& rhs) {
		Vec3::sub(*this, *this, rhs);
	}

	inline void mul(fx32 rhs) {
		Vec3::mul(*this, *this, rhs);
	}

	inline void div(fx32 rhs) {
		Vec3::div(*this, *this, rhs);
	}
};



/*
	2D Vector class
*/
class Vec2
{
public:

	fx32 x, y;

	inline Vec2() {}
	virtual ~Vec2();

	bool normalize();							// If x, and y are not zero, the vector is normalized and returns true.
	fx64 magnitudeSquared();					// Returns the magnitude's square.
	fx32 length();								// Returns the vector's length.
	bool operator!=(const VecFx32& in);			// Returns true if vectors are not equal.
	bool operator==(const VecFx32& in);			// Returns true if vectors are equal.
	void operator*=(fx32 in);					// Scalar multiplication.

	static void normalize(Vec2& out, const Vec2& in);						// Normalizes in and stores the result in out.
	static s32 crossLength(const Vec2& a, const VecFx32& b);				// Emulates a 3D cross product and returns the z-component of the resulting vector.
	static fx32 distance(const Vec2& a, const VecFx32& b);					// Returns the distance between a and b.
	static void div(Vec2& out, const Vec2& v, fx32 divisor);				// Divides v by divisor.
	static void mul(Vec2& out, const Vec2& v, fx32 factor);					// Multiplies v by factor.
	static void sub(Vec2& out, const Vec2& a, const VecFx32& b);			// Calculates a - b.
	static void add(Vec2& out, const Vec2& a, const VecFx32& b);			// Calculates a + b.

	// C vectors conversions (value of z is unpredictable).

	operator VecFx32& () { return *reinterpret_cast<VecFx32*>(&x); }
	operator const VecFx32& () const { return *reinterpret_cast<const VecFx32*>(&x); }

	inline VecFx32* vecfx() {
		return reinterpret_cast<VecFx32*>(&this->x);
	}

	// Inline methods re-creations.

	inline Vec2(fx32 val) {
		x = y = val;
	}

	inline Vec2(fx32 x, fx32 y) {
		this->x = x;
		this->y = y;
	}

	inline Vec2(const Vec2& vec) {
		x = vec.x;
		y = vec.y;
	}


	inline Vec2 operator+(const VecFx32& rhs) {
		Vec2 out;
		Vec2::add(out, *this, rhs);
		return out;
	}

	inline Vec2 operator-(const VecFx32& rhs) {
		Vec2 out;
		Vec2::sub(out, *this, rhs);
		return out;
	}

	inline Vec2 operator*(fx32 rhs) {
		Vec2 out;
		Vec2::mul(out, *this, rhs);
		return out;
	}

	inline Vec2 operator/(fx32 rhs) {
		Vec2 out;
		Vec2::div(out, *this, rhs);
		return out;
	}


	inline void operator+=(const VecFx32& rhs) {
		*this = *this + rhs;
	}

	inline void operator-=(const VecFx32& rhs) {
		*this = *this - rhs;
	}

	inline void operator/=(fx32 rhs) {
		*this = *this / rhs;
	}

	inline Vec2 operator-() const {
		Vec2 v;
		v.x = -x;
		v.y = -y;
		return v;
	}

	inline s32 crossLength(const VecFx32& rhs) {
		return Vec2::crossLength(*this, rhs);
	}

	inline fx32 distance(const VecFx32& rhs) {
		return Vec2::distance(*this, rhs);
	}

	inline void add(const VecFx32& rhs) {
		Vec2::add(*this, *this, rhs);
	}

	inline void sub(const VecFx32& rhs) {
		Vec2::sub(*this, *this, rhs);
	}

	inline void mul(fx32 rhs) {
		Vec2::mul(*this, *this, rhs);
	}

	inline void div(fx32 rhs) {
		Vec2::div(*this, *this, rhs);
	}
};



/*
	3D Vector class (fx16 type)
*/
class Vec3s
{
public:

	fx16 x, y, z;

	inline Vec3s() {}
	virtual ~Vec3s();

	// C vectors conversions.

	operator VecFx16& () { return *reinterpret_cast<VecFx16*>(&x); }
	operator const VecFx16& () const { return *reinterpret_cast<const VecFx16*>(&x); }

	inline VecFx16* vecfx() {
		return reinterpret_cast<VecFx16*>(&this->x);
	}

	// Inline methods re-creations.

	inline Vec3s(fx16 val) {
		x = y = z = val;
	}

	inline Vec3s(fx16 x, fx16 y, fx16 z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	inline Vec3s(const VecFx16& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	inline static Vec3s& add(Vec3s& out, const VecFx16& lhs, const VecFx16& rhs) {
		out = Vec3s(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
		return out;
	}

	inline static Vec3s& sub(Vec3s& out, const VecFx16& lhs, const VecFx16& rhs) {
		out = Vec3s(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
		return out;
	}

	inline static Vec3s& mul(Vec3s& out, const VecFx16& lhs, fx32 rhs) {
		out = Vec3s(FX_MulInline(lhs.x, rhs), FX_MulInline(lhs.y, rhs), FX_MulInline(lhs.z, rhs));
		return out;
	}

	inline static Vec3s& div(Vec3s& out, const VecFx16& lhs, fx32 rhs) {
		out = Vec3s(FX_Div(lhs.x, rhs), FX_Div(lhs.y, rhs), FX_Div(lhs.z, rhs));
		return out;
	}


	inline Vec3s operator+(const VecFx16& rhs) {
		Vec3s out;
		Vec3s::add(out, *this, rhs);
		return out;
	}

	inline Vec3s operator-(const VecFx16& rhs) {
		Vec3s out;
		Vec3s::sub(out, *this, rhs);
		return out;
	}

	inline Vec3s operator*(fx32 rhs) {
		Vec3s out;
		Vec3s::mul(out, *this, rhs);
		return out;
	}

	inline Vec3s operator/(fx32 rhs) {
		Vec3s out;
		Vec3s::div(out, *this, rhs);
		return out;
	}


	inline void operator+=(const VecFx16& rhs) {
		*this = *this + rhs;
	}

	inline void operator-=(const VecFx16& rhs) {
		*this = *this - rhs;
	}

	inline void operator*=(fx32 rhs) {
		*this = *this * rhs;
	}

	inline void operator/=(fx32 rhs) {
		*this = *this / rhs;
	}

	inline Vec3s operator-() const {
		Vec3s v;
		v.x = -x;
		v.y = -y;
		v.z = -z;
		return v;
	}

	inline bool operator==(const Vec3s& rhs) {
		if (x == rhs.x && y == rhs.y && z == rhs.x) {
			return true;
		}

		return false;
	}

	inline bool operator!=(const Vec3s& rhs) {
		if (x != rhs.x || y != rhs.y || z != rhs.x) {
			return true;
		}

		return false;
	}

};

#endif // !NSMB_VECTOR_H_
