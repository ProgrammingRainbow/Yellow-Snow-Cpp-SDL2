#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
constexpr int PLAYER_LEFT_OFFSET = 45;
constexpr int PLAYER_RIGHT_OFFSET = 45;
constexpr int PLAYER_TOP_OFFSET = 16;
constexpr int PLAYER_VEL = 5;

#endif
