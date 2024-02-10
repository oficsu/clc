//                 Curious Loopholed Counter
//
//             Copyright Ofee Oficsu 2021 - 2024.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)
//
//        Project home: https://github.com/oficsu/clc

#include <clc.hpp>


// exactly a power of 2 - 1
namespace { struct reverse_counter_tag_3; }

static_assert(clc::reverse_counter<3, reverse_counter_tag_3>() == 3, "starts at the specified value");
static_assert(clc::reverse_counter<3, reverse_counter_tag_3>() == 2, "and keeps decrementing...");
static_assert(clc::reverse_counter<3, reverse_counter_tag_3>() == 1, "");
static_assert(clc::reverse_counter<3, reverse_counter_tag_3>() == 0, "then stops at 0");

#ifdef CLC_SHULD_NOT_COMPILE
namespace {
    auto should_not_compile_3 = clc::reverse_counter<3, reverse_counter_tag_3>();
}
#endif



// exactly a power of 2
namespace { struct counter_tag_4; }

static_assert(clc::reverse_counter<4, counter_tag_4>() == 4, "");
static_assert(clc::reverse_counter<4, counter_tag_4>() == 3, "");
static_assert(clc::reverse_counter<4, counter_tag_4>() == 2, "");
static_assert(clc::reverse_counter<4, counter_tag_4>() == 1, "");
static_assert(clc::reverse_counter<4, counter_tag_4>() == 0, "");

#ifdef CLC_SHULD_NOT_COMPILE
namespace {
    auto should_not_compile_4 = clc::reverse_counter<4, reverse_counter_tag_4>();
}
#endif




// exactly a power of 2 + 1
namespace { struct counter_tag_5; }

static_assert(clc::reverse_counter<5>() == 5, "");
static_assert(clc::reverse_counter<5>() == 4, "");
static_assert(clc::reverse_counter<5>() == 3, "");
static_assert(clc::reverse_counter<5>() == 2, "");
static_assert(clc::reverse_counter<5>() == 1, "");
static_assert(clc::reverse_counter<5>() == 0, "");

#ifdef CLC_SHULD_NOT_COMPILE
namespace {
    auto should_not_compile_5 = clc::reverse_counter<5, reverse_counter_tag_5>();
}
#endif
