#pragma once
#include "nitro_if.h"


namespace GFX {

	//02019b6c
	// Initializes the graphics engine
	ssym void initialize() __body

	//02019b78
	// Does nothing
	ssym void terminate() __body

	//02019afc
	// Obtains the texture's parameters and stores them in texParams. returns whether texture params were fetched successfully.
	ssym bool getTextureParams(NNSG3dResTex* texture, u32 texID, u32& texParams) __rbody

	//02019a88
	// Calculates the texture's VRAM slot destination address and stores it in palDest. returns whether address calculation was successful.
	ssym bool getTexturePaletteDestination(NNSG3dResTex* texture, u32 palID, u32& palDest) __rbody

	//020446b4
	ssym void setRotationZ(MtxFx43& mtx, s16 angle) __body

	//020446f4
	ssym void setRotationY(MtxFx43& mtx, s16 angle) __body

	//02044734
	ssym void setRotationX(MtxFx43& mtx, s16 angle) __body

	//02044774
	ssym void setRotation(MtxFx43& mtx, s16 angleX, s16 angleY, s16 angleZ) __body

	__inline void setRotation(MtxFx43& mtx, const VecFx16& vec) {
		setRotation(mtx, vec.x, vec.y, vec.z);
	}

	//02044814
	ssym void setTranslation(MtxFx43& mtx, fx32 x, fx32 y, fx32 z) __body

	__inline void setTranslation(MtxFx43& mtx, const VecFx32& vec) {
		GFX::setTranslation(mtx, vec.x, vec.y, vec.z);
	}

	//0204485c
	ssym void rotateZ(MtxFx43& mtx, s16 angle) __body

	//02044888
	ssym void rotateY(MtxFx43& mtx, s16 angle) __body

	//020448b4
	ssym void rotateX(MtxFx43& mtx, s16 angle) __body

	//020448e0
	ssym void rotate(MtxFx43& mtx, s16 angleX, s16 angleY, s16 angleZ) __body

	__inline void rotate(MtxFx43& mtx, const VecFx16& vec) {
		rotate(mtx, vec.x, vec.y, vec.z);
	}

	//0204496c
	ssym void rotateReversed(MtxFx43& mtx, s16 angleX, s16 angleY, s16 angleZ) __body

	__inline void rotateReversed(MtxFx43& mtx, const VecFx16& vec) {
		rotateReversed(mtx, vec.x, vec.y, vec.z);
	}

	//020449f8
	ssym void scale(MtxFx43& mtx, fx32 scaleX, fx32 scaleY, fx32 scaleZ) __body

	__inline void scale(MtxFx43& mtx, fx32 scale) {
		GFX::scale(mtx, scale, scale, scale);
	}

	__inline void scale(MtxFx43& mtx, const VecFx32& vec) {
		GFX::scale(mtx, vec.x, vec.y, vec.z);
	}

	//02044a24
	ssym void translate(MtxFx43& mtx, fx32 transX, fx32 transY, fx32 transZ) __body

	__inline void translate(MtxFx43& mtx, const VecFx32& vec) {
		GFX::translate(mtx, vec.x, vec.y, vec.z);
	}

	constexpr void identity(MtxFx43& mtx) {
		if_consteval{
			fx32 l = FX32_ONE;
			mtx.m[0][0] = l; mtx.m[0][1] = 0; mtx.m[0][2] = 0;
			mtx.m[1][0] = 0; mtx.m[1][1] = l; mtx.m[1][2] = 0;
			mtx.m[2][0] = 0; mtx.m[2][1] = 0; mtx.m[2][2] = l;
			mtx.m[3][0] = 0; mtx.m[3][1] = 0; mtx.m[3][2] = 0;
		}
		else {
			MTX_Identity43(&mtx);
		}
	}

	__inline void multiply(const MtxFx43& a, const MtxFx43& b, MtxFx43& ab) {
		MTX_Concat43(&a, &b, &ab);
	}

}
