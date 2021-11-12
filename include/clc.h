//                 Curious Loopholed Counter
//
//             Copyright Ofee Oficsu 2020 - 2021.
//                 Copyright Malibushko  2020
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)
//
//        Project home: https://github.com/oficsu/clc

#ifndef CURIOUS_LOOPHOLED_COUNTER_HPP
#define CURIOUS_LOOPHOLED_COUNTER_HPP

#include <utility>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnon-template-friend"

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
            namespace {
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

            template<typename Tag, typename..., meta::unit = get(flag<Tag>{})>
            static constexpr bool read(meta::unit) {
                return true;
            };

            template<typename Tag, typename..., bool = sizeof(writer<Tag, flag<Tag>>)>
            static constexpr meta::unit set(...) {
                return meta::unit::value;
            };

            template<typename Tag>
            static constexpr bool toggle_impl(...) {
                return set<Tag>(), true;
            };

            template<typename Tag, typename..., meta::unit = get(flag<Tag>{})>
            static constexpr bool toggle_impl(meta::unit) {
                return false;
            };
        }

        template<typename Tag, typename..., bool Value = type_loophole::read<Tag>(meta::unit::value)>
        static constexpr bool read() {
            return Value;
        };

        template<typename Tag, typename..., meta::unit = type_loophole::set<Tag>(meta::unit::value)>
        static constexpr meta::unit set() {
            return meta::unit::value;
        };

        template<typename Tag, typename..., bool Value = type_loophole::toggle_impl<Tag>(meta::unit::value)>
        static constexpr bool toggle() { return Value; }
    }

    namespace meta
    {
        namespace {
            // base case of recursion
            struct bit {
                enum { max = 1 };

                template<
                    typename Tag,
                    typename..., // private variable:
                        bool Value = clc::detail::toggle<Tag>()>
                static constexpr std::size_t next() {
                    return Value;
                }
            };
        }



        template<bool Cond, typename Tag>
        using enable_tag_if = typename std::enable_if<Cond, Tag>::type;

        template<
            bool Cond,
            typename Bits,
            typename Tag,
            typename..., // private variables:
                typename ConditionalTag = enable_tag_if<Cond, Tag>,
                std::size_t R = Bits:: template next<ConditionalTag>()>
        static constexpr std::size_t conditional_next_for(meta::unit) {
            return R;
        }

        template<bool Cond, typename Bits, typename Tag>
        static constexpr std::size_t conditional_next_for(...) {
            return Bits::max;
        }

        template<
            typename Bits,
            typename Tag,
            typename..., // private variable:
                std::size_t R = Bits:: template next<Tag>()
        >
        static constexpr std::size_t unconditional_next_for() {
            return R;
        }

        template<typename>
        struct left_recursive_tag {};

        template<typename>
        struct right_recursive_tag {};


        namespace {
            // recursive case
            template<typename Nested = bit>
            struct add_bit {
                enum : std::size_t { max = Nested::max * 2 };

                template<
                    typename Tag,
                    typename..., // private variables:
                        std::size_t Left  = unconditional_next_for<Nested, left_recursive_tag<Tag>>(),
                        std::size_t Right = conditional_next_for<!Left, Nested, right_recursive_tag<Tag>>(meta::unit::value)
                >
                static constexpr std::size_t next() {
                    return Left + Right;
                }
            };
        }



        namespace detail
        {
            template<std::size_t Width>
            struct bits {
                using type = add_bit<typename bits<Width - 1>::type>;
            };

            template<>
            struct bits<1> {
                using type = add_bit<>;
            };
        }

        template<std::size_t Width>
        using bits = typename detail::bits<Width>::type;


        template<std::size_t Value>
        using size_t_constant = std::integral_constant<std::size_t, Value>;

        template <std::size_t Value>
        struct log2 : size_t_constant<1 + log2<Value / 2>::value> {};

        template<> struct log2<1> : size_t_constant<1> {};
    }



    template<
        typename Tag,
        std::size_t Width,
        typename..., // private variables:
            typename Bits = meta::bits<Width>,
            std::size_t Value = Bits::template next<Tag>()
    >
    static constexpr std::size_t unsafe_counter() {
        return Value;
    }



    template<std::size_t>
    struct default_counter_tag {};

    template<std::size_t, std::size_t>
    struct default_range_counter_tag {};

    template<std::size_t>
    struct default_reverse_counter_tag {};



    enum { default_counter_size = 4096 };



    template<
        std::size_t MaxValue = default_counter_size,
        typename Tag = default_counter_tag<MaxValue>,

        typename..., // private variables:
            std::size_t Width = meta::log2<MaxValue>::value,
            typename Bits = meta::bits<Width>,
            std::size_t Index = Bits::template next<Tag>()
    >
    static constexpr std::size_t counter() {
        static_assert(Bits::max - Index <= MaxValue, "counter overflow detected");
        return Bits::max - Index;
    }



    template<
        std::size_t InitialValue,
        typename Tag = default_reverse_counter_tag<InitialValue>,

        typename..., // private variables:
            std::size_t Width = meta::log2<InitialValue>::value,
            typename Bits = meta::bits<Width>,
            std::size_t Diff = Bits::max - InitialValue,
            std::size_t Index = Bits::template next<Tag>()
    >
    static constexpr std::size_t reverse_counter() {
        static_assert(Index >= Diff, "counter underflow detected");
        return Index - Diff;
    }



    template<
        std::size_t Begin,
        std::size_t End,
        typename Tag = default_range_counter_tag<Begin, End>,
        typename..., // private variables:
            typename ConditionalTag = meta::enable_tag_if<(Begin < End), Tag>,
            std::size_t Diff  = End - Begin,
            std::size_t Index = counter<Diff, ConditionalTag>(),
            typename = void
    >
    static constexpr std::size_t range_counter() {
        return Begin + Index;
    }

    template<
        std::size_t Begin,
        std::size_t End,
        typename Tag = default_range_counter_tag<Begin, End>,
        typename..., // private variables:
            typename ConditionalTag = meta::enable_tag_if<(Begin >= End), Tag>,
            std::size_t Diff  = Begin - End,
            std::size_t Index = reverse_counter<Diff, ConditionalTag>()
    >
    static constexpr std::size_t range_counter() {
        return End + Index;
    }
}

#pragma GCC diagnostic pop

#endif
