#                 Curious Loopholed Counter
#
#             Copyright Ofee Oficsu 2020 - 2022.
# Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           https://www.boost.org/LICENSE_1_0.txt)
#
#        Project home: https://github.com/oficsu/clc

cmake_minimum_required(VERSION 3.5)

project(clc VERSION 1.0.0 LANGUAGES CXX)

option(CLC_BUILD_TESTING  "Build the unit tests when BUILD_TESTING is enabled" ON)
option(CLC_BUILD_EXAMPLES "Build examples"                                     ON)
option(CLC_INSTALL        "Install CMake targets during install step"          ON)

include(GNUInstallDirs)

set(CLC_PROJECT_NAME                   "${PROJECT_NAME}")
set(CLC_CONFIG_INSTALL_DIR             "${CMAKE_INSTALL_LIBDIR}/cmake/${CLC_PROJECT_NAME}" CACHE INTERNAL "")
set(CLC_INCLUDE_INSTALL_DIR            "${CMAKE_INSTALL_INCLUDEDIR}")
set(CLC_TARGETS_EXPORT_NAME            "${CLC_PROJECT_NAME}-targets")
set(CLC_CMAKE_VERSION_CONFIG_FILE_NAME "${CLC_PROJECT_NAME}-config-version.cmake")
set(CLC_CMAKE_PROJECT_CONFIG_FILE_NAME "${CLC_PROJECT_NAME}-config.cmake")
set(CLC_CMAKE_CONFIG_DIR               "${CMAKE_CURRENT_BINARY_DIR}")
set(CLC_CMAKE_VERSION_CONFIG_FILE      "${CLC_CMAKE_CONFIG_DIR}/${CLC_CMAKE_VERSION_CONFIG_FILE_NAME}")
set(CLC_CMAKE_PROJECT_CONFIG_FILE      "${CLC_CMAKE_CONFIG_DIR}/${CLC_PROJECT_NAME}-config.cmake")
set(CLC_CMAKE_PROJECT_TARGETS_FILE     "${CLC_CMAKE_CONFIG_DIR}/${CLC_PROJECT_NAME}-targets.cmake")
set(CLC_PKGCONFIG_INSTALL_DIR          "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
set(CLC_CMAKE_CONFIG_TEMPLATE          "cmake/config.cmake.in")

set(HEADER include/clc.hpp)
set(DOCS   README.md LICENSE.txt)
set(PACKAGING
    cmake/config.cmake.in
    cmake/pkg-config.pc.in)

source_group(header FILES ${HEADER})
source_group(packaging FILES ${PACKAGING})

add_custom_target(clc_sources SOURCES ${HEADER} ${DOCS} ${PACKAGING})

add_library(${CLC_PROJECT_NAME} INTERFACE)
add_library(${CLC_PROJECT_NAME}::${CLC_PROJECT_NAME} ALIAS ${CLC_PROJECT_NAME})

target_compile_features(${CLC_PROJECT_NAME} INTERFACE cxx_std_11)

target_include_directories(${CLC_PROJECT_NAME}
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

include(CTest)

if(BUILD_TESTING AND CLC_BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()


if(CLC_INSTALL)
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/pkg-config.pc.in"
                   "${CMAKE_CURRENT_BINARY_DIR}/${CLC_PROJECT_NAME}.pc")

    include(CMakePackageConfigHelpers)

    configure_package_config_file("${CLC_CMAKE_CONFIG_TEMPLATE}"
                                 "${CLC_CMAKE_PROJECT_CONFIG_FILE}"
                                 INSTALL_DESTINATION
                                     "${CLC_CONFIG_INSTALL_DIR}/${CLC_CMAKE_PROJECT_CONFIG_FILE_NAME}")


    write_basic_package_version_file("${CLC_CMAKE_VERSION_CONFIG_FILE}"
                                    VERSION ${PROJECT_VERSION}
                                    COMPATIBILITY AnyNewerVersion)

    install(FILES       ${HEADER}
            DESTINATION ${CLC_INCLUDE_INSTALL_DIR})

    export(TARGETS ${CLC_PROJECT_NAME}
           NAMESPACE ${CLC_PROJECT_NAME}::
           FILE ${CLC_CMAKE_PROJECT_TARGETS_FILE})

    install(TARGETS ${CLC_PROJECT_NAME}
            EXPORT ${CLC_TARGETS_EXPORT_NAME}
            DESTINATION ${CLC_INCLUDE_INSTALL_DIR})

    install(EXPORT ${CLC_TARGETS_EXPORT_NAME}
            NAMESPACE ${CLC_PROJECT_NAME}::
            DESTINATION ${CLC_CONFIG_INSTALL_DIR})

    install(FILES ${CLC_CMAKE_PROJECT_CONFIG_FILE}
                  ${CLC_CMAKE_VERSION_CONFIG_FILE}
           DESTINATION ${CLC_CONFIG_INSTALL_DIR})

    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${CLC_PROJECT_NAME}.pc"
            DESTINATION ${CLC_PKGCONFIG_INSTALL_DIR})
endif()

if(CLC_BUILD_EXAMPLES)
    add_subdirectory("examples")
endif()
