import os
from conan import ConanFile
from conan.tools.files import copy
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import cmake_layout, CMake

class CLCConan(ConanFile):
    name = "clc"
    version = "1.0"
    settings = "os", "arch", "compiler", "build_type"
    exports_sources = "*"
    no_copy_source = True
    generators = "CMakeToolchain", "CMakeDeps"

    def validate(self):
        check_min_cppstd(self, 11)

    def layout(self):
        cmake_layout(self)

    def build(self):
        if not self.conf.get("tools.build:skip_test", default=False):
            cmake = CMake(self)
            cmake.configure(build_script_folder=".")
            # tests are compile-time
            cmake.build()

    def package(self):
        copy(self, "*.hpp", self.source_folder, self.package_folder)

    def package_info(self):
        # for header-only packages, libdirs and bindirs are
        # not used so it's necessary to set those as empty.
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []

    def package_id(self):
        self.info.clear()
