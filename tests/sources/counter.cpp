//                 Curious Loopholed Counter
//
//                Copyright Ofee Oficsu 2021.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)
//
//        Project home: https://github.com/oficsu/clc

#include <clc.h>


// exactly a power of 2 - 1
namespace { struct counter_tag_7; }

static_assert(clc::counter<7, counter_tag_7>() == 0, "");
static_assert(clc::counter<7, counter_tag_7>() == 1, "");
static_assert(clc::counter<7, counter_tag_7>() == 2, "");
static_assert(clc::counter<7, counter_tag_7>() == 3, "");
static_assert(clc::counter<7, counter_tag_7>() == 4, "");
static_assert(clc::counter<7, counter_tag_7>() == 5, "");
static_assert(clc::counter<7, counter_tag_7>() == 6, "");
static_assert(clc::counter<7, counter_tag_7>() == 7, "");

#ifdef CLC_SHULD_NOT_COMPILE
namespace {
    auto should_not_compile_7 = clc::counter<7, counter_tag_7>();
}
#endif



// exactly a power of 2
namespace { struct counter_tag_8; }

static_assert(clc::counter<8, counter_tag_8>() == 0, "");
static_assert(clc::counter<8, counter_tag_8>() == 1, "");
static_assert(clc::counter<8, counter_tag_8>() == 2, "");
static_assert(clc::counter<8, counter_tag_8>() == 3, "");
static_assert(clc::counter<8, counter_tag_8>() == 4, "");
static_assert(clc::counter<8, counter_tag_8>() == 5, "");
static_assert(clc::counter<8, counter_tag_8>() == 6, "");
static_assert(clc::counter<8, counter_tag_8>() == 7, "");
static_assert(clc::counter<8, counter_tag_8>() == 8, "");

#ifdef CLC_SHULD_NOT_COMPILE
namespace {
    auto should_not_compile_8 = clc::counter<8, counter_tag_8>();
}
#endif



// exactly a power of 2 + 1
namespace { struct counter_tag_9; }

static_assert(clc::counter<9, counter_tag_9>() == 0, "");
static_assert(clc::counter<9, counter_tag_9>() == 1, "");
static_assert(clc::counter<9, counter_tag_9>() == 2, "");
static_assert(clc::counter<9, counter_tag_9>() == 3, "");
static_assert(clc::counter<9, counter_tag_9>() == 4, "");
static_assert(clc::counter<9, counter_tag_9>() == 5, "");
static_assert(clc::counter<9, counter_tag_9>() == 6, "");
static_assert(clc::counter<9, counter_tag_9>() == 7, "");
static_assert(clc::counter<9, counter_tag_9>() == 8, "");
static_assert(clc::counter<9, counter_tag_9>() == 9, "");

#ifdef  CLC_SHULD_NOT_COMPILE
namespace {
    auto should_not_compile_9 = clc::counter<9, counter_tag_9>();
}
#endif
