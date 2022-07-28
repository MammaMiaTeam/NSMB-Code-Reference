#pragma once
#include "common.h"
#include "object.h"


enum class SceneID : u16 {

	// Game/common
	Boot,
	Connect,
	Debug,
	Stage,
	TitleScreen,
	MvsLSetup,
	MvsLMainMenu,
	Save,
	World,
	Worldmap,
	MvsLResults,
	CorruptedSave,
	Ending,
	StageIntro,
	GameOver,
	MvsLStageIntro,
	SoundTest,
	Key,

	// Minigames
	MGMainMenu = 0x146,

	Invalid = 0x0181,
};


class Scene : public Object
{
public:

	u32 wifiIconOBJIndex;
	u32 wifiIconOBJPalette;

	//0203bd28
	static bool isSceneActive;

	//0203bd2c
	static u16 previousSceneID;

	//0203bd30
	static u16 nextSceneID;

	//0203bd34
	static u16 currentSceneID;

	//02088f38
	static u32 nextSceneSettings;

	//02013b2c
	sym Scene() __body

	//D2:020137b8

	//D0:020138dc
	//D1:02013a08
	sym virtual ~Scene() override __body

	//02013764
	sym virtual bool preCreate() override __rbody

	//02013718
	sym virtual void postCreate(BaseReturnState state) override __body

	//020136e8
	sym virtual bool preDestroy() override __rbody

	//020136c8
	sym virtual void postDestroy(BaseReturnState state) override __body

	//02013500
	sym virtual bool preUpdate() override __rbody

	//020134f4
	sym virtual void postUpdate(BaseReturnState state) override __body

	//020134c4
	sym virtual bool preRender() override __rbody

	//020134b8
	sym virtual void postRender(BaseReturnState state) override __body

	//020133a4
	sym static void prepareFirstScene() __body

	//020132a0
	sym static u16 tryChangeScene() __rbody

	//020131fc
	sym static void switchScene(u16 sceneID, u32 settings = 0) __body

	NTR_INLINE static void switchScene(SceneID sceneID, u32 settings = 0) {
		switchScene(u16(sceneID), settings);
	}

	//020131d8
	sym static void switchToFileCorruptedScene(u32 settings) __body

};
NTR_SIZE_GUARD(Scene, 0x64);


namespace ProcessManager {

	NTR_INLINE Scene* getNextScene(const Scene* scene = nullptr) {
		return static_cast<Scene*>(getNextObjectByType(ObjectType::Scene, scene));
	}

}
