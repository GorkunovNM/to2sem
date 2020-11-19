#ifndef MY_SORT_HPP
#define MY_SORT_HPP

///////////////////////////////////////////////////////////////////////////////
/// \namespace my_sort
///////////////////////////////////////////////////////////////////////////////
namespace my_sort {
    ///////////////////////////////////////////////////////////////////////////
    /// \enum   consts
    /// \brief  BYTE_BITS_CNT - just how many bits in byte.
    ///////////////////////////////////////////////////////////////////////////
    enum consts {
        BYTE_BITS_CNT = 8
    };

    ///////////////////////////////////////////////////////////////////////////
    /// \tparam random_it  - RandomAccessIterator.
    /// \tparam comparator - comparison function.
    /// \param  begin   - begin of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  end     - end of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  compare - comparison function object (i.e. an object 
    ///                   that satisfies the requirements of [Compare](
    ///                   https://en.cppreference.com/w/cpp/named_req/Compare
    ///                   )).
    /// \return -
    /// \brief  Sort function. Works in O((end - begin)^2).
    ///////////////////////////////////////////////////////////////////////////
    template<typename random_it, typename comparator = std::less<>>
    void bubble_sort(random_it begin, random_it end, 
                     comparator compare = comparator());

    ///////////////////////////////////////////////////////////////////////////
    /// \tparam random_it  - RandomAccessIterator.
    /// \tparam comparator - comparison function.
    /// \param  begin   - begin of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  end     - end of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  compare - comparison function object (i.e. an object 
    ///                   that satisfies the requirements of [Compare](
    ///                   https://en.cppreference.com/w/cpp/named_req/Compare
    ///                   )).
    /// \return -
    /// \brief  Sort function. Works in O((end - begin)^2).
    ///////////////////////////////////////////////////////////////////////////
    template<typename random_it, typename comparator = std::less<>>
    void insertion_sort(random_it begin, random_it end, 
                        comparator compare = comparator());

    ///////////////////////////////////////////////////////////////////////////
    /// \tparam random_it  - RandomAccessIterator.
    /// \tparam comparator - comparison function.
    /// \param  begin   - begin of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  end     - end of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  compare - comparison function object (i.e. an object 
    ///                   that satisfies the requirements of [Compare](
    ///                   https://en.cppreference.com/w/cpp/named_req/Compare
    ///                   )).
    /// \return -
    /// \brief  Sort function. Works in O((end - begin)^2).
    ///////////////////////////////////////////////////////////////////////////
    template<typename random_it, typename comparator = std::less<>>
    void shell_sort(random_it begin, random_it end, 
                    comparator compare = comparator());

    ///////////////////////////////////////////////////////////////////////////
    /// \tparam random_it  - RandomAccessIterator.
    /// \tparam comparator - comparison function.
    /// \param  begin   - begin of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  end     - end of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  compare - comparison function object (i.e. an object 
    ///                   that satisfies the requirements of [Compare](
    ///                   https://en.cppreference.com/w/cpp/named_req/Compare
    ///                   )).
    /// \return -
    /// \brief  Sort function. Works in O((end - begin)log(end - begin)).
    ///////////////////////////////////////////////////////////////////////////
    template<typename random_it, typename comparator = std::less<>>
    void heap_sort(random_it begin, random_it end, 
                   comparator compare = comparator());

    ///////////////////////////////////////////////////////////////////////////
    /// \tparam random_it  - RandomAccessIterator.
    /// \tparam comparator - comparison function.
    /// \param  begin   - begin of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  end     - end of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  compare - comparison function object (i.e. an object 
    ///                   that satisfies the requirements of [Compare](
    ///                   https://en.cppreference.com/w/cpp/named_req/Compare
    ///                   )).
    /// \return -
    /// \brief  Sort function. Works in O((end - begin)log(end - begin)).
    ///////////////////////////////////////////////////////////////////////////
    template<typename random_it, typename comparator = std::less<>>
    void merge_sort(random_it begin, random_it end, 
                    comparator compare = comparator());
    
    ///////////////////////////////////////////////////////////////////////////
    /// \tparam random_it  - RandomAccessIterator.
    /// \tparam comparator - comparison function.
    /// \param  begin   - begin of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  end     - end of the range of elements to sort, 
    ///                   must be RandomAccessIterator.
    /// \param  compare - comparison function object (i.e. an object 
    ///                   that satisfies the requirements of [Compare](
    ///                   https://en.cppreference.com/w/cpp/named_req/Compare
    ///                   )).
    /// \return -
    /// \brief  Sort function. Works in O(end - begin) 
    ///         (or in O((end - begin) * (size of element's type in bits))).
    ///////////////////////////////////////////////////////////////////////////
    template<typename random_it, typename comparator = std::less<>>
    void radix_sort(random_it begin, random_it end, 
                    comparator compare = comparator());
}

#endif
