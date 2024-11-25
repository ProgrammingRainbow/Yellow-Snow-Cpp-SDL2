#include "player.h"

Player::Player(std::shared_ptr<SDL_Renderer> renderer)
    : renderer{renderer},
      image{nullptr, SDL_DestroyTexture},
      y{374},
      top_offset{16},
      left_offset{47},
      right_offset{43},
      flip{SDL_FLIP_NONE} {}

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
    this->rect.x = (WINDOW_WIDTH - this->rect.w) / 2;
    this->x_pos = this->rect.x;
    this->keystate = SDL_GetKeyboardState(nullptr);
}

void Player::update(double dt) {
    if (this->keystate[SDL_SCANCODE_LEFT]) {
        this->x_pos -= PLAYER_SPEED * dt;
        this->rect.x = (int)this->x_pos;
        if (this->left() < 0) {
            this->set_left(0);
        }
        this->flip = SDL_FLIP_HORIZONTAL;
    }
    if (this->keystate[SDL_SCANCODE_RIGHT]) {
        this->x_pos += PLAYER_SPEED * dt;
        this->rect.x = (int)this->x_pos;
        if (this->right() > 800) {
            this->set_right(800);
        }
        this->flip = SDL_FLIP_NONE;
    }
}

void Player::draw() {
    SDL_RenderCopyEx(this->renderer.get(), this->image.get(), nullptr,
                     &this->rect, 0, nullptr, this->flip);
}
