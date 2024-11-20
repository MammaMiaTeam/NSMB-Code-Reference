#pragma once

#include <nsmb/core/entity/scene.hpp>


// vtable at 020E9B90 (ov8)
class EndingScene : public Scene {

public:

	inline EndingScene() {}

	// D0: 020DDD74
	// D1: 020DDD94
	virtual ~EndingScene();

	// 020DDE1C
	virtual s32 onCreate() override;
	// 020DDDBC
	virtual s32 onUpdate() override;
	// 020DDDD8
	virtual s32 onRender() override;
	// 020DDDF8
	virtual s32 onDestroy() override;
	// 020DDDF4
	virtual void onCleanupResources() override;

	static constexpr u16 ObjectID = 12;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 19;

	// 020E9B88
	static const ObjectProfile profile;

	// 020E9B80
	static const u32 sseqIDs[2];
	// 020E9B78
	static const u32 sfxSets[2];


	u32 unused64;

};
NTR_SIZE_GUARD(EndingScene, 0x68);
