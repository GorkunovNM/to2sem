#ifndef BUBBLE_SORT_CPP
#define BUBBLE_SORT_CPP

#include <functional>
#include <algorithm>
#include "my_sort.hpp"

namespace my_sort {
    template<typename random_it, typename comparator>
    void bubble_sort(random_it begin, random_it end, comparator compare) {
        if (end <= begin + 1) return;
        random_it counter = begin;
        size_t size = end - begin;
        for (size_t i = 1; i < size; ++i) {
            bool finished = true;
            counter = begin;
            for (size_t j = 0; j < size - i; ++j) {
                random_it counter_cpy = counter;
                if (!compare(*counter_cpy, *++counter)) {
                    std::swap(*counter_cpy, *counter);
                    finished = false;
                }
            }
            if (finished) break;
        }
    }
}

#endif
