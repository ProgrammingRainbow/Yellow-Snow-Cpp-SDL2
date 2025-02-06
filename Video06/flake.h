#ifndef FLAKE_H
#define FLAKE_H

#include "main.h"

class Flake {
    public:
        Flake(std::shared_ptr<SDL_Renderer> new_renderer,
              std::shared_ptr<SDL_Texture> new_image, SDL_Rect new_rect,
              bool new_is_white, std::mt19937 &new_gen)
            : renderer{new_renderer},
              image{new_image},
              rect{new_rect},
              is_white{new_is_white},
              gen{new_gen} {}

        void reset();
        void update();
        void draw() const;

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::shared_ptr<SDL_Texture> image;
        SDL_Rect rect;
        bool is_white;
        std::mt19937 &gen;
};

#endif
