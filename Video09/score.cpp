#include "score.h"

void Score::init() {
    this->font.reset(TTF_OpenFont("fonts/freesansbold.ttf", FONT_SIZE));
    if (!this->font) {
        auto error =
            std::format("Error loading True Type Font: {}", TTF_GetError());
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
            std::format("Error creating Surface from Text: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    this->rect.w = this->surface->w;
    this->rect.h = this->surface->h;

    this->image.reset(SDL_CreateTextureFromSurface(this->renderer.get(),
                                                   this->surface.get()));
    if (!this->image) {
        auto error = std::format("Error creating Texture from Surface: {}",
                                 SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Score::draw() const {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
