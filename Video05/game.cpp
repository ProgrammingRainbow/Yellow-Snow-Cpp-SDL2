#include "game.h"
#include "player.h"

Game::~Game() {
    this->player.reset();

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
            break;
        default:
            break;
        }
    }
}

void Game::update() { this->player->update(); }

void Game::draw() const {
    SDL_RenderClear(this->renderer.get());

    SDL_RenderCopy(this->renderer.get(), this->background.get(), nullptr,
                   nullptr);
    this->player->draw();

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
