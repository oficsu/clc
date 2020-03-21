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
#include <boost/preprocessor.hpp>

namespace clc
{
    namespace detail
    {
        template<
            std::size_t GeneratorID,
            std::size_t V>
        struct declarator {
            enum {
                value = V
            };
            friend constexpr std::size_t get(declarator<GeneratorID, V>);
        };

        template<
            std::size_t GeneratorID,
            typename Src>
        struct infector {
            friend constexpr std::size_t get(Src) {
                return Src::value + 1;
            }
        };

        template<
            std::size_t GeneratorID,
            std::size_t Index = 0>
        constexpr auto up_to_one(float k) -> std::size_t {
            using t = decltype(infector<GeneratorID, declarator<GeneratorID, Index>>{});
            return get(declarator<GeneratorID, Index>()) + static_cast<std::size_t>(k);
        };

        template<
            std::size_t GeneratorID,
            std::size_t Index = 0,
            std::size_t Next = get(declarator<GeneratorID, Index>{})>
        constexpr std::size_t up_to_one(int i) {
            return up_to_one<GeneratorID, Next>(i);
        };

        #ifndef CURIOUS_LOOPHOLED_COUNTER_LIMIT
            #define CURIOUS_LOOPHOLED_COUNTER_LIMIT 45
        #endif

        #define CURIOUS_LOOPHOLED_COUNTER_SUM(z, n, data)  + _##n
        #define CURIOUS_LOOPHOLED_COUNTER_UP_TO_ONE_SEQUENCE(z, n, data) size_t _##n = up_to_one<0+ BOOST_PP_REPEAT(n, CURIOUS_LOOPHOLED_COUNTER_SUM,)>(n),
        #define CURIOUS_LOOPHOLED_COUNTER_SEQUENCE(n) BOOST_PP_REPEAT_FROM_TO(1, n, CURIOUS_LOOPHOLED_COUNTER_UP_TO_ONE_SEQUENCE, 1)

        constexpr std::size_t offset = ((2 + CURIOUS_LOOPHOLED_COUNTER_LIMIT - 1) * CURIOUS_LOOPHOLED_COUNTER_LIMIT) / 2 + 1;

        template<
            std::size_t _0 = up_to_one<0>(1),
            CURIOUS_LOOPHOLED_COUNTER_SEQUENCE(CURIOUS_LOOPHOLED_COUNTER_LIMIT)
            std::size_t = 0>
        constexpr std::size_t up_to_limit() {
            return _0 BOOST_PP_REPEAT_FROM_TO(1, CURIOUS_LOOPHOLED_COUNTER_LIMIT, CURIOUS_LOOPHOLED_COUNTER_SUM,) - offset;
        };

    }

    template<std::size_t Value = detail::up_to_limit()>
    constexpr std::size_t counter() {
        static_assert (Value < CURIOUS_LOOPHOLED_COUNTER_LIMIT, "You can't call this function more times than CURIOUS_LOOPHOLED_COUNTER_LIMIT - 1");
        return Value;
    }
}

#endif
