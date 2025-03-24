#pragma once

#include "log.hpp"


struct __ntr {

#ifdef NTR_DEBUG

	struct Debug {

		char message[120];

		const char* function;
		const char* file;
		int line;

	};

	static inline Debug debug;

#endif

	NTR_COPY(OS_Terminate) NTR_FORMAT(printf, 4, 5) static void terminate(const char* file, const char* function, int line, const char* fmt, ...)
#ifndef NTR_DEBUG
	asm("OS_Terminate");
#else
	{

		va_list vl;
		va_start(vl, fmt);

		OS_VSNPrintf(debug.message, 120, fmt, vl);

		Log::print("ntr_terminate: %s\n", debug.message);

		va_end(vl);

		debug.function = function;
		debug.file = file;
		debug.line = line;

		OS_Terminate();

	}
#endif

#ifdef NTR_DEBUG

	NTR_FORMAT(printf, 5, 6) static constexpr void assert(bool condition, const char* file, const char* function, int line, const char* fmt, ...) {

		if (condition) {
			return;
		}

		Log::print("ntr_assert failed in file '%s' [%d]\n", file, line);

		terminate(file, function, line, fmt, __builtin_apply_args());

	}

#endif

};


#define ntr_terminate(fmt, ...) do { ::__ntr::terminate(__FILE__, __PRETTY_FUNCTION__, __LINE__, fmt __VA_OPT__(,) __VA_ARGS__); } while (false)

#ifdef NTR_DEBUG
	#define ntr_debug_message	scast<const char*>(::__ntr::debug.message)
	#define ntr_debug_function	scast<const char*>(::__ntr::debug.function)
	#define ntr_debug_file		scast<const char*>(::__ntr::debug.file)
	#define ntr_debug_line		scast<const int>(::__ntr::debug.line)
#else
	#define ntr_debug_message	"Unknown"
	#define ntr_debug_function	"Unknown"
	#define ntr_debug_file		"Unknown"
	#define ntr_debug_line		-1
#endif


inline void __ntr_assertion_failed_at_compile_time() {}

static constexpr void __ntr_assert_constexpr(bool condition) {

	if (std::is_constant_evaluated() && !condition) {
		__ntr_assertion_failed_at_compile_time();
	}

}


#ifdef NTR_DEBUG
	#define __NTR_ASSERT_IMPL(cond, fmt, ...) ::__ntr::assert(!!(cond), __FILE__, __PRETTY_FUNCTION__, __LINE__, fmt __VA_OPT__(,) __VA_ARGS__)
#else
	#define __NTR_ASSERT_IMPL(cond, fmt, ...) [[assume(cond)]]
#endif


#define ntr_assert(cond, msg, ...) do { ::__ntr_assert_constexpr(!!(cond)); __NTR_ASSERT_IMPL(cond, msg __VA_OPT__(,) __VA_ARGS__); } while (false)
#define ntr_force_assert(msg, ...) do { __NTR_ASSERT_IMPL(false, msg __VA_OPT__(,) __VA_ARGS__); } while (false)
