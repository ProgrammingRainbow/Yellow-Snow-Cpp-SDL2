#include "game.h"

void Game::load_media() {
    this->background.reset(
        IMG_LoadTexture(this->renderer.get(), "images/background.png"));
    if (!this->background) {
        auto error =
            fmt::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->white.reset(IMG_LoadTexture(this->renderer.get(), "images/white.png"),
                      SDL_DestroyTexture);
    if (!this->white) {
        auto error =
            fmt::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->yellow.reset(
        IMG_LoadTexture(this->renderer.get(), "images/yellow.png"),
        SDL_DestroyTexture);
    if (!this->yellow) {
        auto error =
            fmt::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->collect.reset(Mix_LoadWAV("sounds/collect.ogg"));
    if (!this->collect) {
        auto error =
            fmt::format("Failed to load sound effect: {}", Mix_GetError());
        throw std::runtime_error(error);
    }

    this->hit.reset(Mix_LoadWAV("sounds/hit.ogg"));
    if (!this->hit) {
        auto error =
            fmt::format("Failed to load sound effect: {}", Mix_GetError());
        throw std::runtime_error(error);
    }

    this->music.reset(Mix_LoadMUS("music/winter_loop.ogg"));
    if (!this->music) {
        auto error = fmt::format("Failed to load music: {}", Mix_GetError());
        throw std::runtime_error(error);
    }
}
