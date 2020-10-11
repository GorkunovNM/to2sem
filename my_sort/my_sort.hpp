#ifndef MY_SORT_HPP
#define MY_SORT_HPP

namespace my_sort {
    template<typename random_it, typename comparator = std::less<>>
    void bubble_sort(random_it begin, random_it end, 
                     comparator compare = comparator());

    template<typename random_it, typename comparator = std::less<>>
    void insertion_sort(random_it begin, random_it end, 
                        comparator compare = comparator());

    template<typename random_it, typename comparator = std::less<>>
    void shell_sort(random_it begin, random_it end, 
                    comparator compare = comparator());

    template<typename random_it, typename comparator = std::less<>>
    void heap_sort(random_it begin, random_it end, 
                    comparator compare = comparator());
}

#endif
