Curious Loopholed Counter
=========================

This library exploits C++ loophole to allow different template instantiation each time in C++11

Dependencies
------------

There are no dependencies from now

Supported Compilers
-------------------

The code is known to work on the following compilers:

- Clang 3.4.1 (or later)
- GCC 4.7.1 (or later)
- MSVC v19.14 (or later, or maybe earlier)
- ICC 18.0 (or later)

**Development Status:** This code is not stable or well-tested. No promise is made about support or long-term stability. This code *will* evolve without regard to backwards compatibility.

Building
--------

```bash
git clone https://github.com/oficsu/clc
cd clc
mkdir build && cd build
cmake -D CMAKE_INSTALL_PREFIX=/opt/clc ..
cmake --build . --target install
```

Licensed under the [Boost Software License](LICENSE.txt)
--------------------------------------------------------
