#pragma once
#include "nsmb/graphics/util/perspview.h"


// ov8
class WorldCamera : public PerspView
{
public:

	typedef void (WorldCamera::* StateFunction)();

	StateFunction updateStateFunction;
	u32 updateStateID;
	u32 enteringState;
	fx32 distance;
	s16 pitch;

	// 0x020E58D0
	static ObjectProfile profile;

	//C3:0x020CD2C0
	WorldCamera();

	//D0:0x020CCC68
	//D1:0x020CCC04
	virtual ~WorldCamera();

	//0x020CD040
	virtual s32 onCreate() override;

	//0x020CCD7C
	virtual s32 onUpdate() override;

	//0x020CCF6C
	virtual s32 onRender() override;

	//0x020CCD78
	// empty
	void enterState0();

	//0x020CCD74
	// empty
	void state0();

	//0x020CCD48
	void setState(u32 id);

	//0x020CCCD4
	void updateState();

};
NTR_SIZE_GUARD(WorldCamera, 0x120);
