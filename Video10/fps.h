#ifndef FPS_H
#define FPS_H

#include "main.h"

class Fps {
    public:
        Fps()
            : target_duration{std::chrono::nanoseconds(1000000000) /
                              TARGET_FPS},
              max_carry{std::chrono::milliseconds(50)},
              last_time{std::chrono::steady_clock::now()},
              carry_duration{},
              last_fps{std::chrono::steady_clock::now()},
              dt{},
              frames{},
              enable_fps{false} {}

        void update();
        void toggleFps();
        inline double getDt() const { return this->dt; };

    private:
        void showFps();

        const std::chrono::steady_clock::duration target_duration;
        const std::chrono::steady_clock::duration max_carry;
        std::chrono::time_point<std::chrono::steady_clock> last_time;
        std::chrono::steady_clock::duration carry_duration;
        std::chrono::time_point<std::chrono::steady_clock> last_fps;
        double dt;
        unsigned int frames;
        bool enable_fps;
};

#endif
