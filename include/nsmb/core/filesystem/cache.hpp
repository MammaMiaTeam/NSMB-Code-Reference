#pragma once

#include <nsmb/core/system/memory.hpp>
#include "file.hpp"


namespace FS {

	/**
	 * \brief The filesystem cache namespace.
	 *
	 * This namespace is used to prevent lag spikes in game when loading files.
	 * \n It's mostly used to cache the files of stage actors for faster use when they spawn.
	 * */
	namespace Cache {

		class CacheEntry;

		// 0x02086A30
		/// \brief %Cache entry table 0.
		extern CacheEntry fileCache0[128];

		// 0x02085E30
		/// \brief %Cache entry table 1.
		extern CacheEntry fileCache1[128];

		// 0x02085E0C
		/// \brief The cache entry table in use.
		extern u32 activeFileCache;

		// 0x02085E10
		/// \brief The address of the overlay block reserved for cached file storage.
		extern void* overlayFileDest;

		// 0x02085E14
		/// \brief The remaining space of the overlay block reserved for cached file storage.
		extern u32 overlayFileSize;

		/// \brief The cache entry class.
		class CacheEntry {

		public:

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

			// 0x0200A138
			/**
			 * \brief Allocates a cache heap block.
			 *
			 * \param size The size of the data block.
			 *
			 * \return The heap block where the cache data can be written to
			 * */
			void* loadData(u32 size);

			// 0x0200A10C
			/**
			 * \brief Unloads a file from the cache entry.
			 * */
			void unload();


			s16 entryID;
			u16 refCount;
			u16 fileID;
			bool compressed;
			u32 size;
			Heap* heap;
			void* data;

		};

		/// \brief The internal functions of the cache system.
		namespace Internal {

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

		}

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

	}
}
