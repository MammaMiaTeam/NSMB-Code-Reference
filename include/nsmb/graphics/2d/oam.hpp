#pragma once
#include "nsmb_nitro.hpp"
#include "nsmb/extra/bitmaskenum.hpp"
#include "nsmb/math/vector.hpp"


/**
 * \brief The <b>O</b>bject <b>A</b>ttribute <b>M</b>emory namespace.
 *
 * This namespace is used to draw the 2-dimensional sprites you see in the game.
 * \n Examples of things that use %OAM: HUD, Goombas, Koopas, and so on...
 * */
namespace OAM
{

	/* ======== TYPES ======== */

	/// \brief The %OAM drawing flags.
	enum class Flags : u32
	{
		None = 0,				/**< \brief No flags. */
		FlipX = 1, 				/**< \brief Flips the object horizontally. */
		FlipY = 2, 				/**< \brief Flips the object vertically. */
		Unk4h = 4, 				/**< \brief Unknown 0x4. */
		FromLast = 8, 			/**< \brief Starts rendering the objects from the last entry to the first. */
		Prio1 = 0x10, 			/**< \brief Draws with layer priority 1. */
		Prio2 = 0x20, 			/**< \brief Draws with layer priority 2. */
		Prio3 = 0x30, 			/**< \brief Draws with layer priority 3. */
		TranslucentMode = 0x40,	/**< \brief Renders the objects in translucent mode. */
		WindowMode = 0x80,		/**< \brief Renders the objects in window mode. */
		BitmapMode = 0xC0		/**< \brief Renders the objects in bitmap mode. */
	};

	/// \brief The %OAM drawing settings.
	enum class Settings : u32
	{
		None = 0,	/**< \brief No settings. */
		Single = 1,	/**< \brief Only draws the first %OAM entry. */
		NoWrap = 2	/**< \brief Does not wrap the objects when wrap around is enabled in the level. */
	};

	/// \brief The %OAM counter updater flags.
	enum class CounterFlags : u32
	{
		None = 0,			/**< \brief No flags. */
		UpdateShadow = 1,	/**< \brief Updates double the digit count in the array to account for the shadow. */
		NoLeadingZeroes = 2	/**< \brief Does not render leading zeroes */
	};

	struct File {
		u32 fileID;
		GXOamAttr** pOamAttrs;
		u32 oamAttrCount;
		u32 ncgOffsetShifted;
	};

	struct FileEntry {
		File* files;
		bool loaded;
	};

	struct Affine { s16 PA, PB, PC, PD; };

	/* ======== HELPERS ======== */

	/**
	 * \brief A function that allows to setup %OAM directly in an array.
	 * 
	 * \param x The X coordinate of the object.
	 * \param y The Y coordinate of the object.
	 * \param priority The priority of the object.
	 * \param mode The object mode.
	 * \param mosaic If true the object has mosaic effect.
	 * \param effect The effect of the object.
	 * \param shape The size of the object.
	 * \param color The color mode of the object (16 or 256 colors).
	 * \param charName The tile number.
	 * \param cParam The color parameter.
	 * \param rsParam The affine transformation if an affine effect is specified.
	 * \param attr3 The 3rd attribute (0x8000 = last sprite entry).
	 * 
	 * \return The %OAM object.
	 * */
	constexpr GXOamAttr getOBJAttr
	(
		s32 x, s32 y, s32 priority,
		GXOamMode mode, bool mosaic, GXOamEffect effect, GXOamShape shape,
		GXOamColorMode color, s32 charName, s32 cParam, s32 rsParam, u16 attr3
	)
	{
		GXOamAttr oam = { 0 };

		u32 sParams = 0;
		if (effect == GX_OAM_EFFECT_AFFINE || effect == GX_OAM_EFFECT_AFFINE_DOUBLE)
			sParams |= (rsParam << GX_OAM_ATTR01_RS_SHIFT);

		if (mode != GX_OAM_MODE_BITMAPOBJ)
			sParams |= (color << GX_OAM_ATTR01_CM_SHIFT);

		oam.attr01 = static_cast<u32>(
			sParams |
			((x & (GX_OAM_ATTR01_X_MASK >> GX_OAM_ATTR01_X_SHIFT)) << GX_OAM_ATTR01_X_SHIFT) |
			((y & (GX_OAM_ATTR01_Y_MASK >> GX_OAM_ATTR01_Y_SHIFT)) << GX_OAM_ATTR01_Y_SHIFT) |
			(mode << GX_OAM_ATTR01_MODE_SHIFT) |
			(mosaic << GX_OAM_ATTR01_MOSAIC_SHIFT) |
			effect |
			shape
		);

		oam.attr2 = static_cast<u16>(charName | (cParam << GX_OAM_ATTR2_CPARAM_SHIFT) | (priority << GX_OAM_ATTR2_PRIORITY_SHIFT));
		oam._3 = attr3;

		return oam;
	}

	/* ======== VARIABLES ======== */

	extern u32 unused_2087708;				/**< \brief Gets set at 0x0200DE4C and never used. */

	extern u32 _2087710;					/**< \brief Unknown 0x02087710. */
	extern u32 _208770C;					/**< \brief Unknown 0x02087710. */
	extern u32 _20876FC;					/**< \brief Unknown 0x02087710. */

	extern u32 curTileOffset;				/**< \brief The current tile offset being used for %OAM file loading. */

	extern GXOamAttr objBuffer1[128];		/**< \brief The first object buffer. (Top screen) */
	extern GXOamAttr objBuffer2[128];		/**< \brief The second object buffer. (Top screen) */
	extern Affine affineBuffer[8];			/**< \brief The affine parameter buffer. (Top screen) */
	extern u16 objsFromHead;				/**< \brief The amount of objects to render normally. (Top screen) */
	extern u16 objsFromTail;				/**< \brief The amount of objects to render in reverse. (Top screen) */
	extern u16 objSlotsLeft;				/**< \brief The amount of objects slots left. (Top screen) */
	extern u32 affineSetSlot;				/**< \brief The affine set slot to use in multiples of 4. (Top screen) */

	extern GXOamAttr objBuffer1Sub[128];	/**< \brief The first object buffer. (Bottom screen) */
	extern GXOamAttr objBuffer2Sub[128];	/**< \brief The second object buffer. (Bottom screen) */
	extern Affine affineBufferSub[8];		/**< \brief The affine parameter buffer. (Bottom screen) */
	extern u16 objsFromHeadSub;				/**< \brief The amount of objects to render normally. (Bottom screen) */
	extern u16 objsFromTailSub;				/**< \brief The amount of objects to render in reverse. (Bottom screen) */
	extern u16 objSlotsLeftSub;				/**< \brief The amount of objects slots left. (Bottom screen) */
	extern u32 affineSetSlotSub;			/**< \brief The affine set slot to use in multiples of 4. (Bottom screen) */

	/* ======== COMMON ======== */

	// OAM::reset | 0x0200DD94
	/**
	 * \brief Clears the %OAM render list to prepare the next frame.
	 * */
	void reset();

	// OAM::loadAffineSets | 0x0200DC48
	/**
	 * \brief Sets up the %OAM affine sets.
	 * */
	void loadAffineSets();

	// OAM::load | 0x0200DA60
	/**
	 * \brief Pushes the render list %OAM objects into the screen.
	 * */
	void load();

	// OAM::updateCounter | 0x0200B580
	/**
	 * \brief Updates the digit values of an %OAM counter.
	 * 
	 * \param oamAttrs The oam objects.
	 * \param oamCounterAttrTable The oam object list.
	 * \param value The value to set in the counter.
	 * \param digitCount The number of digits the counter has.
	 * \param flags The flags for updating the counter.
	 * */
	void updateCounter(const GXOamAttr* oamAttrs, GXOamAttr** oamCounterAttrTable, s32 value, s32 digitCount, CounterFlags flags);

	// OAM::loadFiles | 0x0200B708
	/**
	 * \brief Loads the files to memory.
	 * 
	 * \param files The file array.
	 * */
	void loadFiles(File* files);

	// OAM::loadFilesByEntryID | 0x0200B740
	/**
	 * \brief Loads the files of an entry by ID to memory.
	 * 
	 * \param entryID The file array entry ID.
	 * */
	void loadFiles(u32 entryID);

	// OAM::setupFile | 0x0200B758
	/**
	 * \brief Calculates the tile addresses (attr2) to prevent conflicts with other sprites. (This function is used internally)
	 * 
	 * \param file The file.
	 * \param lastAttrOffset The last offset.
	 * */
	void setupFile(File* file, u32 lastAttrOffset);

	// OAM::loadFilesToVRAM | 0x0200B7D0
	/**
	 * \brief Loads the files to the VRAM.
	 * 
	 * \param files The file array.
	 * */
	void loadFilesToVRAM(File *files);

	// OAM::loadFilesByEntryIDToVRAM | 0x0200B83C
	/**
	 * \brief Loads the files of an entry by ID to the VRAM.
	 * 
	 * \param entryID The file array entry ID.
	 * */
	void loadFilesToVRAM(u32 entryID);

	// OAM::setFilesUnloaded | 0x0200B87C
	/**
	 * \brief Sets all file array entries as unloaded.
	 * */
	void setFilesUnloaded();

	// OAM::copyMtx | 0x0200B8A4
	/**
	 * \brief Copies an affine matrix to another affine matrix.
	 * 
	 * \param pSrc The pointer to the source matrix.
	 * \param pDst The pointer to the destination matrix.
	 * */
	void copyMtx(const MtxFx22* pSrc, MtxFx22* pDst);

	// OAM::fillData | 0x0200B358
	/**
	 * \brief Fills %OAM attributes of an array.
	 * 
	 * \param attr01 The attributes 0 and 1.
	 * \param attr23 The attributes 2 and 3.
	 * \param oamAttrs The %OAM objects to be filled.
	 * \param size The size in bytes of the object array.
	 * */
	void fillData(u16 attr01, u16 attr23, GXOamAttr *oamAttrs, u32 size);

	/* ======== TOP SCREEN ======== */

	// OAM::draw | 0x0200D2A4
	/**
	 * \brief Pushes an object to the top screen render list to be drawn.
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool draw(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, Settings settings);

	// OAM::drawExt | 0x0200D87C
	/**
	 * \brief Pushes an object to the top screen render list to be drawn. (Extended version)
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param scale The scale that the objects will be drawn.
	 * \param rot The rotation that the object will be drawn.
	 * \param rotCenter The rotation center.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool draw(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const Vec2* scale, s16 rot, const s16 rotCenter[2], Settings settings);

	// OAM::drawMtx | 0x0200CE10
	/**
	 * \brief Pushes an object to the top screen render list to be drawn. (Matrix version)
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param mtx The affine transformation matrix to use when drawing the object.
	 * \param unk8 
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool drawMtx(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const MtxFx22* mtx, s32 unk8, Settings settings);

	// OAM::drawMtxRot | 0x0200C7D4
	/**
	 * \brief Pushes an object to the top screen render list to be drawn. (Matrix w/rotation version)
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param mtx The affine transformation matrix to use when drawing the object.
	 * \param unk8 
	 * \param rot The rotation that the object will be drawn.
	 * \param rotCenter The rotation center.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool drawMtx(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const MtxFx22* mtx, s32 unk8, s16 rot, const s16 rotCenter[2], Settings settings);
	
	// OAM::drawSprite | 0x0200D578
	/**
	 * \brief Pushes an object to the top screen render list to be drawn.
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the level of where to draw the objects.
	 * \param y The Y coordinate relative to the level of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param scale The scale that the objects will be drawn.
	 * \param rot The rotation that the object will be drawn.
	 * \param rotCenter The rotation center.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool drawSprite(const GXOamAttr* oamAttrs, fx32 x, fx32 y, Flags flags, u8 palette, u8 affineSet, const Vec2* scale, s16 rot, const s16 rotCenter[2], Settings settings);

	/* ======== BOTTOM SCREEN ======== */

	// OAM::drawSub | 0x0200C32C
	/**
	 * \brief Pushes an object to the bottom screen render list to be drawn.
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool drawSub(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, Settings settings);

	// OAM::drawExtSub | 0x0200C600
	/**
	 * \brief Pushes an object to the bottom screen render list to be drawn. (Extended version)
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param scale The scale that the objects will be drawn.
	 * \param rot The rotation that the object will be drawn.
	 * \param rotCenter The rotation center.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool drawSub(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const Vec2* scale, s16 rot, const s16 rotCenter[2], Settings settings);

	// OAM::drawMtxSub | 0x0200BED4
	/**
	 * \brief Pushes an object to the bottom screen render list to be drawn. (Matrix version)
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param mtx The affine transformation matrix to use when drawing the object.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool drawMtxSub(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const MtxFx22* mtx, Settings settings);

	// OAM::drawMtxRotSub | 0x0200B8C8
	/**
	 * \brief Pushes an object to the bottom screen render list to be drawn. (Matrix w/rotation version)
	 * 
	 * \param oamAttrs The %OAM object attribute array.
	 * \param x The X coordinate relative to the screen of where to draw the objects.
	 * \param y The Y coordinate relative to the screen of where to draw the objects.
	 * \param flags The flags of how to draw the objects.
	 * \param palette The palette shift of which to draw the objects.
	 * \param affineSet The affine set to be used when drawing the objects.
	 * \param mtx The affine transformation matrix to use when drawing the object.
	 * \param rot The rotation that the object will be drawn.
	 * \param rotCenter The rotation center.
	 * \param settings The object processing settings.
	 * 
	 * \return True if the objects were pushed to the render list successfully, false otherwise.
	 * */
	bool drawMtxSub(const GXOamAttr* oamAttrs, s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const MtxFx22* mtx, fx16 rot, const s16 rotCenter[2], Settings settings);

	/* ======== ANIMATION CLASS ======== */

	/// \brief The animated %OAM class.
	class Anim
	{
	public:

		struct Frame
		{
			GXOamAttr *oamAttrs;
			fx32 duration;
			u32 reserved;
		};

		struct FrameEntry
		{
			Frame* frames;
			u32 frameCount;
		};

		// OAM::Anim::init | 0x0200B510
		/**
		 * \brief Initializes the animation class. (Can be called multiple times)
		 * 
		 * \param frameTable The table containing the information about the frames.
		 * \param frameTableID The table ID to use from the frame table.
		 * \param flags The updater flags.
		 * \param updateSpeed The frame update speed.
		 * \param curFrameID The current frame.
		 * */
		void init(const FrameEntry* frameTable, u32 frameTableID, u8 flags, fx32 updateSpeed, u16 curFrameID);

		// OAM::Anim::update | 0x0200B44C
		/**
		 * \brief Updates the animation.
		 * 
		 * \return True if updated properly, false otherwise.
		 * */
		bool update();

		/**
		 * \brief Sets the update speed.
		 * 
		 * \param updateSpeed The frame update speed.
		 * */
		NTR_INLINE void setUpdateSpeed(fx32 updateSpeed)
		{
			if ( updateSpeed < 0 )
			{
				this->flags |= 4;
				this->updateSpeed = -updateSpeed;
			}
			else
			{
				this->flags &= ~4;
				this->updateSpeed = updateSpeed;
			}
		}

		/**
		 * \brief Pushes the current animated object to the top screen render list to be drawn. (Extended version)
		 * 
		 * \param x The X coordinate relative to the screen of where to draw the objects.
		 * \param y The Y coordinate relative to the screen of where to draw the objects.
		 * \param flags The flags of how to draw the objects.
		 * \param palette The palette shift of which to draw the objects.
		 * \param affineSet The affine set to be used when drawing the objects.
		 * \param scale The scale that the objects will be drawn.
		 * \param rot The rotation that the object will be drawn.
		 * \param rotCenter The rotation center.
		 * \param settings The object processing settings.
		 * 
		 * \return True if the objects were pushed to the render list successfully, false otherwise.
		 * */
		NTR_INLINE bool draw(s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const Vec2* scale, fx16 rot, const s16 rotCenter[2], Settings settings) {
			return OAM::draw(this->frames[this->curFrameID].oamAttrs, x, y, flags, palette, affineSet, scale, rot, rotCenter, settings);
		}

		// OAM::Anim::drawSprite | 0x0200B3F4
		/**
		 * \brief Pushes the current animated object to the top screen render list to be drawn.
		 * 
		 * \param x The X coordinate relative to the level of where to draw the objects.
		 * \param y The Y coordinate relative to the level of where to draw the objects.
		 * \param flags The flags of how to draw the objects.
		 * \param palette The palette shift of which to draw the objects.
		 * \param affineSet The affine set to be used when drawing the objects.
		 * \param scale The scale that the objects will be drawn.
		 * \param rot The rotation that the object will be drawn.
		 * \param rotCenter The rotation center.
		 * \param settings The object processing settings.
		 * 
		 * \return True if the objects were pushed to the render list successfully, false otherwise.
		 * */
		bool drawSprite(fx32 x, fx32 y, Flags flags, u8 palette, u8 affineSet, const Vec2* scale, fx16 rot, const s16 rotCenter[2], Settings settings);

		// OAM::Anim::drawSprite | 0x0200B39C
		/**
		 * \brief Pushes the current animated object to the bottom screen render list to be drawn. (Extended version)
		 * 
		 * \param x The X coordinate relative to the screen of where to draw the objects.
		 * \param y The Y coordinate relative to the screen of where to draw the objects.
		 * \param flags The flags of how to draw the objects.
		 * \param palette The palette shift of which to draw the objects.
		 * \param affineSet The affine set to be used when drawing the objects.
		 * \param scale The scale that the objects will be drawn.
		 * \param rot The rotation that the object will be drawn.
		 * \param rotCenter The rotation center.
		 * \param settings The object processing settings.
		 * 
		 * \return True if the objects were pushed to the render list successfully, false otherwise.
		 * */
		bool drawSub(s32 x, s32 y, Flags flags, u8 palette, u8 affineSet, const Vec2* scale, fx16 rot, const s16 rotCenter[2], Settings settings);
		
	private:

		Frame* frames;		/**< \brief The pointer to the frames. */
		u32 frameTableID;	/**< \brief The ID of the current frame table. */
		fx32 curFrameDur;	/**< \brief The duration of the current frame. */
		fx32 updateSpeed;	/**< \brief The frame update speed. */
		u16 curFrameID;		/**< \brief The ID of the current frame. */
		u16 frameCount;		/**< \brief The frame count. */
		u8 flags;			/**< \brief The animation flags. */

	};

}

NTR_CREATE_BITMASK_ENUM(OAM::Flags);
NTR_CREATE_BITMASK_ENUM(OAM::Settings);
NTR_CREATE_BITMASK_ENUM(OAM::CounterFlags);
