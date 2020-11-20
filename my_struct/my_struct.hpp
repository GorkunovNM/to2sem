#ifndef MY_STRUCT_HPP
#define MY_STRUCT_HPP

///////////////////////////////////////////////////////////////////////////////
/// \namespace my_struct
///////////////////////////////////////////////////////////////////////////////
namespace my_struct {
    ///////////////////////////////////////////////////////////////////////////
    /// \tparam  T          - heap elements type.
    /// \tparam  comparator - comparison function.
    /// \private data    - contains elements of the heap
    /// \private compare - comparison function object (i.e. an object 
    ///                    that satisfies the requirements of 
    ///                    https://en.cppreference.com/w/cpp/named_req/Compare
    ///                    ).
    /// \class   heap my_struct.hpp "my_struct/heap.hpp"
    /// \brief   Simple structure.
    ///////////////////////////////////////////////////////////////////////////
    template<typename T, typename comparator>
    class heap;

    ///////////////////////////////////////////////////////////////////////////
    /// \tparam T          - heap elements type.
    /// \tparam comparator - comparison function.
    /// \param  out       - output stream.
    /// \param  this_heap - the heap.
    /// \return output stream.
    /// \brief  Overloaded operator << for heap. Works in O(end - begin).
    ///////////////////////////////////////////////////////////////////////////
    template<typename T, typename comparator>
    std::ostream& operator<<(std::ostream &out, 
                             const heap<T, comparator> &this_heap);

    template<typename T, typename comparator = std::less<>>
    class heap {
    public:
        ///////////////////////////////////////////////////////////////////////
        /// \param  -
        /// \return value
        /// \brief  Constructs the heap and sets comparator.
        ///////////////////////////////////////////////////////////////////////
        heap();

        ///////////////////////////////////////////////////////////////////////
        /// \param  -
        /// \return most element
        /// \brief  Gets most element from the heap. Most means less by default, 
        ///         but if using custom comparator, it does not.
        ///////////////////////////////////////////////////////////////////////
        T get_most();
        
        ///////////////////////////////////////////////////////////////////////
        /// \param  -
        /// \return most element
        /// \brief  Pops most element from the heap. Most means less by  
        ///         default, but if using custom comparator, it does not. 
        ///         Works in O(heap height).
        ///////////////////////////////////////////////////////////////////////
        T pop_most();

        ///////////////////////////////////////////////////////////////////////
        /// \param  elem - element to push.
        /// \return -
        /// \brief  Pushes element to the heap. Works in O(heap height).
        ///////////////////////////////////////////////////////////////////////
        void push(const T &elem);

        friend std::ostream& operator<<<T, comparator>
            (std::ostream &out, const heap<T, comparator> &this_heap);
    private:
        std::vector<T> data;
        comparator compare;

        ///////////////////////////////////////////////////////////////////////
        /// \param  index - index of element to sift up.
        /// \return -
        /// \brief  Sifts up the element. Works in O(heap height).
        ///////////////////////////////////////////////////////////////////////
        void sift_up(size_t index);

        ///////////////////////////////////////////////////////////////////////
        /// \param  index - index of element to sift down.
        /// \return -
        /// \brief  Sifts down the element. Works in O(heap height).
        ///////////////////////////////////////////////////////////////////////
        void sift_down(size_t index);
    };
}

#endif
