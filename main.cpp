#include <cstdio>                       ////////stats on my laptop)////////
#include "my_sort/bubble_sort.cpp"      // 106425.139328 ms for 1e5 size //
#include "my_sort/insertion_sort.cpp"   // 63773.803891  ms for 1e5 size //
#include "my_sort/shell_sort.cpp"       // 227.231203    ms for 1e5 size //
#include "my_sort/heap_sort.cpp"        // 108298.404238 ms for 1e5 size //
#include "my_sort/merge_sort.cpp"       // 58.448836     ms for 1e5 size //
#include "my_sort/radix_sort.cpp"       // 108.331753    ms for 1e5 size //
#include "my_tester/sorts_tester.cpp"   ///////////////////////////////////

enum consts {
    SIZE = 100000
};

int main(int argc, char const *argv[]) {
    printf("Sorting vector of %d random unsigned integers.\n", SIZE);
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
           "radix_sort:\t%lf ms\nTest finished.\n", results[0], results[1], 
           results[2], results[3], results[4], results[5]);
    return 0;
}
