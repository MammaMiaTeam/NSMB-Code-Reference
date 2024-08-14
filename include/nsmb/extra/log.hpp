#pragma once

#include "nsmb_nitro.hpp"
#include "nsmb/extra/bits.hpp"
#include "nsmb/extra/fixedpoint.hpp"
#include "nsmb/math/vector.hpp"
#include "stringconv.hpp"


#ifdef NTR_DEBUG

asm(R"(
.macro		print text:req cc=al
	b\cc	2f			@ Double branch could be avoided but it's only for debugging anyways
	b		1f
2:
	mov		r12, r12
	b		1f
	.word	0x6464
	.ascii	"\text"
	.align	4
1:
.endm
)");

#else

asm(R"(
.macro		print text:req cc=al
.endm
)");

#endif

#define __NTR_PRINT_ALIAS(cc) asm(".macro print" #cc " text\nprint \"\\text\", " #cc "\n.endm");

__NTR_PRINT_ALIAS(eq);
__NTR_PRINT_ALIAS(ne);
__NTR_PRINT_ALIAS(gt);
__NTR_PRINT_ALIAS(lt);
__NTR_PRINT_ALIAS(ge);
__NTR_PRINT_ALIAS(le);
__NTR_PRINT_ALIAS(hs);
__NTR_PRINT_ALIAS(lo);
__NTR_PRINT_ALIAS(mi);
__NTR_PRINT_ALIAS(pl);
__NTR_PRINT_ALIAS(al);
__NTR_PRINT_ALIAS(nv);
__NTR_PRINT_ALIAS(vs);
__NTR_PRINT_ALIAS(vc);
__NTR_PRINT_ALIAS(hi);
__NTR_PRINT_ALIAS(ls);

#undef __NTR_PRINT_ALIAS


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

	struct FixedVecToken {};
	struct IntVecToken {};

public:

	static constexpr UppercaseToken Uppercase{};
	static constexpr LowercaseToken Lowercase{};

	static constexpr FixedVecToken FixedVec{};
	static constexpr IntVecToken IntVec{};

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

	template<auto>
	NTR_INLINE consteval void softConstant() {}

	template<auto>
	NTR_INLINE consteval void hardConstant() {}


	NTR_INLINE Log& operator<<(const auto&) {
		return *this;
	}


	NTR_INLINE static void puts(const char* text) {}

	NTR_INLINE static void print(const char* fmt, ...) {}

	NTR_INLINE static void vprint(const char* fmt, va_list vl) {}

#else

	template<auto>
	NTR_WARNING("Log") NTR_INLINE consteval void softConstant() {}

	template<auto>
	NTR_ERROR("Log") NTR_INLINE consteval void hardConstant() {}


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


	template<CC::Pointer P>
	NTR_INLINE Log& operator<<(P ptr) {

		Flags old = flags;

		flags.fill = '0';
		flags.width = 8;
		flags.base = Base::Hex;

		operator<<(rcast<AddressT>(ptr));

		flags = old;

		return *this;
		
	}

	template<class R, class T, class... Args>
	NTR_INLINE Log& operator<<(R(T::*func)(Args...)) {

		union PTMF {

			struct {
				void* ptr;
				u32 param;
			};

			R(T::*func)(Args...);

		};

		PTMF ptmf = func;

		return *this << "[" << ptmf.ptr << " " << ptmf.param << "]";

	}

	template<class T, SizeT N> requires requires (Log&& l, T&& t) { l << t; }
	NTR_INLINE Log& operator<<(const T (&arr)[N]) {

		*this << "[";

		for (SizeT i; const T& e : arr) {

			*this << e;

			if (i++ != N - 1) {
				*this << ", ";
			}

		}

		return *this << "]";

	}

	NTR_INLINE Log& operator<<(bool b) {
		return *this << (flags.uppercase ? (b ? "TRUE" : "FALSE") : (b ? "true" : "false"));
	}

	NTR_INLINE Log& operator<<(const Vec2& v) { // TODO Better implementation (CC::Vector concept + array indexing)

		if (flags.fixedVec) {
			return *this << "[" << Fx32(v.x) << ", " << Fx32(v.y) << "]";
		} else {
			return *this << "[" << v.x << ", " << v.y << "]";
		}

	}

	NTR_INLINE Log& operator<<(const Vec3& v) {

		if (flags.fixedVec) {
			return *this << "[" << Fx32(v.x) << ", " << Fx32(v.y) << ", " << Fx32(v.z) << "]";
		} else {
			return *this << "[" << v.x << ", " << v.y << ", " << v.z << "]";
		}

	}

	NTR_INLINE Log& operator<<(const Vec3s& v) {

		if (flags.fixedVec) {
			return *this << "[" << Fx16(v.x) << ", " << Fx16(v.y) << ", " << Fx16(v.z) << "]";
		} else {
			return *this << "[" << v.x << ", " << v.y << ", " << v.z << "]";
		}

	}

	template<CC::Integer I>
	NTR_INLINE Log& operator<<(I n) {

		SizeT length;

		if (flags.base == Base::Dec) {
			length = StringConv::decimal(buffer, n);
		} else if (flags.base == Base::Hex) {
			length = StringConv::hex(buffer, n, flags.uppercase);
		} else {
			length = StringConv::binary(buffer, n);
		}

		insertFill(length);
		flush();

		return *this;

	}

	template<CC::Fixed F>
	NTR_INLINE Log& operator<<(F f) {

		SizeT length = StringConv::fixed(buffer, f, flags.precision);

		insertFill(length);
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

	constexpr static const char* data() {
		return buffer;
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
		.uppercase = false,
		.fixedVec = true
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
		mov		r12, r12
		b		end
		.word	0x00006464
		.global _ZN3Log6bufferE
	_ZN3Log6bufferE:
		.fill	120
		.word	0
	end:
		bx		lr
	)");};

#endif

};

class DiscardLog {
public:

	constexpr const DiscardLog& operator<<(const auto&) const {
		return *this;
	}

};
