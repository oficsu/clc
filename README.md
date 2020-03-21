Curious Loopholed Counter
=========================

This library exploits C++ loophole to allow different template instantiation each time in C++11

Dependencies
------------

Now we use [Boost Preprocessor](https://www.boost.org/doc/libs/release/libs/preprocessor/) for generate some internal boilerplate code

Supported Compilers
-------------------

he code is known to work on the following compilers:

- clang 3.9 (or later)
- GCC 7.1 (or later)

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
