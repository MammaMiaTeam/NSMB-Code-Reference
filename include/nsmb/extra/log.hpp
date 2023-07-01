#pragma once

#include "nsmb_nitro.hpp"
#include "nsmb/extra/bits.hpp"
#include "nsmb/extra/fixedpoint.hpp"
#include "nsmb/math/vector.hpp"
#include "stringconv.hpp"


/*#ifdef NTR_DEBUG

asm(R"(
	.macro print text
	mov		r12, r12
	b		end
	.word	0x6464
	.ascii	"\text"
	.word	0
	end:
	.endm
)");

#else

asm(R"(
	.macro print text
	.endm
)");

#endif*/


/*template<auto>
NTR_WARNING("SoftLog") constexpr void SoftLog() {}

template<auto>
NTR_ERROR("HardLog") constexpr void HardLog() {}


#ifdef __INTELLISENSE__

	#define NTR_SOFTLOG(v) do {} while (false)
	#define NTR_HARDLOG(v) do {} while (false)

#else

	#define NTR_SOFTLOG(v) do { SoftLog<(v)>() } while (false)
	#define NTR_HARDLOG(v) do { HardLog<(v)>() } while (false)

#endif*/



class Log {

private:

	static constexpr SizeT BufferSize = 120;

	template<class T>
	struct ValueToken {

		constexpr ValueToken(T value) : value(value) {}

		T value;

	};

	struct UppercaseToken {};
	struct LowercaseToken {};

public:

	static constexpr UppercaseToken Uppercase{};
	static constexpr LowercaseToken Lowercase{};

	struct SetW : ValueToken<u8> {};
	struct SetFill : ValueToken<char> {};
	struct Precision : ValueToken<u8> {};

	enum Base : u8 {
		Dec,
		Hex,
		Bin
	};

	struct Flags : BitFlag<u32> {

		char fill;
		u8 width;
		u8 precision;
		Base base : 2;
		bool uppercase : 1;
		bool fixedVec : 1;

	};


	#ifndef NTR_DEBUG

	NTR_INLINE Log& operator<<(const auto&) {
		return *this;
	}


	NTR_INLINE static void puts(const char* text) {}

	NTR_INLINE static void print(const char* fmt, ...) {}

	NTR_INLINE static void vprint(const char* fmt, va_list vl) {}

	#else

	NTR_INLINE Log& operator<<(UppercaseToken) {
		flags.uppercase = true;
		return *this;
	}

	NTR_INLINE Log& operator<<(LowercaseToken) {
		flags.uppercase = false;
		return *this;
	}

	NTR_INLINE Log& operator<<(SetW width) {
		flags.width = width.value;
		return *this;
	}

	NTR_INLINE Log& operator<<(SetFill fill) {
		flags.fill = fill.value;
		return *this;
	}

	NTR_INLINE Log& operator<<(Precision precision) {
		flags.precision = precision.value;
		return *this;
	}

	NTR_INLINE Log& operator<<(Base base) {
		flags.base = base;
		return *this;
	}


	NTR_INLINE Log& operator<<(const char* text) {

		puts(text);

		return *this;

	}

	template<SizeT N>
	NTR_INLINE Log& operator<<(const char (&text)[N]) {

		puts(text);

		return *this;

	}

	NTR_INLINE Log& operator<<(char c) {

		buffer[0] = c;
		buffer[1] = '\0';

		flush();

		return *this;

	}


	template<class T>
	NTR_INLINE Log& operator<<(T* ptr) {
		return *this << rcast<AddressT>(ptr);
	}

	template<class R, class T, class... Args>
	NTR_INLINE Log& operator<<(R(T::*func)(Args...)) {

		union PTMF {

			struct {
				AddressT ptr;
				u32 param;
			};

			R(T::*func)(Args...);

		};

		PTMF ptmf = func;

		return *this << "[ " << ptmf.ptr << " " << ptmf.param << "]";

	}

	NTR_INLINE Log& operator<<(bool b) {
		return *this << (flags.uppercase ? (b ? "TRUE" : "FALSE") : (b ? "true" : "false"));
	}

	NTR_INLINE Log& operator<<(const Vec2& v) {
		return *this << "[ " << v.x << ", " << v.y << " ]";
	}

	NTR_INLINE Log& operator<<(const Vec3& v) {
		return *this << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
	}

	NTR_INLINE Log& operator<<(const Vec3s& v) {
		return *this << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
	}

	template<CC::Integer I>
	NTR_INLINE Log& operator<<(I n) {

		printInteger(Math::abs(n), n < 0);

		return *this;

	}

	template<CC::Fixed F>
	NTR_INLINE Log& operator<<(F f) {

		StringConv::fixed(buffer, f, flags.precision);
		flush();

		return *this;

	}


	static void puts(const char* text) {

		char* ptr = buffer;
		char* end = buffer + BufferSize - 1;

		while (true) {

			*ptr++ = *text++;

			if (ptr >= end) {
				*ptr = '\0';
				flush();
				ptr = buffer;
			}

			if (*text == 0) {
				*ptr = '\0';
				break;
			}

		}

		flush();

	}

	NTR_FORMAT(printf, 1, 2) static void print(const char* fmt, ...) {

		va_list vl;
		va_start(vl, fmt);

		OS_VSNPrintf(buffer, BufferSize, fmt, vl);

		flush();

		va_end(vl);

	}

	NTR_INLINE static void vprint(const char* fmt, va_list vl) {

		OS_VSNPrintf(buffer, BufferSize, fmt, vl);

		flush();

	}

	#endif

private:

	#ifdef NTR_DEBUG

	static char buffer[BufferSize];

	static inline Flags flags = {
		.fill = ' ',
		.width = 0,
		.precision = 4,
		.base = Dec,
		.uppercase = false
	};


	static void printInteger(u64 n, bool sign) {

		SizeT length;

		if (flags.base == Base::Dec) {
			length = StringConv::decimal(buffer, sign ? -n : n);
		} else if (flags.base == Base::Hex) {
			length = StringConv::hex(buffer, sign ? -n : n, flags.uppercase);
		} else {
			length = StringConv::binary(buffer, sign ? -n : n);
		}

		insertFill(length);
		flush();

	}

	static void insertFill(SizeT length) {

		s32 width = Log::flags.width;
		char fill = Log::flags.fill;

		width -= length;

		if (width <= 0) {
			return;
		}

		for (s32 i = length; i >= 0; i--) {
			buffer[i + width] = buffer[i];
		}

		for (u32 i = 0; i < width; i++) {
			buffer[i] = fill;
		}

	}

	NTR_NAKED static void flush() {asm(R"(
		mov		r12,r12
		b		skip
		.word	0x00006464
		.global _ZN3Log6bufferE
	_ZN3Log6bufferE:
		.fill	120
		.word	0
	skip:
		bx		lr
	)");};

	#endif

};
