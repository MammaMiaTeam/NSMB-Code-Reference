#pragma once
#include "nsmb/stage/entity3danm.h"


class Toadsworth : public StageEntity3DAnm
{
public:

	typedef bool(Toadsworth::*StateFunction)();

	static constexpr u16 objectID = 134;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 152;

	StateFunction* updateFunction;  // Current update function
	Vec3 magicWandPos;			    // Current position of the magic wand
	u32 blockStartX[6];			    // (Green only) Block start X for every block ID
	u32 blockStartY[6];			    // (Green only) Block start Y for every block ID
	u32 activeBlockField;		    // Blue: Holds the current active block ID bit, Green: Bitfield for all triggered blocks, Red: Block activated
	u32 magicEmitterID;			    // Particle emitter ID of the magic particle 
	u16 startSceneState;		    // State of the intro
	u16 timer;			            // Generic timer
	u16 greenBlockIndex;		    // Current index of green toadhouse block
	u16 blockSpawnState;		    // 0: None spawned, 1: Item/2x green spawned, 2: 6x green spawned
	u16 unused510;                  // Unused
	bool playingSpecialMusic;	    // True if the special toadhouse track at the level end is being played
	bool exitingLevel;			    // True is the level is about to finish
	u8 cardDroppedField;		    // (Green only) Bitfield storing which card block IDs have been dropped
	bool resolveCards;			    // (Green only) True if the cards should turn into their corresponding items
	bool greenGameFinished;		    // (Green only) True if the game ends and items will drop soon
	bool bowserHitFirstTry;		    // (Green only) True if the player picked bowser as the first card
	bool doubleHitFirstTry;		    // (Green only) True if the player picked x2 as the first card
	bool doubleCardDropped;		    // (Green only) True if the double card got dropped
	u8 tripleUpBlockID;			    // (Green only) Block ID of the triple up card
	u8 bowserBlockID;			    // (Green only) Block ID of the bowser card
	u8 doubleBlockID;			    // (Green only) Block ID of the x2 card
	u8 nextCardHideIndex;		    // (Green only) Green card index of the card that is about to hide
	u8 hiddenCardField;			    // (Green only) Bitfield storing which card IDs have been hidden
	bool cardsHidden;			    // (Green only) True when the cards have been hidden
	bool cardsMixed;			    // (Green only) True when the cards have been mixed
	bool gameActive;			    // True when the game's setup is finished
	u8 stageMode;			        // 0: Green, 1: Enemy, 2: Red, 3: Yellow, 4: Blue
	s8 updateStep;			        // Step of the current state: 0:init,1:update,-1:exit

};
NTR_SIZE_GUARD(Toadsworth, 0x524);
