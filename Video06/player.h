#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"

class Player {
    public:
        Player(std::shared_ptr<SDL_Renderer> renderer);

        void init();
        void update();
        void draw();

        inline int left() const { return this->rect.x + this->left_offset; }
        inline int right() const {
            return this->rect.x + this->rect.w - this->right_offset;
        }
        inline int top() const { return this->rect.y + this->top_offset; }
        inline void set_left() { this->rect.x = -this->left_offset; }
        inline void set_right() {
            this->rect.x = WINDOW_WIDTH - this->rect.w + this->right_offset;
        }

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
        SDL_Rect rect;
        const Uint8 *keystate;
        SDL_RendererFlip flip;
        const int top_offset;
        const int left_offset;
        const int right_offset;
};

#endif
