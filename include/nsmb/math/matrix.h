#pragma once
#include "math.h"


namespace MTX {

	// 020446B0
	void initialize(); // Does nothing

	// 020446B4
	void setRotationZ(MtxFx43& mtx, s16 angle);
	// 020446F4
	void setRotationY(MtxFx43& mtx, s16 angle);
	// 02044734
	void setRotationX(MtxFx43& mtx, s16 angle);
	// 02044774
	void setRotation(MtxFx43& mtx, s16 angleX, s16 angleY, s16 angleZ);

	inline void setRotation(MtxFx43& mtx, const VecFx16& vec) {
		setRotation(mtx, vec.x, vec.y, vec.z);
	}

	inline void setScale(MtxFx43& mtx, fx32 x, fx32 y, fx32 z) {

		mtx.m[0][0] = x; mtx.m[0][1] = 0; mtx.m[0][2] = 0;
		mtx.m[1][0] = 0; mtx.m[1][1] = y; mtx.m[1][2] = 0;
		mtx.m[2][0] = 0; mtx.m[2][1] = 0; mtx.m[2][2] = z;
		mtx.m[3][0] = 0; mtx.m[3][1] = 0; mtx.m[3][2] = 0;

	}

	// 02044814
	void setTranslation(MtxFx43& mtx, fx32 x, fx32 y, fx32 z);

	inline void setTranslation(MtxFx43& mtx, const VecFx32& vec) {
		setTranslation(mtx, vec.x, vec.y, vec.z);
	}

	// 0204485C
	void rotateZ(MtxFx43& mtx, s16 angle);
	// 02044888
	void rotateY(MtxFx43& mtx, s16 angle);
	// 020448B4
	void rotateX(MtxFx43& mtx, s16 angle);
	// 020448E0
	void rotate(MtxFx43& mtx, s16 angleX, s16 angleY, s16 angleZ);

	inline void rotate(MtxFx43& mtx, const VecFx16& vec) {
		rotate(mtx, vec.x, vec.y, vec.z);
	}

	// 0204496C
	void rotateReversed(MtxFx43& mtx, s16 angleX, s16 angleY, s16 angleZ);

	inline void rotateReversed(MtxFx43& mtx, const VecFx16& vec) {
		rotateReversed(mtx, vec.x, vec.y, vec.z);
	}

	// 020449F8
	void scale(MtxFx43& mtx, fx32 scaleX, fx32 scaleY, fx32 scaleZ);

	inline void scale(MtxFx43& mtx, fx32 value) {
		scale(mtx, value, value, value);
	}

	inline void scale(MtxFx43& mtx, const VecFx32& vec) {
		scale(mtx, vec.x, vec.y, vec.z);
	}

	// 02044A24
	void translate(MtxFx43& mtx, fx32 transX, fx32 transY, fx32 transZ);

	inline void translate(MtxFx43& mtx, const VecFx32& vec) {
		translate(mtx, vec.x, vec.y, vec.z);
	}

	inline void identity(MtxFx43& mtx) {

		fx32 i = FX32_ONE;

		mtx.m[0][0] = i; mtx.m[0][1] = 0; mtx.m[0][2] = 0;
		mtx.m[1][0] = 0; mtx.m[1][1] = i; mtx.m[1][2] = 0;
		mtx.m[2][0] = 0; mtx.m[2][1] = 0; mtx.m[2][2] = i;
		mtx.m[3][0] = 0; mtx.m[3][1] = 0; mtx.m[3][2] = 0;

	}

	inline void multiply(const MtxFx43& a, const MtxFx43& b, MtxFx43& ab) {
		MTX_Concat43(&a, &b, &ab);
	}

}
