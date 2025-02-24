#pragma once

#include <nsmb_nitro.hpp>

class BNBL
{
public:
	struct Header {
		char magic[4]; // JNBL
		u16 unused4;
		u16 boxCount;
	};

	struct Box {
		enum class Alignment {
			Begin,  // Top/Left
			Center,
			End     // Bottom/Right
		};

		union AlignedCoordinate {
			struct {
				u16 coordinate : 12;
				u16 alignment : 2;
				u16 unused : 2;
			};
			u16 raw;

			inline s16 getCoordinate() {
				return scast<s16>(coordinate);
			}

			inline Alignment getAlignment() {
				return scast<Alignment>(alignment);
			}
		};

		AlignedCoordinate x;
		AlignedCoordinate y;
		u8 width;
		u8 height;

		// 0x02055930
		static s32 getAlignedX(AlignedCoordinate x, u32 width);

		// 0x020558E8
		static s32 getAlignedY(AlignedCoordinate y, u32 height);

		inline s32 getAlignedX() {
			return getAlignedX(x, width);
		}

		inline s32 getAlignedY() {
			return getAlignedY(y, height);
		}

		inline bool contains(s32 x, s32 y) {
			s32 alignedBoxX = getAlignedX();
			s32 alignedBoxY = getAlignedY();
			return (alignedBoxX <= x && x <= alignedBoxX + width && alignedBoxY <= y && y <= alignedBoxY + height);
		}
	};

	Header header;

	// 0x02055AD4
	u16 getBoxCount();

	// 0x02055A0C
	s16 getBox(s32 x, s32 y);

	inline Box* getBoxes() {
		return rcast<Box*>(rcast<u8*>(this) + sizeof(Header));
	}

	inline Box& getBox(u32 id) {
		return getBoxes()[id];
	}

	static inline BNBL& cast(void* data) {
		return *rcast<BNBL*>(data);
	}

private:
	// This class is not constructable.
	// It must be loaded from a file and casted.
	BNBL() = delete;
	BNBL(const BNBL&) = delete;
	BNBL& operator=(const BNBL&) = delete;
	~BNBL() = delete;
};
