#include "player.h"
#include "game.h"

Player::Player(std::shared_ptr<SDL_Renderer> renderer)
    : renderer{renderer},
      image{nullptr, SDL_DestroyTexture},
      flip{SDL_FLIP_NONE},
      y{374},
      speed{300},
      top_offset{16},
      left_offset{47},
      right_offset{43} {

    this->image.reset(
        IMG_LoadTexture(this->renderer.get(), "images/player.png"));
    if (!this->image) {
        auto error =
            fmt::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    // Get a rect from the image.
    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w,
                         &this->rect.h)) {
        auto error =
            fmt::format("Error while querying texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->keystate = SDL_GetKeyboardState(nullptr);
    this->rect.y = this->y;
    this->rect.x = (Game::width - this->rect.w) / 2;
}

void Player::update(double delta_time) {
    if (this->keystate[SDL_SCANCODE_LEFT]) {
        this->rect.x -= static_cast<int>(delta_time * this->speed + 0.5);
        if (this->left() < 0) {
            this->set_left(0);
        }
        this->flip = SDL_FLIP_HORIZONTAL;
    }
    if (this->keystate[SDL_SCANCODE_RIGHT]) {
        this->rect.x += static_cast<int>(delta_time * this->speed + 0.5);
        if (this->right() > 800) {
            this->set_right(800);
        }
        this->flip = SDL_FLIP_NONE;
    }
}

void Player::draw() {
    if (SDL_RenderCopyEx(this->renderer.get(), this->image.get(), nullptr,
                         &this->rect, 0, nullptr, this->flip)) {
        auto error =
            fmt::format("Error while rendering texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}
