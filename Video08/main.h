#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <format>
#include <iostream>
#include <memory>
#include <random>

constexpr Uint32 SDL_FLAGS = SDL_INIT_EVERYTHING;
constexpr int IMG_FLAGS = IMG_INIT_PNG;

constexpr char WINDOW_TITLE[] = "Don't Eat the Yellow Snow!";
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

constexpr int PLAYER_Y = 376;
constexpr int PLAYER_TOP_OFFSET = 16;
constexpr int PLAYER_LEFT_OFFSET = 47;
constexpr int PLAYER_RIGHT_OFFSET = 43;
constexpr int PLAYER_VEL = 5;

constexpr int GROUND = 550;
constexpr int FLAKE_VEL = 5;

constexpr int FONT_SIZE = 32;
constexpr SDL_Color FONT_COLOR = {255, 255, 255, 255};

#endif
