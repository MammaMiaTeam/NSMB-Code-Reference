#pragma once

#include "nsmb/entity/actor.h"
#include "mainscreen/bowser.h"
#include "mainscreen/bowserjr.h"
#include "mainscreen/slideshow.h"


// vtable at 020EE2D4 (ov8)
class EndingController : public Actor {

public:


	inline EndingController() {}

	// D0: 020E0410
	// D1: 020E0498
	virtual ~EndingController();

	// 020E1BF0
	virtual s32 onCreate() override;
	// 020E1BC0
	virtual s32 onUpdate() override;
	// 020E1B90
	virtual s32 onRender() override;
	// 020E1B60
	virtual s32 onDestroy() override;
	// 020E1C5C
	virtual bool onPrepareResources() override;

	// 020E1CAC
	static void renderModelTexture(fx32 z, NNSG3dResMdl* mdl);
	// 020E1E50
	static void loadModelTexture(NNSG3dResMdl* mdl, const char* name, void* texData, u32 texSize, void* palData, u32 palSize);

	// 020E206C
	static s32 getNextSlideID(s32 slideID);
	// 020E20A4
	static bool getAlternatedSlideFlag(s32 slideID);
	// 020E20F4
	static s32 getFirstSlideID();

	// 020E2124
	static void processSlidesCount();
	// 020E2184
	static void setSlideshowConstants(u32 slidesCount);

	// 020E21C0
	static void markSlideStageCompleted(s32 slide);
	// 020E21D0
	static void markSlideStage(s32 slide, bool completed);
	// 020E22C8
	static bool slideStageBeaten(s32 slide);

	// 020E1EF0
	static bool loadResources();
	// 020E1F38
	static bool loadBowserJrResources();
	// 020E1F88
	static bool loadBowserResources();
	// 020E1FD4
	static bool loadSlideshowResources();

	static constexpr u16 objectID = 314;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 305;

	// 020EE2C8
	static const ObjectProfile profile;

	// 020F1468
	static bool bowserJrComplained;
	// 020F14F0
	static Vec3 bowserJrPosition;

	// 020F14C0
	static Vec3 bowserStartPosition;

	// 020F14E0
	static Vec3 slideshowBackPosition;
	// 020F14D0
	static Vec3 slideshowFrontPosition;

	// 020F1464
	static bool cutsceneEnded;
	// 020F146C
	static bool cutsceneFlag;

	// 020EE210
	static u32 slidesCount;
	// 020EE214
	static u32 slideDuration;


	End::Bowser bowser;
	End::BowserJr bowserJr;
	End::Slideshow slideshow;

};
NTR_SIZE_GUARD(EndingController, 0xA5C);
