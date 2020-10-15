#ifndef SORTS_TESTER_CPP
#define SORTS_TESTER_CPP

//#define DEBUG_MODE_IS_ON // comment definition to turn it off or uncomment to turn it on

#include <functional>
#include <vector>
#include "../my_timer/simple_timer.cpp"
#include "my_tester.hpp"

namespace my_tester {
    void sorts_tester(double *results, sort_ptr_tester *sorts, 
                      size_t sorts_cnt, size_t test_size) {
        std::vector<unsigned> v(test_size);
        for (size_t i = 0; i < test_size; ++i) v[i] = rand();
        //////////////////////////////////////
        #ifdef DEBUG_MODE_IS_ON             //
        printf("To sort: ");                //
        for (auto &i: v) printf("%u ", i);  // DEBUG ONLY!
        printf("\b.\n");                    //
        #endif                              //
        //////////////////////////////////////
        my_timer::simple_timer timer;
        for (size_t it = 0; it < sorts_cnt; ++it) {
            std::vector<unsigned> v_cpy(v);
            timer.start();
            sorts[it](v_cpy.begin(), v_cpy.end(), std::less<>());
            results[it] = timer.finish();
            //////////////////////////////////////////
            #ifdef DEBUG_MODE_IS_ON                 //
            printf("Sorted by %lu: ", it);          //
            for (auto &i: v_cpy) printf("%u ", i);  // DEBUG ONLY!
            printf("\b.\n");                        //
            #endif                                  //
            //////////////////////////////////////////
        }
    }
}

#endif