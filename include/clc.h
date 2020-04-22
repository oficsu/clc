//  Curious Loopholed Counter
//
//  Copyright Ofee Oficsu 2020
//  Copyright Malibushko  2020
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  Project home: https://github.com/oficsu/clc

#ifndef CURIOUS_LOOPHOLED_COUNTER_HPP
#define CURIOUS_LOOPHOLED_COUNTER_HPP

#include <utility>

namespace clc
{
    namespace detail
    {
        enum class unit { value };

        template<typename Tag>
        struct declarator {
            friend constexpr unit get(declarator);
        };

        template<typename Tag, typename Declarator>
        struct infector {
            friend constexpr unit get(Declarator) {
                return unit::value;
            }
        };

        template<typename Tag>
        constexpr bool binary_descending_impl(float) {
            return sizeof(infector<Tag, declarator<Tag>>);
        };

        template<typename Tag, unit = get(declarator<Tag>{})>
        constexpr bool binary_descending_impl(int) {
            return false;
        };

        struct default_tag {};

        template<typename Tag, bool value = binary_descending_impl<Tag>(42)>
        using binary_descending = std::integral_constant<bool, value>;

        template<bool C>
        struct fast_conditional;

        template<>
        struct fast_conditional<true> {
            template<typename Then, typename Else> using type = Then;
        };

        template<>
        struct fast_conditional<false> {
            template<typename Then, typename Else> using type = Else;
        };

        template<bool C, typename Then, typename Else>
        using fast_conditional_t = typename fast_conditional<C>:: template type<Then, Else>;

        struct force_true {};

        template<typename Tag,
                 bool Freezed>
        using toggleable_binary_descending = std::integral_constant<bool, Freezed || binary_descending_impl<fast_conditional_t<Freezed, force_true, Tag>>(42)>;

        template<bool C>
        struct partial_conditional;

        template<>
        struct partial_conditional<true> {
            template<template<typename...> class Then, typename Else, typename ...Args> using type = Then<Args...>;
        };

        template<>
        struct partial_conditional<false> {
            template<template<typename...> class Then, typename Else, typename ...Args> using type = Else;
        };

        template<bool C, template<typename...> class Then, typename Else, typename ...Args>
        using partial_conditional_t = typename partial_conditional<C>:: template type<Then, Else, Args...>;

        template<std::size_t Value, typename>
        struct tagged_tag : std::integral_constant<std::size_t, Value + 1> {};

        struct bit {
            enum { max = 2 };

            template<
                typename Tag = default_tag,
                bool Freezed = false,
                std::size_t _0 = toggleable_binary_descending<tagged_tag<0, Tag>, Freezed>(),
                std::size_t _1 = toggleable_binary_descending<tagged_tag<1, Tag>, !!_0>()
            >
            using information = std::integral_constant<std::size_t, _0 + _1>;
        };

        template<typename Inner = bit>
        struct add_bit {
            enum { max = Inner::max * 2 };

            template<typename Args, typename FreezedConstant>
            using previous = typename Inner:: template information<Args, FreezedConstant::value>;

            template<typename Tag, bool Freezed>
            using part = partial_conditional_t<!Freezed, previous, std::integral_constant<std::size_t, Inner::max>, Tag, std::integral_constant<bool, Freezed>>;

            template<
                typename Tag = default_tag,
                bool Freezed = false,
                std::size_t _0 = part<tagged_tag<0, Tag>, Freezed>::value,
                std::size_t _1 = part<tagged_tag<1, Tag>,  !! _0 >::value
            >
            using information = std::integral_constant<std::size_t, _0 + _1>;
        };
    }

    template<typename T = detail::bit>
    using add_bit = detail::add_bit<T>;

    using counter2bit = add_bit<>;
    using counter3bit = add_bit<counter2bit>;
    using counter4bit = add_bit<counter3bit>;
    using counter5bit = add_bit<counter4bit>;
    using counter6bit = add_bit<counter5bit>;
    using counter7bit = add_bit<counter6bit>;
    using counter8bit = add_bit<counter7bit>;


    using counter9bit  = detail::add_bit<counter8bit>;
    using counter10bit = detail::add_bit<counter9bit>;
    using counter11bit = detail::add_bit<counter10bit>;
    using counter12bit = detail::add_bit<counter11bit>;
    using counter13bit = detail::add_bit<counter12bit>;
    using counter14bit = detail::add_bit<counter13bit>;
    using counter15bit = detail::add_bit<counter14bit>;
    using counter16bit = detail::add_bit<counter15bit>;

}

#endif
