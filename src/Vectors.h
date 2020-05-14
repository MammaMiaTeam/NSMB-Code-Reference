#ifndef NSMB_VECTORS_INCLUDED
#define NSMB_VECTORS_INCLUDED

#include "nitro_if.h"

class Vec3 {
public:

	fx32 x, y, z;

	inline Vec3() {}
	virtual ~Vec3();

	void applyRotXZ(fx16 angle);
	void applyRotYZ(fx16 angle);
	BOOL canBeNormalized();
	BOOL operator!=(const VecFx32& in);
	BOOL operator==(const VecFx32& in);
	void operator*=(fx32 in);
	void applyRotXY(fx16 angle);

	static void normalize(Vec3& out, const Vec3& in);
	static void crossProduct2(Vec3& out, Vec3& out2, const VecFx32& in1, const VecFx32& in2);
	static void crossProduct(Vec3& out, const VecFx32& in1, const VecFx32& in2);
	static fx32 distance(const Vec3& in1, const VecFx32& in2);
	static Vec3& mul(Vec3& out, const Vec3& lhs, fx32 rhs);
	static Vec3& sub(Vec3& out, const Vec3& lhs, const VecFx32& rhs);
	static Vec3& add(Vec3& out, const Vec3& lhs, const VecFx32& rhs);

	// implicit conversion
	operator VecFx32& () { return *reinterpret_cast<VecFx32*>(&x); }

	// inline methods re-creations
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
	}

	inline void operator+=(const VecFx32& in) {
		Vec3::add(*this, *this, in);
	}
	inline void operator-=(const VecFx32& in) {
		Vec3::sub(*this, *this, in);
	}
	inline void operator/=(fx32 in) {
		Vec3::div(*this, *this, in);
	}
};

class Vec2 {
public:

	fx32 x, y;

	inline Vec2() {}
	virtual ~Vec2();

	BOOL canBeNormalized();
	fx32 mag2();
	fx32 mag();
	BOOL operator!=(const VecFx32& in);
	BOOL operator==(const VecFx32& in);
	void operator*=(fx32 in);

	static void normalize(Vec2& out, const Vec2& in);
	static int crossProduct(const Vec2& in1, const VecFx32& in2);
	static fx32 distance(const Vec2& in1, const VecFx32& in2);
	static void div(Vec2& out, const Vec2& lhs, fx32 rhs);
	static void mul(Vec2& out, const Vec2& lhs, fx32 rhs);
	static void sub(Vec2& out, const Vec2& lhs, const VecFx32& rhs);
	static void add(Vec2& out, const Vec2& lhs, const VecFx32& rhs);

	// inline methods re-creations
	inline Vec2(fx32 val) {
		x = y = val;
	}
	inline Vec2(fx32 x, fx32 y) {
		this->x = x;
		this->y = y;
	}
	inline Vec2(const VecFx32& vec) {
		x = vec.x;
		y = vec.y;
	}

	inline void operator+=(const VecFx32& in) {
		Vec2::add(*this, *this, in);
	}
	inline void operator-=(const VecFx32& in) {
		Vec2::sub(*this, *this, in);
	}
	inline void operator/=(fx32 in) {
		Vec2::div(*this, *this, in);
	}
};

class S16Vec3 {
public:

	fx16 x, y, z;

	inline S16Vec3() {}
	virtual ~S16Vec3();

	// implicit conversion
	operator VecFx16& () { return *reinterpret_cast<VecFx16*>(&x); }

	// inline methods re-creations
	inline S16Vec3(fx16 val) {
		x = y = z = val;
	}
	inline S16Vec3(fx16 x, fx16 y, fx16 z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	inline S16Vec3(const VecFx16& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	inline static S16Vec3& add(S16Vec3& out, const VecFx16& lhs, const VecFx16& rhs) {
		out = S16Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}
	inline static S16Vec3& sub(S16Vec3& out, const VecFx16& lhs, const VecFx16& rhs) {
		out = S16Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}
	inline static S16Vec3& mul(S16Vec3& out, const VecFx16& lhs, fx32 rhs) {
		out = S16Vec3(FX_MulInline(lhs.x, rhs), FX_MulInline(lhs.y, rhs), FX_MulInline(lhs.z, rhs));
	}
	inline static S16Vec3& div(S16Vec3& out, const VecFx16& lhs, fx32 rhs) {
		out = S16Vec3(FX_Div(lhs.x, rhs), FX_Div(lhs.y, rhs), FX_Div(lhs.z, rhs));
	}

	inline void operator+=(const VecFx16& in) {
		S16Vec3::add(*this, *this, in);
	}
	inline void operator-=(const VecFx16& in) {
		S16Vec3::sub(*this, *this, in);
	}
	inline void operator*=(fx32 in) {
		S16Vec3::mul(*this, *this, in);
	}
	inline void operator/=(fx32 in) {
		S16Vec3::div(*this, *this, in);
	}

	inline BOOL operator==(const S16Vec3& in) {
		if (x == in.x && y == in.y && z == in.x)
			return TRUE;
		return FALSE;
	}
	inline BOOL operator!=(const S16Vec3& in) {
		if (x != in.x || y != in.y || z != in.x)
			return TRUE;
		return FALSE;
	}
};

#endif	// NSMB_VECTORS_INCLUDED
