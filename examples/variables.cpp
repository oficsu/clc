//                 Curious Loopholed Counter
//
//             Copyright Ofee Oficsu 2021 - 2024.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)
//
//        Project home: https://github.com/oficsu/clc

#include <clc.hpp>

// as mentioned in tags.cpp, we can have many unique variables
using my_var = clc::variable<>;
using my_other_var = clc::variable<>;

static_assert(
    ! std::is_same<my_var, my_other_var>::value
    , "same declaration, but different types");

// why it works? do you remember that we have a _constexpr_ counter?
// and so... _constexpr_ variables can be non-type template parameter

// mix both:
template<std::size_t>
struct naive_unique_type {};

static_assert(
    ! std::is_same<
           naive_unique_type<clc::counter()>,
           naive_unique_type<clc::counter()>
       >::value
    , "the types of course different");

// can we express this better? just place counter() as default parameter:
// (this example can fire on gcc < 5.1, but generally it works)
template<std::size_t = clc::counter()>
struct defective_unique_type {};

// ooops! this might also fire even if the above is compiled:
// static_assert(std::is_same<defective_unique_type<>, defective_unique_type<>>::value);

// well, how's that? why?
// it is because compilers see std::size_t = clc::counter() in
// the template definition. this default parameter is not dependent
// on another parameter and compilers can call counter() immediately

// and that's the best you can do? no, of course not!
// deceive the ~~world~~ compiler.
// the ~~world~~ compiler can be tricked.

// the key word here is 'dependent', let me do it:
template<typename DoesNotMatter = void, std::size_t = clc::counter<DoesNotMatter>()>
struct true_unique_type {};

static_assert(
    ! std::is_same<true_unique_type<>, true_unique_type<>>::value
    , "the types of course different");


// for a few examples of clc::variable usage, see main() below



int main()
{
    // creates new variable
    using var = clc::variable<>;

    // assign 42 to variable:
    var::assign<42>();

    // check actual value:
    static_assert(var::value() == 42, "var is 42 now");

    var::assign<128>();
    static_assert(var::value() == 128, "it can be greater...");

    var::assign<0>();
    static_assert(var::value() == 0, "or lesser");

    static_assert(var::increment() == 1, "also it can be incremented");
    static_assert(var::increment() == 2, "more...");
    static_assert(var::increment() == 3, "and more...");
}

