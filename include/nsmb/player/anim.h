#pragma once
#include "nsmb/graphics/util/framectrl.h"


struct PlayerCapAnimation {

	u32 marioAnimID;
	u32 marioSmallAnimID;
	u32 luigiAnimID;
	u32 luigiSmallAnimID;
	u32 frameCtrlType;
	fx32 frameCtrlSpeed;
	u32 frameCtrlStart;

};


struct PlayerHeadAnimation {

	u32 animID;
	FrameCtrl::Type type;
	fx32 speed;
	u16 startFrame;

};
