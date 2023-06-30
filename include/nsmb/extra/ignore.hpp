#pragma once


namespace Detail {

	struct Ignore {

		template<class T>
		constexpr const Ignore& operator=(const T&) const {
			return *this;
		}

	};

}

static constexpr Detail::Ignore Ignore;
