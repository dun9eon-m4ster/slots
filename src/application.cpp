#include "application.h"
#include "SDL.h"
#include "iostream"
#include "chrono"
#include "window.h"
#include "event.h"
#include "object.h"
#include "rect.h"
#include "mouseevent.h"
#include "chrono"
#include "callbackevent.h"
#include "SDL_timer.h"
#include "texturemanager.h"
#include "fpsevent.h"


Application::Application()
    :   application_state(State::Waiting),
        application_window(nullptr)
{
}

int Application::exec()
{
    if (init() < 0)
        return -1;

    application_state = State::Running;
	return mainEventLoop();
}

void Application::setApplicationWindow(Window* _new_window)
{
    application_window = std::shared_ptr<Window>(_new_window);
}

int Application::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    TextureManager::instance();

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
        else if (type == SDL_EventType::SDL_USEREVENT)
        {
            auto _new_custom_event = static_cast<Event*>(sdl_event.user.data1);

            if      (auto callback_event = dynamic_cast<CallbackEvent*>(_new_custom_event))
                application_window->processSelfEvent(callback_event);
            else
                application_window->notify(_new_custom_event);
            
            delete _new_custom_event;
        }
    }
}

void Application::processRender()
{
    static auto time = SDL_GetTicks();
    static int counter = 0;
    counter++;

    auto current_time = SDL_GetTicks();
    auto msecs_elapsed = current_time - time;
    if (msecs_elapsed >= 1000)
    {
        SDL_Event _new_event;
        _new_event.type = SDL_EventType::SDL_USEREVENT;
        _new_event.user.timestamp = SDL_GetTicks();
        _new_event.user.data1 = new FpsEvent(counter);
        SDL_PushEvent(&_new_event);

        time = current_time;
        counter = 0;
    }

    application_window->redraw();
}
