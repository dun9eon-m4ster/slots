#include "texture.h"
#include "SDL_render.h"

Texture::Texture(SDL_Surface* _new_sdl_surface)
	: sdl_surface(_new_sdl_surface)
{
}

Texture::~Texture()
{
	SDL_FreeSurface(sdl_surface);
}

SDL_Surface* Texture::get()
{
	return sdl_surface;
}
