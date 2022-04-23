#pragma once
#include "nitro_if.h"


//Default DMA number
extern "C" u32 fsi_default_dma_no;


/// \brief The filesystem functions that directly call %Nitro filesystem functions.
namespace FS {
	namespace Internal {

		// 0x02085CF8
		/// \brief The pointer to the crash reason message.
		extern const char* crashReason;

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
		void terminate(const char* reason);

	}
}
