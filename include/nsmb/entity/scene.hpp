#pragma once
#include "common.hpp"
#include "object.hpp"


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
	Scene();

	//D2:020137b8

	//D0:020138dc
	//D1:02013a08
	virtual ~Scene() override;

	//02013764
	virtual bool preCreate() override;

	//02013718
	virtual void postCreate(BaseReturnState state) override;

	//020136e8
	virtual bool preDestroy() override;

	//020136c8
	virtual void postDestroy(BaseReturnState state) override;

	//02013500
	virtual bool preUpdate() override;

	//020134f4
	virtual void postUpdate(BaseReturnState state) override;

	//020134c4
	virtual bool preRender() override;

	//020134b8
	virtual void postRender(BaseReturnState state) override;

	//020133a4
	static void prepareFirstScene();

	//020132a0
	static u16 tryChangeScene();

	//020131fc
	static void switchScene(u16 sceneID, u32 settings = 0);

	NTR_INLINE static void switchScene(SceneID sceneID, u32 settings = 0) {
		switchScene(u16(sceneID), settings);
	}

	//020131d8
	static void switchToFileCorruptedScene(u32 settings);

};
NTR_SIZE_GUARD(Scene, 0x64);


namespace ProcessManager {

	NTR_INLINE Scene* getNextScene(const Scene* scene = nullptr) {
		return static_cast<Scene*>(getNextObjectByType(ObjectType::Scene, scene));
	}

}
