#pragma once

#include "preprocessor.hpp"

#ifndef NTR_EXT_DIR
	#define NTR_EXT_DIR nsmb/extend
#endif

#define __NTR_MAKE_EXT_PATH(t) PP_STR(NTR_EXT_DIR/t.inl)

#define NTR_EXT_EXISTS(t)	PP_HAS_INCLUDE(__NTR_MAKE_EXT_PATH(t))
#define NTR_EXT_INCLUDE(t)	__NTR_MAKE_EXT_PATH(t)
