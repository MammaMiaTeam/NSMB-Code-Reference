#pragma once

#include "nsmb_nitro.hpp"

#include "log.hpp"


#define NTR_ASSERT_SYMBOL		__ntr_assert // TODO Weak symbols
#define NTR_TERMINATE_SYMBOL	__ntr_terminate


NTR_COPY(OS_Terminate) NTR_INLINE static void NTR_TERMINATE_SYMBOL() {
	OS_Terminate();
}


#define ntr_terminate() do {NTR_TERMINATE_SYMBOL();} while (false)


#ifdef NTR_DEBUG

NTR_FORMAT(printf, 4, 5) static constexpr void NTR_ASSERT_SYMBOL(bool condition, const char* file, int line, const char* message, ...) {

	if (!condition) {

		va_list vl;
		va_start(vl, message);

		Log::print("Assertion failed (File %s, line %d):\n", file, line);
		Log::vprint(message, vl);
		Log::puts("\n");

		va_end(vl);

		ntr_terminate();

	}

}

#endif


#ifdef NTR_DEBUG

	#define ntr_assert(cond, msg, ...) do {NTR_ASSERT_SYMBOL(!!(cond), __FILE__, __LINE__, msg __VA_OPT__(,) __VA_ARGS__);} while (false)
	#define ntr_force_assert(msg, ...) ntr_assert(false, msg __VA_OPT__(,) __VA_ARGS__)

#else

	#define ntr_assert(cond, msg, ...) do {} while (false)
	#define ntr_force_assert(msg, ...) do {} while (false)

#endif
