#include "flake.h"

void Flake::reset(bool full) {
    std::uniform_int_distribution<int> randx(0, (WINDOW_WIDTH - this->rect.w));

    int height = full ? WINDOW_HEIGHT * 2 : WINDOW_HEIGHT;
    std::uniform_int_distribution<int> randy(0, height);

    this->rect.x = randx(this->gen);
    this->rect.y = -randy(this->gen) - this->rect.h;
}

void Flake::init() { this->reset(true); }

void Flake::update() {
    this->rect.y += FLAKE_VEL;
    if (this->bottom() > GROUND) {
        this->reset(false);
    }
}

void Flake::draw() {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
