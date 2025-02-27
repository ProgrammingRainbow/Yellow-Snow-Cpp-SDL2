#ifndef FPS_H
#define FPS_H

#include "main.h"

class Fps {
    public:
        Fps()
            : target_duration{std::chrono::nanoseconds(1000000000) /
                              TARGET_FPS},
              max_duration{std::chrono::milliseconds(50)},
              last_time{std::chrono::steady_clock::now()},
              carry_delay{},
              first_elapsed{},
              second_elapsed{},
              last_fps{std::chrono::steady_clock::now()},
              fps_duration{std::chrono::seconds(1)},
              dt{0},
              frames{0},
              enable_fps{false} {}

        void update();
        void toggleFps();
        inline double getDt() const { return this->dt; };

    private:
        void showFps();

        const std::chrono::steady_clock::duration target_duration;
        const std::chrono::steady_clock::duration max_duration;
        std::chrono::time_point<std::chrono::steady_clock> last_time;
        std::chrono::steady_clock::duration carry_delay;
        std::chrono::steady_clock::duration first_elapsed;
        std::chrono::steady_clock::duration second_elapsed;
        std::chrono::time_point<std::chrono::steady_clock> last_fps;
        const std::chrono::steady_clock::duration fps_duration;
        double dt;
        unsigned int frames;
        bool enable_fps;
};

#endif
