#include "flake.h"

void Flake::reset(bool is_full) {

    int height = is_full ? WINDOW_HEIGHT * 2 : WINDOW_HEIGHT;

    std::uniform_int_distribution<int> randX(0, WINDOW_WIDTH - this->rect.w);

    std::uniform_int_distribution<int> randY(0, height);

    this->rect.x = randX(this->gen);
    this->rect.y = -randY(this->gen) - this->rect.h;
    this->pos_y = this->rect.y;
}

void Flake::update(double dt) {
    this->pos_y += FLAKE_VEL * dt;
    this->rect.y = (int)this->pos_y;
    if (this->bottom() > GROUND) {
        this->reset(false);
    }
}

void Flake::draw() const {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
