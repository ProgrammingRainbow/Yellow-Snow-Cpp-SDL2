#include "init_sdl.h"

void Game::initSdl() {
    if (SDL_Init(SDL_FLAGS) != 0) {
        auto error = std::format("Error initializing SDL2: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    if ((IMG_Init(IMG_FLAGS) & IMG_FLAGS) != IMG_FLAGS) {
        auto error =
            std::format("Error initializing SDL_image: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (TTF_Init()) {
        auto error =
            std::format("Error initializing SDL_ttf: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    if ((Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG) != MIX_INIT_OGG) {
        auto error =
            std::format("Error initializing SDL_mixer: {}", Mix_GetError());
        throw std::runtime_error(error);
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
                      MIX_DEFAULT_CHANNELS, CHUNK_SIZE) < 0) {
        auto error =
            std::format("Error initializing SDL_mixer: {}", Mix_GetError());
        throw std::runtime_error(error);
    }

    this->window.reset(SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                        WINDOW_HEIGHT, 0));
    if (!this->window) {
        auto error = std::format("Error creating Window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->renderer.reset(
        SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer);
    if (!this->renderer) {
        auto error = std::format("Error creating Renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> icon_surf{
        IMG_Load("images/yellow.png"), SDL_FreeSurface};
    if (!icon_surf) {
        auto error = std::format("Error loading Surface: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    SDL_SetWindowIcon(this->window.get(), icon_surf.get());
}
