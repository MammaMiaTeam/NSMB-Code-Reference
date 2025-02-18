#pragma once

#include <nsmb_nitro.hpp>

class BNCD
{
public:
	struct Header {
		char magic[4]; // JNCD
		u16 unk4;
		u16 objectCount;
		u32 objectDataOffset;
		u32 oamAttrDataOffset;
		u32 bitmapDataOffset;
		u32 bitmapDataSize;
		u32 unk18;
	};

	struct Object {
		u8 width;
		u8 height;
		u16 attrStartIndex;
		u16 attrCount;
	};

	struct OamAttr {
		GXOamAttr oamAttr;
		u16 tileNumber;
		u16 tileCount;
	};

	Header header;

	static inline BNCD& cast(void* data) {
		return *rcast<BNCD*>(data);
	}

	// 0x02055978
	u32 getDisplayFlags();

	// 0x020559A4
	Object& getObject(u32 objectID);

	// 0x020559B8
	u32 getBitmapDataSize();

	// 0x020559C0
	void* getBitmapData();

	// 0x020559CC
	OamAttr* getOamAttr(u32 objectID);

	// 0x020559F4
	u32 getOamAttrCount(u32 objectID);

private:
	// This class is not constructable.
	// It must be loaded from a file and casted.
	BNCD() = delete;
	BNCD(const BNCD&) = delete;
	BNCD& operator=(const BNCD&) = delete;
	~BNCD() = delete;
};
