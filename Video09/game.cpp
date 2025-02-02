#include "game.h"

Game::~Game() {
    Mix_HaltMusic();
    Mix_HaltChannel(-1);

    this->collect.reset();
    this->hit.reset();
    this->music.reset();

    this->score.reset();
    this->flakes.clear();
    this->player.reset();

    this->yellow_image.reset();
    this->white_image.reset();
    this->background.reset();

    this->renderer.reset();
    this->window.reset();

    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << std::endl;
}

void Game::init() {
    this->initSdl();
    this->loadMedia();

    this->player.reset(new Player(this->renderer));
    this->player->init();

    for (int i = 0; i < 10; i++) {
        auto flake = std::make_unique<Flake>(this->renderer, this->white_image,
                                             this->white_rect, true, this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }
    for (int i = 0; i < 5; i++) {
        auto flake =
            std::make_unique<Flake>(this->renderer, this->yellow_image,
                                    this->yellow_rect, false, this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }

    this->score.reset(new Score(this->renderer));
    this->score->init();

    if (Mix_PlayMusic(this->music.get(), -1)) {
        auto error = std::format("Error playing music: {}", Mix_GetError());
        throw std::runtime_error(error);
    }
}

void Game::collision(std::unique_ptr<Flake> &flake) {
    if (flake->bottom() > this->player->top() &&
        flake->right() > this->player->left() &&
        flake->left() < this->player->right()) {
        if (flake->isWhite()) {
            flake->reset(false);
            this->score->increment();
            Mix_PlayChannel(-1, this->collect.get(), 0);
        } else {
            Mix_HaltMusic();
            Mix_PlayChannel(-1, this->hit.get(), 0);
            this->paused = true;
        }
    }
}

void Game::reset() {
    if (this->paused) {
        this->paused = false;
        for (auto &flake : this->flakes) {
            flake->reset(true);
        }
        this->score->reset();
        if (!this->muted) {
            Mix_PlayMusic(this->music.get(), -1);
        }
    }
}

void Game::toggleMute() {
    if (this->muted) {
        this->muted = false;
        if (Mix_PlayingMusic()) {
            Mix_ResumeMusic();
        } else {
            if (!this->paused) {
                Mix_PlayMusic(this->music.get(), -1);
            }
        }
    } else {
        this->muted = true;
        Mix_PauseMusic();
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
            case SDL_SCANCODE_M:
                this->toggleMute();
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
    if (!this->paused) {
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
    this->score->draw();

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
