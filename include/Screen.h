#ifndef SCREEN_H
#define SCREEN_H

#ifdef __linux__
	#include <SDL2/SDL.h>
#elif _WIN32 || __APPLE__
	#include <SDL.h>
#endif

#include <cstddef>

#include "Image.h"
#include "Vector2.h"

class Screen
{
private:
	static SDL_Surface* _surface;

public:
	static void Init ();
	static void Quit (); 

	static void Draw (Image* image, const Vector2& pos);

	static void Render ();
	static void Clear ();

	static std::size_t GetWidth ();
	static std::size_t GetHeight ();
};

#endif