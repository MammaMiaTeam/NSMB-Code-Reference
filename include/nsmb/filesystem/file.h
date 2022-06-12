#pragma once
#include "nitro_if.h"
#include "internal.h"


namespace FS {

	// 0x02085D08
	/// \brief A pointer to the ROM archive.
	extern FSArchive* romArchive;

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
	typedef void* (*ReadFileFunction)(FSFile*, bool);

	// 0x0203A390
	/// \brief The read file function table for the file read mode.
	extern ReadFileFunction readFunctionTable[2];

	// 0x02085CFC
	/// \brief The mode to use when reading files.
	extern ReadMode readMode;

	// 0x02008E2C
	/**
	 * \brief Converts a file ID to a %Nitro file ID.
	 *
	 * \param fsFileID The pointer to filesystem file ID structure.
	 * \param fileID The file identifier of a file in the rom archive.
	 * */
	FSFileID getFileID(u32 fileID);

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
	u32 getLZ77DecompressedSize(void* header);


	constexpr u32 makeExtFileID(u16 fileID, u16 vsFileID) {
		return fileID | (vsFileID) << 16;
	}

	constexpr u32 makeFileID(u16 fileID) {
		return fileID;
	}

	constexpr u32 makeFileID(u8 fileID, u8 arcID) {
		return fileID | arcID << 8;
	}

	NTR_INLINE u32 setDefaultDMA(u32 dmaNo) {
		u32 old = fsi_default_dma_no;
		fsi_default_dma_no = dmaNo;
		return old;
	}

	NTR_INLINE u32 getDefaultDMA() {
		return fsi_default_dma_no;
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
	/**
	 * \brief Gets the decompressed size of a compressed file. Only compatible with headerless LZ files.
	 *
	 * \param extFileID The extended file ID of the file.
	 *
	 * \return The decompressed size of the file.
	 * */
	u32 getDecompressedFileSize(u32 extFileID);

	// 0x02009A98
	/**
	 * \brief Loads a cached file to the object video memory.
	 *
	 * \param extFileID The extended file ID of the file.
	 * \param offset The byte offset relative to the object bank A video memory.
	 * */
	void loadFileToOBJVram(u32 extFileID, u32 offset);

	// 0x02009A30
	/**
	 * \brief Loads a file to the object palette video memory.
	 *
	 * \param extFileID The extended file ID of the file.
	 * \param offset The byte offset relative to the object palette video memory.
	 * \param compressed If the file is an LZ77 file without identifier.
	 * */
	void loadOBJPalette(u32 extFileID, u32 offset, bool compressed);

	// 0x020099C8
	/**
	 * \brief Loads a file to the object extended palette video memory.
	 *
	 * \param extFileID The extended file ID of the file.
	 * \param offset The byte offset relative to the object extended palette video memory.
	 * \param compressed If the file is an LZ77 file without identifier.
	 * */
	void loadOBJExtPalette(u32 extFileID, u32 offset, bool compressed);

	// 0x02009980
	/**
	 * \brief Loads a cached file to the object extended palette video memory.
	 *
	 * \param extFileID The extended file ID of the file.
	 * \param offset The byte offset relative to the object extended palette video memory.
	 * */
	void loadOBJExtPaletteCached(u32 extFileID, u32 offset);

	// 0x02009918
	/**
	 * \brief Loads a file to the background palette video memory.
	 *
	 * \param extFileID The extended file ID of the file.
	 * \param offset The byte offset relative to the background palette video memory.
	 * \param compressed If the file is an LZ77 file without identifier.
	 * */
	void loadBGPalette(u32 extFileID, u32 offset, bool compressed);

	// 0x020098CC
	/**
	 * \brief Loads a cached file to the background extended palette video memory.
	 *
	 * \param extFileID The extended file ID of the file.
	 * \param offset The byte offset relative to the background extended palette video memory.
	 * */
	void loadBGExtPaletteCached(u32 extFileID, u32 offset);

	// 0x02009878
	/**
	 * \brief Loads a file to the background palette video memory. (bottom screen)
	 *
	 * \param extFileID The extended file ID of the file.
	 * \param offset The byte offset relative to the background palette video memory.
	 * */
	void loadBGSubPalette(u32 extFileID, u32 offset);


	// 0x02009864
	// 0x0200984C
	// 0x02009828
	// 0x0200981C

}
