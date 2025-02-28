#include "fps.h"

void Fps::toggleFps() {
    if (this->enable_fps) {
        this->enable_fps = false;
    } else {
        this->enable_fps = true;
        this->frames = 0;
        this->last_fps = std::chrono::steady_clock::now();
    }
}

void Fps::showFps() {
    if (this->enable_fps) {
        auto current_time = std::chrono::steady_clock::now();
        if (current_time >= this->last_fps + std::chrono::seconds(1)) {
            std::cout << this->frames << std::endl;
            this->last_fps = this->last_fps + std::chrono::seconds(1);
            this->frames = 0;
        }
        this->frames++;
    }
}

void Fps::update() {
    auto current_time = std::chrono::steady_clock::now();
    auto elapsed_time = current_time - this->last_time;
    auto sleep_duration =
        this->target_duration - elapsed_time + this->carry_delay;

    if (sleep_duration.count() > 0) {
        std::this_thread::sleep_for(sleep_duration);
    }

    current_time = std::chrono::steady_clock::now();
    elapsed_time = current_time - this->last_time;

    this->dt =
        std::chrono::duration<double>(elapsed_time) / std::chrono::seconds(1);

    this->carry_delay =
        this->target_duration - elapsed_time + this->carry_delay;
    if (this->carry_delay > this->max_duration)
        this->carry_delay = this->max_duration;
    if (this->carry_delay < -(this->max_duration))
        this->carry_delay = -(this->max_duration);
    this->last_time = current_time;

    this->showFps();
}
