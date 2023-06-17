#pragma once
#ifdef _MSC_VER

#define __asm__(x)
#define __extension__(x)
#define __attribute__(x)
#define __builtin_va_list char*
#define __builtin_va_start(v, l) ((void)(0))
#define __builtin_va_arg(v, l) ((void)(0))
#define __builtin_va_end(v) ((void)(0))
#define __extension__
#define __inline__
#define NO_ANSI_KEYWORDS
#define __builtin_constant_p
#define _Bool bool
//typedef int BOOL;
#define BOOL int

#define consteval constexpr
#define if_consteval if (true)

//#undef __cplusplus

#define __INTPTR_TYPE__ int
#define __INT32_TYPE__ int

#define NNS_G2D_UNICODE

#define asm(x)
#define __arm

#define SDK_ARM9
#define SDK_CODE_ARM

//#define NULL nullptr

#define ATTRIBUTE_ALIGN()
#define va_list		__builtin_va_list
#define va_start(v, l) __builtin_va_start(v, l)
#define va_arg(v, l) __builtin_va_arg(v, l)
#define va_end(v) __builtin_va_end(v)

#define ncp_jump(...) ;
#define ncp_call(...) ;
#define ncp_hook(...) ;
#define ncp_repl(...) ;
#define ncp_over(...) ;
#define arm9_start 0x02000000


#endif