#ifndef PAINTER_H
#define PAINTER_H

#include "rect.h"
#include "SDL_stdinc.h"
#include "memory"

enum class Color
{
	Black = 0,

	Red,
	Green,
	Blue,
	Yellow,
	Magenta,
	Cyan
};

class Texture;
struct SDL_Renderer;

class Painter
{
public:
	Painter(SDL_Renderer* _new_sdl_renderer);
	~Painter();
	void setRenderColor(const Uint32& render_color);
	void setRenderColor(const Color &render_color);
	void drawRect(const Rect &rect);
	void drawLine(const int x1, const int y1, const int x2, const int y2);
	void drawTexture(std::shared_ptr<Texture> texture, const Rect& dist, const Rect &src = Rect());
	void clear();
	SDL_Renderer* sdlRenderer();

private:
	SDL_Renderer *sdl_renderer;
};

#endif // PAINTER_H
