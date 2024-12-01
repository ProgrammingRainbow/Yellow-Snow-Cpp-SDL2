#include "player.h"
#include "main.h"

Player::Player(std::shared_ptr<SDL_Renderer> renderer)
    : renderer{renderer},
      image{nullptr, SDL_DestroyTexture},
      rect{0, 374, 0, 0},
      keystate{nullptr},
      flip{SDL_FLIP_NONE},
      top_offset{16},
      left_offset{47},
      right_offset{43} {}

void Player::init() {
    this->image.reset(
        IMG_LoadTexture(this->renderer.get(), "images/player.png"));
    if (!this->image) {
        auto error = fmt::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w,
                         &this->rect.h) != 0) {
        auto error = fmt::format("Error querying Texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->rect.x = (WINDOW_WIDTH - this->rect.w) / 2;
    this->keystate = SDL_GetKeyboardState(nullptr);
}

void Player::update() {
    if (this->keystate[SDL_SCANCODE_LEFT]) {
        this->rect.x -= PLAYER_SPEED;
        if (this->left() < 0) {
            this->set_left();
        }
        this->flip = SDL_FLIP_HORIZONTAL;
    }

    if (this->keystate[SDL_SCANCODE_RIGHT]) {
        this->rect.x += PLAYER_SPEED;
        if (this->right() > WINDOW_WIDTH) {
            this->set_right();
        }

        this->flip = SDL_FLIP_NONE;
    }
}

void Player::draw() {
    SDL_RenderCopyEx(this->renderer.get(), this->image.get(), nullptr,
                     &this->rect, 0, nullptr, this->flip);
}
