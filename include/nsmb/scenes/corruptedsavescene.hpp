#pragma once
#include "nsmb/entity/scene.hpp"
#include "nsmb/graphics/2d/font.hpp"

class CorruptedSaveScene : public Scene {
public:

	CorruptedSaveScene();

	virtual ~CorruptedSaveScene() override;

	virtual s32 onCreate() override;

	virtual s32 onDestroy() override;

	virtual s32 onUpdate() override;

	virtual s32 onRender() override;

	virtual void onCleanupResources() override;


	void centerText();

	void appendSpecificSaveName();

	void setMessage(u32 id);

	void eraseSaveData();


	void dialogState();

	void eraseState();

	void promptState();

	void delayState();

	void terminateState();


	static constexpr u16 objectID = 11;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 18;

	static const ObjectProfile profile;

	static const u32 specificSaveStringIDs[4];
	static const u32 specificSaveMasks[4];


	TextBox textBox;
	void* textFile;
	u32 messageID;
	u32 updateStep;
	s32 delayTimer;
	u32 specificSave;
	u32 lineCount;
	s32 dialogSelection;

};
NTR_SIZE_GUARD(CorruptedSaveScene, 0xF8);
