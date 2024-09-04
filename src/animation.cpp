#include "animation.h"
#include "cmath"
#include "SDL_timer.h"
#include "iostream"
#include "memory"
#include "atomic"
#include "chrono"



uint32_t callback(uint32_t interval, void* data)
{
    std::cout << "callback()" << std::endl;

    auto pimpl = static_cast<Pimpl*>(data);

    pimpl->current_value += pimpl->speed;
    if (pimpl->current_value >= pimpl->end_value)
    {
        if (pimpl->mode == Animation::Overlap)
            pimpl->current_value = pimpl->start_value;
        else if (pimpl->mode == Animation::Stop)
        {
            pimpl->is_running = false;
            return 0;
        }
    }


    if (SDL_GetTicks() >= pimpl->end_time)
    {
        pimpl->is_running = false;
        return 0;
    }

    return interval;
}


Animation::Animation()
    : pimpl(new Pimpl)
{}

Animation::~Animation()
{
    delete pimpl;
}

void Animation::setValueRange(const uint32_t& start, const uint32_t& end)
{
    pimpl->start_value = start;
    pimpl->end_value = end;
}

uint32_t Animation::currentValue() const
{
    return pimpl->current_value;
}

void Animation::start(const uint32_t& duration)
{
    pimpl->is_running = true;

    pimpl->end_time = SDL_GetTicks() + duration;
    SDL_AddTimer(pimpl->tick, callback, pimpl);
}

void Animation::setTick(const uint32_t& tick)
{
    pimpl->tick = tick;
}

void Animation::setSpeed(const uint32_t& speed)
{
    pimpl->speed = speed;
}

bool Animation::isRunning() const
{
    return pimpl->is_running;
}

Pimpl::Pimpl()
    :   end_time(0),
        is_running(false),
        start_value(0),
        end_value(0),
        current_value(0),
        tick(100),
        speed(1),
        mode(Animation::Overlap)
{
}
