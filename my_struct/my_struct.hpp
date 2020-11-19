#ifndef MY_STRUCT_HPP
#define MY_STRUCT_HPP

namespace my_struct {
    template<typename T, typename comparator>
    class heap;

    template<typename T, typename comparator>
    std::ostream& operator<<(std::ostream &out, 
                             const heap<T, comparator> &this_heap);

    template<typename T, typename comparator = std::less<>>
    class heap {
    public:
        heap();

        T get_most(); // most means less by default
                      // ^v - but if using custom comparator, it is not
        T pop_most(); // most means less by default

        void push(const T &elem);

        friend std::ostream& operator<<<T, comparator>
            (std::ostream &out, const heap<T, comparator> &this_heap);
    private:
        std::vector<T> data;
        comparator compare;

        void sift_up(size_t index);

        void sift_down(size_t index);
    };
}

#endif
