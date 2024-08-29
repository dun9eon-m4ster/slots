#include "window.h"
#include "object.h"

#include "SDL.h"


Window::Window(const unsigned int &width, const unsigned int &height)
{
	sdl_window = SDL_CreateWindow(	"",
									SDL_WINDOWPOS_CENTERED, 
									SDL_WINDOWPOS_CENTERED,
									width,
									height, 
									0);
}

Window::~Window()
{
	SDL_DestroyWindow(sdl_window);
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

}

