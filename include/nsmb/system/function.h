#pragma once
#include "nitro_if.h"


#define FUNC_INIT			static_cast<s8>(0)
#define FUNC_STEP(x)		static_cast<s8>((x)+1)
#define FUNC_EXIT			static_cast<s8>(-1)


template<class Ret, class Class, class... Args>
auto ptmf_cast(Ret(*func)(Class*, Args...))->Ret(Class::*)(Args...) {

    static_assert(sizeof(Ret(*)(Class*, Args...)) + sizeof(u32) == sizeof(Ret(Class::*)(Args...)), "Illegal conversion between static function and member function: Size mismatch");

    union {
        struct {
            Ret(*func)(Class*, Args...);
            u32 adj;
        } staticFunc;
        Ret(Class::* memberFunc)(Args...);
    } f;

    f.staticFunc.func = func;
    f.staticFunc.adj = 0;
    return f.memberFunc;

}


template<class Ret, class Class, class... Args>
auto ptmf_cast(Ret(*func)(Class&, Args...))->Ret(Class::*)(Args...) {

    static_assert(sizeof(Ret(*)(Class&, Args...)) + sizeof(u32) == sizeof(Ret(Class::*)(Args...)), "Illegal conversion between static function and member function: Size mismatch");

    union {
        struct {
            Ret(*func)(Class&, Args...);
            u32 adj;
        } staticFunc;
        Ret(Class::* memberFunc)(Args...);
    } f;

    f.staticFunc.func = func;
    f.staticFunc.adj = 0;
    return f.memberFunc;

}

