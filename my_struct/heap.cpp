#ifndef HEAP_CPP
#define HEAP_CPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "my_struct.hpp"

namespace my_struct {
    template<typename T, typename comparator>
    heap<T, comparator>::heap() {
        compare = comparator();
    }

    template<typename T, typename comparator>
    T heap<T, comparator>::get_most() {
        return data[0];
    }

    template<typename T, typename comparator>
    T heap<T, comparator>::pop_most() {
        T ans = data[0];
        size_t last_pos = data.size() - 1;
        std::swap(data[0], data[last_pos]);
        data.pop_back();
        sift_down(0);
        return ans;
    }

    template<typename T, typename comparator>
    void heap<T, comparator>::push(const T &elem) {
        size_t pos_now = data.size();
        data.push_back(elem);
        sift_up(pos_now);
    }

    template<typename T, typename comparator>
    std::ostream& operator<<(std::ostream &out, const heap<T, 
                             comparator> &this_heap) {
        for (auto i: this_heap.data) out << i << ' ';
        out << "\b.";
        return out;
    }

    template<typename T, typename comparator>
    void heap<T, comparator>::sift_up(size_t index) {\
        size_t parent = index / 2;
        while (index > 0 && compare(data[index], data[parent])) {
            std::swap(data[index], data[parent]);
            index = parent;
            parent /= 2;
        }
    }

    template<typename T, typename comparator>
    void heap<T, comparator>::sift_down(size_t index) {
        size_t fin = data.size();
        while (index < fin) {                      // just not using while true
            size_t left = 2 * index;
            size_t right = 2 * index + 1;
            if (left >= fin) break;
            else if (right >= fin) {
                if (compare(data[left], data[index])) 
                    std::swap(data[index], data[left]);
                break;
            } else if (compare(data[left], data[right])) {
                if (compare(data[left], data[index])) 
                    std::swap(data[index], data[left]);
                else break;
                index *= 2;
            } else {
                if (compare(data[right], data[index])) 
                    std::swap(data[index], data[right]);
                else break;
                index = index * 2 + 1;
            }
        }
    }
}

#endif

