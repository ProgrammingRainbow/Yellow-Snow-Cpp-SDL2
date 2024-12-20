#ifndef FLAKE_H
#define FLAKE_H

#include "main.h"

class Flake {
    public:
        Flake(std::shared_ptr<SDL_Renderer> renderer,
              std::shared_ptr<SDL_Texture> image, SDL_Rect rect, bool is_white,
              std::mt19937 &gen);

        void reset(bool is_full);
        void update();
        void draw();

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::shared_ptr<SDL_Texture> image;
        SDL_Rect rect;
        bool is_white;
        std::mt19937 &gen;
};

#endif
