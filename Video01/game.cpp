#include "game.h"

Game::Game()
    : title{"Don't Eat the Yellow Snow!"},
      window{nullptr, SDL_DestroyWindow},
      renderer{nullptr, SDL_DestroyRenderer} {}

Game::~Game() {
    this->renderer.reset();
    this->window.reset();

    SDL_Quit();

    std::cout << "all clean!" << std::endl;
}

void Game::draw() {
    SDL_RenderClear(this->renderer.get());

    SDL_RenderPresent(this->renderer.get());

    SDL_Delay(5000);
}

void Game::run() { this->draw(); }
