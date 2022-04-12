#pragma once
#include "nsmb/graphics/util/perspview.h"


// ov8
class WorldMapCamera : public PerspView
{
public:

	typedef void(WorldMapCamera::* StateFunction)();

	StateFunction unk108;//State function
	u32 unk110;//State
	u32 unk114;//Setup state bool
	Vec3 unk118;
	Vec3 unk128;//Light Position
	Vec3 unk138;//Physical camera position
	u32 unk148;//Zoom state (0 = in, 1 = out)
	fx32 unk14c;//FovY (in degrees / 2)
	fx32 unk150;//Left camera view x clamp
	fx32 unk154;//Right camera view x clamp
	u32 unk158;
	u32 unk15c;
	u32 unk160;
	u32 unk164;

	static constexpr u16 objectID = 322;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 2;

	//0x020E8BEC
	static ObjectProfile profile;

	//021a65b0
	static VecFx32 worldLightPositions[8];

	//021a60d4
	static fx32 worldBoundaries[8][2];

	//021a864c
	static fx32 fovySineTable[450];//I don't wanna say anything to this.

	//C3:0x020D1F98
	WorldMapCamera();

	//D0:0x020D15B4
	//D1:0x020D1544
	virtual ~WorldMapCamera();

	//0x020D1CCC
	virtual s32 onCreate() override;

	//0x001575CC
	virtual s32 onUpdate() override;

	//0x020D1BF8
	virtual s32 onRender() override;

	//0x020D16A0
	void setState(u32 state);

	//0x020D162C
	void updateState();

};
NTR_SIZE_GUARD(WorldMapCamera, 0x168);
