#include "game.h"

Game::Game()
    : title{"Don't Eat the Yellow Snow!"},
      window{nullptr, SDL_DestroyWindow},
      renderer{nullptr, SDL_DestroyRenderer},
      running{true},
      background{nullptr, SDL_DestroyTexture},
      white{nullptr, SDL_DestroyTexture},
      yellow{nullptr, SDL_DestroyTexture},
      rd{},
      gen{rd()},
      playing{true} {}

Game::~Game() {
    this->flakes.clear();
    this->player.reset();

    this->yellow.reset();
    this->white.reset();
    this->background.reset();

    this->renderer.reset();
    this->window.reset();

    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << std::endl;
}

void Game::init() {
    this->player.reset(new Player(this->renderer));
    this->player->init();

    for (int i = 0; i < 10; i++) {
        auto flake = std::make_unique<Flake>(this->renderer, this->white, true,
                                             this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }
    for (int i = 0; i < 5; i++) {
        auto flake = std::make_unique<Flake>(this->renderer, this->yellow,
                                             false, this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }
}

void Game::collision(std::unique_ptr<Flake> &flake) {
    if (flake->bottom() > this->player->top() &&
        flake->right() > this->player->left() &&
        flake->left() < this->player->right()) {
        if (flake->is_white()) {
            flake->reset(false);
        } else {
            this->playing = false;
        }
    }
}

void Game::reset() {
    if (!this->playing) {
        this->playing = true;
        for (auto &flake : this->flakes) {
            flake->reset(true);
        }
    }
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
            case SDL_SCANCODE_SPACE:
                this->reset();
                break;
            default:
                break;
            }
        }
    }
}

void Game::update() {
    if (this->playing) {
        this->player->update();

        for (auto &flake : this->flakes) {
            flake->update();
            this->collision(flake);
        }
    }
}

void Game::draw() {
    SDL_RenderClear(this->renderer.get());

    SDL_RenderCopy(this->renderer.get(), this->background.get(), nullptr,
                   nullptr);
    this->player->draw();
    for (auto &flake : this->flakes) {
        flake->draw();
    }

    SDL_RenderPresent(this->renderer.get());

    SDL_Delay(16);
}

void Game::run() {
    while (this->running) {
        this->events();

        this->update();

        this->draw();
    }
}
