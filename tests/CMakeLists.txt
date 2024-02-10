#                 Curious Loopholed Counter
#
#             Copyright Ofee Oficsu 2021 - 2024.
# Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           https://www.boost.org/LICENSE_1_0.txt)
#
#        Project home: https://github.com/oficsu/clc

set(TESTS "main"
          "counter"
          "decrementable_range_counter"
          "incrementable_range_counter"
          "reverse_counter"
          "assign")


foreach(TEST_SOURCE ${TESTS})
    list(APPEND TEST_SOURCES "sources/${TEST_SOURCE}.cpp")
endforeach()

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests ${CLC_PROJECT_NAME}::${CLC_PROJECT_NAME})

set_target_properties(tests PROPERTIES CXX_STANDARD 11)

include(CTest)

add_test(NAME "tests" COMMAND tests)

source_group(sources FILES ${TEST_SOURCES})
