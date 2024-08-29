#ifndef WINDOW_H
#define WINDOW_H

#include "vector"
#include "memory"

class SDL_Window;
class Object;
class Event;

class Window
{
public:
	Window(const unsigned int& width, const unsigned int& height);
	~Window();
	void addObject(Object* _new_object);
	void removeObject(Object* object);
	void notify(Event *event);
	void redraw();

private:
	std::vector<std::shared_ptr<Object>> object_array;
	SDL_Window* sdl_window;
};



#endif // WINDOW_H
