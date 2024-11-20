#pragma once

#include <nsmb_nitro.hpp>


class WindowCtrl {
public:

	enum {
		Off,
		On
	};


	void attach();

	void detach();

	void update();

	void setMode(u8 mode);


	bool dirty;
	u8 mode;
	u8 lastMode;

};
NTR_SIZE_GUARD(WindowCtrl, 0x3);
