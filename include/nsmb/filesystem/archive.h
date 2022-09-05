#pragma once
#include "nitro_if.h"
#include "file.h"


class Heap;


namespace FS {

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
}
