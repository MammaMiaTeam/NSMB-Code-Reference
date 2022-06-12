#pragma once
#include "nitro_if.h"
#include "3d/model.h"


class FadeMask
{
public:

	Model models[10];

	enum class Shape : u8 {
		Circle = 0,
		FadeCircle,
		Bowser,
		Mario,
		Luigi,
		Wario,
		Yoshi,
		Star,
		SlideDown,
		SlideUp
	};

	enum class Mode : u32 {
		//??? = 0,
		Center = 1,
		Invalid,
		//???,
		//???,
		//???
	};

	//02026634
	static u32 modelIDs[10];

	//0203bd88
	static FadeMask::Shape characterFadeMaskIDs[2];

	//02014170
	sym FadeMask() __body

	//D0:02014100
	//D1:0201413c
	sym virtual ~FadeMask() __body

	//020140a0
	bool loadModels();

	//02013c00
	void updateTransition(Shape shape, VecFx32* scale, GXRgb diffuse, s32 alpha, Mode mode);

	//02013bdc
	static bool loadMaskModelFile();

	//02013bd0
	bool loadMaskModels();

	//02013ba8
	bool update(Shape shape, VecFx32* scale, GXRgb diffuse, s32 alpha, Mode mode);

	//02013b98
	static u8 getCharacterFadeMaskID(u8 character);

};
NTR_SIZE_GUARD(FadeMask, 0x5A4);


class Fader
{
public:

	enum class FadingType : u8 {
		FadeOnly = 0,
		StaticMask,
		FadeMask
	};

	enum class StaticMask : u8 {
		Rectangle,
		Rhombus,
		Circle
	};

	//02085c38
	static u8 staticMask[0xC0];

	//02039f80
	static fx32 staticCircleBounds[0xC0];//Used to generate the static circle mask

	//02085a28
	static u32 activeFadeMasks;//Bit0&1

	//02085c28
	static u32 fadeFrames;//Custom fade frames for scenes taking other than 0x20

	//02085c24
	static u32 alphaBlendingPlane1;

	//02085c34
	static u32 alphaBlendingPlane2;

	//02085c30
	static u32 alphaBlendingEVA;

	//02085c2c
	static u32 alphaBlendingEVB;

	FadeMask mask;
	s32 targetBrightness;//Target blend brightness
	FadeMask::Mode fadingMode;//Fading mode
	fx32 brightnessFactor[2];//Blend brightness factor 0-1
	fx32 brightnessIncrement[2];//Blend brightness factor increment
	u8 fadingTarget[2];//Flag targets:1=fade mainscreen;2=fade subscreen
	u8 fadingState[2];//Ugh fade flags:
				/*
					0x01: Fading in
					0x02: Started fade-in
					0x04: Initiated fade-in
					0x08: Fading out
					0x10: Started fade-out
					0x20: Initiated fade-out
					0x40: Faded out (scale reached 0x1000)
				*/
	u8 fadeMaskShape[2];//Fading mask transition shape
	FadingType fadingType;//Fading type
	u8 enableDelay;//Screen enable delay
	u8 unk5c4;//Unknown
	bool fadingStopped;//Fading stopped

	//02008558
	sym Fader() __body

	//02003090
	sym ~Fader() __body

	//020083cc
	void setupSceneFading(FadingType type, bool fadeBright, bool staticBlend);

	//02007f70
	void fade();

	//02007e34
	bool startFadeIn(u32 steps, u8 target);

	//02007df0
	bool tryFadeOut();//True if faded out or no fading was pending

	//02007cf8
	bool startFadeOut(u32 steps, u8 target);

	//02007cb0
	bool fadedIn();

	//02007c68
	bool fadedOut();

	//02007c44
	void enableMainScreenFading();

	//02007c20
	void disableMainScreenFading();

	//02007bfc
	void enableSubScreenFading();

	//02007bd8
	void disableSubScreenFading();

	//02007bb4
	void prepareFadeIn();

	//02007b90
	void prepareFadeOut();

	//02007af8
	static void hBlankIrqHandler();//Only used by non-rectangular masks

	//02007970
	void setupStaticMask(u8 flags, u8 target);

	//020076ac
	void updateStaticMask(u8 target);

	NTR_INLINE void setAlphaBlending(int plane1, int plane2, int ev1, int ev2) {
		alphaBlendingPlane1 = plane1;
		alphaBlendingPlane2 = plane2;
		alphaBlendingEVA = ev1;
		alphaBlendingEVB = ev2;
	}

};
NTR_SIZE_GUARD(Fader, 0x5C8);


namespace Game {

	//02088f48
	extern Fader fader;

	//02085b14
	extern Fader* activeFader;

}
