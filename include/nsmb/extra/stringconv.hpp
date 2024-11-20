#pragma once

#include <nsmb/core/math/math.hpp>
#include "meta.hpp"
#include "fixedpoint.hpp"


namespace StringConv {

	constexpr SizeT generic(char* out, u64 n, SizeT base, bool sign, bool upper) {

		constexpr char UpperChars[] = "0123456789ABCDEF";
		constexpr char LowerChars[] = "0123456789abcdef";

		constexpr SizeT Size = 64;

		if (base < 2 || base > 16) {
			return 0;
		}

		char buffer[Size] = {};

		u32 count = 0;

		const char* chars = upper ? UpperChars : LowerChars;

		for (count; count < Size; count++) {

			buffer[count] = chars[n % base];
			n /= base;

			if (n == 0) {
				break;
			}

		}

		count++;

		u32 pos = 0;

		if (sign) {
			out[pos++] = '-';
		}

		for (s32 i = count - 1; i >= 0; i--) {
			out[pos++] = buffer[i];
		}

		out[pos] = '\0';

		return pos;

	}


	template<CC::Integer I>
	NTR_INLINE constexpr SizeT decimal(char* out, I n) {
		return generic(out, Math::abs(n), 10, n < 0, false);
	}

	template<CC::Integer I>
	NTR_INLINE constexpr SizeT hex(char* out, I n, bool upper) {
		return generic(out, TT::MakeUnsigned<I>(n), 16, false, upper);
	}

	template<CC::Integer I>
	NTR_INLINE constexpr SizeT binary(char* out, I n) {
		return generic(out, TT::MakeUnsigned<I>(n), 2, false, false);
	}


	constexpr SizeT genericFixed(char* out, s64 raw, SizeT shift, SizeT precision) {

		bool sign = raw < 0;

		s64 fract = Bits::mask(sign ? -raw : raw, 0, shift);
		s64 integer = (raw >> shift) + (fract ? sign : 0);

		SizeT pos = generic(out, Math::abs(integer), 10, sign, false);

		if (precision == 0) {
			return pos;
		}

		out[pos++] = '.';

		u32 count = 1;

		do {

			s64 n = fract * 10;
			s64 whole = n >> shift;

			fract = Bits::mask(n, 0, shift);

			out[pos++] = '0' + whole;

		} while (count++ != precision);

		out[pos] = '\0';

		return pos;

	}


	template<CC::Fixed F>
	NTR_INLINE constexpr SizeT fixed(char* out, F f, SizeT precision) {
		return genericFixed(out, f.raw(), F::Shift, precision);
	}

}
