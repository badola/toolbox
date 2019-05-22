
#pragma once

namespace eval
{
    namespace details
    {

        template <typename Range, typename Collection>
        auto subset(Range const & range, Collection const & collection)
            -> bool
        {
            return std::includes(begin(collection), end(collection),
                                 begin(range), end(range));
        }

        template <typename Range, typename Collection>
        auto are_impl(Range const & range, in_t, Collection const & collection)
        -> bool
        {
            std::cout << "are("; print(range); std::cout << ") in (" ; print(collection); std::cout << ") => " ;
            return subset(range, collection);
        }

        template <typename Range, typename Collection>
        auto are_impl(Range const & range, not_in_t, Collection const & collection)
            -> bool
        {
            std::cout << "are("; print(range); std::cout << ") not in (" ; print(collection); std::cout << ") => " ;
            return not subset(range, collection);
        }

    }

    template <typename Range, typename Operator, typename Collection>
    auto are(Range const & range, Operator op, Collection const & collection)
        -> decltype (begin(range), end(range), *begin(range), ++begin(range), true)
    {
        return details::are_impl(range, op, collection);
    }

    template <typename Element, typename Operator>
    auto are(std::initializer_list<Element> const & range, Operator op, std::initializer_list<Element> const & collection)
        -> bool
    {
        return details::are_impl(range, op, collection);
    }
}
