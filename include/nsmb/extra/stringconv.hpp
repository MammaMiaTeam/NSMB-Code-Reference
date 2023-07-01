#pragma once

#include "nsmb_nitro.hpp"
#include "meta.hpp"
#include "nsmb/math/math.hpp"
#include "fixedpoint.hpp"


namespace StringConv {

	constexpr SizeT generic(char* out, u64 n, SizeT base, bool sign, bool upper) {

		constexpr char UpperChars[] = "0123456789ABCDEF";
		constexpr char LowerChars[] = "0123456789abcdef";

		constexpr SizeT Size = 32;

		//ntr_assert(base <= 16, "Illegal numeric base");

		if (base > 16) { // TODO Asserting causes recursive includes
			return 0;
		}

		char buffer[Size];

		const char* chars = upper ? UpperChars : LowerChars;

		u32 count = 0;

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

	template<CC::Integer T>
	NTR_INLINE constexpr SizeT decimal(char* out, T n) {
		return generic(out, Math::abs(n), 10, n < 0, false);
	}

	template<CC::Integer T>
	NTR_INLINE constexpr SizeT hex(char* out, T n, bool upper) {
		return generic(out, Math::abs(n), 16, n < 0, upper);
	}

	template<CC::Integer T>
	NTR_INLINE constexpr SizeT binary(char* out, T n) {
		return generic(out, Math::abs(n), 2, n < 0, false);
	}

	constexpr SizeT genericFixed(char* out, s64 raw, SizeT shift, SizeT precision) { // TODO precision support

		s64 integer = raw >> shift;
		s64 fract = Bits::mask(raw, 0, shift);

		SizeT pos = decimal(out, integer);

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
		return genericFixed(out, f, F::Shift, precision);
	}

}
