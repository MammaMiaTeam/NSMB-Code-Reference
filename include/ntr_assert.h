#pragma once
#include <stdarg.h>

extern "C" void dbg_message(const char* message);

#define __ntr_message(s)	do { dbg_message((s)); } while (false)
#define __ntr_terminate()	OS_Terminate()


/*
* Define __ntr_message and __ntr_terminate before including this file.
* 
* #define __ntr_message(s) ...
*/


extern "C" void OS_Terminate();


inline void ntr_terminate() {
	__ntr_terminate();
}


inline /*NTR_WEAK*/ void __ntr_assert(bool condition, const char* file, int line, const char* message, ...) {

	if (!condition) {

		static char buffer[1024];
		int length;

		va_list vl;
		va_start(vl, message);

		length = OS_SNPrintf(buffer, sizeof(buffer), "Assertion failed (File %s, line %d):\n", file, line);
		buffer[length] = 0;

		__ntr_message(buffer);

		length = OS_VSNPrintf(buffer, sizeof(buffer), message, vl);
		buffer[length++] = '\n';
		buffer[length] = 0;

		__ntr_message(buffer);

		va_end(vl);

		ntr_terminate();
	}

}


#if defined(NTR_DEBUG) && NTR_DEBUG

#define ntr_assert(cond, msg, ...)			do {__ntr_assert(!!(cond), __FILE__, __LINE__, (msg), ##__VA_ARGS__);} while (false)
#define ntr_force_assert(msg, ...)			do {__ntr_assert(false, __FILE__, __LINE__, (msg), ##__VA_ARGS__);} while (false)

#else

#define ntr_assert(cond, msg, ...)
#define ntr_force_assert(msg, ...)

#endif
