#ifndef NSMB_PARTICLE_SYSTEM_INCLUDED
#define NSMB_PARTICLE_SYSTEM_INCLUDED

#include "nitro_if.h"

#include "Vector.h"

// should probably be in another file
struct BossFileInfo {
	u32 file;
	u32 area;
};

class ParticleSystem;
class ParticleHandler;

typedef void* (ParticleAllocator)(u32 size);
typedef void* (ParticleResourceAllocator)(u32 size, BOOL flag);
typedef void (ParticleSystemCallback)(ParticleSystem* system, ...);


class ParticleObjectLink {

	ParticleObjectLink* prev;
	ParticleObjectLink* next;

};

/*
	A generic list for particle objects.
*/
class ParticleObjectList {

	ParticleObjectLink* last;
	u32 count;
	ParticleObjectLink* first;

	// 0x20557dc
	void push(ParticleObjectLink* object);

	// 0x2055790
	ParticleObjectLink* pop();

	// 0x2055710
	ParticleObjectLink* popAt(ParticleObjectLink* where);

};


/*
	Stores the particles' animation behavior resources.
*/
struct ParticleSystemResource {

	void* pSystemData;

	void* pExtraData1;
	void* pExtraData2;
	void* pExtraData3;
	void* pExtraData4;
	void* pExtraData5;

	void* pExtraDataCollection;

	u16 extraDataCollectionCount;

};

/*
	Stores the particles' texture and palette resources.
*/
struct ParticleTextureResource {

	void* pTextureData; // Pointer to the SPT block. (Since the ParticleMgr will resize the file heap after allocating to VRAM, this will point to random garbage after internal usage).

	u32 textureAddress;
	u32 paletteAddress;

	u32 texParam;

	u16 width;
	u16 height;

};


/*
	A particle cluster.
	The individual particle object that gets rendered and affected by physics.
*/
class ParticleCluster : ParticleObjectLink {
public:

};


/*
	A particle system
	The particle object that stores a list of smaller elements (clusters)
	It's responsible for creating, updating and rendering each cluster
*/
class ParticleSystem : ParticleObjectLink {
public:

	ParticleObjectList primaryList;
	ParticleObjectList secondaryList;

	ParticleSystemResource* resource;

	u32 unk24; // some update flag

	VecFx32 position;
	VecFx32 vec1;
	VecFx32 vec2;

	u16 timer;
	u16 unk4E;

	VecFx16 unk50; // callback vector

	u32 unk58;
	u32 unk5C; // callback value 2
	u32 unk60;
	u32 unk64;
	u32 unk68;
	u32 unk6C;
	u32 unk70;

	u16 unk74; // callback value 3
	u16 unk76; // callback value 3

	u32 unk78; // callback value 1

	fx16 unk7C[2]; // scale?
	fx16 unk80[2];

	// seems to be used as some sort of rate?
	union {
		u32 unk84_u32; // initialized in the u32 form
		struct {
			u8 unk84_u8_0; // used as the denominator (timer % value)
			u8 unk84_u8_1; // are these even used?
			u8 unk84_u8_2; // ^
			u8 unk84_u8_3; // ^
		};
	};

	u32 unk88;
	u32 unk8C;
	u32 unk90;

	void* callback; // couldn't find where this is set

	u32 unk98;
	u32 unk9C;

	u16 unkA0;
	u16 unkA2;

	u32 unkA4;
	u32 unkA8[60]; // not an array but I didn't feel like writing 60 unkXX fields


	inline ParticleSystem() {}


	// 0x20507b4
	void init(ParticleSystemResource* resource, const VecFx32* position);

};

/*
	The class reponsible for handling ParticleSystems
	It handles the following processes:
	  - Resources allocation
	  - Resources decoding
	  - ParticleSystem allocation
	  - ParticleSystem creation
	  - ParticleSystem updating
	  - ParticleSystem rendering

*/
class ParticleHandler {
public:

	ParticleAllocator* allocator;

	ParticleObjectList processList;		// ParticleSystems to be processed
	ParticleObjectList freeList;		// ParticleSystems that are free to be used
	ParticleObjectList deadChildList;

	ParticleSystemResource* spaSystemsList;
	ParticleTextureResource* spaTexturesList;

	u16 spaSystemsCount;
	u16 spaTexturesCount;

	u16 maxObjects1;
	u16 maxObjects2;

	union {
		u32 bitfield;
		struct {
			u32 bitfield_0 : 6;
			u32 bitfield_1 : 6;
			u32 bitfield_2 : 6;
			u32 bitfield_3 : 6;
			u32 bitfield_4 : 1;
			u32 bitfield_5 : 7;
		};
	};

	u32 extraPolyAttribute;

	ParticleSystem* curPclSystem;

	MtxFx43* renderMtx;

	u16 timer;
	u16 unk4A; // padding?


	inline ParticleHandler() {}

private:

	// 0x204ff64
	void updateSystem(ParticleSystem* system); // update particle system? (updateOne)

	// 0x204fe80
	void renderPrimaryClusters(); // render particle system?

	// 0x204fda4
	void renderSecondaryClusters(); // render particle system?

	// 0x204fd34
	void renderCurrentSystem(); // render particle system? (renderOne)

	// 0x204fd18
	static void FUN_0204fd18(ParticleHandler* handler, ParticleSystem* system, ParticleObjectList* list);


	// 0x204fce4
	u32 allocateTexture(int szByte, BOOL is4x4comp);

	// 0x204fcb0
	u32 allocatePalette(int szByte, BOOL bPltt4);

public:

	// 0x204fb24
	static ParticleHandler* create(ParticleAllocator* allocator, u16 numObj1, u16 numObj2, u32 unk1, u32 unk2, u32 unk3);

	// 0x204f7b4
	void initFromFile(void* file);

	// 0x204f6ec
	BOOL loadTexturesEx(ParticleResourceAllocator* allocator);

	// 0x204f63c
	BOOL loadPalettesEx(ParticleResourceAllocator* allocator);

	// 0x204f628
	BOOL loadTextures();

	// 0x204f614
	BOOL loadPalettes();

	// 0x204f4e0
	void updateSystems();

	// 0x204f428
	void renderSystems(MtxFx43* mtx);

	// 0x204f3b8
	ParticleSystem* createSystem(u32 id, const VecFx32* position);

	// 0x204f334
	ParticleSystem* createSystemEx(u32 id, const VecFx32* position, void* param, ParticleSystemCallback* func);

	// 0x204f324
	void FUN_0204f324(ParticleSystem* system);

};

/*
	The interface between the game and the particle system.
	Used to load, create, update and render particles
*/
class ParticleMgr {
public:

	enum STDParticleID {
		PCL_COURSE,
		PCL_WORLDMAP,
		PCL_CUTSCENE
	};

	// 0x203cf80
	static bool bParticleMgrEnabled;


	// 0x208b50C
	static void* pParticleHeapBeg;

	// 0x208b510
	static void* pParticleHeapCur;

	// 0x208b514
	static void* pParticleHeapEnd;

	// 0x208b518
	static void* pParticleFileMinigames;

	// 0x208b51c
	static ParticleHandler* pCurParticleHandler;

	// 0x208b520
	static ParticleMgr* pParticleMgr;

	// 0x208b524
	static void* pParticleFile;


	// 0x2023180
	ParticleMgr();

	// 0x2023118
	// 0x20230a8
	virtual ~ParticleMgr();


	// 0x202308c
	static void* allocate(u32 size);

	// 0x2022dd0
	void init(STDParticleID id);

	// 0x2022d98
	static BossFileInfo* getBossParticleInfo(u32 area);

	// 0x2022d68
	static u32 getBossParticleFileID(u32 area);

	// 0x2022cb4
	void initBoss();

	// 0x2022c3c
	void updateParticles();

	// 0x2022be4
	static void renderParticles();

	// 0x2022b64
	static void createParticle(u32 id; const Vec3* position);

	// 0x2022aac
	static void createParticleEx(u32 id, const Vec3* position, void* param, ParticleSystemCallback* func);

	// 0x2022a90
	static void unkCallback1(ParticleSystem* system, const VecFx16* vec);

	// 0x2022a7c
	static void createParticleCallback1(u32 id, const Vec3* position, const VecFx16* vec);

	// 0x2022a70
	static void unkCallback2(ParticleSystem* system, const u32* unk);

	// 0x2022a64
	static void unkCallback3(ParticleSystem* system, const u32* unk);

	// 0x2022a50
	static void createParticleCallback3(u32 id, const Vec3* position, const u32* unk);

	// 0x2022a44
	static void unkCallback4(ParticleSystem* system, const u16* unk);

	// 0x2022a30
	static void createParticleCallback4(u32 id, const Vec3* position, const u16* unk);

};

#endif	// NSMB_PARTICLE_SYSTEM_INCLUDED
