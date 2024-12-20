#include "game.h"

Game::Game()
    : window{nullptr, SDL_DestroyWindow},
      renderer{nullptr, SDL_DestroyRenderer},
      running{true},
      background{nullptr, SDL_DestroyTexture},
      white_image{nullptr, SDL_DestroyTexture},
      yellow_image{nullptr, SDL_DestroyTexture},
      white_rect{0, 0, 0, 0},
      yellow_rect{0, 0, 0, 0},
      rd{},
      gen{rd()} {}

Game::~Game() {
    this->flakes.clear();
    this->player.reset();

    this->background.reset();

    this->renderer.reset();
    this->window.reset();

    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << '\n';
}

void Game::init() {
    this->player.reset(new Player(this->renderer));
    this->player->init();

    for (int i = 0; i < 10; i++) {
        auto flake = std::make_unique<Flake>(this->renderer, this->white_image,
                                             this->white_rect, true, this->gen);
        flake->reset(true);
        this->flakes.emplace_back(std::move(flake));
    }

    for (int i = 0; i < 5; i++) {
        auto flake =
            std::make_unique<Flake>(this->renderer, this->yellow_image,
                                    this->yellow_rect, false, this->gen);
        flake->reset(true);
        this->flakes.emplace_back(std::move(flake));
    }
}

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
        default:
            break;
        }
    }
}

void Game::update() { this->player->update(); }

void Game::draw() {
    SDL_RenderClear(this->renderer.get());

    SDL_RenderCopy(this->renderer.get(), this->background.get(), nullptr,
                   nullptr);
    this->player->draw();
    for (auto &flake : this->flakes) {
        flake->draw();
    }

    SDL_RenderPresent(this->renderer.get());
}

void Game::run() {
    while (this->running) {
        this->events();

        this->update();

        this->draw();

        SDL_Delay(16);
    }
}
