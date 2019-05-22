
#pragma once

#include <eval/details/is.hpp>
#include <string>

//struct _5th_preference{};
//struct _4th_preference : _5th_preference {};
//struct _3rd_preference : _4th_preference {};
//struct _2nd_preference : _3rd_preference {};
//struct _1st_preference : _2nd_preference {};
//struct preference      : _1st_preference {};


namespace eval
{
    template <typename Element, typename Operator>
    auto is(Element const & element, Operator const op, std::initializer_list<Element> const & collection)
        -> bool
    {
        return details::is(element, op, collection);
    }

    template <typename Operator>
    auto is(std::string const & element, Operator const op, std::initializer_list<std::string> const & collection)
        -> bool
    {
        return details::is(element, op, collection);
    }

    template <typename Operator, typename Collection>
    auto is(const char * element, Operator const op, Collection const & collection)
        -> bool
    {
        return is(std::string{element}, op, collection);
    }

    template <typename Element, typename Operator, typename Collection>
    auto is(Element const & element, Operator const op, Collection const & collection)
        -> bool
    {
        return details::is(element, op, collection);
    }

}
