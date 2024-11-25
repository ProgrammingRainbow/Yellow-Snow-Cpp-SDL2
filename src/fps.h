#ifndef FPS_H
#define FPS_H

#include "main.h"

class Fps {
    public:
        Fps();

        void update();
        void toggle_fps();

        double dt;

    private:
        void show_fps();

        const std::chrono::duration<double, std::milli> target_duration;
        const std::chrono::duration<double, std::milli> max_duration;
        std::chrono::time_point<std::chrono::steady_clock> last_time;
        std::chrono::time_point<std::chrono::steady_clock> current_time;
        std::chrono::duration<double, std::milli> carry_delay;
        std::chrono::duration<double, std::milli> first_elapsed;
        std::chrono::duration<double, std::milli> second_elapsed;
        std::chrono::time_point<std::chrono::steady_clock> last_fps;
        const std::chrono::steady_clock::duration fps_duration;
        unsigned int frames;
        bool enable_fps;
};

#endif
