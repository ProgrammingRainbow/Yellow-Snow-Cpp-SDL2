#include "player.h"

void Player::init() {
    this->image.reset(
        IMG_LoadTexture(this->renderer.get(), "images/player.png"));
    if (!this->image) {
        auto error = std::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w,
                         &this->rect.h)) {
        auto error = std::format("Error querying Texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->rect.x = (WINDOW_WIDTH - this->rect.w) / 2;
}

void Player::draw() const {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
