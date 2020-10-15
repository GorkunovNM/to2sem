#ifndef HEAP_SORT_CPP
#define HEAP_SORT_CPP

#include <functional>
#include <algorithm>
#include "my_sort.hpp"

namespace my_sort {
    template<typename random_it, typename comparator>
    void heap_sort(random_it begin, random_it end, comparator compare) {
        if (end <= begin + 1) return;
        size_t size = end - begin;
        for (size_t sort_stage = 0; sort_stage < size; ++sort_stage) {
            random_it last_on_stage = end - sort_stage - 1;
            for (random_it counter = begin + size / 2 - 1 - sort_stage / 2;
                 counter >= begin; --counter) {
                random_it left_son = counter + (counter - begin) + 1;
                random_it right_son = left_son + 1;
                if (right_son <= last_on_stage) {
                    if (compare(*right_son, *left_son)) {
                        if (compare(*counter, *left_son)) 
                            std::swap(*counter, *left_son);
                    } else if (compare(*counter, *right_son)) 
                        std::swap(*counter, *right_son);
                } else if (left_son <= last_on_stage) {
                    if (compare(*counter, *left_son))
                        std::swap(*counter, *left_son);
                }
            }
            std::swap(*begin, *last_on_stage);
        }
    }
}

#endif
