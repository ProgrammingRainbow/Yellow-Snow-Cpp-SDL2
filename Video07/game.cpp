#include "game.h"
#include <memory>

Game::~Game() {
    this->flakes.clear();
    this->player.reset();

    this->yellow_image.reset();
    this->white_image.reset();
    this->background.reset();

    this->renderer.reset();
    this->window.reset();

    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << '\n';
}

void Game::init() {
    this->initSdl();
    this->loadMedia();

    this->player.reset(new Player(this->renderer));
    this->player->init();

    // white flakes
    for (int i = 0; i < 10; i++) {
        auto flake = std::make_unique<Flake>(this->renderer, this->white_image,
                                             this->white_rect, true, this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }

    // yellow flakes
    for (int i = 0; i < 5; i++) {
        auto flake =
            std::make_unique<Flake>(this->renderer, this->yellow_image,
                                    this->yellow_rect, false, this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }
}

void Game::collision(std::unique_ptr<Flake> &flake) {
    if (flake->bottom() > this->player->top() &&
        flake->right() > this->player->left() &&
        flake->left() < this->player->right()) {
        if (flake->isWhite()) {
            flake->reset(false);
        } else {
            this->is_playing = false;
        }
    }
}

void Game::reset() {
    if (!this->is_playing) {
        this->is_playing = true;
        for (auto &flake : this->flakes) {
            flake->init();
        }
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
            case SDL_SCANCODE_SPACE:
                this->reset();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    if (this->is_playing) {
        this->player->update();
        for (auto &flake : this->flakes) {
            flake->update();
            this->collision(flake);
        }
    }
}

void Game::draw() const {
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
