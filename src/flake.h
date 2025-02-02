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
              gen{new_gen},
              pos_y{} {}

        void init();
        void reset(bool is_full);
        void update(double dt);
        void draw();

        inline int left() const { return this->rect.x; }
        inline int right() const { return this->rect.x + this->rect.w; }
        inline int bottom() const { return this->rect.y + this->rect.h; }
        inline bool isWhite() const { return this->is_white; }

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::shared_ptr<SDL_Texture> image;
        SDL_Rect rect;
        bool is_white;
        std::mt19937 &gen;
        double pos_y;
};

#endif
