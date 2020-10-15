#ifndef MY_TIMER_HPP
#define MY_TIMER_HPP

namespace my_timer {
    class simple_timer {
    public:
        void start();

        double finish();

    private:
        std::chrono::time_point<std::chrono::system_clock> start_time;
    };
}

#endif
