#ifndef NSMB_FILE_H_
#define NSMB_FILE_H_

#include "nitro_if.h"
#include "nsmb/memory.h"

/**
 * \brief The <b>F</b>ile<b>S</b>ystem namespace.
 * 
 * This namespace allows you to load files, archives and overlays.
 * 
 * \section fileIDs File IDs
 * `fileID = fileIDInROM - FS::fileIDOffset`
 * 
 * \section extFileIDs Extended File IDs
 * In this example assume that:
 *  - You want the 3rd file from the 2nd archive entry.
 *  - The ID of non archived file is 736.
 *  - FS::fileIDOffset is 131.
 * 
 * Check the list at FS::Archive::archives's address and note the startFileID of the archive you want to use.
 * \n The 2nd archive entry has a startFileID of 0xC100.
 * \n Add the file ID of the file inside the archive startFileID, getting 0xC102.
 * \n Shift the value 16 bits to the left to obtain 0xC1020000.
 * \n Add the ID of the file outside the archive minus the FS::fileIDOffset, getting 0xC102025D.
 * 
 * ```cpp
 * s32 extFileID;
 * extFileID = FS::Archive::archives[1].startFileID; // Get the first file ID of archive 2
 * extFileID += 2;                                   // Add 2 to go from file 1 to 3
 * extFileID <<= 16;                                 // Shift 16 bits to the left
 * extFileID += 736 - FS::fileIDOffset;              // Add the ID of the non archived file minus the offset
 * // extFileID = 0xC102025D;
 * ```
 * \section filePath File Paths
 * `"/"` is the ROM root.
 * \n
 * \n So the paths would look something like this:
 * \n `"/BUILDTIME"`
 * \n `"/sound_data.sdat"`
 * \n `"/demo/staffroll0000.enpg"`
 * */
namespace FS {

	/// \brief The filesystem functions that directly call %Nitro filesystem functions.
	namespace Nitro {

		// 0x02085CF8
		/// \brief The pointer to the crash reason message.
		extern const char* crashReason;

		// 0x0203A280
		/// \brief The open file crash reason message.
		extern const char openFileCrash[0xD];

		// 0x0203A290
		/// \brief The read file crash reason message.
		extern const char readFileCrash[0xD];

		// 0x0203A2A0
		/// \brief The open file fast crash reason message.
		extern const char readFileFastCrash[0x11];

		// 0x0203A2B4
		/// \brief The convert path to file ID crash reason message.
		extern const char convertPathToFileIDCrash[0x18];

		// 0x02008588
		/**
		 * \brief Unloads an overlay.
		 * 
		 * \param target The target processor to unload the overlay for.
		 * \param overlayID The overlay ID to unload.
		 * 
		 * \return True if the overlay was unloaded successfully, false otherwise.
		 * */
		bool unloadOverlay(MIProcessor target, u32 overlayID);

		// 0x02008594
		/**
		 * \brief Loads an overlay.
		 * 
		 * \param target The target processor to load the overlay for.
		 * \param overlayID The overlay ID to load.
		 * 
		 * \return True if the overlay was loaded successfully, false otherwise.
		 * */
		bool loadOverlay(MIProcessor target, u32 overlayID);

		// 0x020085A0
		/**
		 * \brief Loads information about an overlay.
		 * 
		 * \param info The pointer to the FSOverlayInfo structure that will receive the overlay information.
		 * \param target The target processor to load the overlay for.
		 * \param overlayID The overlay ID to load.
		 * 
		 * \return True if the overlay information was loaded successfully, false otherwise.
		 * */
		bool loadOverlayInfo(FSOverlayInfo* info, MIProcessor target, u32 overlayID);

		// 0x020085AC
		/**
		 * \brief Reads a file into the destination address until it reaches the specified byte length.
		 * 
		 * If the file data is not fully read internally as expected,
		 * the crash message will be set and the operating system will terminate.
		 * 
		 * \param file The pointer to the open filesystem file.
		 * \param dest The pointer to where the bytes of the file will be written to.
		 * \param length The amount of bytes to be written into the destination.
		 * 
		 * \return The amount of bytes written.
		 * */
		s32 readFile(FSFile* file, void* dest, s32 length);

		// 0x020085E4
		/**
		 * \brief Opens a file by path.
		 * 
		 * If the file fails to open, the crash message will be set and the operating system will terminate.
		 * 
		 * \param file The pointer to the filesystem file to open.
		 * \param path The path of the file to open.
		 * 
		 * \return True if the file opens properly, false otherwise.
		 * */
		bool openFile(FSFile* file, const char* path);

		// 0x0200860C
		/**
		 * \brief Opens a file by ID.
		 * 
		 * If the file fails to open, the crash message will be set and the operating system will terminate.
		 * 
		 * \param file The pointer to the filesystem file to open.
		 * \param fileID The the filesystem file ID structure.
		 * 
		 * \return True if the file opens properly, false otherwise.
		 * */
		bool openFile(FSFile* file, FSFileID fileID);

		// 0x02008648
		/**
		 * \brief Converts a path to a file ID.
		 * 
		 * If the path fails to be converted, the crash message will be set and the operating system will terminate.
		 * 
		 * \param fileID The pointer to the filesystem file ID structure.
		 * \param path The path of the file to be converted into an ID.
		 * 
		 * \return True if the path was successfully converted, false otherwise.
		 * */
		bool pathToFileID(FSFileID* fileID, const char* path);

		// 0x02008670
		/**
		 * \brief Sets the crash reason message for filesystem crashes.
		 * 
		 * \param reason The pointer to the crash reason message.
		 * */
		void setCrashReason(const char* reason);

		// 0x02008E2C
		/**
		 * \brief Converts a file ID to a %Nitro file ID.
		 * 
		 * \param fsFileID The pointer to filesystem file ID structure.
		 * \param fileID The file identifier of a file in the rom archive.
		 * */
		void getFileID(FSFileID* fsFileID, u32 fileID);

	}

	// 0x02085D04
	/// \brief The file ID offset. (131 by default, mustn't be changed)
	extern u16 fileIDOffset;

	// 0x02085D00
	/// \brief The file count minus the offset. (1957 by default, mustn't be changed)
	extern u16 fileCount;

	/// \brief The file read mode options.
	enum class ReadMode : u8 {
		Safe = 0,	/**< \brief Reads the file with more caution. */
		Fast = 1	/**< \brief Reads the file with less error checking. */
	};

	/// \brief The read file function type.
	typedef void*(*ReadFileFunction)(FSFile*, bool);

	// 0x0203A390
	/// \brief The read file function table for the file read mode.
	extern ReadFileFunction readFunctionTable[2];

	// 0x02085CFC
	/// \brief The mode to use when reading files.
	extern ReadMode readMode;

	// 0x02008E54
	/**
	 * \brief Opens a file by ID.
	 * 
	 * \param fsFileID The pointer to filesystem file ID structure.
	 * \param fileID The file ID to open.
	 * 
	 * \return True if the file is opened successfully. Never false because it crashes before returning it.
	 * */
	bool openFile(FSFile* file, u16 fileID);

	// 0x0200869C
	/**
	 * \brief Loads an LZ77 compressed file by extended ID.
	 * 
	 * \param extFileID The extended file identifier.
	 * 
	 * \return The pointer to the decompressed file data.
	 * */
	void* loadFileLZ77(u32 extFileID);

	// 0x02008784
	/**
	 * \brief Loads an LZ77 compressed file by extended ID to a destination.
	 * 
	 * \param extFileID The extended file identifier.
	 * \param dest The pointer to where the decompressed file data will be written to.
	 * 
	 * \return The decompressed file size.
	 * */
	u32 loadFileLZ77(u32 extFileID, void* dest);

	// 0x020087C0
	/**
	 * \brief Frees the loaded file from memory.
	 * 
	 * \param file The pointer to the file data.
	 * */
	void unloadFile(void* file);

	// 0x020087E0
	/**
	 * \brief Loads a file by ID. (flushed)
	 * 
	 * \param fileID The file identifier.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* loadFile(u16 fileID);

	// 0x020087F0
	/**
	 * \brief Loads a file by extended ID. (flushed)
	 * 
	 * \param extFileID The extended file identifier.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* loadExtFile(u32 extFileID);

	// 0x02008800
	/**
	 * \brief Loads a file by extended ID. (unflushed)
	 * 
	 * \param extFileID The extended file identifier.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* loadExtFileUnflushed(u32 extFileID);

	// 0x02008810
	/**
	 * \brief Loads a file by extended ID.
	 * 
	 * \param extFileID The extended file identifier.
	 * \param flush If the file should be flushed or not.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* loadExtFile(u32 extFileID, bool flush);

	// 0x02008828
	/**
	 * \brief Loads a file by ID.
	 * 
	 * \param fileID The file identifier.
	 * \param flush If the file should be flushed or not.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* loadFile(u16 fileID, bool flush);

	// 0x020088FC
	/**
	 * \brief Loads a file by extended ID to a destination with a read size cap.
	 * 
	 * \param extFileID The extended file identifier.
	 * \param dest The pointer to where the file data will be written to.
	 * \param size The amount of bytes to read.
	 * 
	 * \return The amount of bytes that were read.
	 * */
	s32 loadExtFile(u32 extFileID, void* dest, s32 size);

	// 0x02008934
	/**
	 * \brief Loads a file by extended ID to a destination.
	 * 
	 * \param extFileID The extended file identifier.
	 * \param dest The pointer to where the file data will be written to.
	 * 
	 * \return The amount of bytes that were read.
	 * */
	s32 loadExtFile(u32 extFileID, void* dest);

	// 0x02008944
	/**
	 * \brief Reads an open file.
	 * 
	 * \param file The pointer to the filesystem file structure.
	 * \param flush If the file should be flushed or not.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* readFile(FSFile* file, bool flush);

	// 0x02008970
	/**
	 * \brief Sets the file read mode as fast.
	 * */
	void setReadModeFast();

	// 0x02008980
	/**
	 * \brief Sets the file read mode as slow.
	 * */
	void setReadModeSafe();

	// 0x02008990
	/**
	 * \brief Sets the file read mode.
	 * 
	 * This function should not directly be used.
	 * \n Use either FS::setReadModeFast or FS::setReadModeSafe.
	 * 
	 * \param mode The file read mode.
	 * */
	void setReadMode(ReadMode mode);

	// 0x020089A0
	/**
	 * \brief Reads an open file fast.
	 * 
	 * This function should not directly be used.
	 * \n Use FS::setReadModeFast then FS::readFile instead.
	 * 
	 * \param file The pointer to the filesystem file structure.
	 * \param flush If the file should be flushed or not.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* readFileFast(FSFile* file, bool flush);

	// 0x02008A6C
	/**
	 * \brief Reads an open file safe.
	 * 
	 * This function should not directly be used.
	 * \n Use FS::setReadModeSafe then FS::readFile instead.
	 * 
	 * \param file The pointer to the filesystem file structure.
	 * \param flush If the file should be flushed or not.
	 * 
	 * \return The pointer to the file data.
	 * */
	void* readFileSafe(FSFile* file, bool flush);

	// 0x02008CD8
	/**
	 * \brief Loads a file by path to a destination with a read size cap.
	 * 
	 * \param path The path to the file.
	 * \param dest The pointer to where the file data will be written to.
	 * \param size The amount of bytes to read.
	 * 
	 * \return The amount of bytes that were read.
	 * */
	s32 loadFile(const char* path, void* dest, s32 size);

	// 0x02008D14
	/**
	 * \brief Loads a file by FSFileID to a destination with a read size cap.
	 * 
	 * \param fileID The filesystem file ID.
	 * \param dest The pointer to where the file data will be written to.
	 * \param size The amount of bytes to read.
	 * 
	 * \return The amount of bytes that were read.
	 * */
	s32 loadFile(FSFileID fileID, void* dest, s32 size);

	// 0x02008D80
	/**
	 * \brief Reads an open file to a destination with a read size cap.
	 * 
	 * \param file The pointer to the filesystem file structure.
	 * \param dest The pointer to where the file data will be written to.
	 * \param size The amount of bytes to read.
	 * 
	 * \return The amount of bytes that were read.
	 * */
	s32 readFile(FSFile* file, void* dest, s32 size);

	// 0x02008E00
	/**
	 * \brief Checks if a file has an LZ77 header identifier.
	 * 
	 * \param data The pointer to the file data.
	 * 
	 * \return True if the file has an LZ77 identifier. False otherwise.
	 * */
	bool hasLZ77Header(void* data);

	// 0x02009424
	/**
	 * \brief Initializes the ROM filesystem.
	 * */
	void init();

	// 0x02009478
	/**
	 * \brief Gets the size of an LZ77 compressed file.
	 * 
	 * \param data The pointer to the LZ77 header without the identifier.
	 * 
	 * \return The size of the LZ77 file decompressed.
	 * */
	u32 getLZ77DecompressedSize(u32* header);


	constexpr inline u32 makeExtFileID(u16 fileID, u16 vsFileID) {
		return fileID | (vsFileID) << 16;
	}

	constexpr inline u32 makeFileID(u16 fileID) {
		return fileID;
	}

	constexpr inline u32 makeFileID(u8 fileID, u8 arcID) {
		return fileID | arcID << 8;
	}


	/**
	 * \brief The %Overlay namespace.
	 * 
	 * This namespace contains the functions that allow
	 * code to overlap in certain regions of memory.
	 * */
	namespace Overlay {

		/// \brief The structure that contains the information of an overlay.
		struct Entry {

			u32 id;
			u32 start;
			u32 size;
			u32 refCount;

		};

		// 0x02085D0C
		/// \brief The table that contains the information about the loaded overlays.
		extern Entry loadedOverlays[16];

		// 0x02009484
		/**
		 * \brief Prepares the loaded overlay table.
		 * */
		void initLoadedOverlayTable();

		// 0x020094B8
		/**
		 * \brief Removes an overlay from the loaded overlay table.
		 * 
		 * \param overlayID The identifier of the overlay to remove.
		 * */
		void untrack(u32 overlayID);

		// 0x02009510
		/**
		 * \brief Loads an overlay.
		 * 
		 * \param overlayID The identifier of the overlay to load.
		 * */
		void load(u32 overlayID);

		// 0x02009560
		/**
		 * \brief Loads and adds an overlay to the loaded overlay table.
		 * 
		 * \param overlayID The identifier of the overlay to load and track.
		 * */
		bool trackAndLoad(u32 overlayID);

		// 0x02009798
		/**
		 * \brief Invalidates the memory region of an overlay.
		 * 
		 * \param info The pointer to the overlay info structure.
		 * */
		void flush(FSOverlayInfo* info);

	}


	/// \brief The archive namespace.
	namespace Archive {

		/// \brief The archive entry structure.
		struct Entry {

			NNSFndArchive* archive;
			Heap* heap;
			u16 startFileID;
			u16 endFileID;
			const char* arcName;
			const char* fileName;
			void* binary;

		};

		/// \brief The archive ID type.
		typedef u32 ArchiveID;

		// 0x0203A6C0
		/// \brief The archive table.
		extern Entry archives[48];

		// 0x02085D08
		/// \brief The pointer to the ROM archive.
		extern FSArchive* romArchivePtr;

		// 0x0203A2CC
		/// \brief The ID of the current archive.
		extern s8 currentArchiveID;

		// 0x020262D0
		/// \brief The ID table of the main game archives.
		extern ArchiveID mainGameArchives[3];

		// 0x020262DC
		/// \brief The ID table of the minigame archives.
		extern ArchiveID minigameArchives[4];

		// 0x02008F50
		/**
		 * \brief Gets a file inside an archive by ID.
		 * 
		 * This function automatically mounts the corresponding archive.
		 * 
		 * \param fileID The file identifier.
		 * 
		 * \return The pointer to the file data.
		 * */
		void* getFile(u16 fileID);

		// 0x02008FF4
		/**
		 * Unmounts the archive mounted by FS::openFile or FS::Archive::getFile.
		 * */
		void unmountCurrent();

		// 0x020090F8
		/**
		 * \brief Unmounts an archive by ID.
		 * 
		 * \param id The archive identifier.
		 * */
		void unmount(ArchiveID id);

		// 0x02009288
		/**
		 * \brief Unmounts an NNS archive.
		 * 
		 * \param archive The pointer to the archive.
		 * \param heap The heap used to allocate the archive.
		 * */
		void unmount(NNSFndArchive* archive, Heap* heap);

		// 0x02009084
		/**
		 * Unmounts all archives.
		 * */
		void unmountAll();

		// 0x020090D0
		/**
		 * \brief Unmounts a list of archives.
		 * 
		 * \param list The pointer to the archive list. (Last index ID must be 47)
		 * */
		void unmountList(ArchiveID* list);

		// 0x02009134
		/**
		 * \brief Mounts a list of archives.
		 * 
		 * \param list The pointer to the archive list. (Last index ID must be 47)
		 * \param allocFront If the memory to allocate should be allocated from the heap top.
		 * \param heap The pointer to the heap to use when allocating.
		 * 
		 * \return True if all archives were mounted. False otherwise.
		 * */
		bool mountList(ArchiveID* list, bool allocFront, Heap* heap);

		// 0x0200917C
		/**
		 * \brief Mounts an archive by ID, allocated from the heap top.
		 * 
		 * \param id The archive identifier.
		 * \param heap The pointer to the heap to use when allocating.
		 * 
		 * \return True if the archive was properly mounted.
		 * */
		bool mountFront(ArchiveID id, Heap* heap);

		// 0x02009190
		/**
		 * \brief Mounts an archive by ID, allocated from the heap bottom.
		 * 
		 * \param id The archive identifier.
		 * \param heap The pointer to the heap to use when allocating.
		 * 
		 * \return True if the archive was properly mounted.
		 * */
		bool mountBack(ArchiveID id, Heap* heap);

		// 0x020091A4
		/**
		 * \brief Mounts an archive by ID.
		 * 
		 * Avoid using this function directly, use either FS::Archive::mountFront or FS::Archive::mountBack.
		 * 
		 * \param id The archive identifier.
		 * \param allocFront If the memory to allocate should be allocated from the heap top.
		 * \param heap The pointer to the heap to use when allocating.
		 * 
		 * \return True if the archive was properly mounted.
		 * */
		bool mount(ArchiveID id, bool allocFront, Heap* heap);

		// 0x020092B0
		/**
		 * \brief Mounts the NNS archive.
		 * 
		 * \param arcName The name used to identify the archive on the file system.
		 * \param fileName The path to the archive file name.
		 * \param heap The pointer to the heap to use when allocating.
		 * \param alignment The heap alignment to use. (Either -16 or 16)
		 * 
		 * \return The pointer to the NNS archive structure.
		 * */
		NNSFndArchive* mount(const char* arcName, const char* fileName, Heap* heap, s32 alignment);

		// 0x0200902C
		/**
		 * \brief Unmounts a list of archives then mounts a list of archives.
		 * 
		 * The last index ID of the lists must be 47.
		 * 
		 * \param mountList The pointer to the archive list to mount.
		 * \param unmountList The pointer to the archive list to unmount.
		 * \param allocFront If the memory to allocate should be allocated from the heap top.
		 * \param heap The pointer to the heap to use when allocating.
		 * 
		 * \return True if all archives were mounted. False otherwise.
		 * */
		bool unmountAndMountLists(ArchiveID* mountList, ArchiveID* unmountList, bool allocFront, Heap* heap);

		// 0x020097D0
		/**
		 * \brief Loads all archives related to the main game.
		 * */
		bool loadMainGameArchives();

		// 0x020097EC
		/**
		 * \brief Unloads all archives related to minigames.
		 * */
		void unloadMinigameArchives();

		// 0x02009800
		/**
		 * \brief Loads all archives related to minigames.
		 * */
		bool loadMinigameArchives();


	}

	// 0x0200936C
	/**
	 * \brief Converts a path to a file ID.
	 * 
	 * If the path is invalid, the crash reason is set and the operative system is terminated.
	 * 
	 * \param path The path to the file.
	 * 
	 * \return The file ID that the path corresponds to.
	 * */
	u16 getFileID(const char* path);

	// 0x02009394
	/**
	 * \brief Converts an extended file ID to a simple file ID.
	 * 
	 * \param extFileID The extended file identifier.
	 * 
	 * \return The simplified file identifier.
	 * */
	u16 toFileID(u32 extFileID);

	// 0x020093F8
	/**
	 * \brief Sets the file ID offset.
	 * 
	 * Do not use this function, it will break all file ID tables in the ROM.
	 * 
	 * \param set If it should set it. (stupid as fuck and makes no sense)
	 * \param firstFileID The file ID offset.
	 * */
	void setFileIDOffset(bool set, u16 firstFileID);

	// 0x02009410
	/**
	 * \brief Sets how many files the ROM has.
	 * 
	 * \param fileCount The amount of files minus the file ID offset.
	 * 
	 * \return True if the file count was set successfully. Never false because it is always set successfully.
	 * */
	bool setFileCount(u16 fileCount);

	// 0x02009AF0
	/**
	 * \brief Gets the size of a file.
	 * 
	 * \param extFileID The extended file ID of the file.
	 * 
	 * \return The size of the file.
	 * */
	u32 getFileSize(u32 extFileID);

	// 0x02009ACC

	// 0x02009A98
	/**
	 * \brief Loads a cached file to the object bank A video memory.
	 * 
	 * \param extFileID The extended file ID of the file.
	 * \param offset The offset in bytes relative to the object bank A video memory.
	 * */
	void loadFileToOBJVramA(u32 extFileID, u32 offset);

	// 0x02009A30
	/**
	 * \brief Loads a file to the object palette video memory.
	 * 
	 * \param extFileID The extended file ID of the file.
	 * \param offset The offset in bytes relative to the object palette video memory.
	 * \param compressed If the file is an LZ77 file without identifier.
	 * */
	void loadOBJPalette(u32 extFileID, u32 offset, bool compressed);

	// 0x020099C8
	/**
	 * \brief Loads a file to the object extended palette video memory.
	 * 
	 * \param extFileID The extended file ID of the file.
	 * \param offset The offset in bytes relative to the object extended palette video memory.
	 * \param compressed If the file is an LZ77 file without identifier.
	 * */
	void loadOBJExtPalette(u32 extFileID, u32 offset, bool compressed);

	// 0x02009980
	/**
	 * \brief Loads a cached file to the object extended palette video memory.
	 * 
	 * \param extFileID The extended file ID of the file.
	 * \param offset The offset in bytes relative to the object extended palette video memory.
	 * */
	void loadOBJExtPaletteCached(u32 extFileID, u32 offset);

	// 0x02009918
	/**
	 * \brief Loads a file to the background palette video memory.
	 * 
	 * \param extFileID The extended file ID of the file.
	 * \param offset The offset in bytes relative to the background palette video memory.
	 * \param compressed If the file is an LZ77 file without identifier.
	 * */
	void loadBGPalette(u32 extFileID, u32 offset, bool compressed);

	// 0x020098CC
	/**
	 * \brief Loads a cached file to the background extended palette video memory.
	 * 
	 * \param extFileID The extended file ID of the file.
	 * \param offset The offset in bytes relative to the background extended palette video memory.
	 * */
	void loadBGExtPaletteCached(u32 extFileID, u32 offset);

	// 0x02009878
	/**
	 * \brief Loads a file to the background palette video memory. (bottom screen)
	 * 
	 * \param extFileID The extended file ID of the file.
	 * \param offset The offset in bytes relative to the background palette video memory.
	 * */
	void loadBGSubPalette(u32 extFileID, u32 offset);


	// 0x02009864
	// 0x0200984C
	// 0x02009828
	// 0x0200981C




	/**
	 * \brief The filesystem cache namespace.
	 * 
	 * This namespace is used to prevent lag spikes in game when loading files.
	 * \n It's mostly used to cache the files of stage actors for faster use when they spawn.
	 * */
	namespace Cache {
		
		/// \brief The cache entry class.
		class CacheEntry {
		
		private:

			s16 entryID;
			u16 refCount;
			u16 fileID;
			bool compressed;
			u32 size;
			Heap* heap;
			void* data;

		public:

			// 0x0200A10C
			/**
			 * \brief Unloads a file from the cache entry.
			 * */
			void unload();

			// 0x0200A138
			/**
			 * \brief Allocates a cache heap block.
			 * 
			 * \param size The size of the data block.
			 * 
			 * \return The heap block where the cache data can be written to
			 * */
			void* loadData(u32 size);

			// 0x0200A194
			/**
			 * \brief Loads a file into an overlay.
			 * 
			 * The destination address of the data is in FS::Cache::overlayFileDest
			 * and the remaining size in FS::Cache::overlayFileSize.
			 * 
			 * \param extFileID The extended file identifier.
			 * \param compressed If the file is LZ77 without identifier.
			 * 
			 * \return The pointer to the file data.
			 * */
			void* loadFileToOverlay(u32 extFileID, bool compressed);

			// 0x0200A234
			/**
			 * \brief Loads a file.
			 * 
			 * \param extFileID The extended file identifier.
			 * \param compressed If the file is LZ77 without identifier.
			 * 
			 * \return The pointer to the file data.
			 * */
			void* loadFile(u32 extFileID, bool compressed);

			// 0x0200A358
			/**
			 * \brief The cache entry constructor.
			 * */
			CacheEntry();

			//D0:0200A2B0
			//D1:0200A308
			/**
			 * \brief The cache entry destructor.
			 * */
			virtual ~CacheEntry();

		};

		// 0x02086A30
		/// \brief %Cache entry table 0.
		extern CacheEntry fileCache0[0x80];

		// 0x02085E30
		/// \brief %Cache entry table 1.
		extern CacheEntry fileCache1[0x80];

		// 0x02085E0C
		/// \brief The cache entry table in use.
		extern u32 activeFileCache;

		// 0x02085E10
		/// \brief The address of the overlay block reserved for cached file storage.
		extern void* overlayFileDest;

		// 0x02085E14
		/// \brief The remaining space of the overlay block reserved for cached file storage.
		extern u32 overlayFileSize;

		/// \brief The internal functions of the cache system.
		namespace Internal {

			// 0x02009D30
			/**
			 * \brief Clears the specified amount of entries from a cache table.
			 * 
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * */
			void clear(CacheEntry* cache, u32 entries);

			// 0x02009CD4
			/**
			 * \brief Clears the specified amount of entries from a cache table.
			 * 
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * */
			CacheEntry* findFile(u32 extFileID);

			// 0x02009D6C
			/**
			 * \brief Unloads a file by ID from a cache table.
			 * 
			 * \param extFileID The extended file identifier.
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * 
			 * \return Always true.
			 * */
			bool unloadFile(u32 extFileID, CacheEntry* cache, u32 entries);

			// 0x02009DC0
			/**
			 * \brief Allocates a cache heap block and adds it to a cache table.
			 * 
			 * \param size The size of the data block.
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * 
			 * \return The heap block where the cache data can be written to.
			 * */
			void* loadData(u32 size, CacheEntry* cache, u32 entries);

			// 0x02009DEC
			/**
			 * \brief Initializes a 3D file for usage.
			 * 
			 * This function should not be used directly.
			 * 
			 * \param file The pointer to the cached file data.
			 * \param unloadTextures If the textures don't need to be loaded.
			 * 
			 * \return True if everything was successfuly setup. False otherwise.
			 * */
			bool setup3DFile(void* file, bool unloadTextures);

			// 0x02009E7C
			/**
			 * \brief Loads a file to an overlay and adds it to a cache table.
			 * 
			 * The destination address of the data is in FS::Cache::overlayFileDest
			 * and the remaining size in FS::Cache::overlayFileSize.
			 * 
			 * When loading, if the file is 3D it gets automatically setup.
			 * 
			 * \param extFileID The extended file identifier.
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * \param compressed If the file is LZ77 without identifier.
			 * 
			 * \return The pointer to the file data.
			 * */
			void* loadFileToOverlay(u32 extFileID, CacheEntry* cache, u32 entries, bool compressed);

			// 0x02009ED4
			/**
			 * \brief Loads a file and adds it to a cache table.
			 * 
			 * When loading, if the file is 3D it gets automatically setup.
			 * 
			 * \param extFileID The extended file identifier.
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * \param compressed If the file is LZ77 without identifier.
			 * 
			 * \return The pointer to the file data.
			 * */
			void* loadFile(u32 extFileID, CacheEntry* cache, u32 entries, bool compressed);

			// 0x02009F2C
			/**
			 * \brief Allocates a cache entry from a cache table.
			 * 
			 * \param size The size to allocate.
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * 
			 * \return The pointer to the cache entry.
			 * */
			CacheEntry* getData(u32 size, CacheEntry* cache, u32 entries);

			// 0x02009F8C
			/**
			 * \brief Allocates a cache entry that uses overlay memory from a cache table.
			 * 
			 * \param extFileID The extended identifier of the file.
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * \param allowUnused If allowed to use unused cache entries.
			 * \param compressed If the file is LZ77 without identifier.
			 * 
			 * \return The pointer to the cache entry.
			 * */
			CacheEntry* getFileInOverlay(u32 extFileID, CacheEntry* cache, u32 entries, bool allowUnused, bool compressed);

			// 0x0200A020
			/**
			 * \brief Gets a cache entry corresponding to a file ID in the cache table.
			 * 
			 * \param extFileID The extended identifier of the file.
			 * \param cache The cache table to clear.
			 * \param entries The cache table size.
			 * \param allowUnused If allowed to use unused cache entries.
			 * \param compressed If the file is LZ77 without identifier.
			 * 
			 * \return The pointer to the cache entry.
			 * */
			CacheEntry* getFile(u32 extFileID, CacheEntry* cache, u32 entries, bool allowUnused, bool compressed);


		}

		// 0x02009C64
		/**
		 * \brief Loads a file and adds it to active table cache.
		 * 
		 * When loading, if the file is 3D it gets automatically setup.
		 * 
		 * \param extFileID The extended file identifier.
		 * \param compressed If the file is LZ77 without identifier.
		 * 
		 * \return The pointer to the file data.
		 * */
		void* loadFile(u32 extFileID, bool compressed);

		// 0x02009C14
		/**
		 * \brief Loads a file to an overlay and adds it to the active cache table.
		 * 
		 * The destination address of the data is in FS::Cache::overlayFileDest
		 * and the remaining size in FS::Cache::overlayFileSize.
		 * 
		 * When loading, if the file is 3D it gets automatically setup.
		 * 
		 * \param extFileID The extended file identifier.
		 * \param compressed If the file is LZ77 without identifier.
		 * 
		 * \return The pointer to the file data.
		 * */
		void* loadFileToOverlay(u32 extFileID, bool compressed);

		// 0x02009BC8
		/**
		 * \brief Allocates a cache heap block and adds it to the active cache table.
		 * 
		 * \param size The size of the data block.
		 * 
		 * \return The heap block where the cache data can be written to.
		 * */
		void* loadData(u32 size);

		// 0x02009B94
		/**
		 * \brief Frees a file from both cache tables.
		 * 
		 * \param extFileID The extended identifier of the file.
		 * 
		 * \return Always true.
		 * */
		bool unloadFile(u32 extFileID);

		// 0x02009B64
		/**
		 * \brief Clears all loaded cache files.
		 * */
		void clear();

		// 0x0200A0B4
		/**
		 * \brief Setups the cache entries for the first use.
		 * */
		void setupCacheEntries();

		// 0x02009CB4
		/**
		 * \brief Gets the pointer to a cached file data.
		 * 
		 * \param extFileID The extended identifier of the file.
		 * 
		 * \return The pointer to the file data.
		 * */
		void* getFile(u32 extFileID);

	}

}

#endif // !NSMB_FILE_H_
