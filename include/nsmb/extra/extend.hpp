#pragma once

#include "preprocessor.hpp"



#define __NTR_MAKE_EXT_PATH(t) PP_STR(nsmb/extend/t.inl)

#define NTR_HAS_EXT(t)		PP_HAS_INCLUDE(__NTR_MAKE_EXT_PATH(t))
#define NTR_EXT_INCLUDE(t)	PP_IF_ELSE(NTR_HAS_EXT(t), __NTR_MAKE_EXT_PATH(t), __FILE__)
