#pragma once
#include "nitro_if.h"


namespace G3D {

	// 02019B6C
	void initialize(); // Initializes the graphics engine

	// 02019B78
	void shutdown(); // Does nothing

	// 02019AFC
	bool getTextureParams(NNSG3dResTex* texture, u32 texID, u32& texParams); // Obtains the texture's parameters and stores them in texParams. returns whether texture params were fetched successfully.

	// 02019A88
	bool getPaletteParams(NNSG3dResTex* texture, u32 palID, u32& palParams); // Calculates the palettes's VRAM slot destination address and stores it in palParams. returns whether address calculation was successful.

	template<class T = void>
	T* rsGetRenderObjUser(NNSG3dRS* rs) {
		return static_cast<T*>(NNS_G3dRSGetRenderObj(rs)->ptrUser);
	}

	NTR_INLINE u8 rsGetNodeDesc(NNSG3dRS* rs) {
		return rs->c[1];
	}

	NTR_INLINE NNSG3dMatAnmResult* rsGetMatAnm(NNSG3dRS* rs) {
		return NNS_G3dRSGetMatAnmResult(rs);
	}

	NTR_INLINE NNSG3dJntAnmResult* rsGetJntAnm(NNSG3dRS* rs) {
		return NNS_G3dRSGetJntAnmResult(rs);
	}

	NTR_INLINE NNSG3dVisAnmResult* rsGetVisAnm(NNSG3dRS* rs) {
		return NNS_G3dRSGetVisAnmResult(rs);
	}

	NTR_INLINE void jntAnmSetFlag(NNSG3dJntAnmResult* res, NNSG3dJntAnmResultFlag flag, bool set) {

		u32 tmp = res->flag;

		if (set)
			tmp |= flag;
		else
			tmp &= ~flag;

		res->flag = NNSG3dJntAnmResultFlag(tmp);

	}

	NTR_INLINE void jntAnmUseTranslation(NNSG3dJntAnmResult* res, bool used = true) {
		jntAnmSetFlag(res, NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO, !used);
	}

	NTR_INLINE void jntAnmUseRotation(NNSG3dJntAnmResult* res, bool used = true) {
		jntAnmSetFlag(res, NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO, !used);
	}

	NTR_INLINE void jntAnmUseScale(NNSG3dJntAnmResult* res, bool used = true) {
		jntAnmSetFlag(res, NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE, !used);
	}

	NTR_INLINE void anmObjSetNode(NNSG3dAnmObj* obj, u32 id, bool set) {

		if (id < obj->numMapData && obj->mapData[id] & NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
			if (set) {
				obj->mapData[id] &= ~NNS_G3D_ANMOBJ_MAPDATA_DISABLED;
			} else {
				obj->mapData[id] |= NNS_G3D_ANMOBJ_MAPDATA_DISABLED;
			}
		}

	}

	NTR_INLINE void anmObjDisableNode(NNSG3dAnmObj* obj, u32 id) {
		anmObjSetNode(obj, id, false);
	}

	NTR_INLINE void anmObjEnableNode(NNSG3dAnmObj* obj, u32 id) {
		anmObjSetNode(obj, id, true);
	}

}
