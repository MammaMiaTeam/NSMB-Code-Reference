#pragma once

#include "nitro_if.h"


class TextBox;


namespace End::MainScreen {

	enum class State : u8 {
		Null,
		Init,
		Null2,
		Null3,
		FadeOut,
		SaveRequest,
		ExitRequest,
		Save,
		Exit,
		End
	};


	// 020E29CC
	void setup();
	// 020E2640
	void update();
	// 020E2584
	void render();
	// 020E29B4
	void destroy();

	// 020E2514
	void setSaveRequest();
	// 020E24D8
	void setExitRequest();
	// 020E2488
	void setSave();
	// 020E244C
	void setExit();

	// 020E2550
	void setStoryCompleted();

	// 020E23FC
	void loadText(u32 stringIndex, bool dialogBox);

	// 020F15D0
	extern TextBox textbox;

	// 020F15B0
	extern u8 dialogSelection;
	// 020F15B8
	extern s32 dialogTimer;
	// 020F15C0
	extern void* bmg;

	// 020F15B4
	extern State state;

	// 020F15BC
	extern s32 brightnessTimer;

}
