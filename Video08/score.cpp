#include "score.h"

void Score::init() {
    this->font.reset(TTF_OpenFont("fonts/freesansbold.ttf", FONT_SIZE));
    if (!this->font) {
        auto error = std::format("Error creating font: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    this->update();
}

void Score::increment() {
    this->score++;
    this->update();
}

void Score::reset() {
    this->score = 0;
    this->update();
}

void Score::update() {

    std::string score_text{"Score: " + std::to_string(this->score)};

    this->surface.reset(TTF_RenderText_Blended(this->font.get(),
                                               score_text.c_str(), FONT_COLOR));
    if (!this->surface) {
        auto error =
            std::format("Error creating a surface: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->image.reset(
        SDL_CreateTextureFromSurface(this->renderer.get(), surface.get()));
    if (!this->image) {
        auto error =
            std::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w,
                         &this->rect.h)) {
        auto error =
            std::format("Error while querying texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Score::draw() {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
