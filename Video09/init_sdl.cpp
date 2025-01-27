#include "game.h"

void Game::init_sdl() {
    if (SDL_Init(SDL_FLAGS) != 0) {
        auto error = fmt::format("Error initializing SDL: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    if ((IMG_Init(IMG_FLAGS) & IMG_FLAGS) != IMG_FLAGS) {
        auto error =
            fmt::format("Error initializing SDL_image: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (TTF_Init()) {
        auto error =
            fmt::format("Error initializing SDL_ttf: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    if ((Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG) != MIX_INIT_OGG) {
        auto error =
            fmt::format("Error initializing SDL_mixer: {}", Mix_GetError());
        throw std::runtime_error(error);
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
                      MIX_DEFAULT_CHANNELS, CHUNK_SIZE) < 0) {
        auto error =
            fmt::format("Error initializing SDL_mixer: {}", Mix_GetError());
        throw std::runtime_error(error);
    }

    this->window.reset(SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                                        WINDOW_HEIGHT, SDL_WINDOW_SHOWN),
                       SDL_DestroyWindow);
    if (!this->window) {
        auto error = fmt::format("Error creating window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->renderer.reset(
        SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer);
    if (!this->renderer) {
        auto error = fmt::format("Error creating renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}
