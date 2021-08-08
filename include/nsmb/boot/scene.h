#pragma once
#include "nsmb/entity/scene.h"


//ov1
class BootScene : public Scene
{
public:

	//Save related
	u32 unk64;
	u32 unk68;
	u32 unk6c;
	u32 unk70;

	u32 unk74;//???

	u16 unk78;//Timer: 0x78 or 0 if this is not the starting scene
	u8 unk7a;//State 0-9
	u8 unk7b;
	u8 unk7c;
	u8 unk7d;
	u8 unk7e;

	//021874c4
	static u8 nintendoLogoNCG[0x5F0];

	//02187ab4
	static u8 nintendoLogoNCL[0x200];

	//02187cb4
	static u8 nintendoLogoNSC[0x1F0];

	//02187ea4
	static u8 copyrightTextNCG[0xD28];

	//02188bcc
	static u8 copyrightTextNCL[0x20];

	//02188bec
	static u8 copyrightTextNSC[0x2B8];

	//C3:02187208
	BootScene();

	//D0:02186680
	//D1:02186660
	virtual ~BootScene();

	//02186eb0
	virtual s32 onCreate() override;

	//02186ea8
	virtual s32 onDestroy() override;

	//02186ea4
	virtual void pendingDestroy() override;

	//02186e9c
	virtual s32 onRender() override;

	//02186900
	virtual s32 onUpdate() override;

	//02186834
	//void ? ? ? ();

	//021866a8
	//void ? ? ? ();

	/*
	Case 0 == 7
	Case 1 -> 2/6
	Case 2 -> 3
	Case 3 -> 4/6
	Case 4 -> 5
	Case 5 -> 7
	Case 6 -> 0
	Case 7 -> F
	Case 8 -> 9/F
	Case 9 -> S
	*/

};
