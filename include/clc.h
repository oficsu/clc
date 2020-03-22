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
        template<
            typename Tag,
            std::size_t V>
        struct declarator {
            enum {
                value = V
            };
            friend constexpr std::size_t get(declarator<Tag, V>);
        };

        template<
            typename Tag,
            typename Src>
        struct infector {
            friend constexpr std::size_t get(Src) {
                return Src::value + 1;
            }
        };

        template<
            typename Tag,
            std::size_t Index = 0>
        constexpr auto up_to_one(float k) -> std::size_t {
            using t = decltype(infector<Tag, declarator<Tag, Index>>{});
            return get(declarator<Tag, Index>()) + static_cast<std::size_t>(k);
        };

        template<
            typename Tag,
            std::size_t Index = 0,
            std::size_t Next = get(declarator<Tag, Index>{})>
        constexpr std::size_t up_to_one(int i) {
            return up_to_one<Tag, Next>(i);
        };

        template<typename InnerTag, std::size_t Number>
        struct tag {};

        struct force_null {};

        template<typename Tag>
        struct is_null_forced {
            enum { value = 0 };
        };

        template<>
        struct is_null_forced<force_null> {
            enum { value = 1 };
        };

        template<typename T1, typename T2>
        constexpr inline std::size_t summator(const T1& t1, const T2& t2) {
            return t1 + t2;
        }

        template<typename T1, typename... T2>
        constexpr inline std::size_t summator(const T1& t1, const T2&... t2) {
            return t1 + summator(t2...);
        }

        template<typename Tag, std::size_t Offset, std::size_t... Values>
        struct summary_with_offset {
            enum { value = is_null_forced<Tag>::value ? 0 : summator(Values...) - Offset };
        };

        template<typename Tag, std::size_t... Values>
        struct summary : summary_with_offset <Tag, 0, Values...> {};

        template<
            typename Tag,
            std::size_t _0 = up_to_one<tag<Tag, 0>>(1),
            std::size_t _1 = up_to_one<tag<Tag, _0>>(2),
            std::size_t _2 = up_to_one<tag<Tag, _0 + _1>>(3),
            std::size_t _3 = up_to_one<tag<Tag, _2 + _1 + _0>>(4),
            std::size_t _4 = up_to_one<tag<Tag, _3 + _2 + _1 + _0>>(5),
            std::size_t _5 = up_to_one<tag<Tag, _4 + _3 + _2 + _1 + _0>>(6),
            std::size_t _6 = up_to_one<tag<Tag, _5 + _4 + _3 + _2 + _1 + _0>>(7),
            std::size_t _7 = up_to_one<tag<Tag, _6 + _5 + _4 + _3 + _2 + _1 + _0>>(8),
            std::size_t _8 = up_to_one<tag<Tag, _7 + _6 + _5 + _4 + _3 + _2 + _1 + _0>>(9)>
        constexpr std::size_t up_to_9() {
            return summary_with_offset<Tag, 54, _0, _1, _2, _3, _4, _5, _6, _7, _8>::value;
        };

        template<std::size_t Expected, std::size_t Now, typename Tag>
        using wait_for = typename std::conditional<(Now < Expected), force_null, Tag>::type;

        template<std::size_t Index, typename Tag>
        using wait_for_9 = wait_for<9, Index, Tag>;// typename std::conditional<(Index < 9), force_null, Tag>::type;

        template<
            typename Tag,
            std::size_t _0 = up_to_9<wait_for_9<9,  tag<Tag, 1>>>(),
            std::size_t _1 = up_to_9<wait_for_9<_0, tag<Tag, 2>>>(),
            std::size_t _2 = up_to_9<wait_for_9<_1, tag<Tag, 3>>>(),
            std::size_t _3 = up_to_9<wait_for_9<_2, tag<Tag, 4>>>(),
            std::size_t _4 = up_to_9<wait_for_9<_3, tag<Tag, 5>>>(),
            std::size_t _5 = up_to_9<wait_for_9<_4, tag<Tag, 6>>>(),
            std::size_t _6 = up_to_9<wait_for_9<_5, tag<Tag, 7>>>(),
            std::size_t _7 = up_to_9<wait_for_9<_6, tag<Tag, 8>>>(),
            std::size_t _8 = up_to_9<wait_for_9<_7, tag<Tag, 9>>>()>
        constexpr std::size_t up_to_81() {
            return summary<Tag, _0, _1, _2, _3, _4, _5, _6, _7, _8>::value;
        };

        template<std::size_t Index, typename Tag>
        using wait_for_81 = wait_for<81, Index, Tag>;

        template<
            typename Tag,
            std::size_t _0 = up_to_81<wait_for_81<81, tag<Tag, 1>>>(),
            std::size_t _1 = up_to_81<wait_for_81<_0, tag<Tag, 2>>>(),
            std::size_t _2 = up_to_81<wait_for_81<_1, tag<Tag, 3>>>(),
            std::size_t _3 = up_to_81<wait_for_81<_2, tag<Tag, 4>>>(),
            std::size_t _4 = up_to_81<wait_for_81<_3, tag<Tag, 5>>>(),
            std::size_t _5 = up_to_81<wait_for_81<_4, tag<Tag, 6>>>(),
            std::size_t _6 = up_to_81<wait_for_81<_5, tag<Tag, 7>>>(),
            std::size_t _7 = up_to_81<wait_for_81<_6, tag<Tag, 8>>>(),
            std::size_t _8 = up_to_81<wait_for_81<_7, tag<Tag, 9>>>()>
        constexpr std::size_t up_to_729() {
            return summary<Tag, _0, _1, _2, _3, _4, _5, _6, _7, _8>::value;
        };

        template<std::size_t Index, typename Tag>
        using wait_for_729 = typename std::conditional<(Index < 729), force_null, Tag>::type;

        template<
            typename Tag,
            std::size_t _0 = up_to_729<wait_for_729<729, tag<Tag, 1>>>(),
            std::size_t _1 = up_to_729<wait_for_729<_0,  tag<Tag, 2>>>(),
            std::size_t _2 = up_to_729<wait_for_729<_1,  tag<Tag, 3>>>(),
            std::size_t _3 = up_to_729<wait_for_729<_2,  tag<Tag, 4>>>(),
            std::size_t _4 = up_to_729<wait_for_729<_3,  tag<Tag, 5>>>(),
            std::size_t _5 = up_to_729<wait_for_729<_4,  tag<Tag, 6>>>(),
            std::size_t _6 = up_to_729<wait_for_729<_5,  tag<Tag, 7>>>(),
            std::size_t _7 = up_to_729<wait_for_729<_6,  tag<Tag, 8>>>(),
            std::size_t _8 = up_to_729<wait_for_729<_7,  tag<Tag, 9>>>()>
        constexpr std::size_t up_to_6561() {
            return summary<Tag, _0, _1, _2, _3, _4, _5, _6, _7, _8>::value;
        };
    }

    struct default_tag {};
    struct default_unique_tag {};
    struct default_largest_tag {};

    template<std::size_t Value = detail::up_to_729<default_tag>()>
    constexpr std::size_t default_counter() {
        static_assert(
            Value != 729,
            "This counter is limited by 729, please use larger counter, "
            "but this will require more time to compile");

        return Value;
    }

    template<std::size_t Value = detail::up_to_6561<default_largest_tag>()>
    constexpr std::size_t largest_counter() {
        static_assert(
            Value != 6561,
            "This counter is limited by 6561. "
            "Maybe you need to use different counters "
            "or counters with different tags?");

        return Value;
    }

    template<std::size_t = detail::up_to_729<default_unique_tag>()>
    struct unique {};
}

#endif
