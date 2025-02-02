#ifndef SCORE_H
#define SCORE_H

#include "main.h"

class Score {
    public:
        Score(std::shared_ptr<SDL_Renderer> new_renderer)
            : renderer{new_renderer},
              font{nullptr, TTF_CloseFont},
              surface{nullptr, SDL_FreeSurface},
              image{nullptr, SDL_DestroyTexture},
              rect{10, 10, 0, 0},
              score{0} {}

        void init();
        void increment();
        void reset();
        void draw();

    private:
        void update();

        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
        SDL_Rect rect;
        unsigned int score;
};

#endif
