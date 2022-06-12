#pragma once

#include "nitro_if.h"


namespace End {

	using CharT = u8;


	namespace SubScreen {

		struct String {
			u8 tailCharID;
			u8 headCharID;
			u8 positionY;
			u8 palette;
			u8 pagesLeft;
			u8 unused5[3];
			s32 fadeInTimer;
		};
		NTR_SIZE_GUARD(String, 0xC);

		enum class State : s32 {
			Start,
			Init,
			FadeOutChars,
			Idle,
			FadeInChars,
			SwitchPage,
			WaitFadeTrigger,
			FadeOut,
			End
		};


		// 020DF378
		void setup();
		// 020DF110
		void update();
		// 020DF0D8
		void render();

		// 020E00A0
		void renderChars();

		// 020E023C
		void initScript();
		// 020DFC08
		bool switchPage();
		// 020DFCC0
		void loadPage(u32 page);
		// 020DFE5C
		void loadString(u8 y, const CharT* string);

		// 020DEFC4
		void updateChars();

		// 020DED60
		void updateStringWaves(u32 stringID);
		// 020DECBC
		void updateCharWaves(s32 charID);

		// 020DEF14
		void updateWavesDistance();
		// 020DEF90
		void updateWavesBlink();

		// 020DEC40
		s32 getInactiveWaveID();
		// 020DEC88
		void stopWaves(u32 stringID);
		// 020DEF48
		bool getCharBlink(s32 charID);

		// 020DF0A8
		void enableBGFade();
		// 020DF58C
		void startBGFade();

		// 020DF738
		void startCharsFadeOut();
		// 020DF81C
		s32 startStringFadeOut(u32 stringID);
		// 020DF5F4
		bool fadeOutChars();
		// 020DF638
		bool fadeOutString(u32 stringID);

		// 020DF8E8
		bool fadeInChars();
		// 020DF92C
		bool fadeInString(u32 stringID);

		// 020DFA74
		void fadeChar(u32 charID);
		// 020DF7D0
		void reduceFadeOffset(u32 stringID, s32 factor);
		// 020DFB10
		void applyFadeOffsetY(u32 stringID, bool fadeOut);

		// 020DF0BC
		bool shownFirstPage();

		// 020E035C
		u32 getStringWidth(const CharT* string, s32 length);
		// 020E03B0
		u8 getCharWidth(CharT c);
		// 020E03D4
		u8 getCharOffsetX(CharT c);

		// 020EE8B0
		extern State state;
		// 020EE898
		extern u8 stateStep;
		// 020EE8AC
		extern s32 stateCooldown;
		// 020EE8B8
		extern u32 executionTimer;

		// 020E9C68
		extern GXOamAttr charOamAttr;

		// 020EA3A8
		extern u8 fontOffsetsX[104];
		// 020EA410
		extern u8 fontWidths[104];

		// 020EAA10
		extern u8 subOBJ[14336];
		// 020EA478
		extern u8 subOBJPalette[508];
		// 020EE8A0
		extern u8 mainBGPalette[2];
		// 020E9C48
		extern u8 subBGPalette[2];

		// 020EE89C
		extern bool bgFadeEnabled;
		// 020EE8A8
		extern s32 bgFadeTimer;

		// 020EE8A4
		extern s32 basePageDuration;
		// 020EE8B4
		extern u32 pageDurationOffset;
		// 020EE8BC
		extern u32 pageDurationFactor;

		// 020EE8C0
		extern s32 scriptEntriesCount;
		// 020EE8C8
		extern s32 currentPage;
		// 020EE8CC
		extern s32 pagesCount;
		// 020EE8C4
		extern s32 charCursor;

		// 020EEA24
		extern CharT chars[128];

		// 020EEC64
		extern u32 charsObjCharName[128];

		// 020EE924
		extern u8 charsWavePaletteOffset[128];
		// 020EE9A4
		extern u8 charsFadePaletteOffset[128];

		// 020EF264
		extern s32 charsPositionX[128];
		// 020EF464
		extern s32 charsPositionY[128];

		// 020EF664
		extern s32 charsOffsetX[128];
		// 020EF864
		extern s32 charsOffsetY[128];

		// 020EEB64
		extern s16 charsFadeAngle[128];
		// 020EEE64
		extern s32 charsFadeVelocity[128];
		// 020EFA64
		extern s32 charsFadeOffset[128]; // Separated into x and y component with the angle
		// 020EF064
		extern s32 charsFadeOffsetY[128]; // Divisor for a sine wave offset

		// 020EFC64
		extern s32 charsWaveOffsetX[128];
		// 020EFE64
		extern s32 charsWaveOffsetY[128];
		// 020F0064
		extern s16 charsWaveAngle[4][128];
		// 020F0464
		extern s32 charsWaveFactor[4][128];
		// 020F0C64
		extern s32 charsWaveOffset[4][128]; // Separated into x and y component with the angle

		// 020EE8DC
		extern String strings[6];

	}

}
