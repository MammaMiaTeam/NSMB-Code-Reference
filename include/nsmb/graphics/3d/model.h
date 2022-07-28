#pragma once
#include "nitro_if.h"
#include "modelbase.h"
#include "nsmb/math/vector.h"


//vtable 0203c51c
class Model : public ModelBase
{
public:

	//C1:02019a30
	//C2:02019a5c
	sym Model() __body

	//D0:020199e8
	//D1:02019a10
	//D2:020199c8
	sym virtual ~Model() override __body
		
	//02019948
	bool create(void* bmd, u32 modelID, u32 polygonID); //Loads the model with ID modelID from the bmd, assigns texture and model, sets the polygon ID and disables ambient/emission components. returns true if successful, false otherwise.

	//02019944
	virtual void null();

	//02019934
	void renderModel();

	//02019934
	void flush() const;

	//020198c4
	virtual void render(const VecFx32* scale);

	//02019864
	virtual void render(const MtxFx43& transform, const VecFx32* scale);

	//02019858
	virtual void render();

	//02019838
	/*
		The callback is executed when the current SBC command equals cmd.
		Timings:
		A: Before
		B: During
		C: After
	*/
	void setCommandCallback(NNSG3dSbcCallBackFunc cb, u8* address, u8 cmd, NNSG3dSbcCallBackTiming timing); //Sets the SBC command callback with the given timing (address is eliminated and only left for backwards compatibility)

	NTR_INLINE void disableRendering() {
		NNS_G3dRenderObjSetFlag(&renderObj, NNS_G3D_RENDEROBJ_FLAG_SKIP_SBC_DRAW);
	}

	NTR_INLINE void enableRendering() {
		NNS_G3dRenderObjResetFlag(&renderObj, NNS_G3D_RENDEROBJ_FLAG_SKIP_SBC_DRAW);
	}

	NTR_INLINE void setOwner(void* ptr) {
		NNS_G3dRenderObjSetUserPtr(&renderObj, ptr);
	}

	NTR_INLINE void* getOwner() {
		return renderObj.ptrUser;
	}

	//0201980c
	NNSG3dResMatData* getMaterialData(u32 index); //returns a pointer to the model's material data with the given index (doesn't check for index out of bounds)

	//020197fc
	NNSG3dResMat* getMaterialCollection(); //returns a pointer to the model's material collection

	NTR_INLINE u32 getMaterialCount() const {
		return data->info.numMat;
	}

	//020197e0
	s32 getMaterialIndex(const NNSG3dResName* name); //returns an index to the material given by name or -1 if no matching entry could be found

	//020197d4
	NNSG3dResNodeInfo* getNodeInfo(); //returns a pointer to the node info

	NTR_INLINE u32 getNodeCount() const {
		return data->info.numNode;
	}

	//020197bc
	s32 getNodeIndex(const NNSG3dResName* name); //returns an index to the node given by name or -1 if no matching entry could be found

	//02019740
	static bool getNodeMatrixInternal(NNSG3dResNodeInfo* nodeInfo, u32 nodeIndex, MtxFx43* mtx); //If the model's matrix is on the stack, it back-calculates the node's model matrix and stores it in mtx. returns true after operation, false if the matrix wasn't on stack.

	//0201972c
	bool getNodeMatrix(u32 nodeIndex, MtxFx43* mtx); //Calls getNodeMatrixInternal on the model's node info with index nodeIndex. The resulting matrix is stored in mtx and true is returned; on failure, false is returned.

	//020196dc
	bool getNodePosition(u32 nodeIndex, Vec3& position); //returns the translation component of the node matrix with index nodeIndex in position. returns true on success, false on failure.

	//0201967c
	bool restoreNodeMatrix(u32 nodeIndex); //Restores the node matrix with index nodeIndex. returns true if successful, false otherwise.


	NNSG3dResMdl* data;
	NNSG3dResTex* texture;

	MtxFx43 matrix;

};
NTR_SIZE_GUARD(Model, 0x90);
