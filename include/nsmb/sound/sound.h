#pragma once
#include "internal.h"
#include "seqdef.h"
#include "seqarcdef.h"
#include "sndgroupdef.h"
#include "seqplayerdef.h"
#include "nsmb/math/vector.h"


namespace SND {

	constexpr u32 StopSound      = 1 << 0;
	constexpr u32 StopRequests   = 1 << 1;

	constexpr s32 ReqStageBGM    = -1;
	constexpr s32 ReqWaitBGM     = -2;
	constexpr s32 ReqResumeBGM   = -3;
	
	constexpr u32 SeqCount       = SeqID::Count;
	constexpr u32 SeqArcCount    = SeqArc::Count;
	constexpr u32 SeqArcIdxCount = SeqArc::SfxCount;
	constexpr u32 SeqPlayerCount = SeqPlayerID::Count;
	constexpr u32 SfxGroupCount  = SndGroupID::Count;

	using Internal::SFXMode;

	struct SFXEntry {

		u32 seqArcNo;
		u32 seqArcIndex;

	};

	// 0203AEB0
	extern SFXEntry soundEffectTable[SeqArcIdxCount];

	// 02088B4C
	extern u16 currentTempoRatio;
	// 02088B50
	extern u16 pendingSeqCount;
	// 02088B54
	extern u32 stopFlags;
	// 02088B58
	extern u32 unused0;
	// 02088B5C
	extern BOOL useBossMusic;
	// 02088B60
	extern s32 currentSfxGroupID;
	// 02088B64
	extern s32 loadedSeqID;
	// 02088B68
	extern s32 requestedSeq;
	// 02088B6C
	extern s32 seqHeapState;
	// 02088B70
	extern s32 bgmSeqID;
	// 02088B74
	extern BOOL bgmInactive;
	// 02088B78
	extern BOOL bgmResumeFlag;
	// 02088B7C
	extern s32 bgmResumeTimer;
	// 02088B80
	extern s32 currentSeqID;
	// 02088B84
	extern u32 unused1;
	// 02088B88
	extern s32 lastReqSeqID;
	// 02088B8C
	extern BOOL requestsPaused[2];
	// 02088B94
	extern s32 bgmVariables[4];
	// 02088BA4
	extern s32 screenBoundsLeft;
	// 02088BA8
	extern s32 screenBoundsRight;
	// 02088BAC
	extern s32 screenBoundsDown;
	// 02088BB0
	extern s32 screenBoundsUp;

	NTR_INLINE void soundOff() {
		stopFlags |= StopSound;
	}

	NTR_INLINE void soundOn() {
		stopFlags &= ~StopSound;
	}

	NTR_INLINE void requestsOff() {
		stopFlags |= StopRequests;
	}

	NTR_INLINE void requestsOn() {
		stopFlags &= ~StopRequests;
	}

	NTR_INLINE void pauseRequests(u8 playerID) {
		ntr_assert(playerID < 2, "Invalid player ID specified");
		requestsPaused[playerID] = true;
	}

	NTR_INLINE void resumeRequests(u8 playerID) {
		ntr_assert(playerID < 2, "Invalid player ID specified");
		requestsPaused[playerID] = false;
	}

	// 02011988
	void loadCommonToadHouseMusic();

	// 020119E8
	void loadCommonStageMusic();

	// 02011ACC
	void loadStageBGM();

	// 02011B64
	void loadAllSoundEffects();

	// 02011B84
	void loadStageSounds();

	// 02011BF8
	void loadMenuSoundList(s32* seqIDs);

	// 02011C34
	void loadMenuSounds(s32 seqID);

	// 02011C64
	void loadVSSoundEffects();

	// 02011C84
	void loadSoundLists(s32* seqIDs, s32* groupIDs);

	// 02011CE4
	void loadSounds(s32 seqID, s32 groupID);

	// 02011D24
	void loadSoundGroup(s32 groupID);

	// 02011D40
	void stopSounds();

	// 02011D60
	void setTempoRatio(u16 ratio);

	// 02011D94
	void stopRequestedBGM(s32 seqID);

	// 02011DC4
	void requestSpecialBGM(s32 seqID);

	// 02011DD4
	bool isBGMStopped();

	// 02011DF4
	void stopStageBGM(s32 frames);

	NTR_INLINE bool suspendSeq(s32 framesMain, s32 framesSecondary = 30) {
		return Internal::suspendSeq(framesMain, framesSecondary);
	}

	// 02011E3C
	void stopBGM(s32 frames);

	NTR_INLINE void pauseBGM(bool paused = true) {
		Internal::pauseSeq(paused);
	}

	// 02011E7C
	bool playBGM(s32 seqID, bool restart);

	// 02011F04
	void playStageBGM(s32 seqID);

	// 02011F5C
	void updateScreenBoundaries();

	// 02012038
	bool playSFX(s32 seqArcNo, s32 seqArcIndex, const Vec3* pos, s32 arg, SFXMode mode);

	// 020121E4
	void stopSFX(s32 sfxID);

	// 0201220C
	bool playSFXHold(s32 sfxID, const Vec3* pos = nullptr);

	// 0201224C
	bool playSFXUnique(s32 sfxID, const Vec3* pos, s32 arg);

	// 02012290
	bool playSFXUnique(s32 sfxID, const Vec3* pos = nullptr);

	// 020122D0
	bool playSFXContinuous(s32 sfxID, const Vec3* pos, s32 arg);

	// 02012314
	bool playSFXContinuous(s32 sfxID, const Vec3* pos = nullptr);

	// 02012354
	bool playSFX(s32 sfxID, const Vec3* pos, s32 arg);

	// 02012398
	bool playSFX(s32 sfxID, const Vec3* pos = nullptr);

	// 020123D8
	void loop();

	// 020125C4
	void useDefaultArchive();

	// 020125D4
	void initializeMB();

	// 020125E8
	void initialize();

	// 02012624
	void resetUnused();

	// 02012638
	void resetState();

	// 02012714
	void reset();
	
}
