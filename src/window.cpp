#include "window.h"
#include "object.h"
#include "string"
#include "paintevent.h"
#include "painter.h"
#include "SDL_render.h"
#include "callbackevent.h"
#include "buttonclickevent.h"
#include "iostream"
#include "texture.h"
#include "texturemanager.h"

Window::Window(const unsigned int& width, const unsigned int& height, const std::string& window_title)
{
	_rect.x = 0;
	_rect.y = 0;
	_rect.w = width;
	_rect.h = height;

	_background_color = 0x4B0082;

	sdl_window = SDL_CreateWindow(	window_title.c_str(),
									SDL_WINDOWPOS_CENTERED, 
									SDL_WINDOWPOS_CENTERED,
									width,
									height, 
									0);

	sdl_renderer = SDL_CreateRenderer(sdl_window, -1, 0);
}

Window::~Window()
{
	SDL_DestroyWindow(sdl_window);
	SDL_DestroyRenderer(sdl_renderer);
}

void Window::addObject(Object* _new_object)
{
	object_array.push_back(std::shared_ptr<Object>(_new_object));
}

void Window::removeObject(Object* object)
{
	for (auto it = object_array.begin(); it != object_array.end(); it++)
	{
		if ((*it).get() == object)
			object_array.erase(it);
	}
}

void Window::notify(Event* event)
{
	for (auto it = object_array.begin(); it != object_array.end(); it++)
	{
		(*it)->handleEvent(event);
	}
}

void Window::redraw()
{
	Painter painter(sdl_renderer);

	painter.setRenderColor(_background_color);

	painter.drawRect(_rect);

	painter.drawTexture(TextureManager::instance()->texture("picture.bmp"), _rect);

	PaintEvent paint_event(&painter);
	for (auto it = object_array.begin(); it != object_array.end(); it++)
	{
		(*it)->handleEvent(&paint_event);
	}
}

void Window::setBackgroundColor(const Uint32& _new_background_color)
{
	_background_color = _new_background_color;
}

void Window::processSelfEvent(CallbackEvent* event)
{

}

