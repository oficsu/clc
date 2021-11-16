//                 Curious Loopholed Counter
//
//                Copyright Ofee Oficsu 2021.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)
//
//        Project home: https://github.com/oficsu/clc

#include <clc.hpp>

// for illustration purposes only:
#define assert(expr) void(expr)

int main()
{
    // what does this library allow?
    assert(clc::counter() != clc::counter());

    // nothing special, right? but... how about the next one?
    static_assert(clc::counter() != clc::counter(), "The results are different");
    static_assert(clc::counter() == 4, "The result is now 4, and then...");
    static_assert(clc::counter() == 5, "5! It's magic");
}
