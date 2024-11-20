#pragma once

#include "types.hpp"


namespace Net {

	BOOL hasMultiBootChildren();

	u32 getMultiBootGgid();


	const Packet* getPacket(u16 aid);

	PacketAction getPacketAction(u16 aid);

	u16 getPacketTick(u16 aid);

	void setPacketByte(u32 offset, u8 data);

	u8 getPacketByte(u16 aid, u32 offset);


	void uploadSignalStrengthIcon(void* charPtr, const void* iconTop, const void* iconBottom, u32 charName, u8 subScreen);

	void uploadSignalStrengthPalette(u32 charName, u32 paletteSlot, u8 subScreen);

	void renderSignalStrengthIcon(u32 charName, u32 paletteSlot, u8 subScreen);


	u16 getConsoleKeys(u16 aid);

	TPData getConsoleTouchPad(u16 aid);


	void setMarker(u32 index);

	void clearMarker(u32 index);

	BOOL checkMarker(u32 index);


	void clearUnused2A();

	void syncRandomFast();

	BOOL syncRandomFull();

	u32 getRandom();

	u32 getRandom12();


	BOOL assert(BOOL condition);

}
