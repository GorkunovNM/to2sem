#ifndef MY_TESTER_HPP
#define MY_TESTER_HPP

///////////////////////////////////////////////////////////////////////////////
/// \namespace my_tester
///////////////////////////////////////////////////////////////////////////////
namespace my_tester {
    template<typename random_it, typename comparator> struct function_it_cmp {
        typedef std::function<void(random_it, random_it, comparator)> sort_ptr;
    };
    
    typedef std::vector<unsigned>::iterator tester_it;
    typedef function_it_cmp<tester_it, std::less<>>::sort_ptr sort_ptr_tester;

    ///////////////////////////////////////////////////////////////////////////
    /// \param  results   - array of doubles to write time of sorting.
    /// \param  sorts     - array of ptrs to sort functions.
    /// \param  sorts_cnt - sorts count.
    /// \param  test_size - size of test vector to sort in sorts test.
    /// \return -
    /// \brief  Tests sorts.
    ///////////////////////////////////////////////////////////////////////////
    void sorts_tester(double *results,
                      sort_ptr_tester *sorts, 
                      size_t sorts_cnt, 
                      size_t test_size);

    ///////////////////////////////////////////////////////////////////////////
    /// \tparam T - elements type.
    /// \param  v - vector to fill with random values.
    /// \return -
    /// \brief  Fills the vector with random values.
    ///////////////////////////////////////////////////////////////////////////
    template<typename T>
    void rand_vector(std::vector<T> &v);

    ///////////////////////////////////////////////////////////////////////////
    /// \param  test_size - count of integers in heap test.
    /// \param  psh_time  - double to write total pushes time.
    /// \param  pop_time  - double to write total pops time.
    /// \return -
    /// \brief  Tests heap class.
    ///////////////////////////////////////////////////////////////////////////
    void heap_tester(size_t test_size, double &psh_time, double &pop_time);
}

#endif
