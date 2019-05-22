
#pragma once

#include <eval/details/in.hpp>
#include <eval/details/tests.hpp>

namespace eval
{
    namespace details
    {
        template <typename Element, typename Collection>
        auto is(Element const & element, in_t, Collection const & collection)
        -> bool
        {
            return in(element, collection);
        }

        template <typename Element, typename Collection>
        auto is(Element const & element, not_in_t, Collection const & collection)
            -> bool
        {
            return not in(element, collection);
        }
    }
}
