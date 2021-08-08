#pragma once
#include "nitro_if.h"


#define FUNC_INIT			static_cast<u8>(0x00)
#define FUNC_MODE(x)		static_cast<u8>((x)+1)
#define FUNC_EXIT			static_cast<u8>(0xFF)


template<class __ret, class Class, class... Args>
auto ptmf_cast(__ret(*func)(Class*, Args...)) -> __ret(Class::*)(Args...){

    static_assert(sizeof(__ret(*)(Class*, Args...)) + sizeof(u32) == sizeof(__ret(Class::*)(Args...)), "Illegal conversion between static function and member function: Size mismatch");

    union {
        struct{
            __ret(*func)(Class*, Args...);
            u32 adj;
        } staticFunc;
        __ret(Class::*memberFunc)(Args...);
    } f;

    f.staticFunc.func = func;
    f.staticFunc.adj = 0;
    return f.memberFunc;

}


template<class __ret, class Class, class... Args>
auto ptmf_cast(__ret(*func)(Class&, Args...)) -> __ret(Class::*)(Args...){

    static_assert(sizeof(__ret(*)(Class&, Args...)) + sizeof(u32) == sizeof(__ret(Class::*)(Args...)), "Illegal conversion between static function and member function: Size mismatch");
    
    union {
        struct{
            __ret(*func)(Class&, Args...);
            u32 adj;
        } staticFunc;
        __ret(Class::*memberFunc)(Args...);
    } f;

    f.staticFunc.func = func;
    f.staticFunc.adj = 0;
    return f.memberFunc;

}

