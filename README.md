Curious Loopholed Counter
=========================

This library exploits C++ loophole to allow different template instantiation each time in C++11

Dependencies
------------

There are no dependencies from now

Example
-------

What does this library allow?
```cpp
assert(clc::counter() != clc::counter());
```
Nothing special, right? But... How about the next one?
```cpp
static_assert(clc::counter() != clc::counter(), "The results are different");
static_assert(clc::counter() == 2, "The result is now 2, and then...");
static_assert(clc::counter() == 3, "3! It's magic");
```

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
