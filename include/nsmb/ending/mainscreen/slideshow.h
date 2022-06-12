#pragma once

#include "nsmb/graphics/3d/modelanm.h"
#include "nsmb/graphics/3d/animationctrl.h"


namespace End {

	class Slideshow {

	public:

		using StateFunction = void(Slideshow::*)();
		using TransitStateFunction = bool(Slideshow::*)();


		inline Slideshow() {}

		inline ~Slideshow() {}

		// 020E1A64
		bool setup();
		// 020E1A4C
		bool update();
		// 020E1830
		bool render();
		// 020E180C
		bool destroy();
		// 020E1A8C
		bool prepareResources();

		// 020E17E8
		void loadSlide(u32 fileID);
		// 020E17C4
		void unloadSlide();
		// 020E17B4
		void* getSlide();

		// 020E178C
		void loadNewOverlay();
		// 020E1768
		void unloadNewOverlay();
		// 020E16D4
		void applyNewOverlay();

		// 020E1614
		bool switchState(s32 stateID);
		// 020E1560
		void callState();

		// 020E1488
		void initState();
		// 020E112C
		void slideState();
		// 020E1120
		void endState();

		// 020E14AC
		bool initTransitState();
		// 020E1378
		bool slideTransitState();
		// 020E1124
		bool endTransitState();

		// 020E4184
		static const u32 cachePaletteOffsets[2];
		// 020E417C
		static const u32 cacheTextureOffsets[2];

		// 020E418C
		static const char* materialName;

		// 020F1500
		static const StateFunction stateFunctions[3];
		// 020F1518
		static const TransitStateFunction transitStateFunctions[3];


		ModelAnm frontModel;
		ModelAnm backModel;
		AnimationCtrl textureAnimation;
		s16 slideCooldown;
		s16 currentSlide;
		u16 textureDelayTimer;
		u8 unused182;
		bool setupNextSlide;
		bool lastSlide;
		bool finished;
		bool loadingSlide;
		u8 unused187;
		void* slide;
		void* newOverlay;
		u16 slidesCount;
		u16 shownSlides;
		bool useSecondTexture;
		u8 unused193[3];
		s32 stateID;

	};
	NTR_SIZE_GUARD(Slideshow, 0x19C);


	struct alignas(4) Slide {
		u32 fileID;
		char str[20];
		bool sequenceLast;
		u8 world;
		u8 stage;
	};
	NTR_SIZE_GUARD(Slide, 0x1C);

	// 020E4198
	extern const Slide slides[105];

}
