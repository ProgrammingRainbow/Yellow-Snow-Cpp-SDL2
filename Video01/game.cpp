#include "game.h"

Game::~Game() {
    this->renderer.reset();
    this->window.reset();

    SDL_Quit();

    std::cout << "all clean!" << '\n';
}

void Game::run() {
    SDL_RenderClear(this->renderer.get());

    SDL_RenderPresent(this->renderer.get());

    SDL_Delay(5000);
}
