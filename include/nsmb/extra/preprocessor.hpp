#pragma once


#define PP_CATX(a, b) a##b

#define PP_CAT(a, b)		PP_CATX(a, b)
#define PP_CAT3(a, b, c)	PP_CAT(PP_CAT(a, b), c)

#define PP_STRX(x) #x
#define PP_STR(x) PP_STRX(x)


#define PP_GET0(m, ...) m
#define PP_GET1(_1, m, ...) m
#define PP_GET2(_1, _2, m, ...) m 
#define PP_GET3(_1, _2, _3, m, ...) m
#define PP_GET4(_1, _2, _3, _4, m, ...) m
#define PP_GET5(_1, _2, _3, _4, _5, m, ...) m
#define PP_GET6(_1, _2, _3, _4, _5, _6, m, ...) m
#define PP_GET7(_1, _2, _3, _4, _5, _6, _7, m, ...) m
#define PP_GET8(_1, _2, _3, _4, _5, _6, _7, _8, m, ...) m
#define PP_GET9(_1, _2, _3, _4, _5, _6, _7, _8, _9, m, ...) m


#define PP_EMPTY
#define PP_IGNORE(...)
#define PP_EXPAND(...) __VA_ARGS__


#define PP_PRAGMA(p) _Pragma(PP_STR(p))

#define PP_MESSAGE(msg)		PP_PRAGMA(message msg)
#define PP_WARNING(msg)		PP_PRAGMA(GCC warning msg)
#define PP_ERROR(msg)		PP_PRAGMA(GCC error msg)

#define PP_DIAGNOSTIC(p)	PP_PRAGMA(GCC diagnostic p)

#define PP_DIAGNOSTIC_PUSH				PP_DIAGNOSTIC(push)
#define PP_DIAGNOSTIC_POP				PP_DIAGNOSTIC(pop)
#define PP_DIAGNOSTIC_IGNORE(x)			PP_DIAGNOSTIC(ignored x)
#define PP_DIAGNOSTIC_ERROR(x)			PP_DIAGNOSTIC(error x)
#define PP_DIAGNOSTIC_WARNING(x)		PP_DIAGNOSTIC(warning x)


#define PP_FILE			__FILE__
#define PP_LINE			__LINE__
#define PP_DATE			__DATE__
#define PP_TIME			__TIME__
#define PP_TIMESTAMP	__TIMESTAMP__
#define PP_BASEFILE		__BASE_FILE__
#define PP_FILENAME		__FILE_NAME__
#define PP_COUNTER		__COUNTER__


#define PP_HAS_INCLUDE __has_include


#ifdef __INTELLISENSE__
	#define IDE_HAS_INTELLISENSE
#endif

#ifdef _MSC_VER
	#define IDE_VS
#elif defined(__CLION_IDE__)
	#define IDE_CLION
#else
	#define IDE_UNKNOWN
#endif
