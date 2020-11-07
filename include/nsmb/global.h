#ifndef NSMB_GLOBAL_H_
#define NSMB_GLOBAL_H_

//Warning: This header is not existent in normal C++ programs, it's just here to document all init/fini functions and everything regarding static/global objects
//Usage in other ways is strongly discouraged.


/*
	GlobalObjectInfo is a small object linking other global objects together to enable a global reversed dtor calling chain.
*/
struct GlobalObjectInfo {

	GlobalObjectInfo* previous;						//Pointer to previous global object
	void* dtorPtr;									//Pointer to static destructor
	void* object;									//Pointer to object on which the static dtor is being called on

};

void __register_global_object(void* object, void* dtor, GlobalObjectInfo* info);		//Registers info in the global dtor chain and sets it up



extern GlobalObjectInfo* __last_global_object;		//Pointer to the last global object in the chain


/*
	List of known global objects
*/
extern GlobalObjectInfo __global_info_font;			//Global object info on FontManager


/*
	List of global ctors / dtors
*/
void __init_font();
void __fini_font(void* object);



#endif // !NSMB_GLOBAL_H_
