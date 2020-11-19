/*
This is just testing program.
Github: https://github.com/akaZabey/to2sem
*/

////////////WARNING!//////////
#define DEBUG_MODE_IS_ON    // comment to turn it off or uncomment to turn on
//spam a lot in the terminal//
/////(debug only option)//////

#include <iostream>                     ////////stats on my laptop)////////
#include "my_sort/bubble_sort.cpp"      // 106425.139328 ms for 1e5 size //
#include "my_sort/insertion_sort.cpp"   // 63773.803891  ms for 1e5 size //
#include "my_sort/shell_sort.cpp"       // 227.231203    ms for 1e5 size //
#include "my_sort/heap_sort.cpp"        // 108298.404238 ms for 1e5 size //
#include "my_sort/merge_sort.cpp"       // 58.448836     ms for 1e5 size //
#include "my_sort/radix_sort.cpp"       // 108.331753    ms for 1e5 size //
#include "my_tester/sorts_tester.cpp"   ///////////////////////////////////
#include "my_tester/heap_tester.cpp"    // Pushes time: 755.627076   ms  //
#include "my_struct/heap.cpp"           // Pops time:   12215.003567 ms  //
                                        //      (for 1e7 heap size)      //
                                        ///////////////////////////////////

#define TEST_SORTS // comment to turn it off or uncomment to turn it on
#define TEST_HEAP  // comment to turn it off or uncomment to turn it on

enum consts {
    SIZE = 10,      // size of test vector to sort in sorts test
    HEAP_SIZE = 10  // count of integers in heap test
};

/*Much more interesting (but it is important to turn off debug mode):
enum consts {
    SIZE = 100000,
    HEAP_SIZE = 10000000
};
*/

int main(int argc, char const *argv[]) {
    printf("This is just testing program.\n");
    ////////////////////////////////SORTS TESTS////////////////////////////////
    #ifdef TEST_SORTS
    printf("\tSorts test:\nSorting vector of %d random unsigned integers.\n", 
           SIZE);
    my_tester::sort_ptr_tester sorts[] = {
                                my_sort::bubble_sort   <my_tester::tester_it>, 
                                my_sort::insertion_sort<my_tester::tester_it>, 
                                my_sort::shell_sort    <my_tester::tester_it>, 
                                my_sort::heap_sort     <my_tester::tester_it>, 
                                my_sort::merge_sort    <my_tester::tester_it>, 
                                my_sort::radix_sort    <my_tester::tester_it>};
    double results[6];
    my_tester::sorts_tester(results, sorts, 6, SIZE);
    printf("bubble_sort:\t%lf ms\ninsertion_sort:\t%lf ms\n"
           "shell_sort:\t%lf ms\nheap_sort:\t%lf ms\nmerge_sort:\t%lf ms\n"
           "radix_sort:\t%lf ms\n\tSorts test finished.\n", results[0], 
           results[1], results[2], results[3], results[4], results[5]);
    #endif
    ///////////////////////////////////////////////////////////////////////////
    /////////////////////////////////HEAP TEST/////////////////////////////////
    #ifdef TEST_HEAP
    printf("\tHeap test:\nPushing and popping %d random unsigned "
           "integers from heap.\n", HEAP_SIZE);
    double pushes_time = 0;
    double pops_time   = 0;
    my_tester::heap_tester(HEAP_SIZE, pushes_time, pops_time);
    printf("Pushes time:\t%lf ms\nPops time:\t%lf ms\n\tHeap test finished.\n", 
           pushes_time, pops_time);
    #endif
    ///////////////////////////////////////////////////////////////////////////
    printf("All tests are done.\n");
    return 0;
}
