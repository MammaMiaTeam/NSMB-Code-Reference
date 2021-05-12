#ifndef NSMB_UTIL_H_
#define NSMB_UTIL_H_

#include "nitro_if.h"


/*
	Misc memory transfer functions
*/
void* memchr(void* ptr, u8 value, u32 num);
s32 memcmp(const void* ptr1, const void* ptr2, u32 num);
void memcpy(void* destination, const void* source, u32 num);
void memmove(void* destination, const void* source, u32 num);
void memset(void* ptr, u8 value, u32 num);


#endif // !NSMB_UTIL_H_
