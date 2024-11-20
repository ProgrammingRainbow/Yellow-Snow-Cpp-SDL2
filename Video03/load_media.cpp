#include "game.h"

void Game::load_media() {
    this->background.reset(
        IMG_LoadTexture(this->renderer.get(), "images/background.png"));
    if (!this->background) {
        auto error =
            fmt::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}
