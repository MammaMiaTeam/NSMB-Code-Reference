#pragma once
#include "nitro_if.h"


namespace SND {
namespace Internal {

	constexpr u32 MainArchive      = 0;
	constexpr u32 MultiBootArchive = 1;

	enum class SFXMode {
		Retrigger,
		Continuous,
		Unique
	};

	struct SFXParams {

		s32 x;
		s32 y;
		s32 parameter;

	};

	struct SFXEmitter {

		NNSSndHandle handle;
		u32 seqArcIndex;
		u32 seqArcNo;
		BOOL continuous;
		BOOL starting;

	};

	struct SeqPlayer {

		NNSSndHandle handle;
		BOOL paused;
		BOOL secondary;
		u32 unusedC;

	};

	// 02085304
	extern const char* soundArchivePaths[1];
	// 02085308
	extern s32 subTempoRatio;
	// 0208530C
	extern s32 mainTempoRatio;

	// 0208FB9C
	extern s32 currentSfxGroupID;
	// 0208FBA0
	extern BOOL ignoreSeq;
	// 0208FBA4
	extern BOOL heapCreated;
	// 0208FBA8
	extern BOOL initializedMB;
	// 0208FBAC
	extern s32 lastContinuousPan;
	// 0208FBB0
	extern NNSSndArc* lastSoundArchive;
	// 0208FBB4
	extern s32 unused0;
	// 0208FBB8
	extern NNSSndHeapHandle soundHeap;
	// 0208FBBC
	extern BOOL initialized;
	// 0208FBC0
	extern BOOL world8TrackUnmute;
	// 0208FBC4
	extern BOOL useLuigiSounds;
	// 0208FBC8
	extern NNSSndCaptureOutputEffectType outputEffect;
	// 0208FBCC
	extern s32 scheduledSeqTimer;
	// 0208FBD0
	extern s32 currentHeapState;
	// 0208FBD4
	extern s32 initialHeapState;
	// 0208FBD8
	extern s32 currentSeqID;
	// 0208FBDC
	extern s32 sfxVolume;
	// 0208FBE0
	extern BOOL sleepEnded;
	// 0208FBE4
	extern BOOL sleepStarted;
	// 0208FBE8
	extern BOOL sleepFade;
	// 0208FBEC
	extern BOOL hurryUpFade;
	// 0208FBF0
	extern BOOL hurryUpTempo;
	// 0208FBF4
	extern s32 seqVolume;
	// 0208FBF8
	extern u32 currentSeqPlayerID;
	// 0208FBFC
	extern u32 currentSfxEmitterID;
	// 0208FC00
	extern s16 seqPlayerVariables[4];
	// 0208FC08
	extern SeqPlayer seqPlayerPool[2];
	// 0208FC28
	extern NNSSndArc soundArchive;
	// 0208FCB8
	extern NNSSndArc mbSoundArchive;
	// 0208FD48
	extern SFXEmitter sfxEmitterPool[16];

	// 0204D98C
	void setWorld8TrackMute(bool mute);

	// 0204DA18
	bool createBossHeap();

	// 0204DA6C
	void switchArchive(u32 id);

	// 0204DAD8
	void setLuigiSounds(bool enabled);

	// 0204DAE8
	void setPlayerVoiceCount(u32 playerCount);

	// 0204DB48
	void updateMusicEvents(s32 vars[4]);

	// 0204DC2C
	bool inRange(s32 val, s32 min, s32 max);

	// 0204DC48
	s32 abs(s32 val);

	// 0204DC54
	s32 clamp(s32 val, s32 min, s32 max);

	// 0204DC6C
	s32 wrap(s32 val, s32 min, s32 max);

	// 0204DC98
	void setOutputEffect(NNSSndCaptureOutputEffectType effect);

	// 0204DCB4
	void fadeSeqVolume(s32 targetVolume, s32 frames);

	// 0204DD00
	void stopAllSFXEmitters(s32 frames);

	// 0204DD74
	void stopSFXEmitter(s32 seqArcIndex, s32 seqArcNo);

	// 0204DE10
	bool startSFXEmitter(s32 seqArcIndex, s32 seqArcNo, SFXParams* params, SFXMode mode);

	// 0204E2F8
	bool playSFX(s32 seqArcIndex, s32 seqArcNo, SFXParams* params, SFXMode mode);

	// 0204E304
	SFXEmitter* findActiveSFXEmitter(s32 seqArcIndex, s32 seqArcNo);

	// 0204E358
	SFXEmitter* findFreeSFXEmitter(bool recycleLast);

	// 0204E3F8
	bool isSeqPlaying();

	// 0204E420
	void stopSeq(s32 frames);

	// 0204E47C
	void pauseSeq(bool paused);

	// 0204E4D0
	bool setTempoRatio(NNSSndHandle* handle, s32 ratio);

	// 0204E52C
	bool setTempoRatio(s32 ratio);

	// 0204E5AC
	bool startSeq(s32 id);

	// 0204E87C
	bool suspendSeq(s32 framesMain, s32 framesSecondary);

	// 0204E924
	void updateSound();

	// 0204ECBC
	bool loadGroup(s32 id);

	// 0204EDA8
	bool loadSFXGroup(s32 id);

	// 0204EE14
	void unloadAll();

	// 0204EE84
	void unload(u32 count);

	// 0204EF04
	void resetHeap();

	// 0204EF5C
	void initArchive();

	// 0204F194
	bool loadSeq(s32 seqId);

	// 0204F1DC
	bool startOutputEffect(void* buffer, u32 size);

	// 0204F20C
	void initializeMB(void* archive);

	// 0204F2D4
	void initialize();

	// 0204F2E0
	void createHeap(void* start, u32 size);

}
}
