#include <clc.hpp>

static constexpr auto unit = clc::meta::unit::value;



namespace {
    struct assign_tag_0;
    struct assign_tag_1;
    struct assign_tag_2;
    struct assign_tag_3;
    struct assign_tag_4;
    struct assign_tag_5;
    struct assign_tag_6;
    struct assign_tag_7;
    struct assign_tag_8;
    struct assign_tag_9;
}

static_assert(clc::assign<assign_tag_0, 0>() == unit, "");
static_assert(clc::search<assign_tag_0>() == 0, "");

static_assert(clc::assign<assign_tag_1, 1>() == unit, "");
static_assert(clc::search<assign_tag_1>() == 1, "");

static_assert(clc::assign<assign_tag_2, 2>() == unit, "");
static_assert(clc::search<assign_tag_2>() == 2, "");

static_assert(clc::assign<assign_tag_3, 3>() == unit, "");
static_assert(clc::search<assign_tag_3>() == 3, "");

static_assert(clc::assign<assign_tag_4, 4>() == unit, "");
static_assert(clc::search<assign_tag_4>() == 4, "");

static_assert(clc::assign<assign_tag_5, 5>() == unit, "");
static_assert(clc::search<assign_tag_5>() == 5, "");

static_assert(clc::assign<assign_tag_6, 6>() == unit, "");
static_assert(clc::search<assign_tag_6>() == 6, "");

static_assert(clc::assign<assign_tag_7, 7>() == unit, "");
static_assert(clc::search<assign_tag_7>() == 7, "");

static_assert(clc::assign<assign_tag_8, 8>() == unit, "");
static_assert(clc::search<assign_tag_8>() == 8, "");

static_assert(clc::assign<assign_tag_9, 9>() == unit, "");
static_assert(clc::search<assign_tag_9>() == 9, "");



namespace {
    struct assign_tag_size_t_max;
    struct assign_tag_size_t_max_minus_1;
    struct assign_tag_size_t_max_minus_2;
    struct assign_tag_size_t_max_minus_3;
}

static_assert (clc::assign<assign_tag_size_t_max, std::size_t(-1)>() == clc::meta::unit::value, "");
static_assert (clc::search<assign_tag_size_t_max>() == std::size_t(-1), "");

static_assert (clc::assign<assign_tag_size_t_max_minus_1, std::size_t(-2)>() == clc::meta::unit::value, "");
static_assert (clc::search<assign_tag_size_t_max_minus_1>() == std::size_t(-2), "");

static_assert (clc::assign<assign_tag_size_t_max_minus_2, std::size_t(-3)>() == clc::meta::unit::value, "");
static_assert (clc::search<assign_tag_size_t_max_minus_2>() == std::size_t(-3), "");

static_assert (clc::assign<assign_tag_size_t_max_minus_3, std::size_t(-4)>() == clc::meta::unit::value, "");
static_assert (clc::search<assign_tag_size_t_max_minus_3>() == std::size_t(-4), "");



namespace { struct counter_like_tag; }

static_assert(clc::search<counter_like_tag>() == 0, "");
static_assert(clc::assign<counter_like_tag, 0>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 0, "");

static_assert(clc::assign<counter_like_tag, 1>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 1, "");

static_assert(clc::assign<counter_like_tag, 2>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 2, "");

static_assert(clc::assign<counter_like_tag, 3>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 3, "");

static_assert(clc::assign<counter_like_tag, 4>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 4, "");

static_assert(clc::assign<counter_like_tag, 5>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 5, "");

static_assert(clc::assign<counter_like_tag, 6>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 6, "");

static_assert(clc::assign<counter_like_tag, 7>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 7, "");

static_assert(clc::assign<counter_like_tag, 8>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 8, "");

static_assert(clc::assign<counter_like_tag, 9>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 9, "");

static_assert(clc::assign<counter_like_tag, 10>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 10, "");

static_assert(clc::assign<counter_like_tag, 11>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 11, "");

static_assert(clc::assign<counter_like_tag, 12>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 12, "");

static_assert(clc::assign<counter_like_tag, 13>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 13, "");

static_assert(clc::assign<counter_like_tag, 14>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 14, "");

static_assert(clc::assign<counter_like_tag, 15>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 15, "");

static_assert(clc::assign<counter_like_tag, 16>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 16, "");

static_assert(clc::assign<counter_like_tag, 17>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 17, "");

static_assert(clc::assign<counter_like_tag, 18>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 18, "");

static_assert(clc::assign<counter_like_tag, 19>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 19, "");

static_assert(clc::assign<counter_like_tag, 20>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 20, "");

static_assert(clc::assign<counter_like_tag, 21>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 21, "");

static_assert(clc::assign<counter_like_tag, 22>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 22, "");

static_assert(clc::assign<counter_like_tag, 23>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 23, "");

static_assert(clc::assign<counter_like_tag, 24>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 24, "");

static_assert(clc::assign<counter_like_tag, 25>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 25, "");

static_assert(clc::assign<counter_like_tag, 26>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 26, "");

static_assert(clc::assign<counter_like_tag, 27>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 27, "");

static_assert(clc::assign<counter_like_tag, 28>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 28, "");

static_assert(clc::assign<counter_like_tag, 29>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 29, "");

static_assert(clc::assign<counter_like_tag, 30>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 30, "");

static_assert(clc::assign<counter_like_tag, 31>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 31, "");

static_assert(clc::assign<counter_like_tag, 32>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 32, "");

static_assert(clc::assign<counter_like_tag, 33>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 33, "");

static_assert(clc::assign<counter_like_tag, 34>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 34, "");

static_assert(clc::assign<counter_like_tag, 35>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 35, "");

static_assert(clc::assign<counter_like_tag, 36>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 36, "");

static_assert(clc::assign<counter_like_tag, 37>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 37, "");

static_assert(clc::assign<counter_like_tag, 38>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 38, "");

static_assert(clc::assign<counter_like_tag, 39>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 39, "");

static_assert(clc::assign<counter_like_tag, 40>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 40, "");

static_assert(clc::assign<counter_like_tag, 41>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 41, "");

static_assert(clc::assign<counter_like_tag, 42>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 42, "");

static_assert(clc::assign<counter_like_tag, 43>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 43, "");

static_assert(clc::assign<counter_like_tag, 44>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 44, "");

static_assert(clc::assign<counter_like_tag, 45>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 45, "");

static_assert(clc::assign<counter_like_tag, 46>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 46, "");

static_assert(clc::assign<counter_like_tag, 47>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 47, "");

static_assert(clc::assign<counter_like_tag, 48>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 48, "");

static_assert(clc::assign<counter_like_tag, 49>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 49, "");

static_assert(clc::assign<counter_like_tag, 50>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 50, "");

static_assert(clc::assign<counter_like_tag, 51>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 51, "");

static_assert(clc::assign<counter_like_tag, 52>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 52, "");

static_assert(clc::assign<counter_like_tag, 53>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 53, "");

static_assert(clc::assign<counter_like_tag, 54>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 54, "");

static_assert(clc::assign<counter_like_tag, 55>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 55, "");

static_assert(clc::assign<counter_like_tag, 56>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 56, "");

static_assert(clc::assign<counter_like_tag, 57>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 57, "");

static_assert(clc::assign<counter_like_tag, 58>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 58, "");

static_assert(clc::assign<counter_like_tag, 59>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 59, "");

static_assert(clc::assign<counter_like_tag, 60>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 60, "");

static_assert(clc::assign<counter_like_tag, 61>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 61, "");

static_assert(clc::assign<counter_like_tag, 62>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 62, "");

static_assert(clc::assign<counter_like_tag, 63>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 63, "");

static_assert(clc::assign<counter_like_tag, 64>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 64, "");

static_assert(clc::assign<counter_like_tag, 65>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 65, "");

static_assert(clc::assign<counter_like_tag, 66>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 66, "");

static_assert(clc::assign<counter_like_tag, 67>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 67, "");

static_assert(clc::assign<counter_like_tag, 68>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 68, "");

static_assert(clc::assign<counter_like_tag, 69>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 69, "");

static_assert(clc::assign<counter_like_tag, 70>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 70, "");

static_assert(clc::assign<counter_like_tag, 71>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 71, "");

static_assert(clc::assign<counter_like_tag, 72>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 72, "");

static_assert(clc::assign<counter_like_tag, 73>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 73, "");

static_assert(clc::assign<counter_like_tag, 74>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 74, "");

static_assert(clc::assign<counter_like_tag, 75>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 75, "");

static_assert(clc::assign<counter_like_tag, 76>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 76, "");

static_assert(clc::assign<counter_like_tag, 77>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 77, "");

static_assert(clc::assign<counter_like_tag, 78>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 78, "");

static_assert(clc::assign<counter_like_tag, 79>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 79, "");

static_assert(clc::assign<counter_like_tag, 80>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 80, "");

static_assert(clc::assign<counter_like_tag, 81>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 81, "");

static_assert(clc::assign<counter_like_tag, 82>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 82, "");

static_assert(clc::assign<counter_like_tag, 83>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 83, "");

static_assert(clc::assign<counter_like_tag, 84>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 84, "");

static_assert(clc::assign<counter_like_tag, 85>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 85, "");

static_assert(clc::assign<counter_like_tag, 86>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 86, "");

static_assert(clc::assign<counter_like_tag, 87>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 87, "");

static_assert(clc::assign<counter_like_tag, 88>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 88, "");

static_assert(clc::assign<counter_like_tag, 89>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 89, "");

static_assert(clc::assign<counter_like_tag, 90>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 90, "");

static_assert(clc::assign<counter_like_tag, 91>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 91, "");

static_assert(clc::assign<counter_like_tag, 92>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 92, "");

static_assert(clc::assign<counter_like_tag, 93>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 93, "");

static_assert(clc::assign<counter_like_tag, 94>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 94, "");

static_assert(clc::assign<counter_like_tag, 95>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 95, "");

static_assert(clc::assign<counter_like_tag, 96>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 96, "");

static_assert(clc::assign<counter_like_tag, 97>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 97, "");

static_assert(clc::assign<counter_like_tag, 98>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 98, "");

static_assert(clc::assign<counter_like_tag, 99>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 99, "");

static_assert(clc::assign<counter_like_tag, 100>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 100, "");

static_assert(clc::assign<counter_like_tag, 101>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 101, "");

static_assert(clc::assign<counter_like_tag, 102>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 102, "");

static_assert(clc::assign<counter_like_tag, 103>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 103, "");

static_assert(clc::assign<counter_like_tag, 104>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 104, "");

static_assert(clc::assign<counter_like_tag, 105>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 105, "");

static_assert(clc::assign<counter_like_tag, 106>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 106, "");

static_assert(clc::assign<counter_like_tag, 107>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 107, "");

static_assert(clc::assign<counter_like_tag, 108>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 108, "");

static_assert(clc::assign<counter_like_tag, 109>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 109, "");

static_assert(clc::assign<counter_like_tag, 110>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 110, "");

static_assert(clc::assign<counter_like_tag, 111>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 111, "");

static_assert(clc::assign<counter_like_tag, 112>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 112, "");

static_assert(clc::assign<counter_like_tag, 113>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 113, "");

static_assert(clc::assign<counter_like_tag, 114>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 114, "");

static_assert(clc::assign<counter_like_tag, 115>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 115, "");

static_assert(clc::assign<counter_like_tag, 116>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 116, "");

static_assert(clc::assign<counter_like_tag, 117>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 117, "");

static_assert(clc::assign<counter_like_tag, 118>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 118, "");

static_assert(clc::assign<counter_like_tag, 119>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 119, "");

static_assert(clc::assign<counter_like_tag, 120>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 120, "");

static_assert(clc::assign<counter_like_tag, 121>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 121, "");

static_assert(clc::assign<counter_like_tag, 122>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 122, "");

static_assert(clc::assign<counter_like_tag, 123>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 123, "");

static_assert(clc::assign<counter_like_tag, 124>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 124, "");

static_assert(clc::assign<counter_like_tag, 125>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 125, "");

static_assert(clc::assign<counter_like_tag, 126>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 126, "");

static_assert(clc::assign<counter_like_tag, 127>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 127, "");

static_assert(clc::assign<counter_like_tag, 128>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 128, "");

static_assert(clc::assign<counter_like_tag, 129>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 129, "");

static_assert(clc::assign<counter_like_tag, 130>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 130, "");

static_assert(clc::assign<counter_like_tag, 131>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 131, "");

static_assert(clc::assign<counter_like_tag, 132>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 132, "");

static_assert(clc::assign<counter_like_tag, 133>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 133, "");

static_assert(clc::assign<counter_like_tag, 134>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 134, "");

static_assert(clc::assign<counter_like_tag, 135>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 135, "");

static_assert(clc::assign<counter_like_tag, 136>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 136, "");

static_assert(clc::assign<counter_like_tag, 137>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 137, "");

static_assert(clc::assign<counter_like_tag, 138>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 138, "");

static_assert(clc::assign<counter_like_tag, 139>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 139, "");

static_assert(clc::assign<counter_like_tag, 140>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 140, "");

static_assert(clc::assign<counter_like_tag, 141>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 141, "");

static_assert(clc::assign<counter_like_tag, 142>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 142, "");

static_assert(clc::assign<counter_like_tag, 143>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 143, "");

static_assert(clc::assign<counter_like_tag, 144>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 144, "");

static_assert(clc::assign<counter_like_tag, 145>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 145, "");

static_assert(clc::assign<counter_like_tag, 146>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 146, "");

static_assert(clc::assign<counter_like_tag, 147>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 147, "");

static_assert(clc::assign<counter_like_tag, 148>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 148, "");

static_assert(clc::assign<counter_like_tag, 149>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 149, "");

static_assert(clc::assign<counter_like_tag, 150>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 150, "");

static_assert(clc::assign<counter_like_tag, 151>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 151, "");

static_assert(clc::assign<counter_like_tag, 152>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 152, "");

static_assert(clc::assign<counter_like_tag, 153>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 153, "");

static_assert(clc::assign<counter_like_tag, 154>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 154, "");

static_assert(clc::assign<counter_like_tag, 155>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 155, "");

static_assert(clc::assign<counter_like_tag, 156>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 156, "");

static_assert(clc::assign<counter_like_tag, 157>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 157, "");

static_assert(clc::assign<counter_like_tag, 158>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 158, "");

static_assert(clc::assign<counter_like_tag, 159>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 159, "");

static_assert(clc::assign<counter_like_tag, 160>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 160, "");

static_assert(clc::assign<counter_like_tag, 161>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 161, "");

static_assert(clc::assign<counter_like_tag, 162>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 162, "");

static_assert(clc::assign<counter_like_tag, 163>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 163, "");

static_assert(clc::assign<counter_like_tag, 164>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 164, "");

static_assert(clc::assign<counter_like_tag, 165>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 165, "");

static_assert(clc::assign<counter_like_tag, 166>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 166, "");

static_assert(clc::assign<counter_like_tag, 167>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 167, "");

static_assert(clc::assign<counter_like_tag, 168>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 168, "");

static_assert(clc::assign<counter_like_tag, 169>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 169, "");

static_assert(clc::assign<counter_like_tag, 170>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 170, "");

static_assert(clc::assign<counter_like_tag, 171>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 171, "");

static_assert(clc::assign<counter_like_tag, 172>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 172, "");

static_assert(clc::assign<counter_like_tag, 173>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 173, "");

static_assert(clc::assign<counter_like_tag, 174>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 174, "");

static_assert(clc::assign<counter_like_tag, 175>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 175, "");

static_assert(clc::assign<counter_like_tag, 176>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 176, "");

static_assert(clc::assign<counter_like_tag, 177>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 177, "");

static_assert(clc::assign<counter_like_tag, 178>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 178, "");

static_assert(clc::assign<counter_like_tag, 179>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 179, "");

static_assert(clc::assign<counter_like_tag, 180>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 180, "");

static_assert(clc::assign<counter_like_tag, 181>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 181, "");

static_assert(clc::assign<counter_like_tag, 182>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 182, "");

static_assert(clc::assign<counter_like_tag, 183>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 183, "");

static_assert(clc::assign<counter_like_tag, 184>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 184, "");

static_assert(clc::assign<counter_like_tag, 185>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 185, "");

static_assert(clc::assign<counter_like_tag, 186>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 186, "");

static_assert(clc::assign<counter_like_tag, 187>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 187, "");

static_assert(clc::assign<counter_like_tag, 188>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 188, "");

static_assert(clc::assign<counter_like_tag, 189>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 189, "");

static_assert(clc::assign<counter_like_tag, 190>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 190, "");

static_assert(clc::assign<counter_like_tag, 191>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 191, "");

static_assert(clc::assign<counter_like_tag, 192>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 192, "");

static_assert(clc::assign<counter_like_tag, 193>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 193, "");

static_assert(clc::assign<counter_like_tag, 194>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 194, "");

static_assert(clc::assign<counter_like_tag, 195>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 195, "");

static_assert(clc::assign<counter_like_tag, 196>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 196, "");

static_assert(clc::assign<counter_like_tag, 197>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 197, "");

static_assert(clc::assign<counter_like_tag, 198>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 198, "");

static_assert(clc::assign<counter_like_tag, 199>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 199, "");

static_assert(clc::assign<counter_like_tag, 200>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 200, "");

static_assert(clc::assign<counter_like_tag, 201>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 201, "");

static_assert(clc::assign<counter_like_tag, 202>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 202, "");

static_assert(clc::assign<counter_like_tag, 203>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 203, "");

static_assert(clc::assign<counter_like_tag, 204>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 204, "");

static_assert(clc::assign<counter_like_tag, 205>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 205, "");

static_assert(clc::assign<counter_like_tag, 206>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 206, "");

static_assert(clc::assign<counter_like_tag, 207>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 207, "");

static_assert(clc::assign<counter_like_tag, 208>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 208, "");

static_assert(clc::assign<counter_like_tag, 209>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 209, "");

static_assert(clc::assign<counter_like_tag, 210>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 210, "");

static_assert(clc::assign<counter_like_tag, 211>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 211, "");

static_assert(clc::assign<counter_like_tag, 212>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 212, "");

static_assert(clc::assign<counter_like_tag, 213>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 213, "");

static_assert(clc::assign<counter_like_tag, 214>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 214, "");

static_assert(clc::assign<counter_like_tag, 215>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 215, "");

static_assert(clc::assign<counter_like_tag, 216>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 216, "");

static_assert(clc::assign<counter_like_tag, 217>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 217, "");

static_assert(clc::assign<counter_like_tag, 218>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 218, "");

static_assert(clc::assign<counter_like_tag, 219>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 219, "");

static_assert(clc::assign<counter_like_tag, 220>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 220, "");

static_assert(clc::assign<counter_like_tag, 221>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 221, "");

static_assert(clc::assign<counter_like_tag, 222>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 222, "");

static_assert(clc::assign<counter_like_tag, 223>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 223, "");

static_assert(clc::assign<counter_like_tag, 224>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 224, "");

static_assert(clc::assign<counter_like_tag, 225>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 225, "");

static_assert(clc::assign<counter_like_tag, 226>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 226, "");

static_assert(clc::assign<counter_like_tag, 227>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 227, "");

static_assert(clc::assign<counter_like_tag, 228>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 228, "");

static_assert(clc::assign<counter_like_tag, 229>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 229, "");

static_assert(clc::assign<counter_like_tag, 230>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 230, "");

static_assert(clc::assign<counter_like_tag, 231>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 231, "");

static_assert(clc::assign<counter_like_tag, 232>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 232, "");

static_assert(clc::assign<counter_like_tag, 233>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 233, "");

static_assert(clc::assign<counter_like_tag, 234>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 234, "");

static_assert(clc::assign<counter_like_tag, 235>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 235, "");

static_assert(clc::assign<counter_like_tag, 236>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 236, "");

static_assert(clc::assign<counter_like_tag, 237>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 237, "");

static_assert(clc::assign<counter_like_tag, 238>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 238, "");

static_assert(clc::assign<counter_like_tag, 239>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 239, "");

static_assert(clc::assign<counter_like_tag, 240>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 240, "");

static_assert(clc::assign<counter_like_tag, 241>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 241, "");

static_assert(clc::assign<counter_like_tag, 242>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 242, "");

static_assert(clc::assign<counter_like_tag, 243>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 243, "");

static_assert(clc::assign<counter_like_tag, 244>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 244, "");

static_assert(clc::assign<counter_like_tag, 245>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 245, "");

static_assert(clc::assign<counter_like_tag, 246>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 246, "");

static_assert(clc::assign<counter_like_tag, 247>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 247, "");

static_assert(clc::assign<counter_like_tag, 248>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 248, "");

static_assert(clc::assign<counter_like_tag, 249>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 249, "");

static_assert(clc::assign<counter_like_tag, 250>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 250, "");

static_assert(clc::assign<counter_like_tag, 251>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 251, "");

static_assert(clc::assign<counter_like_tag, 252>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 252, "");

static_assert(clc::assign<counter_like_tag, 253>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 253, "");

static_assert(clc::assign<counter_like_tag, 254>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 254, "");

static_assert(clc::assign<counter_like_tag, 255>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 255, "");

static_assert(clc::assign<counter_like_tag, 256>() == unit, "");
static_assert(clc::search<counter_like_tag>() == 256, "");
