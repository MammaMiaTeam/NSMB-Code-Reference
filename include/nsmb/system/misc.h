#pragma once
#include "nitro_if.h"
#include "nsmb/graphics/2d/oam.h"


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
	ssym void storeDataCache(const void* ptr, u32 size) __body
	
	// 02007684
	ssym void flushDataCache(const void* ptr, u32 size) __body
	


	typedef void (*TaskFunc)(void*);
	
	// 02004c30
	ssym bool taskCleanup() __rbody
	
	// 02004cb8
	ssym void runTask(TaskFunc func, void* arg, u32 prio, void* stack, u32 stackSize) __body




	// 02085a88
	extern u32 visiblePlaneMain;

	NTR_INLINE void setVisiblePlane(int plane) {
		visiblePlaneMain = plane;
	}




	// 0200514c
	ssym void resetSystem(u32 param) __body

	// 0200421c
	ssym bool drawBNCLSprite(u8 id, GXOamAttr* oamAttrs, OAM::Flags flags, u8 palette, u8 affineSet, const Vec2* scale, s16 rot, const s16 rotCenter[2], OAM::Settings settings, s32 x, s32 y) __rbody

	// 0200419c
	ssym bool drawBNCLSpriteSub(u8 id, GXOamAttr* oamAttrs, OAM::Flags flags, u8 palette, u8 affineSet, const Vec2* scale, s16 rot, const s16 rotCenter[2], OAM::Settings settings, s32 x, s32 y) __rbody


	// 02004dfc
	ssym void initExtendedIDs() __body

	// 020058c0
	ssym void waitVBlankIntr() __body

	// 02004be0
	ssym void disableVRAMBanks() __body

	// 0200563c
	ssym u16 getBootScene() __rbody

	// 0200564c
	ssym void setBootScene(u16 sceneID) __body

}
