#ifndef MERGE_SORT_CPP
#define MERGE_SORT_CPP

#include <functional>
#include <algorithm>
#include <utility>
#include "my_sort.hpp"

namespace my_sort {
    template<typename random_it, typename comparator>
    void merge_sort(random_it begin, random_it end, comparator compare) {
        typedef typename std::iterator_traits<random_it>::value_type r_i_type;
        if (end <= begin + 1) return;
        size_t size = end - begin;
        r_i_type *tmp_buf = new r_i_type[size];
        for (size_t sort_stage = 1; sort_stage < size; sort_stage *= 2) {
            for (size_t it = 0; it < size - sort_stage; it += 2 * sort_stage) {
                auto left_it = 0;
                random_it merge_it = begin + it;
                random_it right_it = merge_it + sort_stage;
                random_it end_it   = std::min(right_it + sort_stage, end);
                for (size_t copy_it = 0; copy_it < sort_stage; ++copy_it) {
                    tmp_buf[copy_it] = std::move(*(merge_it + copy_it));
                }
                for (; merge_it < end_it; ++merge_it) {
                    if (left_it < sort_stage && 
                        (compare(tmp_buf[left_it], *right_it) || 
                         right_it >= end_it)) {
                        *merge_it = std::move(tmp_buf[left_it]);
                        ++left_it;
                    } else {
                        *merge_it = std::move(*right_it);
                        ++right_it;
                    }
                }
            }
        }
        delete[] tmp_buf;
    }
}

#endif
