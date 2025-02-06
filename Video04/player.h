#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"

class Player {
    public:
        Player(std::shared_ptr<SDL_Renderer> new_renderer)
            : renderer{new_renderer},
              image{nullptr, SDL_DestroyTexture},
              rect{0, PLAYER_Y, 0, 0} {}

        void init();
        void draw() const;

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
        SDL_Rect rect;
};

#endif
