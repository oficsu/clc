//                 Curious Loopholed Counter
//
//             Copyright Ofee Oficsu 2021 - 2024.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)
//
//        Project home: https://github.com/oficsu/clc

#include <clc.hpp>

int main()
{
    // so how can we have two or more independent counters?
    // the answer is simple, use unique tags:
    struct my_tag;
    struct my_other_tag;

    static_assert(clc::counter<my_tag>() == 0, "this is 0");
    static_assert(clc::counter<my_tag>() == 1, "increment for my_tag");
    static_assert(clc::counter<my_other_tag>() == 0, "but this one is still 0");

    // or you can use variables:
    using my_var = clc::variable<>;
    using my_other_var = clc::variable<>;

    static_assert(my_var::increment() == 1, "returns actual value");
    static_assert(my_other_var::increment() == 1, "it is 1 too");

    static_assert(my_other_var::increment() == 2, "no, incrementing is not broken");

    // see variables.cpp for how this work and more examples
}
