//                 Curious Loopholed Counter
//
//             Copyright Ofee Oficsu 2020 - 2024.
//            Copyright webreh (t.me/webreh) 2021.
//                 Copyright Malibushko 2020.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)
//
//        Project home: https://github.com/oficsu/clc

#ifndef CURIOUS_LOOPHOLED_COUNTER_HPP
#define CURIOUS_LOOPHOLED_COUNTER_HPP

#include <type_traits>

#ifdef __GNUC__
    #pragma GCC diagnostic push

    #ifdef __clang__
        #pragma clang diagnostic ignored "-Wundefined-internal"
    #endif

    #if not defined(__clang__)
        #pragma GCC diagnostic ignored "-Wnon-template-friend"
    #endif
#endif

#ifdef __INTEL_COMPILER
    #pragma warning ( push )
    #pragma warning ( disable:1624 )
    #pragma warning ( disable:114 )
#endif

// definitely not the best solution
#if (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L) || __cplusplus >= 202002L
    #ifdef __clang__
        #if __clang_major__ >= 13
            #define CLC_HAS_LAMBDAS_IN_UNEVALUATED_CONTEXTS
        #endif
    #elif  defined(__GNUC__)
        #if __GNUC__ >= 10
            #define CLC_HAS_LAMBDAS_IN_UNEVALUATED_CONTEXTS
        #endif
    #elif defined(_MSC_VER)
        #if _MSC_VER >= 1928
            #define CLC_HAS_LAMBDAS_IN_UNEVALUATED_CONTEXTS
        #endif
    #elif defined(__INTEL_COMPILER)
        #if __INTEL_COMPILER >= 2021
            #define CLC_HAS_LAMBDAS_IN_UNEVALUATED_CONTEXTS
        #endif
    #elif defined(__EDG_VERSION__)
        #if __EDG_VERSION__ >= 501
            #define CLC_HAS_LAMBDAS_IN_UNEVALUATED_CONTEXTS
        #endif
    #endif
#endif

namespace clc
{
    namespace meta
    {
        enum class unit { value };
    }

    namespace detail
    {
        namespace type_loophole
        {
            namespace
            {
                template<typename Tag>
                struct flag {
                    friend constexpr meta::unit get(flag);
                };

                template<typename Tag, typename Flag>
                struct writer {
                    friend constexpr meta::unit get(Flag) {
                        return meta::unit::value;
                    }
                };
            }

            template<typename Tag>
            static constexpr bool read(...) {
                return false;
            };

            template<
                typename Tag,
                typename..., // private variable:
                    meta::unit = get(flag<Tag>{})>
            static constexpr bool read(meta::unit) {
                return true;
            };

            template<typename Tag>
            static constexpr bool toggle_impl(...) {
                return !sizeof(writer<Tag, flag<Tag>>);
            };

            template<
                typename Tag,
                typename..., // private variable:
                    meta::unit = get(flag<Tag>{})>
            static constexpr bool toggle_impl(meta::unit) {
                return true;
            };
        }

        template<
            typename Tag,
            typename..., // private variable:
                bool Result = type_loophole::read<Tag>(meta::unit::value)>
        static constexpr bool read() {
            return Result;
        };

        template<
            typename Tag,
            typename..., // private variable:
                bool Result = type_loophole::toggle_impl<Tag>(meta::unit::value)>
        static constexpr bool toggle() { return Result; }

        // why toggle rather than something
        // like a non-overloaded type_loophole::set?
        //
        // consult with clang        '"\_( ''_ )_/"'
        template<
            typename Tag,
            typename..., // private variable:
                bool = toggle<Tag>()>
        static constexpr meta::unit set() {
            return meta::unit::value;
        };
    }

    namespace meta
    {
        template<typename Tag, std::size_t N>
        struct index;

        namespace
        {
            template<std::size_t Size>
            struct binary_searcher;

            // base case
            template<>
            struct binary_searcher<1> {
                template<
                    std::size_t Pivot,
                    typename Tag,
                    typename..., // private variable:
                        bool IsIndexReached = detail::read<index<Tag, Pivot>>()>
                static constexpr std::size_t next() {
                    return Pivot + IsIndexReached;
                }
            };


            // recursive case
            template<std::size_t Size>
            struct binary_searcher {
                template<
                    std::size_t Pivot,
                    typename Tag,
                    typename..., // private variables:
                        std::size_t NextSize = Size / 2,
                        bool IsIndexReached = detail::read<index<Tag, Pivot>>(),
                        std::size_t Shift = NextSize / 2 + 1,
                        std::size_t NextPivot = IsIndexReached ? Pivot + Shift : Pivot - Shift,
                        std::size_t Result = binary_searcher<NextSize>::template next<NextPivot, Tag>()>
                static constexpr std::size_t next() {
                    return Result;
                }
            };


            // prevent falling into recursion in a
            // template instantiation when invalid
            // user input is given
            template<>
            struct binary_searcher<0> {
                template<std::size_t Pivot, typename Tag>
                static constexpr std::size_t next() {
                    return 0;
                }
            };



            template<std::size_t Value>
            struct binary_assigner {
                template<
                    typename Tag,
                    typename...,
                        unit = detail::set<index<Tag, Value - 1>>(),
                        unit = binary_assigner<Value & (Value - 1)>::template next<Tag>()>
                static constexpr unit next() {
                    return unit::value;
                }
            };

            template<>
            struct binary_assigner<0> {
                template<typename Tag>
                static constexpr unit next() {
                    return unit::value;
                }
            };
        }



        // rounds up to 1, 3, 7, 15, 31, 63, 127 and so on...
        static constexpr std::size_t round_up_to_mersenne_number(
                std::size_t x,
                std::size_t power = static_cast<std::size_t>(-1))
        {
            return x <= (power / 2)
                        ? round_up_to_mersenne_number(x, power / 2)
                        : power;
        }


        // is 1, 3, 7, 15, 31, 63, 127... ?
        static constexpr bool is_mersenne_number(std::size_t x) {
            return (x & (x + 1)) == 0;
        }



        template<bool Cond, typename Tag>
        using enable_tag_if = typename std::enable_if<Cond, Tag>::type;
    }




    template<
        typename Tag,
        std::size_t Size = static_cast<std::size_t>(-1),
        typename..., // private variable:
            std::size_t Result = meta::binary_searcher<Size>::template next<Size / 2, Tag>()>
    static constexpr std::size_t search() {
        static_assert (
            meta::is_mersenne_number(Size),
            "Size should be equal to (power of 2) - 1");

        return Result;
    }



    template<
        typename Tag,
        std::size_t Value,
        typename..., // private variable:
            meta::unit = meta::binary_assigner<Value>::template next<Tag>()>
    static constexpr meta::unit assign() {
        return meta::unit::value;
    }



    template<std::size_t>
    struct default_counter_tag {};

    enum { default_counter_size = static_cast<std::size_t>(-1) };

    template<
        std::size_t UpTo = default_counter_size,
        typename Tag = default_counter_tag<UpTo>,
        typename..., // private variables:
            std::size_t Size = meta::round_up_to_mersenne_number(UpTo),
            std::size_t Index = search<Tag, Size>(),
            bool IsIndexReachedEarlier = detail::toggle<meta::index<Tag, Index>>()>
    static constexpr std::size_t counter() {
        static_assert(
            Index <= UpTo && !IsIndexReachedEarlier,
            "counter overflow detected");

        return Index;
    }

    template<
        typename Tag,
        std::size_t UpTo = default_counter_size,
        typename..., // private variable:
            std::size_t Result = counter<UpTo, Tag>()>
    static constexpr std::size_t counter() {
        return Result;
    }



    template<std::size_t>
    struct default_reverse_counter_tag {};

    template<
        std::size_t DownTo,
        typename Tag = default_reverse_counter_tag<DownTo>,
        typename..., // private variables:
            std::size_t Size = meta::round_up_to_mersenne_number(DownTo),
            std::size_t Index = search<Tag, Size>(),
            bool IsIndexReachedEarlier = detail::toggle<meta::index<Tag, Index>>(),
            std::size_t Result = DownTo - Index>
    static constexpr std::size_t reverse_counter() {
        static_assert(
            Result <= DownTo && !IsIndexReachedEarlier,
            "counter underflow detected");

        return Result;
    }



    template<std::size_t, std::size_t>
    struct default_range_counter_tag {};

    template<
        std::size_t Begin,
        std::size_t End,
        typename Tag = default_range_counter_tag<Begin, End>,
        typename..., // private variables:
            typename ConditionalTag = meta::enable_tag_if<(Begin < End), Tag>,
            std::size_t Size = End - Begin,
            std::size_t Index = counter<Size, ConditionalTag>(),
            typename /* fixes overload resolution */ = void>
    static constexpr std::size_t range_counter() {
        return Begin + Index;
    }

    template<
        std::size_t Begin,
        std::size_t End,
        typename Tag = default_range_counter_tag<Begin, End>,
        typename..., // private variables:
            typename ConditionalTag = meta::enable_tag_if<(Begin >= End), Tag>,
            std::size_t Size = Begin - End,
            std::size_t Index = reverse_counter<Size, ConditionalTag>()>
    static constexpr std::size_t range_counter() {
        return End + Index;
    }



    namespace detail
    {
    #ifdef CLC_HAS_LAMBDAS_IN_UNEVALUATED_CONTEXTS
        template<typename T = decltype([]{})>
        using unique_type = T;
    #else
        namespace
        {
            struct unique_type_tag;

            template<typename Tag = unique_type_tag, typename T = meta::index<Tag, counter<default_counter_size, Tag>()>>
            struct unique_type {};
        }
    #endif
    }

    namespace
    {
        template<
        #ifdef CLC_HAS_LAMBDAS_IN_UNEVALUATED_CONTEXTS
            typename Tag = decltype([]{})>
        #else
            typename Tag = detail::unique_type_tag,
            typename = meta::index<Tag, counter<default_counter_size, Tag>()>>
        #endif
        struct variable {
            template<typename UserDefinedTag>
            struct revision_tag {};

            template<typename UserDefinedTag, std::size_t Revision>
            struct versioned_tag {};

            template<
                std::size_t Value,
                typename..., // private variables:
                    typename Tag_ = Tag,
                    std::size_t Revision = counter<default_counter_size, revision_tag<Tag_>>(),
                    meta::unit = clc::assign<versioned_tag<Tag_, Revision + 1>, Value>()>
            static constexpr std::size_t assign() {
                return Value;
            }

            template<
                typename..., // private variables:
                    typename Tag_ = Tag,
                    std::size_t Revision = search<revision_tag<Tag_>>(),
                    std::size_t Value = search<versioned_tag<Tag_, Revision>>()>
            static constexpr std::size_t value() {
                return Value;
            }

            template<
                typename..., // private variables:
                    typename Tag_ = Tag,
                    std::size_t Revision = search<revision_tag<Tag_>>(),
                    std::size_t Value = counter<default_counter_size, versioned_tag<Tag_, Revision>>()>
            static constexpr std::size_t increment() {
                return Value + 1;
            }
        };
    }
}

#ifdef __GNUC__
    #pragma GCC diagnostic pop
#endif

#ifdef __INTEL_COMPILER
    #pragma warning ( disable:1624 )
#endif

#endif
