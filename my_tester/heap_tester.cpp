#ifndef HEAP_TESTER_CPP
#define HEAP_TESTER_CPP

#include <vector>
#include <iostream>
#include "../my_timer/simple_timer.cpp"
#include "../my_struct/heap.cpp"
#include "my_tester.hpp"

namespace my_tester {
    void heap_tester(size_t test_size, double &psh_time, double &pop_time){
        my_struct::heap<unsigned> h;
        std::vector<unsigned> v(test_size);
        my_tester::rand_vector(v);
        ///////////////////////////////////////////////////////
        #ifdef DEBUG_MODE_IS_ON                              //
        printf("Random unsigned integers:\n\tO~~~~~~~~~~");  //
        for (auto &i: v) printf("\n\t|%u ", i);              // DEBUG ONLY!
        printf("\n\tO~~~~~~~~~~\n");                         //
        #endif                                               //
        ///////////////////////////////////////////////////////
        my_timer::simple_timer timer;
        timer.start();
        for (size_t i = 0; i < test_size; ++i)
            h.push(v[i]);
        psh_time = timer.finish();
        /////////////////////////////////////////////////
        #ifdef DEBUG_MODE_IS_ON                        //
        std::cout << "Heap data: " << h << std::endl;  // DEBUG ONLY!
        #endif                                         //
        /////////////////////////////////////////////////
        timer.start();
        for (size_t i = 0; i < test_size; ++i)
            v[i] = h.pop_most();
        pop_time = timer.finish();
        /////////////////////////////////////////////
        #ifdef DEBUG_MODE_IS_ON                    //
        printf("Same integers sorted by popping "  //
               "from heap:\n\tO~~~~~~~~~~");       //
        for (auto &i: v) printf("\n\t|%u ", i);    // DEBUG ONLY!
        printf("\n\tO~~~~~~~~~~\n");               //
        #endif                                     //
        /////////////////////////////////////////////
    }
}

#endif