#ifndef NSMB_FILE_INCLUDED
#define NSMB_FILE_INCLUDED



namespace FS {

	namespace Nitro {

		//02085cf8
		const char* crashReason;

		//0203a280
		const char openFileCrash[0xD];

		//0203a290
		const char readFileCrash[0xD];

		//0203a2a0
		const char readFileFastCrash[0x11];

		//0203a2b4
		const char convertPathToFileIDCrash[0x18];

		//02008588
		bool unloadOverlay(MIProcessor target, u32 overlayID);

		//02008594
		bool loadOverlay(MIProcessor target, u32 overlayID);

		//020085a0
		bool loadOverlayInfo(FSOverlayInfo* info, ProcTarget target, u32 overlayID);

		//020085ac
		s32 readFile(FSFile* file, void* dest, s32 length);

		//020085e4
		bool openFile(FSFile* file, const char* path);

		//0200860c
		bool openFile(FSFile* file, FSFileID fileID);

		//02008648
		bool pathToFileID(FSFileID* fileID, const char* path);

		//02008670
		void setCrashReason(const char* reason);

		//02008e2c
		void getFileID(FSFileID* fsFileID, u32 fileID);

	}

	//02085d04
	u16 fileIDOffset;

	//02085d00
	u16 fileCount;

	enum class ReadMode : u8 {
		Safe = 0,
		Fast
	};

	typedef s32(*ReadFileFunction)(FSFile*, bool);

	//0203a390
	ReadFileFunction readFunctionTable[2];

	//02085cfc
	ReadMode readMode;

	//02008e54
	bool openFile(FSFile* file, u16 fileID);

	//0200869c
	void* loadFileLZ77(u32 extFileID);

	//02008784
	u32 loadFileLZ77(u32 extFileID, void* dest);

	//020087c0
	void unloadFile(void* file);

	//020087e0
	void* loadFile(u16 fileID);//Flushed

	//020087f0
	void* loadExtFile(u32 extFileID);//Flushed

	//02008800
	void* loadExtFileUnflushed(u32 extFileID);

	//02008810
	void* loadExtFile(u32 extFileID, bool flush);

	//02008828
	void* loadFile(u16 fileID, bool flush);

	//020088fc
	s32 loadExtFile(u32 extFileID, void* dest, s32 size);

	//02008934
	s32 loadExtFile(u32 extFileID, void* dest);

	//02008944
	void* readFile(FSFile* file, bool flush);

	//02008970
	void setReadModeFast();

	//02008980
	void setReadModeSafe();

	//02008990
	void setReadMode(ReadMode mode);

	//020089a0
	void* readFileFast(FSFile* file, bool flush);

	//02008a6c
	void* readFileSafe(FSFile* file, bool flush);

	//02008cd8
	s32 loadFile(const char* path, void* dest, s32 size);

	//02008d14
	s32 loadFile(FSFileID fileID, void* dest, s32 size);

	//02008d80
	s32 readFile(FSFile* file, void* dest, s32 size);

	//02008e00
	bool hasLZ77Header(void* data);

	//02009424
	void initialize();

	//02009478
	u32 getLZ77DecompressedSize(u32* header);


	namespace Overlay {

		struct Entry {

			u32 id;
			u32 start;
			u32 size;
			u32 refCount;

		};

		//02085d0c
		Entry loadedOverlays[16];


		//02009484
		void initializeLoadedOverlayTable();

		//020094b8
		void untrack(u32 overlayID);

		//02009510
		void load(u32 overlayID);

		//02009560
		bool trackAndLoad(u32 overlayID);

		//02009798
		void flush(FSOverlayInfo* info);

	}



	namespace Archive {

		struct Entry {

			NNSFndArchive* archive;
			Heap* heap;
			u16 startFileID;
			u16 endFileID;
			const char* arcName;
			const char* fileName;
			void* binary;

		};

		typedef u32 ArchiveID;

		//0203a6c0
		Entry archives[48];

		//02085d08
		FSArchive* romArchivePtr;

		//0203a2cc
		s8 currentArchiveID;

		//020262d0
		ArchiveID mainGameArchives[3];

		//020262dc
		ArchiveID minigameArchives[4];

		//02008f50
		void* getFile(u16 fileID);

		//02008ff4
		void unmountCurrent();

		//020090f8
		void unmount(ArchiveID id);

		//02009288
		void unmount(NNSFndArchive* archive, Heap* heap);

		//02009084
		void unmountAll();

		//020090d0
		void unmountList(ArchiveID* list);

		//02009134
		bool mountList(ArchiveID* list, bool allocateFront, Heap* heap);

		//0200917c
		bool mountFront(ArchiveID id, Heap* heap);

		//02009190
		bool mountBack(ArchiveID id, Heap* heap);

		//020091a4
		bool mount(ArchiveID id, bool allocateFront, Heap* heap);

		//020092b0
		NNSFndArchive* mount(const char* arcName, const char* fileName, Heap* heap, s32 alignment);

		//0200902c
		bool unmountAndMountLists(ArchiveID* mountList, ArchiveID* unmountList, bool allocateFront, Heap* heap);

		//020097d0
		bool loadMainGameArchives();

		//020097ec
		void unloadMinigameArchives();

		//02009800
		void loadMinigameArchives();


	}

	//0200936c
	u16 getFileID(const char* path);

	//02009394
	u16 calculateFileID(u32 extFileID);

	//020093f8
	void setFileIDOffset(bool set, u16 firstFileID);

	//02009410
	bool setFileCount(u16 files);

	//02009af0
	u32 getFileSize(u32 extFileID);

	//02009acc

	//02009a98
	void loadFileToOBJVramA(u32 extFileID, u32 offset);

	//02009a30
	void loadOBJPalette(u32 extFileID, u32 offset, bool compressed);

	//020099c8
	void loadOBJExtPalette(u32 extFileID, u32 offset, bool compressed);

	//02009980
	void loadOBJExtPaletteCached(u32 extFileID, u32 offset);

	//02009918
	void loadBGPalette(u32 extFileID, u32 offset, bool compressed);

	//020098cc
	void loadBGExtPaletteCached(u32 extFileID, u32 offset);

	//02009878
	void loadBGSubPalette(u32 extFileID, u32 offset);


	//02009864
	//0200984c
	//02009828
	//0200981c





	namespace Cache {

		//02086a30
		extern Cache::CacheEntry fileCache0[0x80];

		//02085e30
		extern Cache::CacheEntry fileCache1[0x80];

		//02085e0c
		u32 activeFileCache;


		class CacheEntry {

			s16 entryID;
			u16 refCount;
			u16 fileID;
			bool compressed;
			u32 size;
			Heap* heap;
			void* data;

			//0200a10c
			void unload();

			//0200a138
			void* loadData(u32 size);

			//0200a194
			void* loadBossFile(u32 extFileID, bool compressed);

			//0200a234
			void* loadFile(u32 extFileID, bool compressed);

			//0200a358
			CacheEntry();

			//D0:0200a2b0
			//D1:0200a308
			virtual ~CacheEntry();

		};

		namespace Internal {

			//02009d30
			void clear(CacheEntry* cache, u32 entries);

			//02009cd4
			CacheEntry* findFile(u32 extFileID);

			//02009d6c
			bool unloadFile(u32 extFileID, CacheEntry* cache, u32 entries);

			//02009dc0
			void* loadData(u32 size, CacheEntry* cache, u32 entries);

			//02009dec
			bool setup3DFile(void* file, bool unloadTextures);

			//02009e7c
			void* loadBoss3DFile(u32 extFileID, CacheEntry* cache, u32 entries, bool compressed);

			//02009ed4
			void* load3DFile(u32 extFileID, CacheEntry* cache, u32 entries, bool compressed);

			//02009f2c
			CacheEntry* getData(u32 size, CacheEntry* cache, u32 entries);

			//02009f8c
			CacheEntry* getBossFile(u32 extFileID, CacheEntry* cache, u32 entries, bool allowUnused, bool compressed);

			//0200a020
			CacheEntry* getFile(u32 extFileID, CacheEntry* cache, u32 entries, bool allowUnused, bool compressed);


		}

		//02009c64
		void* load3DFile(u32 extFileID, bool compressed);

		//02009c14
		void* loadBoss3DFile(u32 extFileID, bool compressed);

		//02009bc8
		void* loadData(u32 size);

		//02009b94
		bool unloadFile(u32 extFileID);

		//02009b64
		void clear();

		//0200a0b4
		void setupCacheEntries();

		//02009cb4
		void* getFile(u32 extFileID);

	}

}




#endif  // NSMB_FILE_INCLUDED
