#include "game.h"

Game::Game()
    : title{"Don't Eat the Yellow Snow!"},
      window{nullptr, SDL_DestroyWindow},
      renderer{nullptr, SDL_DestroyRenderer},
      running{true},
      background{nullptr, SDL_DestroyTexture} {}

Game::~Game() {
    this->background.reset();

    this->renderer.reset();
    this->window.reset();

    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << std::endl;
}

void Game::events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            this->running = false;
            return;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                this->running = false;
                return;
            default:
                break;
            }
        }
    }
}

void Game::draw() {
    SDL_RenderClear(this->renderer.get());

    SDL_RenderCopy(this->renderer.get(), this->background.get(), nullptr,
                   nullptr);
    SDL_RenderPresent(this->renderer.get());

    SDL_Delay(16);
}

void Game::run() {
    while (this->running) {
        this->events();

        this->draw();
    }
}
