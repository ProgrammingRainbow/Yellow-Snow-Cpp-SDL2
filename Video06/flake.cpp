#include "flake.h"

void Flake::reset() {
    std::uniform_int_distribution<int> randX(0, WINDOW_WIDTH - this->rect.w);

    std::uniform_int_distribution<int> randY(0, WINDOW_HEIGHT - this->rect.h);

    this->rect.x = randX(this->gen);
    this->rect.y = randY(this->gen);
}

void Flake::draw() const {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
