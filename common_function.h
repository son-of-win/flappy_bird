#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <SDL.h>
#include <string.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BFF = 32;
const int NUMS_THREAT = 3;

 static SDL_Surface* g_screen = NULL;
 static SDL_Surface* g_background = NULL;
 static SDL_Event g_event;
 static SDL_Surface* g_object = NULL;
// static SDL_Surface* g_img_menu = NULL;

namespace CommonFunc {
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void cleanup();
	//int ShowMenu(SDL_Surface* des, TTF_Font* font);
}

#endif // !COMMON_FUNCTION_H_
#pragma once

