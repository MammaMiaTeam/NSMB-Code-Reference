#pragma once
#include "nsmb/math/vector.h"



/*
	Stack that holds linking pointers to UTF-16 strings
	Links are used to have special font cache's contents inlined into a string. 
	If e.g. a NumberCache is linked, the FontLinkStack pushes the pointer to the next character in the main string and sets charPtr to the special cache's string start.
*/
struct FontLinkStack {

	u16* fontLinks[3];						//Font link stack
	u32 linkCount;							//Font link count
	

	FontLinkStack();						//Resets the stack
	~FontLinkStack();						//Destroys. Does nothing.
	
	bool empty();							//returns true if linkCount is 0
	void push(u16** link);					//Pushes a new link on the stack and increments linkCount
	u16** peek();							//returns a pointer to the stack top (doesn't check if stack is empty)
	void pop();								//Pops the topmost element from the stack and decrements the linkCount
	void clear();							//Clears the stack and sets linkCount to 0

};
NTR_SIZE_GUARD(FontLinkStack, 0x10);



/*
	Stores information on a UTF16 character
	BUG: Cannot parse extended UTF-16 codepoints (>0xFFFF), possible fix is changing the instruction 02016bf8 from bcc to bcs
*/
struct UTF16Character {

	u16* charPtr;				//Pointer to u16 array containing the UTF-16 codepoint
	u32 utf16Char;				//Decoded UTF-16 codepoint
	u32 size;					//2 or 4, depending on UTF-16 codepoint location
	bool invalidChar;			//True if UTF-16 codepoint is invalid

	UTF16Character(u16* ptr);	//Sets ptr to charPtr and calls decode()
	void decode();				//Decodes the UTF-16 codepoint pointed to by charPtr and writes all other fields. 

};
NTR_SIZE_GUARD(UTF16Character, 0x10);




/*
	Holds escape sequence data
	Escape sequences are constructed with the following layout:
		0x0: Escape sequence identifier 0x001A
		0x2: Escape sequence length
		0x3: Primary selector ID (u8)
		0x4: Secondary selector ID (u16)
		0x6 (length=[0x2]-6]): Parameters (always as u16's)
	In fact, parameter byte count could be greater than 2 (but must be even), getParameter() and readParameter() limit this to the first u16. However, more parameters could be read manually from params.
*/

struct EscapeSequence {

	u32 psid;				//Primary sequence ID
	u32 ssid;				//Secondary sequence ID
	u32 paramBytes;			//Parameter byte count
	u8* params;				//Parameter pointer
	u8* sequence;			//Sequence pointer (start of sequence)

	EscapeSequence(u8* sequencePtr);					//Sets both ids to -1 and calls parse() when sequencePtr is non-null
	void parse(u8* sequencePtr);						//Parses the sequence and updates the object's data accordingly
	u16 getParameter();									//returns the first parameter of the given sequence
	void readParameter(u16* parameter);					//Writes the first parameter from params into parameter
	static u16 buildU16(u8* sequencePtr, u32 offset);	//Build a u16 from two consecutive bytes pointed to by sequencePtr + offset

};
NTR_SIZE_GUARD(EscapeSequence, 0x14);





/*
	Escape sequence table entry
	Used for escape sequence lookup.
*/
struct EscapeSequenceEntry {

	u32 psid;				//Primary sequence ID
	u32 ssid;				//Secondary sequence ID
	u32 functionTarget;		//Callback address or virtual function offset, see unk0c
	u32 callParams;			//Call parameters

	/*
		Call parameters are encoded as follows:
			0x00000001: Virtual function call flag: If set, functionTarget is interp__reted as the virtual function table offset
			0xFFFFFFFE: Object offset: Determines the caller object by offsetting the object's current this pointer.

		An escape sequence function is thereby called like:

			object = reinterp__ret_cast<u8*>(object) + (entry->callParams >> 1); //Offset address by object offset

			if(entry->callParams & 1){
				(**object + entry->functionTarget)(object, escapeSequence); //Call virtual function
			}else{
				entry->functionTarget(object, escapeSequence); //Call entry->functionTarget
			}

		WARNING: An object offset greater than 1GB leads to unpredictable results; The object offset is calculated at 0x02015380 with [add r0,r0,r2, asr #0x1] and any u32 values where the MSB is set are arithmetically shifted to the right, leading to faults.
	*/
};
NTR_SIZE_GUARD(EscapeSequenceEntry, 0x10);




/*
	Base class for all font related objects
*/
class FontBase 
{
public:

	u16* charPtr;						//Current UTF-16 character dispatch pointer
	FontLinkStack linkStack;			//Font link stack

	FontBase();
	virtual ~FontBase();

	virtual void prepare();											//Does nothing
	virtual void onStringDispatched();								//Does nothing
	virtual void processChar(UTF16Character* c);					//Does nothing
	virtual void parseEscapeSequence(EscapeSequence* sequence);		//Does nothing

	void reset();								//Sets charPtr to 0 and calls linkStack.clear()
	void addLink(u16* fontLink);				//Copies charPtr to the link stack and sets charPtr to fontLink
	void restoreLink();							//Sets charPtr to the topmost link on the stack and pops it thereafter
	void copy(FontBase* src);					//Copies src's parameters into the calling object and calls prepare()
	void setCharPtr(u16* cPtr);					//Sets charPtr to cPtr and calls prepare()
	bool processNextChar(bool stopAtNewline);	//Processes the next char, calls processChar()/parseEscapeSequence() respectively and returns true if there are still chars left to dispatch. 
												//stopAtNewline forces a full stop if a newline character is encountered (also clears the link stack).
												//When a null character is encountered, onStringDispatched() is invoked and false is returned.

};
NTR_SIZE_GUARD(FontBase, 0x18);



/*
	Base class for all string storage objects
	'Special font caches' refer to all caches not being a StringCache.
	When subclassing, ensure alignment on a 4-byte boundary
*/
class FontCache : public FontBase 
{
public:

	u32 copy;						//Copy flag (if 1, the next processed string can be copied into the cache)
	u16* srcPtr;					//UTF-16 string source pointer
	bool success;					//True if process finished successfully (always true, probably intended to be modifiable in processNextChar() to set an error status).

	FontCache();
	virtual ~FontCache();

	virtual void onStringDispatched() override;			//If copy is 1, the cache is cleared and the string ranging from srcPtr to charPtr is copied into the cache???
	virtual u32 getCacheSize() = 0;
	virtual u16* getCachePtr() = 0;

	bool processString(u16* string);					//Processes string and copies it into the caller's cache. returns success.
	bool processString(FontCache* cache);				//Processes cache's cached string and copies the string into the caller's cache. returns success.
	void processString(u32 doCopy, u16* string);		//Clears all links, copies doCopy and string to copy and srcPtr respectively and processes every char in the string

};
NTR_SIZE_GUARD(FontCache, 0x24);



/*
	Cache holding main strings
*/
class StringCache : public FontCache 
{
public:

	alignas(4)
	u16 stringCache[128];			//String cache for up to 64 2 byte UTF-16 characters

	StringCache();
	virtual ~StringCache();

	virtual u32 getCacheSize() override;				//returns 256
	virtual u16* getCachePtr() override;				//returns a pointer to stringCache

};
NTR_SIZE_GUARD(StringCache, 0x124);



/*
	Cache holding a player's nickname
*/
class NicknameCache : public FontCache 
{
public:

	alignas(4)
	u16 nicknameCache[11];			//String cache for the nickname

	NicknameCache();
	virtual ~NicknameCache();

	virtual u32 getCacheSize() override;				//returns 22
	virtual u16* getCachePtr() override;				//returns a pointer to nicknameCache

	void stringifyNickname();							//Copies the owner's nickname string into the nicknameCache
	void stringifyOtherName(u16* name, u32 length);		//Copies name with length length (capped at 10) into the nicknameCache (used for the other player's name)

};
NTR_SIZE_GUARD(NicknameCache, 0x3C);




/*
	Cache holding numbers
*/
class NumberCache : public FontCache
{
public:

	alignas(4)
	u16 numberCache[11];			//String cache for 4-byte u32 numbers

	static u16 numberTable[10];							//Lookup table to convert between numbers and UTF-16 characters

	NumberCache();
	virtual ~NumberCache();

	virtual u32 getCacheSize() override;				//returns 22
	virtual u16* getCachePtr() override;				//returns a pointer to numberCache

	void stringifyNumber(u32 number);					//Converts number to a string and stores it into the numberCache

};
NTR_SIZE_GUARD(NumberCache, 0x3C);





/*
	Cache holding generic strings
*/
class GenericCache : public FontCache 
{
public:

	alignas(4)
	u16 genericCache[32];			//String cache for generic strings

	GenericCache();
	virtual ~GenericCache();

	virtual u32 getCacheSize() override;				//returns 64
	virtual u16* getCachePtr() override;				//returns a pointer to genericCache

};
NTR_SIZE_GUARD(GenericCache, 0x64);





class FontRenderer;
/*
	Object used to calculate the font's bounds
	There are 4 operation modes:
		CountMode::NextLineWidth: The current line's width is accumulated until a newline or null character is encountered
		CountMode::IndexedLineWidth: Same as NextLineWidth, but calculates the width of the line at a given index where the current line is denoted with index 0
		CountMode::LineCount: Counts the number of lines
		CountMode::Done: Finished calculation
*/
class FontBounds : public FontBase 
{
public:

	typedef void(*EscapeSequenceCallback)(FontBounds*, EscapeSequence*);

	enum CountMode : u32 {
		NextLineWidth = 0,
		IndexedLineWidth,
		LineCount,
		Done
	};

	FontRenderer* renderer;			//Pointer to the FontRenderer
	u32 count;						//Current element count, depending on mode
	NNSG2dFont* font;				//Pointer to the used font
	u8 xMargin;						//x char margin between characters
	u32 lineIndex;					//Line index, used in IndexedLineWidth mode only
	u32 newlineCount;				//Number of newline characters, used in IndexedLineWidth mode only
	CountMode mode;					//Determines the count mode of the current operation

	static u32 sequenceTableInitialized;									//1 if the escape sequence table has been initialized, 0 otherwise
	/*
		The escape sequence table consists of the following entries:
			0: PSID=1, SSID=0, linkNicknameCache()
			1: PSID=1, SSID=1, linkNumberCache()
			2: PSID=1, SSID=2, linkGenericCache0()
			3: PSID=1, SSID=3, linkGenericCache1()
			4: PSID=1, SSID=4, linkGenericCache2()
			5: PSID=1, SSID=5, linkGenericCache3()
	*/
	static EscapeSequenceEntry escapeSequenceTable[6];						//Table containing escape sequence entries

	/*
		Callback read addresses (when table is not initialized yet, this is where the function pointers reside)
	*/
	static EscapeSequenceCallback linkNicknameCB;
	static EscapeSequenceCallback linkNumberCB;
	static EscapeSequenceCallback linkGeneric0CB;
	static EscapeSequenceCallback linkGeneric1CB;
	static EscapeSequenceCallback linkGeneric2CB;
	static EscapeSequenceCallback linkGeneric3CB;


	FontBounds(FontRenderer* renderer);										//Initializes the object with renderer
	virtual ~FontBounds();

	virtual void processChar(UTF16Character* c) override;												//Main mode execution, increments count accordingly
	virtual void parseEscapeSequence(EscapeSequence* sequence) override;								//Parses the given escape sequence to also account for dynamic characters

	u32 getNextLineWidth(FontBase* src, NNSG2dFont* font, u8 margin);									//returns the width in px from src's string pointer to the next newline / null character (including linked string caches) with the given font and margin
	s32 getIndexedLineWidth(u16* charPtr, NNSG2dFont* font, u8 margin, u32 line);						//returns the width in px from charPtr of the line indexed by line (including linked string caches) with the given font and margin. In case lineIndex is out of bounds, -1 is returned.
	u32 getLineCount(u16* charPtr);																		//returns the number of lines from charPtr to the next null character
	s32 getCharacterWidth(u16 character);																//returns the char width of character including x advancement

	void linkNicknameCache(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the nickname cache's cache ptr
	void linkNumberCache(EscapeSequence* sequence);							//Links to the next character in the string and sets charPtr to the number cache's cache ptr
	void linkGenericCache0(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the first generic cache's cache ptr
	void linkGenericCache1(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the second generic cache's cache ptr
	void linkGenericCache2(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the third generic cache's cache ptr
	void linkGenericCache3(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the fourth generic cache's cache ptr

};
NTR_SIZE_GUARD(FontBounds, 0x34);



/*
	Stores a 2D tile's parameters
*/
struct FontTile {

	u16 xPosition;			//X position in 8x8 tile units
	u16 yPosition;			//Y position in 8x8 tile units
	u16 tileOffset;			//Offset from starting font tile in 8x8 tile units
	u32 tileShape;			//Encoded tile shape

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

	static void decode(u32* x, u32* y, u32 shape);			//Converts from shape to separate x and y 8x8 tile counts

};
NTR_SIZE_GUARD(FontTile, 0xC);



/*
	Object storing a renderable string including its parameters
	It contains two buffers:
		1) Bitmap buffer: Font rendered as bitmap
		2) Tile buffer: Font rendered in tiled order
	Before the font is displayed on screen, the (filled) bitmap buffer is converted and copied to the tile buffer.
*/
class FontString 
{
public:

	enum Alignment : u32 {
		Left = 0,
		Centered,
		Right
	};

	FontBounds* bounds;			//Pointer to font bounds
	u8* bmpBufferPtr;			//Bitmap buffer ptr
	u8* tileBufferPtr;			//Tile buffer ptr
	u32 bufferSize;				//Buffer size
	u8* vramTarget;				//Destination VRAM address
	u32 xTiles;					//Tiles in x direction (in 8x8 tile units)
	u32 yTiles;					//Tiles in y direction (in 8x8 tile units)
	StringCache stringCache;	//String cache
	NNSG2dFont* font;			//Pointer to the font
	Alignment align;			//Alignment (left=0, centered=1, right=2)
	u8 paletteIndex0;			//Font base palette index 0 (glyph pixel with value one takes this index, value two index + 1 and so on; if shadow is enabled, the default palette offset is added -1)
	u8 paletteIndex1;			//Font base palette index 1
	u8 paletteIndex2;			//Font base palette index 2
	u8 bufferFill;				//Buffer fill value (only lower half-byte)
	u8 xMargin;					//x char margin in px
	u8 yMargin;					//y char margin in px
	u8 yOffset;					//y offset from top in px
	bool shadow;				//Shadow enable
	FontTile* tileList;			//Pointer to the font tiles
	u32 tileCount;				//Number of font tiles

	FontString();				//Enables shadows by default
	virtual ~FontString();

	void setup(u8* vramTarget, u32 xTiles, u32 yTiles, NNSG2dFont* fontPtr);				//Sets up the object to defaults with the given parameters
	void setFontTileList(FontTile* tiles, u32 count);										//Sets font tile list pointer and font tile count
	u32 getLineCount();																		//returns the line count of the stringCache's string
	s32 getIndexedLineWidth(u32 index);														//returns the width of the index'th line of stringCache's string or -1 upon failure
	bool allocateBuffers();																	//Allocates both buffers, sets buffer properties accordingly and returns true if successful
	void freeBuffers();																		//Deletes both buffers from heap and sets size to 0
	void clearBuffers();																	//Clears both buffers with bufferFill's lower half-byte every half-byte ((bufferFill & 0xF) << 4 | bufferFill)
	void deleteTarget();																	//Deletes buffers and sets the VRAM target address to null

};
NTR_SIZE_GUARD(FontString, 0x15C);




/*
	Main font class
	Renders fonts into a FontString object and contains all other special font caches. Also holds global font parameters.
	Fonts are rendered differently depending on currentString's shadow:
		Shadow enabled: All greyscale anti-aliasing information is ignored and every non-zero glyph pixel obtains the palette index value n = currentString->paletteIndex<colorSelector> + shadowIndexOffset - 1
		Shadow disabled: Greyscale values are added to the palette index, so every non-zero glyph pixel obtains the palette index value n = currentString->paletteIndex<colorSelector> + greyscaleValue - 1
	This font engine only supports 2bpp fonts. This is a hardcoded limitation in several functions.
	Shadowed strings are rendered three times: Twice at startY = 1 (startX 0 and 1), once with a different color selector at startX and startY = 0.
*/
class FontRenderer : public FontBase 
{
public:

	typedef void(*EscapeSequenceCallback)(FontBounds*, EscapeSequence*);

	FontString fontStrings[16];		//Font string objects containing the renderable text
	FontString* currentString;		//Current font string
	u32 currentX;					//Current font x offset in px
	u32 currentY;					//Current font y offset in px
	u8 startX;						//x start offset from left
	u8 startY;						//y start offset from top
	u8 shadowIndexOffset;			//Shadowed font palette offset
	u32 colorSelector;				//Font color selector
	NicknameCache nicknameCache;	//Nickname cache
	NumberCache numberCache;		//Number cache
	GenericCache genericCache[4];	//4 generic caches
	FontBounds bounds;				//Font bounds

	static u32 sequenceTableInitialized;									//1 if the escape sequence table has been initialized, 0 otherwise
	/*
		The escape sequence table consists of the following entries:
			0: PSID=1, SSID=0, linkNicknameCache()
			1: PSID=1, SSID=1, linkNumberCache()
			2: PSID=1, SSID=2, linkGenericCache0()
			3: PSID=1, SSID=3, linkGenericCache1()
			4: PSID=1, SSID=4, linkGenericCache2()
			5: PSID=1, SSID=5, linkGenericCache3()
			6: PSID=255, SSID=0, setColorSelector()
	*/
	static EscapeSequenceEntry escapeSequenceTable[7];						//Table containing escape sequence entries

	/*
		Callback read addresses (when table is not initialized yet, this is where the function pointers reside)
	*/
	static EscapeSequenceCallback linkNicknameCB;
	static EscapeSequenceCallback linkNumberCB;
	static EscapeSequenceCallback linkGeneric0CB;
	static EscapeSequenceCallback linkGeneric1CB;
	static EscapeSequenceCallback linkGeneric2CB;
	static EscapeSequenceCallback linkGeneric3CB;
	static EscapeSequenceCallback colorSelectCB;


	FontRenderer();
	virtual ~FontRenderer();

	virtual void prepare() override;										//Calculates alignment and sets start offsets appropriately
	virtual void onStringDispatched() override;								//Checks the font tile table and converts the bitmap buffer to the tile buffer
	virtual void processChar(UTF16Character* c) override;					//Immediately calls renderChar()
	virtual void parseEscapeSequence(EscapeSequence* sequence) override;	//Parses the given escape sequence and invokes the respective function

	FontString* setupAndRender(u8* vramTarget, u32 xTiles, u32 yTiles, void* bmg, u32* index);							//Renders string with the main font to vramTarget with xTiles tiles in x direction and yTiles tiles in y direction (and allocates buffers accordingly). The string is fetched from file and a pointer to it is returned if successful. Buffers are deallocated upon failure and false is returned in this case.
	FontString* setupAndRender(u8* vramTarget, u32 xTiles, u32 yTiles, FontCache* stringCache, NNSG2dFont* fontPtr);	//Renders the string into the next free FontString (and allocates buffers accordingly). The string is fetched from stringCache's cache, copied into FontString's cache and a pointer to it is returned if successful. Buffers are deallocated upon failure and false is returned in this case.
	
	void loadAndRenderGenericCache(u32 index, void* bmg, u32* stringIndex);	//Loads the string from file and renders it into genericCache[index]
	void renderGenericCache(u32 index, FontCache* cache);					//Renders cache's string and copies it into genericCache[index]'s cache
	void clearGenericCache(u32 index);										//If index is smaller than 4, genericCache[index] is cleared; if index >= 4, all generic caches are cleared
	
	void resetSpecialCaches();												//Loads the owner's nickname into its respective cache and clears all other special font caches
	void uploadBuffer();													//Copies for each GarbageFrame (if a VRAM target address is set) the tile buffer to the destination and deletes both bitmap and tile buffers	
	FontString* getNextFreeFontString();									//returns a pointer to the next FontString without other linked caches or null if none could be found
	void convertBuffer(FontTile* tile);										//Copies the bitmap buffer's contents containing tile into the tile buffer
	void calculateAlignment();												//Calculates alignment on the x axis and adds startX to the left alignment border. 
	
	void renderChar(UTF16Character* c);										//Renders the character's glyph and increments currentX accordingly. In case c is a newline character, currentY is incremented by yMargin + 16 and alignment is recalculated.
	void renderGlyph(NNSG2dGlyph* glyph);									//Renders glyph into the bitmap buffer
	void renderFontString(FontString* string);								//Renders string's contents. If shadows are enabled, it's rendered two additional times offset.
	void renderFontStrings();												//Calls renderString() on every FontString having a non-null VRAM target pointer
	
	void linkNicknameCache(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the nickname cache's cache ptr
	void linkNumberCache(EscapeSequence* sequence);							//Links to the next character in the string and sets charPtr to the number cache's cache ptr
	void linkGenericCache0(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the first generic cache's cache ptr
	void linkGenericCache1(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the second generic cache's cache ptr
	void linkGenericCache2(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the third generic cache's cache ptr
	void linkGenericCache3(EscapeSequence* sequence);						//Links to the next character in the string and sets charPtr to the fourth generic cache's cache ptr
	void setColorSelector(EscapeSequence* sequence);						//Sets the font color selector to the escape sequence parameter

};
NTR_SIZE_GUARD(FontRenderer, 0x1828);



/*
	Reads BMG files and renders strings into caches
	BMG file reference:
		Header:
			0x00: "MESGbmg1"			//BMG magic
			0x08: u32 bmgSize;			//Total file size
			0x0c: u32 chunks;			//Number of chunks
			0x10: u8 encoding;			//Encoding (2=UTF-16) [1=CP1252, 2=UTF-16, 3=Shift-JIS, 4=UTF-8]

		align(16)
		Info chunk:
			0x00: "INF1"				//Info chunk magic
			0x04: u32 infSize;			//Size of INF chunk
			0x08: u16 numSections;		//Number of strings/sections in file
			0x0A: u16 sectionSize;		//Section size
			0x0C: u16 bmgFileID;		//BMG file ID (not NitroFS file ID), unused
			0x0E: u8 unk;
			0x10+: u32 stringOffset[];	//Info entry numStrings times

		align(16)
		Data chunk [0x20 + infSize]:
			0x00: "DAT1"				//Data chunk magic
			0x04: u32 datSize;			//Size of DAT chunk
			0x08+: u8 stringData[];		//String pool [at offset]
	renderParsed() and renderCleared() are functions that can be used to render strings easily.
*/
class BMGReader
{
public:

	u32 infIndex;			//BMG string info section index (INF chunk offset / 4)
	u32 currentDatOffset;	//Always in sync with datOffset
	u32 datOffset;			//BMG string data offset (u32 read from INF chunk)
	u32 stringLength;		//BMG string length in bytes
	u8 bmgHeader[32];		//Copy of the parsed BMG header
	u8 infHeader[20];		//Copy of the parsed INF header
	u8 datHeader[12];		//Copy of the parsed DAT header
	void* bmgFile;			//BMG file pointer

	BMGReader();
	virtual ~BMGReader();

	bool parseBMGHeader();								//Copy and check BMG header, returns true if successful
	bool parseBMGInfo();								//Copy and check BMG INF chunk header (info), returns true if successful
	bool parseBMGData();								//Copy and check BMG DAT chunk header (data), returns true if successful
	void reset(void* bmg, u32* stringIndex);			//Resets all fields to 0 and assigns file and *stringIndex to their respective fields.
	bool parseBMGString();								//Parses the string from the BMG file with the index given by infIndex and sets the pointer to datOffset. Does not check if index is out of bounds. Always returns true (successful).
	u8 processBMGString(FontCache* cache);				//Calls cache->processString() with copy = 1 and a pointer to the string in the BMG file. returns cache->succesful.

	bool render(FontCache* cache, void* bmg, u32* index);			//Parses bmg and renders the string indexed by index into cache's buffer. returns true if successful, false otherwise.
	bool renderCleared(FontCache* cache, void* bmg, u32* index);	//Clears cache's string buffer and renders a new string into it by calling renderParsed. returns true if successful, false otherwise.

};
NTR_SIZE_GUARD(BMGReader, 0x58);


class TextBox
{
public:

	enum class TextVisibility : u8{
		Visible = 0,
		Created,
		Hidden
	};

	enum class Type : u8 {
		Standard = 0,
		Dialog
	};

	GXOamAttr tileOAMAttributes[0xC];
	u32 optionCount;
	u8 leftSelectArrow[6];  //Left select arrow
	u8 rightSelectArrow[6]; //Right select arrow
	u8 leftDialogArrow[2];  //Left dialog arrow
	u8 rightDialogArrow[2]; //Right dialog arrow
	u8 yOffset;
	Type type;
	TextVisibility visibility;

	//020148b4
	static void loadOAMAttributes(FontTile* tiles, u32 count, GXOamAttr* tileAttributes, u16 tileBase, u8 palette, u8 priority);

	//0201486c
	static void renderOpaqueBox(s32 x, s32 y, const Vec2& scale);

	//02014824
	static void renderAButton(s32 x, s32 y);

	//02014820
	TextBox();

	//0201481c
	~TextBox();

	//020146e4
	FontString* loadText(void* bmg, u32* stringIndex, u32 vramOffset);

	//020146d0
	FontString* loadText(void* bmg, u32* stringIndex);

	//020145f8
	void renderText(s32 x, s32 y);

	//020144bc
	void renderArrows(u8 option, s32 x, s32 y);

	//02014220
	u32 getArrowSelectY(u8 option);

	//02014214
	u32 getArrowSelectLeft(u8 option);

	//02014208
	u32 getArrowSelectRight(u8 option);

	//0201424c
	static u32 getArrowDialogY();

	//02014240
	u32 getArrowDialogLeft(u8 option);

	//02014234
	u32 getArrowDialogRight(u8 option);

	//020141b8
	u32 getOptionCount();

	//02014368
	void loadLeftDialogOption(void* bmg, u32* stringIndex, u32 vramOffset);

	//02014300
	void loadRightDialogOption(void* bmg, u32* stringIndex, u32 vramOffset);

	//0201427c
	FontString* loadDialogOption(void* bmg, u32* stringIndex, u32 vramOffset, GXOamAttr* tileAttributes);

	//020143d0
	void loadMultiplayerDialogOptions();

	//0201443c
	void loadSingleplayerDialogOptions();

	//02014268
	void setStandardBox();

	//02014254
	void setDialogBox();

	//020144a8
	void setDefaultBox();

	//020141c0
	void calculateYOffset(u32 lines);

};
NTR_SIZE_GUARD(TextBox, 0x78);



/*
	Font namespace
*/
namespace Font {

	/*
		Global font related objects
	*/
	extern NNSG2dFont mainFont;			//Main font for everything
	extern NNSG2dFont loadingFont;		//Loading 'fireball' font
	extern BMGReader bmgReader;			//Used to read BMG files
	extern FontRenderer fontRenderer;	//Renders font strings
	extern u32 scriptFileIDList[5];		//Script file IDs [0=course.bmg, 1=data.bmg, 2=error.bmg, 3=game.bmg, 4=vs.bmg]

	/*
		Font tile tables
	*/
	extern FontTile selectFileTiles[4];       //4 tiles
	extern FontTile gameTextboxTiles[8];      //8 tiles
	extern FontTile yesNoOptionTiles[2];      //2 tiles
	extern FontTile mvslModeMenuTiles[4];     //4 tiles
	extern FontTile mvslSelectMenuTiles[12];  //12 tiles
	extern FontTile mvslLoadingTiles[1];      //1 tile
	extern FontTile mvslResultScreenTiles[5]; //5 tiles

	/*
		Getters for font related objects
	*/
	NNSG2dFont* getMainFont();			//returns a pointer to the main font
	NNSG2dFont* getLoadingFont();		//returns a pointer to the loading font
	BMGReader* getBMGReader();			//returns a pointer to the BMG reader
	FontRenderer* getFontRenderer();	//returns a pointer to the font renderer
	u16 getScriptFileID(u32 index);		//returns scriptFileIDList[index]

	/*
		Font loading functions
	*/
	void initMainFonts();									//Loads the main and loading icon font and resets special font caches
	void loadFont(NNSG2dFont* font, u32 fileID);			//Calls loadFontInternal()
	void loadFontInternal(NNSG2dFont* font, u32 fileID);	//Loads the font in memory and creates the corresponding NNSG2dFont object

	/*
		Game loop functions
	*/
	void renderBuffer();				//Uploads the font buffer to VRAM and deallocates it from heap
	void updateFont();					//Updates the font buffer by rendering the font into it

};



/*
	Namespace for generic functions
*/
namespace Util {

	u32 reverse(u32* value);					//Reverses the u32 pointed to by value and returns it
	
	u32 dereference(u32* ptr);					//returns *ptr as u32
	u16 dereference(u16* ptr);					//returns *ptr as u16
	u8 dereference(u8* ptr);					//returns *ptr as u8
	u8 dereference(u8* ptr, u32 offset);		//returns *(ptr + offset) as u8

}
