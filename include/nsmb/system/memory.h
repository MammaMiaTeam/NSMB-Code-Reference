#pragma once
#include "nitro_if.h"
#include <stdlib.h>


//Block (frontend): 0x02044A50 - 0x020455D4
//Block (backend): 0x02055ADC - 0x02056A58


class ExpandedHeap;

//Abstract heap base class
class Heap								//original name: mHeap::Heap_t
{
public:

	typedef void(*OnAllocate)(Heap*, void*, u32, s32);		//void OnAllocate(Heap* heap, void* allocatedPtr, u32 size, s32 align);
	typedef void(*OnDeallocate)(Heap*, void*);				//void OnDeallocate(Heap* heap, void* ptrToDeallocate);

	void* heapStart;					//Pointer to the heap's start
	u32 heapSize;						//Heap size from heapStart
	Heap* parentHeap;					//Pointer to the heap's parent. May be null if it's the root heap.
	u32 flags;							//Flags:
										//0x0400: If set and Memory::onAllocate is non-null, the function pointed to by it is called.
										//0x0800: If set and Memory::onDeallocate is non-null, the function pointed to by it is called.
										//0x2000: If set, OS_Panic is called if a mutex is locked in non-system modes
										//0x4000: If set, OS_Panic is called on fatal exceptions (ResizeToFit / Allocate)
										//0x8000: Not a real flag. It's never set and only used in Heap::SetFlags to indicate a flags change when 0.

	NTR_INLINE Heap() {}
	Heap(void* start, u32 size, Heap* parent);
	virtual ~Heap();

	virtual void vLockMutex();												//Locks mutex if it exists.
	virtual void vUnlockMutex();											//Unlocks mutex if it exists.
	virtual bool vTryLockMutex();											//Tries to lock mutex. If successful, it returns true, false otherwise. Always returns 1 if heap requires/uses no mutex mechanism.
	virtual void vDestroy() = 0;											//Destroys the heap and removes the allocator
	virtual void* vAllocate(u32 size, s32 align) = 0;						//Allocates size bytes with an alignment/allocation direction of align
	virtual void vDeallocate(void* ptr) = 0;								//Deallocates ptr from the heap.
	virtual void vDeallocateAll() = 0;										//Deallocates everything from the heap.
	virtual bool vIntact() = 0;												//returns 1 if the heap represents a valid object. Not very reliable to check if the heap is broken...
	virtual void vTest() = 0;												//Does nothing.
	virtual u32 vReallocate(void* ptr, u32 newSize) = 0;					//Reallocates the memory given by ptr with the size of newSize. returns 0 in case the reallocation failed.
	virtual u32 vSizeOf(void* ptr) = 0;										//returns the size of an allocated block
	virtual u32 vMaxAllocationUnitSize() = 0;								//returns the maximum size that is allocatable at once
	virtual u32 vMaxAllocatableSize() = 0;									//returns the size of the largest contiguous free memory block, aligned on a 4-byte boundary
	virtual u32 vMaxAllocatableSize(s32 align) = 0;							//returns the size of the largest contiguous free memory block, aligned with align
	virtual u32 vMemoryLeft() = 0;											//returns the number of unallocated bytes
	virtual u16 vSetGroupID(u16 id) = 0;									//Sets the assignable group ID for subsequent nodes. returns the previous group ID.
	virtual u16 vGetGroupID() = 0;											//returns the current group ID.
	virtual u32 vResizeToFit() = 0;											//Resizes the heap to fit (e.g. deallocates all unused memory). returns the new size or 0 if it failed.

	void* allocate(u32 size, s32 align);									//Calls vAllocate. If size == -1, then all available heap space is allocated.
	void deallocate(void* ptr);												//Calls vDeallocate. Skips null pointers.
	void destroy();															//Calls vDestroy
	void dispose();															//Calls Destroy
	static s32 forcePo2Alignment(s32 minAlign, u32 po2Align);				//returns po2Align if it's not smaller than minAlign. If it is, it finds the next greater po2 of minAlign. Sign is __retained.
	void lockMutex();														//Calls vLockMutex. If we're in a non-system mode (e.g. IRQ) and flag 0x2000 is set, OS_Panic is called.
	u32 maxAllocatableSize(s32 align);										//Calls vMaxAllocatableSize
	u32 maxAllocationUnitSize();											//Calls vMaxAllocationUnitSize
	u32 reallocate(void* ptr, u32 newSize);									//Calls vReallocate
	u32 resizeToFit();														//Calls vResizeToFit
	u16 setGroupID(u16 id);													//Calls vSetGroupID
	u32 sizeOf(void* ptr);													//Calls vSizeOf
	void test();															//Calls vTest. Called by the debug screen handler in stage 6, requires special key combinations to trigger on different heaps. Probably to check if heaps are intact, since if the objects are corrupted, the call fails and the game may finally crash.
	u32 setFlags(u32 newFlags);												//returns the current heap flags and sets flags (if newFlags & 0x8000 == 0) to newFlags
	void unlockMutex();														//Calls vUnlockMutex

	static Heap* setCurrent(Heap* currentHeap);								//Sets Memory::currentHeapPtr to currentHeap and returns a pointer to the previous heap

};
NTR_SIZE_GUARD(Heap, 0x14);



//Doubly linked list heap
class ExpandedHeap : public Heap		//original name: mHeap::ExpHeap_t
{
public:

	NNSFndHeapHandle allocator;			//Allocator
	OSMutex mutex;						//Mutex to ensure atomic heap access

	NTR_INLINE ExpandedHeap() {}
	ExpandedHeap(void* start, u32 size, Heap* parent, NNSFndHeapHandle allocator);	//Also inits mutex with OS_InitMutex
	virtual ~ExpandedHeap();

	virtual void vLockMutex() override;
	virtual void vUnlockMutex() override;
	virtual bool vTryLockMutex() override;
	virtual void vDestroy() override;
	virtual void* vAllocate(u32 size, s32 align) override;
	virtual void vDeallocate(void* ptr) override;							//returns immediately if ptr == null
	virtual void vDeallocateAll() override;									//Calls NNS_FndVisitAllocatedForExpHeap with NNSFndHeapVisitor = InvokeDeallocate
	virtual bool vIntact() override;
	virtual void vTest() override;
	virtual u32 vReallocate(void* ptr, u32 newSize) override;
	virtual u32 vSizeOf(void* ptr) override;
	virtual u32 vMaxAllocationUnitSize() override;							//Calls NNS_FndGetAllocatableSizeForExpHeapEx with align = 4
	virtual u32 vMaxAllocatableSize() override;								//Calls NNS_FndGetAllocatableSizeForExpHeapEx with align = 4
	virtual u32 vMaxAllocatableSize(s32 align) override;					//Calls NNS_FndGetAllocatableSizeForExpHeapEx
	virtual u32 vMemoryLeft() override;										//Calls NNS_FndGetTotalFreeSizeForExpHeap
	virtual u16 vSetGroupID(u16 id) override;
	virtual u16 vGetGroupID() override;
	virtual u32 vResizeToFit() override;									//returns 0 (failure) immediately

	static ExpandedHeap* create(u32 size, Heap* parent);					//Creates a heap with size size on parent. If size == -1, the whole memory of parent is allocated for the new heap.

	static void invokeDeallocate(void* memBlock, NNSFndHeapHandle heap, u32 userParam);

};
NTR_SIZE_GUARD(ExpandedHeap, 0x30);



//Linear heap
class FrameHeap : public Heap			//original name: mHeap::SolidHeap_t
{
public:

	NNSFndHeapHandle allocator;			//Allocator
	OSMutex mutex;						//Mutex, never used

	NTR_INLINE FrameHeap() {}
	FrameHeap(void* start, u32 size, Heap* parent, NNSFndHeapHandle allocator);
	virtual ~FrameHeap();

	virtual void vLockMutex();
	virtual void vUnlockMutex();
	virtual bool vTryLockMutex();
	virtual void vDestroy() override;
	virtual void* vAllocate(u32 size, s32 align) override;
	virtual void vDeallocate(void* ptr) override;							//Calls OS_Panic if ptr is non-null. If not, it has no effect.
	virtual void vDeallocateAll() override;									//Calls NNS_FndFreeToFrmHeap with mode = 3
	virtual bool vIntact() override;
	virtual void vTest() override;
	virtual u32 vReallocate(void* ptr, u32 newSize) override;
	virtual u32 vSizeOf(void* ptr) override;								//returns -1 immediately
	virtual u32 vMaxAllocationUnitSize() override;							//Calls NNS_FndGetAllocatableSizeForFrmHeapEx with align = 4
	virtual u32 vMaxAllocatableSize() override;								//Calls NNS_FndGetAllocatableSizeForFrmHeapEx with align = 4
	virtual u32 vMaxAllocatableSize(s32 align) override;					//Calls NNS_FndGetAllocatableSizeForFrmHeapEx
	virtual u32 vMemoryLeft() override;										//Calls NNS_FndGetAllocatableSizeForFrmHeapEx with align = 4
	virtual u16 vSetGroupID(u16 id) override;								//returns 0 immediately
	virtual u16 vGetGroupID() override;										//returns 0 immediately
	virtual u32 vResizeToFit() override;

	static FrameHeap* create(u32 size, Heap* parent);						//Calls create with align = 4
	static FrameHeap* create(u32 size, Heap* parent, s32 align);			//Creates a heap with size size on parent. If size == -1, the whole memory of parent is allocated for the new heap. If parent is null, currentHeapPtr is used (therefore do not create the root heap with this function). Align is replaced with its abolute value immediately and its minimum value is 4. returns a pointer to the new heap or null if allocation failed.

};
NTR_SIZE_GUARD(FrameHeap, 0x30);


/*
	This is the namespace of memory functions you might use directly which are always safe. Since there are multiple layers between a frontend call and the heap's backend (with many thunked functions),
	the code and call chain is heavily documented here. In addition, all globals are defined in Memory.
*/
namespace Memory {

	extern u16 defaultHeapAllocatorFlags;									//Standard flags. Bit 0 determines zero clear on allocation, bit 1 debug fill.
	extern bool rootHeapCreated;											//True if the root heap has been created (only indicates Memory::SetupRootHeap has been called at least once)
	extern u32 rootHeapInitialSize;											//Initial root heap size. If 0, the whole root heap arena is used. Currently always set to 0.
	extern Heap* gameHeapPtr;												//Pointer to game heap
	extern OSArenaId rootHeapArenaID;										//Arena ID the root heap resides in (always set to 0)
	extern Heap* currentHeapPtr;											//Pointer to current (default) heap
	extern Heap* rootHeapPtr;												//Pointer to root heap
	extern Heap::OnDeallocate heapDeallocationFunction;						//Function to be called in Heap::Deallocate before deallocation
	extern Heap::OnAllocate heapAllocationFunction;							//Function to be called in Heap::Allocate after allocation
	extern bool isHeapListHeadInitialized;									//True if the heap list's head has already been created
	extern NNSFndList* heapList;											//Pointer to the top level heap list
	extern OSSwitchThreadCallback prevSwitchThreadCallback;

	void initRootHeap();
	ExpandedHeap* setupRootHeap(void* startAddress, u32 size);				//Creates the root heap and sets both rootHeapPtr and currentHeapPtr to the resulting pointer. Also sets rootHeapCreated to true and returns a pointer to the newly created heap instance.
	ExpandedHeap* setupGameHeap(void* startAddress, u32 size);				//Calls ExpandedHeap::Create with startAddress and size and sets Memory::gameHeapPtr to the resulting pointer. returns a pointer to the newly created heap.
	ExpandedHeap* tryCreateExpandedHeap(void* start, u32 size);				//Creates an expanded heap. Free allocatable space is determined by size - 0x30 since the allocator needs to be fitted, too. returns null upon failure.

	void heapSwitchThreadCallback(OSThread* from, OSThread* to);
	void setThreadHeap(OSThread* thread, Heap* heap);
	void setHeapSwitchThreadCallback();

	//Calls Heap::allocate
	void* allocate(Heap* heap, u32 size, s32 align);

	//Calls Heap::allocate with align = 4
	void* allocate(Heap* heap, u32 size);

	//Calls Heap::deallocate
	void deallocate(Heap* heap, void* ptr);

	//Calls Heap::sizeOf
	u32 sizeOf(Heap* heap, void* ptr);

	//Calls Heap::reallocate
	void* reallocate(Heap* heap, void* ptr, u32 newSize);

	//Calls heap->deallocate (pCurrentHeap if it's null)
	void deallocate(void* ptr, Heap* heap);

	//Calls pCurrentHeap->allocate
	void* allocate(u32 size, s32 align);

	//Calls pCurrentHeap->allocate with align = 4
	void* allocate(u32 size);

	//Calls pCurrentHeap->deallocate
	void deallocate(void* ptr);

}


/*
//Calls to Heap::Allocate (cstd)
void* operator_new(u32 size);												//Standard operator_new, heap = currentHeapPtr, align = 4
void* malloc(u32 size);														//Standard malloc, heap = currentHeapPtr
//Calls to malloc
void* _malloc(u32 size);
//Calls to Heap::Deallocate (cstd)
void operator_delete(void* ptr);											//Standard operator_delete, heap = currentHeapPtr
//Calls to Memory::Deallocate
void free(void* ptr);														//Standard free
void _dtor_free(void* ptr);													//Internal free for deleting dtors
*/
																			
//TODO: Define ActorBase::operator_delete (0x0204CC7C)
