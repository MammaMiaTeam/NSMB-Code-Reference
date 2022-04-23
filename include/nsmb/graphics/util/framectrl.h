#pragma once
#include "nitro_if.h"


class FrameCtrl
{
public:

	static constexpr u32 typeMask = 0xC0000000;
	static constexpr u32 lastFrameMask = 0x3FFFFFFF;

	enum Type : u32 {
		Looping = 0x00000000,
		Standard = 0x40000000
	};

	u32 settings;		/*
							Masked settings:
							0x3FFFFFFF: Frame count as fx32
							0xC0000000: Animation type
						*/
	fx32 currentFrame;	//Current animation frame
	fx32 speed;			//Speed of animation

	//0201feb8
	void update(); //Updates currentFrame by speed. If it's looping, currentFrame is wrapped around. If not, currentFrame is incremented until it reaches frames - 1. When timer becomes negative due to negative speeds, it's kept at 0.

	//0201fe9c
	void init(u16 frames, Type type, fx32 speed, u16 startFrame); //Initializes the controller with the given parameters

	constexpr u16 getFrame() const {
		return currentFrame >> 12;
	}

	constexpr void setFrame(u16 frame) {
		currentFrame = frame << 12;
	}

	//0201fe88
	u16 getFrameCount() const; //returns the frame count (truncated integer)

	constexpr void setFrameCount(u16 count) {
		settings &= typeMask;
		settings |= (count << 12) & lastFrameMask;
	}

	//0201fe74
	void setAnimationType(FrameCtrl::Type type); //Sets the animation type

	constexpr Type getAnimationType() const {
		return Type(settings & typeMask);
	}

	//0201fe34
	bool finished() const; //If speed is positive, it returns true if current frame exceeds frames - 1. If speed is negative, it returns true if currentFrame equals 0 or less.

	//0201fd1c
	bool passing(s16 targetFrame) const; //returns true if the next update passes targetFrame, false otherwise

};
NTR_SIZE_GUARD(FrameCtrl, 0xC);
