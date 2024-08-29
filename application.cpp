#include "application.h"
#include "SDL.h"
#include "iostream"
#include "chrono"
#include "window.h"
#include "event.h"
#include "object.h"
#include "rect.h"


class GraphicsObject : public Object
{
public:
    GraphicsObject(const Rect& _new_rect)
        : _rect(_new_rect)
    {}

    virtual void handleEvent(Event* event)
    {
        if (auto mouse_move_event = dynamic_cast<MouseMoveEvent*>(event))
        {
            if(_rect.contains(mouse_move_event->pos()))
                mouseMoveEvent(mouse_move_event);
        }  
    }

protected:
    virtual void mouseMoveEvent(MouseMoveEvent *event)
    {
        std::cout << "GraphicsObject::mouseMoveEvent(" << event->pos().x() << "," << event->pos().y() << ")" << std::endl;
    }

private:
    Rect _rect;
};




Application::Application()
    :   application_state(State::Waiting),
        application_window(new Window(1000, 800))
{
    application_window->addObject(new GraphicsObject(Rect(200, 200, 50, 50)));
}

int Application::exec()
{
    if (init() < 0)
        return -1;

    application_state = State::Running;
	return mainEventLoop();
}

int Application::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}

int Application::mainEventLoop()
{
    while (application_state == State::Running)
    {
        processEvents();
        processRender();
    }

    return 0;
}

void Application::processEvents()
{
    SDL_Event sdl_event;
    while (SDL_PollEvent(&sdl_event))
    {
        std::shared_ptr<Event> event(nullptr);

        auto type = sdl_event.type;

        if      (type == SDL_EventType::SDL_QUIT)
        {
            application_state = State::Stopping;
        }
        else if (type == SDL_EventType::SDL_MOUSEMOTION)
        {
            MouseMoveEvent _new_mouse_move_event(Point(sdl_event.motion.x, sdl_event.motion.y));
            application_window->notify(&_new_mouse_move_event);
        }
        else if (type == SDL_EventType::SDL_MOUSEBUTTONDOWN)
        {
            MousePressEvent _new_mouse_press_event( Point(sdl_event.button.x, sdl_event.button.y),
                                                    mouseButtonFromSDL(sdl_event.button.which));
            application_window->notify(&_new_mouse_press_event);
        }
        else if (type == SDL_EventType::SDL_MOUSEBUTTONUP)
        {
            MouseReleaseEvent _new_mouse_release_event( Point(sdl_event.button.x, sdl_event.button.y),
                                                        mouseButtonFromSDL(sdl_event.button.which));
            application_window->notify(&_new_mouse_release_event);
        }
    }
}

void Application::processRender()
{

}
