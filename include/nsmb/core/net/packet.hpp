#pragma once

#include "types.hpp"
#include <nsmb/core/math/random.hpp>


namespace Net {

	constexpr u32 MaxPacketSequencers = 4;

	constexpr u32 PacketFreeByteSize = 32;

	namespace PacketOffset {

		constexpr u32 FreeBytesBitmap = PacketFreeByteSize;
		constexpr u32 RandomSeed = FreeBytesBitmap + 4;
		constexpr u32 RandomSeedDirty = RandomSeed + 1;
		constexpr u32 Marker = RandomSeedDirty + 1;
		constexpr u32 Unknown2A = Marker + 1;

	}

	enum class RandomShareStep : u8 {
		Done,
		Share,
		Await
	};

	using OnPacketTransferComplete = void(*)(u16 aid, void* arg);

	struct PacketSequencer {

		enum Step : u8 {
			SequencerID,
			BufferLength,
			BufferData
		};

		OnPacketTransferComplete* completeCallback;
		void* completeArgument;

		u8* buffers[MaxConsoleCount];
		u8 bufferSize;

	};
	NTR_SIZE_GUARD(PacketSequencer, 0x1C);

	class PacketSequenceBuilder {
	public:

		constexpr static u32 MaxPackets = 4;

		using Step = PacketSequencer::Step;

		struct Packet {

			u8* data;
			u8 size;
			u8 sequencerID;

		};
		NTR_SIZE_GUARD(Packet, 0x8);


		PacketSequenceBuilder();

		virtual ~PacketSequenceBuilder();


		void clear();

		bool pushPacket(u8 sequencerID, u8 size, const u8* data);

		u8 nextByte();


		Packet queue[MaxPackets];
		u8 writePacketID;
		u8 buildPacketID;
		u8 sequenceStep;

	};
	NTR_SIZE_GUARD(PacketSequenceBuilder, 0x28);

	namespace Core {

		void initPacket();

		void clearPacket();

		void processSendPacket();

		void processRecvPacket();

		void advancePacketSequencer(u16 aid, u8 data);


		void setMarker(u32 index);

		void clearMarker(u32 index);

		BOOL checkMarker(u32 index);


		BOOL checkAllPacketBits(u32 offset, u8 mask);

		BOOL shareRandomSeed();


		s32 allocPacketBytes(u32 mask);

		void freePacketBytes(u32 offset, u32 mask);

		void writePacketByte(u32 offset, u8 value);

		void writePacketInt(u32 offset, u32 value);

		u8 readPacketByte(u16 aid, u32 offset);

		u32 readPacketInt(u16 aid, u32 offset);


		s32 createPacketSequencer(u8** consoleBuffers, u8 bufferSize, OnPacketTransferComplete completeFunc, void* completeArg = nullptr);

		void deletePacketSequencer(u32 id);

		bool writePacketSequencer(u32 id, u8 size, const u8* data);

	}

	class PacketByte {
	public:

		PacketByte();

		virtual ~PacketByte();


		NTR_INLINE u8 read(u16 aid) const {
			return Core::readPacketByte(aid, byteOffset);
		}

		NTR_INLINE void write(u8 value) const {
			Core::writePacketByte(byteOffset, value);
		}


		u32 byteOffset;

	};
	NTR_SIZE_GUARD(PacketByte, 0x8);

	class PacketInt {
	public:

		PacketInt();

		virtual ~PacketInt();


		NTR_INLINE u32 read(u16 aid) const {
			return Core::readPacketInt(aid, byteOffset);
		}

		NTR_INLINE void write(u32 value) const {
			Core::writePacketInt(byteOffset, value);
		}


		u32 byteOffset;

	};
	NTR_SIZE_GUARD(PacketInt, 0x8);

	/*
		Used to transmit any number of bytes,
		spread across several frames.

		TODO: debug this extensively, as the
		game only uses it to transmit 2 bytes.
	*/
	class PacketBuffer {
	public:

		PacketBuffer();

		virtual ~PacketBuffer();


		void create(u8 size, OnPacketTransferComplete completeFunc, void* completeArg = nullptr);

		bool send(const u8* data);



		u8* buffers[MaxConsoleCount];
		u8 sequencerID;
		u8 bufferSize;
		bool configured;

	};
	NTR_SIZE_GUARD(PacketBuffer, 0x18);


	extern u32 packetSequencerBitmap;

	extern u32 randomBranchAddress;
	extern u8 randomCallCount;
	extern u8 marker;
	extern RandomShareStep randomShareStep;
	extern PacketSequencer::Step packetSequencerSteps[MaxConsoleCount];
	extern u8 packetSequencerIDs[MaxConsoleCount];
	extern u8 packetSequencerBufCursors[MaxConsoleCount];
	extern u32 packetFreeBytesSendBitmap;
	extern u8 packetSequencerBufLengths[MaxConsoleCount];
	extern u32 packetFreeBytesRecvBitmap[MaxConsoleCount];
	extern u8 packetFreeBytes[PacketFreeByteSize];
	extern Random random;
	extern PacketSequenceBuilder packetSequenceBuilder;
	extern PacketSequencer packetSequencers[MaxPacketSequencers];

}
