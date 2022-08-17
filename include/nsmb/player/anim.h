#pragma once
#include "nsmb/graphics/util/framectrl.h"


struct PlayerCapAnimation {

	u32 marioAnimID;
	u32 marioSmallAnimID;
	u32 luigiAnimID;
	u32 luigiSmallAnimID;
	FrameCtrl::Type type;
	fx32 speed;
	u16 startFrame;

};


struct PlayerHeadAnimation {

	u32 animID;
	FrameCtrl::Type type;
	fx32 speed;
	u16 startFrame;

};
