#include "flake.h"

Flake::Flake(std::shared_ptr<SDL_Renderer> renderer,
             std::shared_ptr<SDL_Texture> image, bool white, std::mt19937 &gen)
    : renderer{renderer},
      image{image},
      white{white},
      ground{550},
      gen{gen} {}

void Flake::init() {
    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w,
                         &this->rect.h)) {
        auto error =
            fmt::format("Error while querying texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->reset(true);
}

void Flake::reset(bool full) {
    std::uniform_int_distribution<int> randx(0, (WINDOW_WIDTH - this->rect.w));

    int height = full ? WINDOW_HEIGHT * 2 : WINDOW_HEIGHT;
    std::uniform_int_distribution<int> randy(0, height);

    this->rect.x = randx(this->gen);
    this->rect.y = -randy(this->gen) - this->rect.h;
    this->y_pos = this->rect.y;
}

void Flake::update(double dt) {
    this->y_pos += FLAKE_SPEED * dt;
    this->rect.y = (int)this->y_pos;
    if (this->bottom() > this->ground) {
        this->reset(false);
    }
}

void Flake::draw() {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
