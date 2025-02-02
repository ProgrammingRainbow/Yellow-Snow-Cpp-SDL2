#ifndef FPS_H
#define FPS_H

#include "main.h"

class Fps {
    public:
        Fps()
            : target_duration{1000.0 / TARGET_FPS},
              max_duration{50.0},
              last_time{std::chrono::steady_clock::now()},
              carry_delay{0},
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

        const std::chrono::duration<double, std::milli> target_duration;
        const std::chrono::duration<double, std::milli> max_duration;
        std::chrono::time_point<std::chrono::steady_clock> last_time;
        std::chrono::duration<double, std::milli> carry_delay;
        std::chrono::duration<double, std::milli> first_elapsed;
        std::chrono::duration<double, std::milli> second_elapsed;
        std::chrono::time_point<std::chrono::steady_clock> last_fps;
        const std::chrono::steady_clock::duration fps_duration;
        double dt;
        unsigned int frames;
        bool enable_fps;
};

#endif
