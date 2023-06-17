#pragma once

#define ntr_nodisc [[nodiscard]]

struct __Ignore {

	template<class T>
	constexpr const __Ignore& operator=(const T&) const noexcept { return *this; }

};

inline constexpr __Ignore ntr_ignore{};
