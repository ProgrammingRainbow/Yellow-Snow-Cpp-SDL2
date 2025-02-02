#include "game.h"

void Game::loadMedia() {
    this->background.reset(
        IMG_LoadTexture(this->renderer.get(), "images/background.png"));
    if (!this->background) {
        auto error =
            std::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}
