#include "load_media.h"

void Game::load_media() {
    this->background.reset(
        IMG_LoadTexture(this->renderer.get(), "images/background.png"));
    if (!this->background) {
        auto error = fmt::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }
}
