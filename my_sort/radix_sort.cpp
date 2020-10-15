#ifndef RADIX_SORT_CPP
#define RADIX_SORT_CPP

#include <functional>
#include <algorithm>
#include <utility>
#include <bitset>
#include "my_sort.hpp"

namespace my_sort {
    template<typename random_it, typename comparator>
    void radix_sort(random_it begin, random_it end, comparator compare) {
        typedef typename std::iterator_traits<random_it>::value_type r_i_type;
        typedef std::bitset<sizeof(r_i_type) * BYTE_BITS_CNT> r_i_type_bitset;
        typedef std::pair<r_i_type, r_i_type_bitset> r_i_t_and_t_b_pair;
        if (end <= begin + 1) return;
        size_t size = end - begin;
        size_t r_i_type_bits_cnt = sizeof(r_i_type) * BYTE_BITS_CNT;
        r_i_t_and_t_b_pair *tmp_buf = new r_i_t_and_t_b_pair[size];
        size_t t_b_it = 0;
        for (random_it counter = begin; counter < end; ++counter) {
            r_i_type_bitset tmp(*counter);
            tmp_buf[t_b_it] = std::move(std::make_pair(*counter, tmp));
            ++t_b_it;
        }
        r_i_t_and_t_b_pair *tmp_buf_0 = new r_i_t_and_t_b_pair[size];
        r_i_t_and_t_b_pair *tmp_buf_1 = new r_i_t_and_t_b_pair[size];
        for (size_t bit_num = 0; bit_num != r_i_type_bits_cnt; ++bit_num) {
            size_t t_b_0_it = 0;
            size_t t_b_1_it = 0;
            for (size_t counter = 0; counter < size; ++counter) {
                if (tmp_buf[counter].second.test(bit_num)) {
                    tmp_buf_1[t_b_1_it] = std::move(tmp_buf[counter]);
                    ++t_b_1_it;
                } else {
                    tmp_buf_0[t_b_0_it] = std::move(tmp_buf[counter]);
                    ++t_b_0_it;
                }
            }          
            for (t_b_it = 0; t_b_it < t_b_0_it; ++t_b_it)
                tmp_buf[t_b_it] = std::move(tmp_buf_0[t_b_it]);
            for (; t_b_it < size; ++t_b_it)
                tmp_buf[t_b_it] = std::move(tmp_buf_1[t_b_it - t_b_0_it]);
        }
        t_b_it = 0;
        if (compare(*begin, *(begin + 1))) {
            for (random_it counter = end - 1; counter >= begin; --counter) {
                *counter = std::move(tmp_buf[t_b_it].first);
                ++t_b_it;
            }
        } else {
            for (random_it counter = begin; counter < end; ++counter) {
                *counter = std::move(tmp_buf[t_b_it].first);
                ++t_b_it;
            }
        }
        delete[] tmp_buf;
        delete[] tmp_buf_0;
        delete[] tmp_buf_1;
    }
}

#endif
