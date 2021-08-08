#pragma once
#include "internal.h"


//	Contains the functions used to play sounds in the game.
namespace SND {

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
		The sequence ID to load is __retrieved from the view the player is in.
	*/
	void loadLevelThemeSeq();

	//	Resets the heap state and loads sound effect set 1.
	void clearAndLoadSFXSet1();

	/*
		Calls loadLevelThemeSeq if regular music loading is enabled and
		calls and Internal::loadSFXSet with the sound effect set specified
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
	void loadMvsLSFXSetAndSetSeqCount();

	/*
		Resets the heap state and loads multiple sequences from an array
		until it reaches an index which value is 112.
		It also loads multiple sound effect sets from an array until it
		reaches an index which value is 57.
	*/
	void clearAndLoadSeqsAndSFXSets(s32* seqIDs, s32* sfxSetIDs);

	//	Resets the heap state and loads one sequence and one sound effect set.
	void clearAndLoadSingleSeqAndSFXSet(s32 seqID, s32 sfxSetID);

	//	Resets the heap state and loads one sound effect set.
	void clearAndLoadSingleSFXSet(s32 sfxSetID);

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

	//	Plays a sound effect normally through the sound effect table without being affected by position.
	void playSFX(s32 sfxID);

	//	Plays an entrance sound effect at a position.
	bool playEntranceSFX(s32 sfxID, const Vec3* pos = nullptr);

	//	Plays a sound effect at position with volume through channel 2.
	bool playSFXChannel2(s32 sfxID, const Vec3* pos, s32 volume);

	//	Plays a sound effect at position through channel 2.
	bool playSFXChannel2(s32 sfxID, const Vec3* pos = nullptr);

	//	Plays a sound effect at position with volume through channel 1.
	bool playSFXChannel1(s32 sfxID, const Vec3* pos, s32 volume);

	//	Plays a sound effect at position through channel 1.
	ssym bool playSFXChannel1(s32 sfxID, const Vec3* pos = nullptr) __rbody

	//	Plays a sound effect at position with volume through channel 0.
	bool playSFXChannel0(s32 sfxID, const Vec3* pos, s32 volume);

	//	Plays a sound effect at position through channel 0.
	ssym bool playSFXChannel0(s32 sfxID, const Vec3* pos = nullptr) __rbody

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


}
