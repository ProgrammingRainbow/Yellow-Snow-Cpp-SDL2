#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"

class Player {
    public:
        Player(std::shared_ptr<SDL_Renderer> renderer);

        void init();
        void draw();

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
        SDL_Rect rect;
        const unsigned int y;
};

#endif
