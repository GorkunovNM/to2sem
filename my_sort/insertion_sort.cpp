#ifndef INSERTION_SORT_CPP
#define INSERTION_SORT_CPP

#include <functional>
#include "my_sort.hpp"

namespace my_sort {
    template<typename random_it, typename comparator>
    void insertion_sort(random_it begin, random_it end, comparator compare) {
        random_it counter = begin + 1;
        if (end <= counter) return;
        for (; counter != end; ++counter) {
            auto saved = std::move(*counter);
            random_it to_swap = counter - 1;
            for (; to_swap >= begin && compare(saved, *to_swap); --to_swap)
                *(to_swap + 1) = std::move(*to_swap);
            *++to_swap = std::move(saved);
        }
    }
}

#endif
