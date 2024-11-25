#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fmt/format.h>
#include <iostream>
#include <memory>

constexpr int SDL_FLAGS = (SDL_INIT_VIDEO | SDL_INIT_AUDIO);
constexpr int IMG_FLAGS = IMG_INIT_PNG;
constexpr char WINDOW_TITLE[] = "Don't Eat the Yellow Snow!";
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr int PLAYER_SPEED = 5;

#endif
