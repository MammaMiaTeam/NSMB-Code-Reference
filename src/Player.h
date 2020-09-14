#ifndef NSMB_PLAYER_INCLUDED
#define NSMB_PLAYER_INCLUDED

#include "Actor.h"



struct PlayerCapAnimation {

	u32 marioAnimID;
	u32 marioSmallAnimID;
	u32 luigiAnimID;
	u32 luigiSmallAnimID;
	u32 frameCtrlType;
	fx32 frameCtrlSpeed;
	u32 frameCtrlStart;

};



//vtable 0212f8b8
class PlayerCap
{
public:

	Model model;
	Animation animation;
	FrameCtrl frameController;
	u8 player;
	u8 animType;

	//0212f8e0
	static u16 texPaletteBase[2];

	//0212f8e4
	static u32 texImageParam[2];

	//0212e5a4
	static u32 modelFileIDs[2];

	//0212e5b4
	static PlayerCapAnimation capAnimations[9];

	//0212e5ac
	static u16 texPaletteOffset[4];

	//0212df20
	PlayerCap();

	//D0:0212dec0
	//D1:0212def4
	virtual ~PlayerCap();

	//0212de44
	bool create();

	//0212dce4
	bool render(bool skip, u32 frame, u8 texPalette, GXRgb diffuse, GXRgb ambient, bool toon);

	//0212dc68
	void setAnimation(u8 animType, bool smallPlayer);

	//0212df4c
	static bool loadTextureSettings();

};



//vtable 0212f8c8
class PlayerShell
{
public:

	Model model;

	//0212f8ec
	static u16 texPaletteBase;

	//0212f8f0
	static u32 texImageParam;

	//0212e180
	PlayerShell();

	//D0:0212e130
	//D1:0212e15c
	virtual ~PlayerShell();

	//0212e0f8
	bool create();

	//0212e020
	bool render(bool skip, u8 texPalette, GXRgb diffuse, GXRgb ambient, bool toon);

	//0212e1a4
	static bool loadTextureSettings();

};




#endif  // NSMB_PLAYER_INCLUDED
