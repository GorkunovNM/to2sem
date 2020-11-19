#ifndef MY_TESTER_HPP
#define MY_TESTER_HPP

namespace my_tester {
    template<typename random_it, typename comparator> struct function_it_cmp {
        typedef std::function<void(random_it, random_it, comparator)> sort_ptr;
    };
    
    typedef std::vector<unsigned>::iterator tester_it;
    typedef function_it_cmp<tester_it, std::less<>>::sort_ptr sort_ptr_tester;

    void sorts_tester(double *results,
                      sort_ptr_tester *sorts, 
                      size_t sorts_cnt, 
                      size_t test_size);

    template<typename T>
    void rand_vector(std::vector<T> &v);

    void heap_tester(size_t test_size, double &psh_time, double &pop_time);
}

#endif
