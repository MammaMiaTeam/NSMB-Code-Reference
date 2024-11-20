#pragma once

#include <nsmb/core/wifi/types.hpp>


namespace Net {

	// TODO: Replace with constant from wireless_shared/wh.hpp
	constexpr u32 MaxConsoleCount = Wifi::MaxConsoleCount;

	// TODO: Constant from wireless_shared/wh.hpp
	constexpr SizeT PacketSize = Wifi::SharedDataSize;
	constexpr SizeT PacketHeaderSize = 0x8;
	constexpr SizeT PacketDataSize = PacketSize - PacketHeaderSize;

	enum class PacketAction : u8 {

		None,
		Pair,
		Synchronize,
		Transfer,

		SyncTransfer = Transfer,
		FastTransferOrdered = Transfer | 0x10,
		FastTransferUnordered = Transfer | 0x20,
		TransferDone = Transfer | 0x30

	};

	struct PacketHeader {

		u16 tick;
		u16 keys;
		PacketAction action;
		bool padTouch;
		u8 padX;
		u8 padY;

	};
	NTR_SIZE_GUARD(PacketHeader, PacketHeaderSize);

	struct Packet : PacketHeader {

		u8 data[PacketDataSize];

	};
	NTR_SIZE_GUARD(Packet, PacketSize);

}
