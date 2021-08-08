#pragma once

#define __quik_get(_1,_2,_3,_4,NAME,...) NAME
#define quik(...) __quik_get(__VA_ARGS__, quik4, quik3)(__VA_ARGS__)

#define quik3(addr, og, func) \
hook(addr) \
asm_func void func ## _ ## _quik() { \
    asm(og); \
    asm("PUSH {R0-R3}"); \
    asm("BL " # func); \
    asm("POP {R0-R3}"); \
    asm("B (" # addr " + 4)"); \
} extern "C"

#define quik4(addr, ov, og, func) \
hook(addr, ov) \
asm_func void func ## _ ## addr ## _quik() { \
    asm(og); \
    asm("PUSH {R0-R3}"); \
    asm("BL " # func); \
    asm("POP {R0-R3}"); \
    asm("B (" # addr " + 4)"); \
} extern "C"
