#ifndef NSMB_FONT_INCLUDED
#define NSMB_FONT_INCLUDED


/*

020171a0 - 02017250 [GarbageLink]
020171a0: GarbageLink(); //Resets array and size to 0
020171c0: ~GarbageLink(); //Destroys. Does nothing.
020171c4: bool linkEmpty(); //Returns true if unk0c == 0
020171d8: void addLink(u16** link); //Adds link to unk00[unk0c] and increments unk0c
020171f4: u16** getLastLink(); //Returns a pointer to unk00[unk0c - 1]
02017204: void removeLastLink(); //Sets unk00[unk0c - 1] to 0 and decrements the size
02017224: void clear(); //Removes every element from the array

*/


struct GarbageLink {
	u16* unk00[3];
	unsigned unk0c; //Array size
};


struct UTF16Character {

	u16* charPtr;			//Pointer to u16 array containing the UTF-16 codepoint
	unsigned utf16Char;		//Decoded UTF-16 codepoint
	unsigned size;			//2 or 4, depending on UTF-16 codepoint
	u8 invalidChar;			//True if char is an invalid UTF-16 codepoint

//02016c7c: UTF16Character(u16* ptr);	//Sets ptr to charPtr and calls decode()
//02016ba0: void decode(); //Decodes the UTF-16 codepoint pointed to by charPtr and writes all other fields. BUG: Cannot parse extended UTF-16 codepoints (>0xFFFF), possible fix is changing the instruction 02016bf8 from bcc to bcs

};

/*
Escape sequences are constructed with the following layout:
0x0: Escape sequence identifier 0x001A
0x2: Escape sequence length
0x3: Primary selector ID (u8)
0x4: Secondary selector ID (u16)
0x6 (length=[0x2]-6]): Parameters
*/

struct EscapeSequence {

	unsigned unk00; //Primary sequence ID
	unsigned unk04; //Secondary sequence ID
	unsigned unk08; //Parameter byte count
	unsigned unk0c; //Parameter pointer
	unsigned unk10; //Sequence pointer

//02016b34: EscapeSequence(u16* sequencePtr);
//02016ac8: void parse(u16* sequencePtr);
//02016a90: u16 getParameter();
//02016aac: void readParameter(u16* param);
};


struct EscapeSequenceEntry {
	unsigned unk00; //Primary sequence ID
	unsigned unk04; //Secondary Sequence ID
	unsigned unk08; //Callback address or virtual function offset, see unk0c
	unsigned unk0c; //Call parameters, encoded by:
					/*
						0x01: Virtual function call flag: If set, unk08 is interpreted as the virtual function table offset
						0xFFFFFFFE: Object offset: Determines the caller object by offsetting the this pointer.
					*/

/*
	An escape sequence function is thereby called like:

	object = reinterpret_cast<u8*>(object) + (entry->unk0c >> 1); //Offset address by object offset

	if(entry->unk0c & 1){
		(**object + entry->unk08)(object, escapeSequence); //Call virtual function
	}else{
		entry->unk08(object, escapeSequence); //Call entry->unk08
	}

	WARNING: An object offset greater than 1GB leads to unpredictable results; The object offset is calculated at 0x02015380 with [add r0,r0,r2, asr #0x1] and any u32 values where the MSB is set are arithmetically shifted to the right, leading to faults.
*/
};


//02016c7c: 

//vtable at 0203c0a4:
/*
02016a24 dtor
020169f4 dtor_free
020169c8 -
020169c4 -
020169c0 -
020169bc -
*/
//ctor: 02016a4c
//dtor2: 020169cc

//02016a78: void clear(); //Sets unk04 to 0 and calls unk08.clear()
//020167f4: void restoreLink(); //Sets unk04 to the last link in the array and removes the link from the array
//02016818: void addLink(u16* newLink); //Copies unk04 to the array and sets unk04 to newLink
//02016848: void copy(GarbageBase* src); //Copies src's parameters into the calling object and calls prepare
//02016890: void setCharPtr(u16* charPtr); //Sets the charPtr and calls prepare
//020168b0: bool processNextChar(bool stopAtNewline); //Processes the next char (dispatch, glyph render and restore font link when current string has been fully processed) and returns 1 if there are still chars left to dispatch. 
													  //stopAtNewline forces a full stop if a newline character is encountered (also clears all links).
													  //When a null character is encountered, the string is copied into the cache and returns 0.


class GarbageBase {

	u16* unk04;	//Current UTF-16 character dispatch pointer
	GarbageLink unk08;

	virtual ~GarbageBase();

};




//vtable at 0203c114
//ctor at 020167c8
//dtor at 020167a8
//dtor_free at 02016780
//020169c8: -
//02016614: virtual void SetFontString(); //Copies a new string ranging from unk04 to unk1c into the buffer if unk18 is set
//020169c0: -
//020169bc: -
//pure
//pure
/*
02016744: ???
02016714: ???
020166bc: void renderString(unsigned copy, u16* string); //Renders the string given by string and (if copy is 1) is copied into the cache
*/
class GarbageExtension : public GarbageBase {

	unsigned unk18; //Copy flag (if 1, the next processed string can be copied into the cache)
	u16* unk1c; //UTF-16 string source pointer
	u8 unk20;

};




//vtable at 0203c164
//ctor at 020165f4
//V18=string_size
//V1c=string_offset
//020165d4: dtor
//020165ac: dtor_free
//020169c8: -
//02016614: virtual void SetFontString();
//020169c0: -
//020169bc: -
//020165a4: virtual unsigned GetFontStringMaxSize();
//0201659c: virtual u16* GetFontStringPtr();
class YetAnotherGarbage : public GarbageExtension {

	u16 unk24[128]; //Stored font chars

};



//vtable at 0203c13c
//ctor at 0201657c
//0201655c: dtor
//02016534: dtor_free
//020169c8: -
//02016614: virtual void SetFontString();
//020169c0: -
//020169bc: -
//02016430: virtual unsigned GetFontStringMaxSize();
//02016428: virtual u16* GetFontStringPtr();
/*
020164b4: void stringifyNickname(); //Copies the nickname string into unk24
02016438: void stringifyPartnerName(u16* name, unsigned length); //Copies name with length length (capped at 10) to unk24
*/
class GarbageBoss : public GarbageExtension {

	u16 unk24[11];
	u16 padding;

};



//vtable at 0203c0ec
//ctor at 02016408
//020163e8: dtor
//020163c0: dtor_free
//020169c8: -
//02016614: virtual void SetFontString();
//020169c0: -
//020169bc: -
//020163b8: virtual unsigned GetFontStringMaxSize();
//020163b0: virtual u16* GetFontStringPtr();
class LastGarbage : public GarbageExtension {

	u16 unk24[32];

};



//vtable at 0203c0c4
//ctor at 02016390
//02016370: dtor
//02016348: dtor_free
//020169c8: -
//02016614: virtual void SetFontString();
//020169c0: -
//020169bc: -
//02016260: virtual unsigned GetFontStringMaxSize();
//02016258: virtual u16* GetFontStringPtr();
/*
02016268: void stringifyNumber(unsigned number); //Converts number to a string and stores it in unk24
*/
class GarbageMaster : public GarbageExtension {

	u16 unk24[11];
	u16 padding;

};




//vtable at 0203c084 
//ctor at 02015ec0

//Missing members?

//02015ea0: dtor
//02015e78: dtor_free
//020169c8: -
//020169c4: -
//02015c6c: virtual void render(const CharLink* c);
//02015b38: virtual void parseEscapeSequence(EscapeSequence* sequence);


/*
02015e18: ???
02015da4: ???
02015d48: ???
02015cf4: ???
02015b04: void linkGarbageBoss(); 
02015ad0: void linkGarbageMaster();
02015a9c: void linkLastGarbage1();
02015a68: void linkLastGarbage2();
02015a34: void linkLastGarbage3();
02015a00: void linkLastGarbage4();

*/
class GarbageThing : public GarbageBase {

	WeirdGarbage* unk18;
	unsigned unk1c;
	NNSG2dFont* unk20;
	u8 unk24;
	u8 unk25, unk26, unk27; //Unused?
	unsigned unk28;
	unsigned unk2c; //Line count?
	unsigned unk30;

//02089514: 
	static unsigned sequenceTableInitialized; //1 if the escape sequence table has been initialized.
/*
The escape sequence table consists of the following entries:
0: PSID=1, SSID=0, linkGarbageBoss
1: PSID=1, SSID=1, linkGarbageMaster
2: PSID=1, SSID=2, linkLastGarbage1
3: PSID=1, SSID=3, linkLastGarbage2
4: PSID=1, SSID=4, linkLastGarbage3
5: PSID=1, SSID=5, linkLastGarbage4
*/
	static EscapeSequenceEntry escapeSequenceTable[7]; //0203c184

};







//@WeirdGarbage + 0x18
//There are ten times 0x15c bytes after each other
//vtable at 0x0203C03C
//ctor at 02016104
//dtor at 020160dc
//dtor_free at 020160ac
/*
020161d8: void setFontTileList(FontTile* tiles, unsigned count); //Sets font tile list pointer and font tile count
020161b0: ???
02016170: ???
02016000: void setup(void* vramTarget, unsigned xTiles, unsigned yTiles, NNSG2dFont* fontPtr); //Sets up GarbageFrame to defaults with the given parameters
02015f8c: bool AllocateFontBuffers(); //Allocates buffers, sets unk08 accordingly and returns 1 if successful, otherwise 0
02015f48: void FreeFontBuffers(); //Deletes both buffers from heap and sets size to 0
02015fe8: void DeleteValues(); //Frees buffers and sets the vram dest address to 0
02015f08: void FillBuffers(); //Fills both buffers with unk14f | ((unk14f & 0xF) << 4)

*/
class GarbageFrame{

	GarbageThing* unk04; //May also be GarbageBase* (tho unlikely)
	unsigned unk08; //Bitmap buffer ptr
	unsigned unk0c; //Tile buffer ptr
	unsigned unk10; //Buffer size
	unsigned unk14; //Destination VRAM address
	unsigned unk18; //Tiles in x direction (in 8x8 tile units)
	unsigned unk1c; //Tiles in y direction (in 8x8 tile units)
	YetAnotherGarbage unk20;
	NNSG2dFont* unk144; //Font ptr
	unsigned unk148; //Alignment (left=0, centered=1, right=2)
	u8 unk14c; //Font base palette index 1 (glyph pixel with value one takes this index, value two index + 1 and so on)
	u8 unk14d; //Font base palette index 2
	u8 unk14e; //Font base palette index 3
	u8 unk14f; //Buffer fill value
	u8 unk150; //x char margin in px
	u8 unk151; //y char margin in px
	u8 unk152; //y offset from top in px
	u8 unk153; //If true, the default WeirdGarbage palette offset is used instead of greyscale value offsets
	FontTile* unk154; //Pointer to the font tiles
	unsigned unk158; //Number of font tiles

};



struct FontTile {

	u16 xPosition; //X position in 8x8 tile units
	u16 yPosition; //Y position in 8x8 tile units
	u16 tileOffset; //Offset from starting font tile in 8x8 tile units
	u16 padding;
	u32 tileShape; //Encoded tile shape

/*
	Tile encodings:
		0x00000000: x=1; y=1
		0x40000000: x=2; y=2
		0x80000000: x=4; y=4
		0xC0000000: x=8; y=8
		0x00004000: x=2; y=1
		0x40004000: x=4; y=1
		0x80004000: x=4; y=2
		0xC0004000: x=8; y=4
		0x00008000: x=1; y=2
		0x40008000: x=1; y=4
		0x80008000: x=2; y=4
		0xC0008000: x=4; y=8
*/

	static void decode(unsigned* x, unsigned* y, unsigned shape); //02014dbc: Converts from shape to separate x and y 8x8 tile counts

};


struct CharLink {
	u16* stringPointer;
	u16 character;
};



//@0x02089594
//vtable at 0203c064
/*
02015624 dtor
02015590 dtor_free
02015438 virtual void prepare(); //Resets the x/y-offsets and adjusts the x-offset to proper alignment
020153ec virtual void setFontString(); //??? Better name, renders into tile buffer lmao
020153e0 virtual void render(const CharLink* c);
02015294 virtual void parseEscapeSequence(EscapeSequence* sequence); //Sets up the EscapeSequenceTable and calls the respective sequence callback. If no matching entry can be found, the function returns prematurely.
*/
//ctor: 020156b0
/*
0201596c: ???
020158e4: ???
020158a0: ???
02015874: ???
020157b0: void ClearLastGarbage(unsigned index); //Index < 4 -> clear LastGarbage[index], Index >= 4 -> clear all
02015524: ???
020154dc: ???
02015474: void UploadAndDeleteBuffer(); //Copies for each GarbageFrame (if a vram dest address is set) the tile buffer to dest and deletes both bitmap and tile buffers
02015258: GarbageFrame* getNextFreeFrame(); //Returns a pointer to the next GarbageFrame with the condition (unk08.unk0c == 0) [Nothing linked]
0201518c: void renderChar(const CharLink* c); //Renders character belonging to c
02014fe8: void renderGlyph(const NNSG2dGlyph* glyph); //Renders glyph into the bitmap buffer
02014ec8: void renderTile(FontTile* tile); //Copies the bitmap buffer's contents containing tile into the tile buffer
02014d24: void calculateAlignment(); //Sets unk15dc to account for font alignment
02014c08: ???
02014bd8: void linkGarbageBoss();
02014ba8: void linkGarbageMaster();
02014b78: void linkLastGarbage1();
02014b48: void linkLastGarbage2();
02014b18: void linkLastGarbage3();
02014ae8: void linkLastGarbage4();
02014acc: void setColorSelector(EscapeSequence* sequence); //Sets the font color selector to the escape sequence parameter

*/



class WeirdGarbage : public GarbageBase {

	GarbageFrame unk18[16];
	GarbageFrame* unk15d8;
	unsigned unk15dc; //Current font x offset in px
	unsigned unk15e0; //Current font y offset in px
	u8 unk15e4; //x start offset (from left alignment boundary)
	u8 unk15e5; //y start offset
	u8 unk15e6; //Default palette offset
	u8 unk15e7;	//Unused?
	unsigned unk15e8; //Font color selector offset
	GarbageBoss unk15ec;
	GarbageMaster unk1628;
	LastGarbage unk1664[4];
	GarbageThing unk17f4;

	WeirdGarbage();
	virtual ~WeirdGarbage();


//02089510: 
	static unsigned sequenceTableInitialized; //1 if the escape sequence table has been initialized.
/*
The escape sequence table consists of the following entries:
0: PSID=1, SSID=0, linkGarbageBoss
1: PSID=1, SSID=1, linkGarbageMaster
2: PSID=1, SSID=2, linkLastGarbage1
3: PSID=1, SSID=3, linkLastGarbage2
4: PSID=1, SSID=4, linkLastGarbage3
5: PSID=1, SSID=5, linkLastGarbage4
6: PSID=255, SSID=0, setColorSelector
*/
	static EscapeSequenceEntry escapeSequenceTable[7]; //0203c244

};



//statics
//02014a9c: WeirdGarbage* GetWeirdGarbage();
//02014aa8: UpperGarbage* GetUpperGarbage();
//02014ac0: ??? current nftr?
//02014ab4: ??? another nftr?
//02017190: u16 GetScriptFileID(unsigned index); //Returns the script file ID corresponding to index index
//027e37d0: ???
//027e37d4: ???
//020161e4: ???
//02014dbc: ???


//vtable at 0203c02c
//ctor at 020170ac
//0201709c: dtor
//0201707c: dtor_free
struct UpperGarbage {

	unsigned unk04; //BMG string info section index
	unsigned unk08; //Filled in ctor
	unsigned unk0c; //BMG string data offset
	unsigned unk10; //BMG string length
	u8 bmgHeader[32];
	u8 infHeader[20];
	u8 datHeader[12];
	void* unk54; //BMG file ptr

};


//02017134: Reverse u32
//02016e98: Copy and check BMG header
//02016dc8: Copy and check BMG INF chunk header (info)
//02016d70: Copy and check BMG DAT chunk header (info)

//BMG files:
/*

Header: 
0x00: "MESGbmg1"
0x08: u32 bmgSize; //Total file size
0x0c: u32 chunks; //Number of chunks
0x10: u8 encoding; //Encoding (2=UTF-16) [1=CP1252, 2=UTF-16, 3=Shift-JIS, 4=UTF-8]

align(16)
Info chunk:
0x00: "INF1"
0x04: u32 infSize; //Size of INF chunk
0x08: u16 numSections; //Number of strings/sections in file
0x0A: u16 sectionSize; //Section size
0x0C: u16 bmgFileID; //BMG file ID
0x0E: u8 unk;
0x10+: u32 stringOffset[]; //Info entry numStrings times

align(16)
Data chunk [0x20 + infSize]:
0x00: "DAT1"
0x04: u32 datSize; //Size of DAT chunk
0x08+: u8 stringData[]; //String pool [at offset]

*/



#endif	// NSMB_FONT_INCLUDED