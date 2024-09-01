#ifndef WINDOW_H
#define WINDOW_H

#include "vector"
#include "memory"
#include "string"
#include "SDL_stdinc.h"
#include "SDL_rect.h"

class SDL_Window;
class SDL_Renderer;
class Object;
class Event;
class CallbackEvent;

class Window
{
public:
	Window(const unsigned int& width, const unsigned int& height, const std::string& window_title = std::string(""));
	virtual ~Window();
	void addObject(Object* _new_object);
	void removeObject(Object* object);
	void notify(Event *event);
	void redraw();
	void setBackgroundColor(const Uint32& _new_background_color);
	virtual void processSelfEvent(CallbackEvent *event);

private:
	std::vector<std::shared_ptr<Object>> object_array;
	SDL_Window* sdl_window;
	SDL_Renderer* sdl_renderer;
	SDL_Rect _rect;
	Uint32 _background_color;
};



#endif // WINDOW_H
