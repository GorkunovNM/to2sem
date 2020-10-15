#ifndef SIMPLE_TIMER
#define SIMPLE_TIMER

#include <chrono>
#include <ctime>
#include "my_timer.hpp"

namespace my_timer {
    void simple_timer::start() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double simple_timer::finish() {
        return 1e-6 * std::chrono::duration_cast<std::chrono::nanoseconds>
            (std::chrono::high_resolution_clock::now() - start_time).count();
    }
}

#endif
