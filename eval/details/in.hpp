
#pragma once

#include <algorithm>

namespace eval
{
    namespace details
    {
        template <typename Element, typename Collection>
        auto in(Element const & element, Collection const & collection)
            -> bool
        {
            return std::any_of(begin(collection), end(collection),
                                [&element] (Element const & item) {
                                    return item == element;
                              });
        }

        template <typename Element, typename Collection>
        auto not_in(Element const & element, Collection const & collection)
            -> bool
        {
            return not in(element, collection);
        }
    }
}
