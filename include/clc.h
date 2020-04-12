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
        constexpr bool binary_descending() {
            return value;
        };

        struct force_true {};

        template<typename Tag,
                 bool Freezed,
                 bool value = binary_descending_impl<typename std::conditional<Freezed, force_true, Tag>::type>(42)
        >
        constexpr bool toggleable_binary_descending() {
            return Freezed ? true : value;
        };

        template<std::size_t Value, typename>
        struct tagged_tag : std::integral_constant<std::size_t, Value + 1> {};

        struct nothing : std::integral_constant<std::size_t, 0> {};

        struct bit {
            template<
                typename Tag = default_tag,
                bool Freezed = false,
                std::size_t _0 = toggleable_binary_descending<tagged_tag<0, Tag>, Freezed>(),
                std::size_t _1 = toggleable_binary_descending<tagged_tag<1, Tag>, !!_0>()
            >
            struct information : std::integral_constant<std::size_t, _0 + _1> {

            };
        };

        template<typename Inner = bit>
        struct add_bit {
            template<
                typename Tag = default_tag,
                bool Freezed = false,
                std::size_t _0 = Inner::template information<tagged_tag<0, Tag>, Freezed>::value,
                std::size_t _1 = Inner::template information<tagged_tag<1, Tag>,  !!_0 >::value
            >
            struct information : std::integral_constant<std::size_t, _0 + _1> {

            };
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
    /*
        using counter9bit  = detail::add_bit<counter8bit>;
        using counter10bit = detail::add_bit<counter9bit>;
        using counter11bit = detail::add_bit<counter10bit>;
        using counter12bit = detail::add_bit<counter11bit>;
        using counter13bit = detail::add_bit<counter12bit>;
        using counter14bit = detail::add_bit<counter13bit>;
        using counter15bit = detail::add_bit<counter14bit>;
        using counter16bit = detail::add_bit<counter15bit>;
    */
}

#endif
