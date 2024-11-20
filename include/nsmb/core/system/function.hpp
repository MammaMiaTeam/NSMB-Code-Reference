#pragma once

#include <nsmb_nitro.hpp>


namespace Func {

    template<class Ret, class Class, class... Args>
    using MemberType = Ret(Class::*)(Args...);

    template<class Ret, class... Args>
    using Type = Ret(*)(Args...);


    static constexpr s8 Init = 0;
    static constexpr s8 Exit = -1;

    constexpr s8 Step(u8 step) {
        return step + 1;
    }

}


template<class Ret, class Class, class... Args>
auto ptmf_cast(Ret(*func)(Class*, Args...)) -> Ret(Class::*)(Args...) {

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
auto ptmf_cast(Ret(*func)(Class&, Args...)) -> Ret(Class::*)(Args...) {

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


template<class Ret, class Class, class... Args>
auto ptmf_cast(Ret(*func)(Class*, Args...), u32 adj) -> Ret(Class::*)(Args...) {

    static_assert(sizeof(Ret(*)(Class*, Args...)) + sizeof(u32) == sizeof(Ret(Class::*)(Args...)), "Illegal conversion between static function and member function: Size mismatch");

    union {
        struct {
            Ret(*func)(Class*, Args...);
            u32 adj;
        } staticFunc;
        Ret(Class::* memberFunc)(Args...);
    } f;

    f.staticFunc.func = func;
    f.staticFunc.adj = adj;
    return f.memberFunc;

}

template<class Ret, class Class, class... Args>
auto ptmf_cast(Ret(Class::*func)(Args...)) -> Ret(*)(Class*, Args...) {

    static_assert(sizeof(Ret(*)(Class*, Args...)) + sizeof(u32) == sizeof(Ret(Class::*)(Args...)), "Illegal conversion between static function and member function: Size mismatch");

    union {
        struct {
            Ret(*func)(Class*, Args...);
            u32 adj;
        } staticFunc;
        Ret(Class::* memberFunc)(Args...);
    } f;

	f.memberFunc = func;
    return f.staticFunc.func;

}
