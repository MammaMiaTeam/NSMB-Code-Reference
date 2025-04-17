#pragma once

#include <nsmb_nitro.hpp>
#include <nsmb/extra/bitmaskenum.hpp>

namespace App {

	using CallbackFunction = s32(*)();
	using BootTargetFunction = s32(*)();

	enum class SleepPhase : u8 {
		Awake,
		LidClosing,
		LidClosed,
		Sleeping,
		LidOpening,
		LidOpened,
		WakeUp,
		Stop
	};

	enum class SleepControl : u8 {

		// States that will switch to a "partial sleep".
		UsingWifi = 0x2,			// Wireless communications are running
		WritingSave = 0x10,			// Backup chip is being written to

		// States that will disable sleeping entirely
		LoadingStage = 0x20,		// Currently loading and setting up a stage
		SwitchingScene = 0x40,		// Currently in the process of switching scenes
		UnloadingStage = 0x80,		// Currently unloading and cleaning up stage resources

		/*
			"Partial sleep" states will not make the game go into full hardware sleep mode (which includes power saving).
			Instead the game will simply turn off/on the LCD power while keeping tasks running in the background.
		*/
		PartialSleepMask = 0x1F,
		/*
			"Disable sleep" states will disable sleeping entirely, or, in case the game is already sleeping,
			it will prevent it from waking up from sleep mode.
			Considering a full hardware sleep mode cannot be triggered during a "disable sleep" state,
			this second circumstance is only possible when the game goes to sleep during a "partial sleep" state:
			In this case the game will not power on the LCD until the "disable sleep" state has been cleared.
		*/
		DisableSleepMask = 0xE0

	};
	NTR_CREATE_BITMASK_ENUM(SleepControl);

	enum BootScene {
		Boot,
		TitleScreen
	};

	enum BootTarget {
		Game,
		Minigames
	};

	constexpr u32 BootTargetCount = 2;


	constexpr u32 makeResetParam(u32 target, u32 scene, u32 param = 1) {
		return (target & 0xF) | (scene & 0xF) << 8 | (param & 0xF) << 16;
	}


	void branchToStartup();

	void branchToMain();

	void setBootTarget(u32 target);

	u32 getBootTarget();

	NTR_INLINE bool isGameBoot() {
		return getBootTarget() == Game;
	}

	NTR_INLINE bool isMinigamesBoot() {
		return getBootTarget() == Minigames;
	}

	void setBootScene(u32 scene);

	u32 getBootScene();

	NTR_INLINE bool isRegularBoot() {
		return getBootScene() == Boot;
	}

	NTR_INLINE bool isTitleScreenBoot() {
		return getBootScene() == TitleScreen;
	}

	void setBootParam(u32 param);

	s32 defaultCallback();

	void onInitialize();

	void powerOffBacklight();

	void powerOnBacklight();

	void stopDisplayDMA();

	void updateSleep();

	void forceDisplayOn();

	void stop();

	void reset(u32 param);

	NTR_INLINE void reset(u32 target, u32 scene, u32 param = 1) {
		reset(makeResetParam(target, scene, param));
	}

	bool isSleeping();

	s32 playSFX(u32 sfxID, s32 successValue);

	s32 onLidClosedDefault();

	s32 onLidOpenedDefault();

	s32 updateTaskDefault();

	void onStartup();

	BOOL onCardPulledOut();

	void gameInit();

	void gameLoop();

	void initialize();

	void gameMain();

	void commonStartup();

	void initFileCount(bool multiboot);

	void initBoot();


	extern u8 frameLength;
	extern CallbackFunction preLidClosed;
	extern CallbackFunction postLidOpened;
	extern CallbackFunction onLidClosed;
	extern CallbackFunction onLidOpened;
	extern CallbackFunction updateTask;
	extern BootTargetFunction startupTable[BootTargetCount];
	extern BootTargetFunction mainTable[BootTargetCount];

	extern SleepPhase sleepPhase;
	extern bool backlightOff;
	extern SleepControl sleepControl;
	extern bool sleeping;
	extern s16 sleepPhaseTimer;
	extern u16 sleepWakeUpTimer;
	extern PMBackLightSwitch backlightTop;
	extern PMBackLightSwitch backlightBottom;
	extern u32 bootParam;
	extern u32 bootTarget;
	extern u32 bootScene;


	NTR_INLINE void setUpdateTask(CallbackFunction func) {
		updateTask = func;
	}

	NTR_INLINE void setOnLidOpened(CallbackFunction func) {
		onLidOpened = func;
	}

	NTR_INLINE void setOnLidClosed(CallbackFunction func) {
		onLidClosed = func;
	}

	NTR_INLINE void setPostLidOpened(CallbackFunction func) {
		postLidOpened = func;
	}

	NTR_INLINE void setPreLidClosed(CallbackFunction func) {
		preLidClosed = func;
	}

	NTR_INLINE void setFrameLength(u8 length) {
		frameLength = length;
	}

	NTR_INLINE u32 getBootParam() {
		return bootParam;
	}

	// This control flag is automatically set in App::updateSleep()
	NTR_INLINE void startUsingWifi() {
		sleepControl |= SleepControl::UsingWifi;
	}

	NTR_INLINE void finishUsingWifi() {
		sleepControl &= ~SleepControl::UsingWifi;
	}

	NTR_INLINE void startWritingSave() {
		sleepControl |= SleepControl::WritingSave;
	}

	NTR_INLINE void finishWritingSave() {
		sleepControl &= ~SleepControl::WritingSave;
	}

	NTR_INLINE void startLoadingStage() {
		sleepControl |= SleepControl::LoadingStage;
	}

	NTR_INLINE void finishLoadingStage() {
		sleepControl &= ~SleepControl::LoadingStage;
	}

	NTR_INLINE void startSwitchingScene() {
		sleepControl |= SleepControl::SwitchingScene;
	}

	NTR_INLINE void finishSwitchingScene() {
		sleepControl &= ~SleepControl::SwitchingScene;
	}

	NTR_INLINE void startUnloadingStage() {
		sleepControl |= SleepControl::UnloadingStage;
	}

	NTR_INLINE void finishUnloadingStage() {
		sleepControl &= ~SleepControl::UnloadingStage;
	}

}
