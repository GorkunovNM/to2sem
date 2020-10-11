#ifndef SHELL_SORT_CPP
#define SHELL_SORT_CPP

#include <functional>
#include <algorithm>
#include "my_sort.hpp"

namespace my_sort {
    template<typename random_it, typename comparator>
    void shell_sort(random_it begin, random_it end, comparator compare) {
        if (end <= begin + 1) return;
        ssize_t size = end - begin;
        for (ssize_t delta = size / 2; delta > 0; delta /= 2) 
            for (ssize_t offset = delta; offset < size; ++offset) 
                for (ssize_t i = offset - delta; 
                     i >= 0 && !compare(*(begin + i), *(begin + i + delta)); 
                     i -= delta) 
                    std::swap(*(begin + i), *(begin + i + delta));
    }
}

#endif
