#pragma once
#include "fixedorthoview.h"


//ov9
class TitleScreenCamera : public FixedOrthoView
{
public:

	//0x020DAADC
	static ObjectProfile profile;

	//C3:0x020D3D74
	TitleScreenCamera();

	//D0:0x020D3938
	//D1:0x020D38D4
	virtual ~TitleScreenCamera();

	//0x020D3B68
	virtual s32 onCreate() override;

	//0x020D3A50
	virtual s32 onUpdate() override;

	//0x020D3A94
	virtual s32 onRender() override;

	//0x020D39A4
	void setOrtho(fx32 r, fx32 t, fx32 b, fx32 l);

};
NTR_SIZE_GUARD(TitleScreenCamera, sizeof(FixedOrthoView));
