#pragma once


#define PP_CATX(a, b) a##b

#define PP_CAT(a, b)		PP_CATX(a, b)
#define PP_CAT3(a, b, c)	PP_CAT(PP_CAT(a, b), c)
#define PP_CAT4(a, b, c, d)	PP_CAT(PP_CAT3(a, b, c), d)

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


#define PP_EVAL0(...) __VA_ARGS__
#define PP_EVAL1(...) PP_EVAL0(PP_EVAL0(PP_EVAL0(__VA_ARGS__)))
#define PP_EVAL2(...) PP_EVAL1(PP_EVAL1(PP_EVAL1(__VA_ARGS__)))
#define PP_EVAL3(...) PP_EVAL2(PP_EVAL2(PP_EVAL2(__VA_ARGS__)))
#define PP_EVAL4(...) PP_EVAL3(PP_EVAL3(PP_EVAL3(__VA_ARGS__)))
#define PP_EVAL5(...) PP_EVAL4(PP_EVAL4(PP_EVAL4(__VA_ARGS__)))

#define PP_EVAL(...) PP_EVAL5(__VA_ARGS__)

#define PP_EVAL_LIMIT 365


#define PP_EMPTY
#define PP_COMMA ,
#define PP_IGNORE(...)
#define PP_EXPAND(...) __VA_ARGS__

#define PP_DELAY(m) m PP_EMPTY


#define __PP_IS_NULL_0	0
#define __PP_IS_NULL	1

#define __PP_IS_NULL_CHECK(...) PP_CATX(__PP_IS_NULL, __VA_OPT__(_0))

#define PP_IS_NULL(m) __PP_IS_NULL_CHECK(m)


#define __PP_FOREACH_0(m, x, ...) m(x) __VA_OPT__(PP_DELAY(__PP_FOREACH_1)(m, __VA_ARGS__))
#define __PP_FOREACH_1(m, x, ...) m(x) __VA_OPT__(PP_DELAY(__PP_FOREACH_0)(m, __VA_ARGS__))

#define PP_FOREACH(m, ...) PP_EVAL(__PP_FOREACH_1(m, __VA_ARGS__))


#define __PP_BOOL_NOT_0 1
#define __PP_BOOL_NOT_1 0

#define __PP_BOOL_AND_00 0
#define __PP_BOOL_AND_01 0
#define __PP_BOOL_AND_10 0
#define __PP_BOOL_AND_11 1

#define __PP_BOOL_OR_00 0
#define __PP_BOOL_OR_01 1
#define __PP_BOOL_OR_10 1
#define __PP_BOOL_OR_11 1

#define PP_BOOL_NOT(a)		PP_CAT(__PP_BOOL_NOT_, a)
#define PP_BOOL_AND(a, b)	PP_CAT3(__PP_BOOL_AND_, a, b)
#define PP_BOOL_OR(a, b)	PP_CAT3(__PP_BOOL_OR_, a, b)

#define PP_TRUE 1
#define PP_FALSE 0


#define __PP_TERNARY_1(t, f) t
#define __PP_TERNARY_0(t, f) f

#define PP_IF_ELSE(c, t, f)	PP_CAT(__PP_TERNARY_, c)(t, f)
#define PP_IF(c, t)			PP_CAT(__PP_TERNARY_, c)(t, PP_EMPTY)


#define PP_PRAGMA(p) _Pragma(PP_STR(p))

#define PP_MESSAGE(msg)		PP_PRAGMA(message msg)
#define PP_WARNING(msg)		PP_PRAGMA(GCC warning msg)
#define PP_ERROR(msg)		PP_PRAGMA(GCC error msg)

#define PP_DIAGNOSTIC(p)	PP_PRAGMA(GCC diagnostic p)

#define PP_DIAGNOSTIC_PUSH()			PP_DIAGNOSTIC(push)
#define PP_DIAGNOSTIC_POP()				PP_DIAGNOSTIC(pop)
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
