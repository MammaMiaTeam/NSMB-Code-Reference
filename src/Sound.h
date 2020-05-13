#ifndef NSMB_SOUND_INCLUDED
#define NSMB_SOUND_INCLUDED

#include "nitro_if.h"

#warning("Remove Vec3 structure from Sound.h after vectors are added.")
struct Vec3
{
	void* vTable;
	s32 x;
	s32 y;
	s32 z;
};

/*
	REGION 1 (Sound):
		Start: 0x02011988
		End  : 0x02012714

	REGION 2 (Sound::Internal):
		Start: 0x0204D98C
		End  : 0x0204F324
*/

//	Contains the functions used to play sounds in the game.
namespace Sound {

	//	Loads the music sequences for toad house levels.
	void loadToadHouseLevelSeqs();

	/*
		Resets the heap state and loads the following music sequences.

		 4 - BGM_COURSE_CLEAR  (Course Clear)
		28 - BGM_GOAL_FANFARE2 (Course Clear Bonus)
		 5 - BGM_DOWN          (Player Death)
		 2 - BGM_MUTEKI        (Starman)
		 3 - BGM_HUGE          (Mega Mushroom)
		18 - BGM_SWITCH        (Switch Timer)
	*/
	void clearAndLoadLevelSeqs();

	/*
		Loads the level main theme.
		The sequence ID to load is retrieved from the view the player is in.
	*/
	void loadLevelThemeSeq();

	//	Resets the heap state and loads sound effect set 1.
	void clearAndLoadSfxSet1();

	/*
		Calls loadLevelThemeSeq if regular music loading is enabled and
		calls and Internal::loadSfxSet with the sound effect set specified
		for the current area.
	*/
	void loadLevelSounds();

	/*
		Resets the heap state and loads multiple sequences from an array
		until it reaches an index which value is 112.
	*/
	void clearAndLoadSeqs(s32* seqIDs);

	//	Resets the heap state and loads a single music sequence.
	void clearAndLoadSingleSeq(s32 seqID);

	/*
		Resets the heap state, loads the Mario Vs Luigi sound
		effect set and sets the playble sequence count to 2.
	*/
	void loadMvsLSfxSetAndSetSeqCount();

	/*
		Resets the heap state and loads multiple sequences from an array
		until it reaches an index which value is 112.
		It also loads multiple sound effect sets from an array until it
		reaches an index which value is 57.
	*/
	void clearAndLoadSeqsAndSfxSets(s32* seqIDs, s32* sfxSetIDs);

	//	Resets the heap state and loads one sequence and one sound effect set.
	void clearAndLoadSingleSeqAndSfxSet(s32 seqID, s32 sfxSetID);

	//	Resets the heap state and loads one sound effect set.
	void clearAndLoadSingleSfxSet(s32 sfxSetID);

	//	Stops all the sounds currently playing.
	void stopAllSounds();

	//	Sets the music tempo ratio if it's different from the current one.
	bool setTempoRatioIfDifferent(s32 ratio);

	//	Stops a special music sequence currently playing.
	void stopSpecialLevelSeq(s32 seqID);

	/*
		Starts a special music sequence.
		Common sequences used by this function are:

		 2 - BGM_MUTEKI        (Starman)
		 3 - BGM_HUGE          (Mega Mushroom)
		18 - BGM_SWITCH        (Switch Timer)
	*/
	void startSpecialLevelSeq(s32 seqID);

	//	Checks if the sequence player exists.
	bool playerDoesNotExist();

	//	Stops the current music playing when entering an entrance.
	void stopSeqForEntrance(s32 fadeFrame);

	//	Stops the current music playing.
	void stopSeq(s32 fadeFrame);

	//	Starts a music sequence.
	bool startSeq(s32 seqID, s32 sfxSetID);

	//	Starts the level theme music sequence.
	void startLevelThemeSeq(s32 seqID);

	/*
		Child of the Sound::loop function.
		Updates how far the sound effects play based on the level zoom.
	*/
	void updateSFXRange();

	/*
		Plays a sound effect from one of the loaded sound archives.
		The position is how far away relative to the camera the sound will play.
	*/
	bool playArcSFXAtPosIfInPosRange(s32 seqArcNo, s32 seqArcIndex, Vec3* pos, s32 volume, s32 channel);

	//	Plays a sound effect normally through the sound effect able without being affected by position.
	void playSFX(s32 sfxID);

	//	Plays an entrance sound effect at a position.
	bool playEntranceSFX(s32 sfxID, Vec3* pos);

	//	Plays a sound effect at position with volume through channel 2.
	bool playSFXChannel2(s32 sfxID, Vec3* pos, s32 volume);

	//	Plays a sound effect at position through channel 2.
	bool playSFXChannel2(s32 sfxID, Vec3* pos);

	//	Plays a sound effect at position with volume through channel 1.
	bool playSFXChannel1(s32 sfxID, Vec3* pos, s32 volume);

	//	Plays a sound effect at position through channel 1.
	bool playSFXChannel1(s32 sfxID, Vec3* pos);

	//	Plays a sound effect at position with volume through channel 0.
	bool playSFXChannel0(s32 sfxID, Vec3* pos, s32 volume);

	//	Plays a sound effect at position through channel 0.
	bool playSFXChannel0(s32 sfxID, Vec3* pos);

	//	The main loop function that is called in the game main loop.
	void loop();

	//	Sets the current sound archive to use as sound archive 0.
	void setCurrentSoundArc0();

	//	Initializes sound for Download Play.
	void initDLP();

	//	Initializes sound.
	void init();

	//	Resets the sound variables. Usually used after loading multiple musics between areas.
	void resetVars();

	/*
		Calls resetVars, sets the playable sequence count to 1
		and resets the current level sound effect set ID.
	*/
	void setupForSeqCount1();

	//	This sound sub region which I named of "Internal" is the region that works with the NNS functions.
	namespace Internal {

		//	Information structure for where to play a sound effect.
		struct SFXPlayInfo
		{
			s32 x;
			s32 y;
			s32 volume;
		};

		/*
			Enables 2 extra insturments for world 8 map.
			Used after the bridge has emerged and the second part is revealed.
		*/
		void setTrackPanForWorld8(bool useCustomPan);

		/*
			Allocates the boss sound heap.
			Used in clearAndLoadLevelSeqs if a level field is checked.
			Level field: reinterpret_cast<u16*>(Block3)[1];
		*/
		bool allocBossSndHeapState();

		void setCurrentSoundArc();

		void setUseLuigiSounds(bool value);

		void setPlayableSeqCount(int seqCount);

		/*
			Child of the Sound::loop function.
			Updates when the enemies are supposed to jump.
		*/
		void updateBahps(void* bahpStruct);

		//	Checks if a value is in range. (Math library duplicate)
		bool inRange(s32 val, s32 low, s32 high);

		//	Returns the absolute value of a number. (Math library duplicate)
		s32 abs(s32 val);

		//	Returns a clamped number. (Math library duplicate)
		s32 clamp(s32 val, s32 low, s32 high);

		//	Returns a wrapped range. (Math library duplicate)
		s32 wrapRange(s32 val, s32 low, s32 max);

		/*
			Sets the sound output effect.
			This function should not be used directly.
			Use Options::setOutputEffect instead.
		*/
		void setOutputEffect(NNSSndCaptureOutputEffectType type);

		//	Fades the music to another volume.
		void moveVolume(s32 targetVolume, s32 frames);

		//	Stops all sound effects playing.
		void stopAllSFX(s32 fadeFrame);

		//	Plays a sound effect from the sound archives.
		void playArcSFX(s32 seqArcIndex, s32 seqArcNo);

		//	Plays a sound effect from the sound archives at a specified position.
		bool playArcSFXAtPos(s32 seqArcIndex, s32 seqArcNo, SFXPlayInfo* playInfo, s32 channel);

		//	Gets the handle for a sound effect.
		NNSSndHandle* getHandleForArcSFX(s32 seqArcNo, s32 seqArcIndex);

		//	Gets the handle for a sound effect in range.
		NNSSndHandle* getHandleForArcSFXInRange(bool lastHandleFound);

		//	Returns if the music play exists.
		bool playerExists();

		/*
			Fades a music away and then stops it.
			fadeFrame = Fade-out frame. Takes a value between 0 and 65535.
		*/
		void stopSeq(s32 fadeFrame);

		//	Pauses a music when true, unpauses when false.
		void pauseSeq(bool flag);

		//	Sets the music tempo ratio for a player.
		bool setTempoRatioForPlayer(NNSSndSeqPlayer* player, s32 ratio);

		//	Sets the music tempo ratio.
		bool setTempoRatio(s32 ratio);

		//	Starts a music sequence.
		bool startSeq(s32 seqId);

		/*
			Stops a music sequence while also fading out volume.
			sfx_frames = Frame count over which to fade sound effects.
			seq_frames = Frame count over which to fade the music sequence.
		*/
		bool stopSfxAndSeq(s32 sfx_frames, s32 seq_frames);

		/*
			Child of the Sound::loop function.
			Keeps music playing.
		*/
		bool updateSounds();

		//	Loads an archive for a sound effect set.
		bool loadArcForSfxSet(s32 sfxSetId);

		//	Loads a sound effect set.
		bool loadSfxSet(s32 sfxSetId);

		//	Loads the heap state.
		void loadHeapState();

		//	Loads the heap state and swaps to boss heap state if true.
		void loadHeapStateAndChange(bool changeState);

		//	Resets all heap states, clears all the loaded musics and sounds.
		void resetHeapStates();

		//	Initializes the sound data.
		void initSDAT();

		//	Loads a music sequence.
		bool loadSeq(s32 seqId);

		//	Starts the output effect capturing.
		bool startOutputEffect(void* buffer_p, u32 bufSize);

		//	Initializes the sound data for download play.
		void initSDAT_DLP(void* sdat);

		//	Sets up NNS for working with the sound heap.
		void setup(void* heap, int size);

	};

	/*
		Call functions:
		void FUN_0204E2F8(); //Calls playArcSFXAtPos
		void FUN_0204F2D4(); //Calls initSDAT

		Unused functions:
		void FUN_02012624(); //Clears a variable that is unused

		Unused variables:
		int 0x02088B58
	*/
};

#endif	// NSMB_SOUND_INCLUDED
