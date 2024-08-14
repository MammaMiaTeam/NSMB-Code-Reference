#pragma once
#include "nsmb/entity/scene.hpp"
#include "nsmb/graphics/2d/font.hpp"

class CorruptedSaveScene : public Scene {
public:

	enum Type {

		SaveCorrupted,
		SaveFile1,
		SaveFile2,
		SaveFile3,
		SaveMinigames,
		SpecificSaveCorrupted,
		ReadError,
		OptionsCorrupted,
		EraseError,
		Erasing,
		Erased,
		ErasePrompt,
		Yes,
		No,
		EraseWarning,
		SaveError,
		FileEraseError,
		CopyError

	};

	enum SpecificSave {

		File1 = 0x100,
		File2 = 0x200,
		File3 = 0x400,
		Minigames = 0x800,
		Options = 0x1000,

	};


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


	constexpr static u32 makeSettings(u32 type, u32 specificSave) {
		u32 s{};
		s |= type & 0xFF;
		s |= specificSave & 0x1F00;
		return s;
	}


	static constexpr u16 ObjectID = 11;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 18;

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
