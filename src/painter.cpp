#include "painter.h"
#include "SDL_render.h"
#include "iostream"
#include "texture.h"


Painter::Painter(SDL_Renderer* _new_sdl_renderer)
	: sdl_renderer(_new_sdl_renderer)
{
}

Painter::~Painter()
{
	SDL_RenderPresent(sdl_renderer);
}

void Painter::setRenderColor(const Uint32& render_color)
{
	SDL_SetRenderDrawColor(	sdl_renderer,
							(render_color & 0x00ff0000) >> 16,
							(render_color & 0x0000ff00) >> 8, 
							(render_color & 0x000000ff), 
							(render_color & 0xff000000) >> 24);
}

void Painter::setRenderColor(const Color& render_color)
{
	if (render_color == Color::Red)
		setRenderColor(0x00ff0000);
	else if (render_color == Color::Green)
		setRenderColor(0x0000ff00);
	else if (render_color == Color::Blue)
		setRenderColor(0x000000ff);
	else if (render_color == Color::Yellow)
		setRenderColor(0x00ffff00);
	else if (render_color == Color::Magenta)
		setRenderColor(0x00ff00ff);
	else if (render_color == Color::Cyan)
		setRenderColor(0x0000ffff);
		//else if (render_color == Color::)
	//	setRenderColor(0x00000000);
	else
		setRenderColor(0x00000000);
}

void Painter::drawRect(const Rect& rect)
{
	SDL_Rect sdl_rect;
	sdl_rect.x = rect.x();
	sdl_rect.y = rect.y();
	sdl_rect.w = rect.width();
	sdl_rect.h = rect.height();

	SDL_RenderFillRect(sdl_renderer, &sdl_rect);
}

void Painter::drawLine(const int x1, const int y1, const int x2, const int y2)
{
	SDL_RenderDrawLine(sdl_renderer, x1,y1,x2,y2);
}

void Painter::drawTexture(std::shared_ptr<Texture> texture, const Rect& dist, const Rect& src)
{
	if (!texture)
		return;

	auto sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, texture->get());

	auto sdl_src = src.sdlRect();
	auto sdl_dist = dist.sdlRect();

	SDL_RenderCopy(sdl_renderer, sdl_texture, src.isNull() ? NULL : &sdl_src, dist.isNull() ? NULL : &sdl_dist);
	SDL_DestroyTexture(sdl_texture);
}

void Painter::clear()
{
	SDL_RenderClear(sdl_renderer);
}


