#include "flake.h"

Flake::Flake(std::shared_ptr<SDL_Renderer> renderer,
             std::shared_ptr<SDL_Texture> image, SDL_Rect rect, bool is_white,
             std::mt19937 &gen)
    : renderer{renderer},
      image{image},
      rect{rect},
      is_white{is_white},
      gen{gen} {}

void Flake::reset(bool is_full) {
    (void)is_full;
    std::uniform_int_distribution<int> randx(0, (WINDOW_WIDTH - this->rect.w));

    std::uniform_int_distribution<int> randy(0, (WINDOW_HEIGHT - this->rect.y));

    this->rect.x = randx(this->gen);
    this->rect.y = randy(this->gen);
}

void Flake::draw() {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
