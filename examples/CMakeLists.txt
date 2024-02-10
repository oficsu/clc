#                 Curious Loopholed Counter
#
#             Copyright Ofee Oficsu 2021 - 2024.
# Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           https://www.boost.org/LICENSE_1_0.txt)
#
#        Project home: https://github.com/oficsu/clc

project(example)

set(SOURCES variables
            counter
            tags)

source_group(example REGULAR_EXPRESSION .*)

foreach(SOURCE ${SOURCES})
    add_executable(${SOURCE}_example ${SOURCE}.cpp)

    set_property(TARGET ${SOURCE}_example PROPERTY CXX_STANDARD 11)
    set_property(TARGET ${SOURCE}_example PROPERTY CXX_EXTENSIONS OFF)

    target_link_libraries(${SOURCE}_example clc::clc)
endforeach()


