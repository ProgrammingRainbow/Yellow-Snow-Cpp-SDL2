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
    this->keystate = SDL_GetKeyboardState(nullptr);
}

void Player::update() {
    if (this->keystate[SDL_SCANCODE_LEFT] || this->keystate[SDL_SCANCODE_A]) {
        this->rect.x -= PLAYER_VEL;
        if (this->left() < 0) {
            this->setLeft();
        }
        this->flip = SDL_FLIP_HORIZONTAL;
    }
    if (this->keystate[SDL_SCANCODE_RIGHT] || this->keystate[SDL_SCANCODE_D]) {
        this->rect.x += PLAYER_VEL;
        if (this->right() > WINDOW_WIDTH) {
            this->setRight();
        }
        this->flip = SDL_FLIP_NONE;
    }
}

void Player::draw() const {
    SDL_RenderCopyEx(this->renderer.get(), this->image.get(), nullptr,
                     &this->rect, 0, nullptr, this->flip);
}
