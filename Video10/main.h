#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <random>
#include <thread>

constexpr int SDL_FLAGS = (SDL_INIT_VIDEO | SDL_INIT_AUDIO);
constexpr int IMG_FLAGS = IMG_INIT_PNG;
constexpr char WINDOW_TITLE[] = "Don't Eat the Yellow Snow!";
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr double PLAYER_SPEED = 300;
constexpr double FLAKE_SPEED = 300;
constexpr int FONT_SIZE = 24;
constexpr SDL_Color FONT_COLOR = {255, 255, 255, 255};
constexpr int CHUNK_SIZE = 1024;
constexpr double TARGET_FPS = 60;

#endif
