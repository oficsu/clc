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
        constexpr bool toggle_impl(float) {
            return sizeof(infector<Tag, declarator<Tag>>);
        };

        template<typename Tag, unit = get(declarator<Tag>{})>
        constexpr bool toggle_impl(int) {
            return false;
        };

        template<std::size_t Value>
        using index = std::integral_constant<std::size_t, Value>;

        template<bool Value>
        using boolean = std::integral_constant<bool, Value>;

        template<typename Tag>
        using toggle = boolean<toggle_impl<Tag>(42)>;

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
        struct recursive_tag : index<Value + 1> {};

        struct bit {
            enum { max = 1 };

            template<
                typename Tag,
                typename Freezed = boolean<false>,
                std::size_t Value = partial_conditional_t<!Freezed::value, toggle, index<1>, recursive_tag<0, Tag>>::value
            >
            using next = index<Value>;
        };

        template<typename Nested = bit>
        struct add_bit {
            enum { max = Nested::max * 2 };

            template<typename Args, typename Freezed>
            using previous = typename Nested:: template next<Args, Freezed>;

            template<bool Freezed, typename Tag>
            using instantiate_for_false_only = partial_conditional_t<!Freezed, previous, index<Nested::max>, Tag, boolean<Freezed>>;

            template<
                typename Tag,
                typename Freezed = boolean<false>,
                std::size_t First  = instantiate_for_false_only<Freezed::value, recursive_tag<0, Tag>>::value,
                std::size_t Second = instantiate_for_false_only<bool ( First ), recursive_tag<1, Tag>>::value
            >
            using next = index<First + Second>;
        };

        template<std::size_t Width>
        struct bits : add_bit<bits<Width - 1>> {};

        template<>
        struct bits<0> : bit {};

        template<typename Nested>
        struct reverse {
            template<
                typename Tag,
                typename Freezed = boolean<false>,
                std::size_t Value = Nested:: template next<Tag, Freezed>::value
            >
            using next = index<Nested::max - Value>;
        };

        template <std::size_t Value>
        struct log2 : index<1 + log2<Value / 2>::value> {};

        template<> struct log2<1> : index<1> {};
    }

    struct default_counter_tag {};
    struct default_reverse_counter_tag {};

    template<
        typename Tag = default_counter_tag,
        std::size_t value = detail::reverse<detail::bits<16>>::next<Tag>()
    >
    constexpr std::size_t counter() { return value; }

    template<
        std::size_t InitialValue,
        typename Tag = default_reverse_counter_tag,
        typename BitWidth = detail::log2<InitialValue - 1>,
        typename Bits = typename detail::bits<BitWidth::value>,
        typename Index = typename Bits::template next<Tag>
    >
    constexpr std::size_t reverse_counter() {
        static_assert ((Index::value - (Bits::max - InitialValue)) <= InitialValue, "Overflow");
        return Index::value - (Bits::max - InitialValue);
    }
}

#endif
