#pragma once
#include "nsmb.hpp"

// vtable at 0216D3C0 (ov54)
class TileGod : public StageEntity
{
public:

	using StateFunction = bool(TileGod::*)();

	enum class BlockTypes : u32 
	{
		RedBlock,
		BrickBlock,
		BlueCoin,
		StoneBlock,
		WoodBlock,
		Nothing, 
		RightFacingPipeTop,
		BrokenPipeTopRight,
		UsedBlock = 0xf
	};

	enum class PatternTypes : u32 
	{
		Solid,
		Checkerboard,
		ReverseCheckerboard
	};

	// D0: 021566C4
	// D1: 02156668
	virtual ~TileGod();

	// 02156758
	s32 onCreate() override;

	// 02156728
	bool updateMain() override;

	// 02156CD8
	bool switchState(const StateFunction& function);
	// 02156C90
	void updateState();

	// 02156890
	bool mainState();

	// 021569CC
	void setTiles(bool triggered, bool onCreate); //onCreate = when called from spawn

	// 0216c5e0
	static void init(); // probably what this is?

	static constexpr u16 objectID = 206;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 120;

	// 0216D3B4
	static const ActorProfile profile;

	// 02171768
	static const StateFunction sMain;

	// 0216c0a4
	static const u16 tileIDTable[16];  


	const StateFunction* updateFunction;

	u32 eventMask[2]; 		// ?
	u32 tilesX; 			// num tiles X
	u32 tilesY;				// num tiles Y
	bool32 triggered;
	BlockTypes blockType;
	bool32 permanent;
	PatternTypes patternType;
	bool16 isActive; 		// if not set actor can be destroyed when inactive
	s8 updateStep;

};
NTR_SIZE_GUARD(TileGod, 0x41C);
