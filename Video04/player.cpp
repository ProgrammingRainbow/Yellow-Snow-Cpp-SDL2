#include "player.h"
#include "game.h"

Player::Player(std::shared_ptr<SDL_Renderer> renderer)
    : renderer{renderer},
      image{nullptr, SDL_DestroyTexture},
      y{374} {}

void Player::init() {
    this->image.reset(
        IMG_LoadTexture(this->renderer.get(), "images/player.png"));
    if (!this->image) {
        auto error =
            fmt::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w,
                         &this->rect.h)) {
        auto error =
            fmt::format("Error while querying texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->rect.y = this->y;
    this->rect.x = (Game::width - this->rect.w) / 2;
}

void Player::draw() {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}