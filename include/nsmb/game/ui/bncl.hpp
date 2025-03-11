#pragma once

#include <nsmb_nitro.hpp>

class BNCL
{
public:
	struct Header {
		char magic[4]; // JNCL
		u16 unused4;
		u16 positionCount;
	};

	struct Object {
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
		u32 bncdObjectID;
	};

	Header header;

	inline Object* getObjects() {
		return rcast<Object*>(rcast<u8*>(this) + sizeof(Header));
	}

	inline Object& getObject(u32 id) {
		return getObjects()[id];
	}

	static inline BNCL* cast(void* data) {
		return rcast<BNCL*>(data);
	}

private:
	// This class is not constructable.
	// It must be loaded from a file and casted.
	BNCL() = delete;
	BNCL(const BNCL&) = delete;
	BNCL& operator=(const BNCL&) = delete;
	~BNCL() = delete;
};
