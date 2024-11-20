#pragma once

#include <nsmb_nitro.hpp>

struct NicknameInfo
{
    u8 pad;
    u8 length;
    u16 chars[10];
};
