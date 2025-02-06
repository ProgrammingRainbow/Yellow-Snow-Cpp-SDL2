#include "game.h"

Game::~Game() {
    this->renderer.reset();
    this->window.reset();

    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << '\n';
}

void Game::init() { this->initSdl(); }

void Game::events() {
    while (SDL_PollEvent(&this->event)) {
        switch (this->event.type) {
        case SDL_QUIT:
            this->running = false;
            return;
        case SDL_KEYDOWN:
            switch (this->event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                this->running = false;
                return;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Game::draw() const {
    SDL_RenderClear(this->renderer.get());

    SDL_RenderPresent(this->renderer.get());
}

void Game::run() {
    while (this->running) {
        this->events();

        this->draw();

        SDL_Delay(16);
    }
}
