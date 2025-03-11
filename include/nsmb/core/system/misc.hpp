#pragma once

#include <nsmb/core/graphics/2d/oam.hpp>


#define isDSiMode			(*reinterpret_cast<u8*>(0x04004000) & 1)

/*
*	TODO:
*	add TP/TouchPad header
*/

#define penDownAddr			((bool*)0x20888E5)
#define penXAddr			((u8*)0x20888E6)
#define penYAddr			((u8*)0x20888E7)

#define penDown				(*penDownAddr)														// touchpad being touched
#define penX				(*penXAddr)															// calibrated touchpad X
#define penY				(*penYAddr)															// calibrated touchpad Y


namespace Game
{

	// 0200765c
	void storeDataCache(const void* ptr, u32 size);

	// 02007684
	void flushDataCache(const void* ptr, u32 size);



	typedef void (*TaskFunc)(void*);

	// 02004c30
	bool taskCleanup();

	// 02004cb8
	void runTask(TaskFunc func, void* arg, u32 prio, void* stack, u32 stackSize);




	// 02085a88
	extern u32 visiblePlaneMain;

	NTR_INLINE void setVisiblePlane(int plane) {
		visiblePlaneMain = plane;
	}




	// 0200514c
	void resetSystem(u32 param);

	// 02004dfc
	void initExtendedIDs();

	// 020058c0
	void waitVBlankIntr();

	// 02004be0
	void disableVRAMBanks();

	// 0200563c
	u16 getBootScene();

	// 0200564c
	void setBootScene(u16 sceneID);

}
