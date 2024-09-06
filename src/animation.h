#ifndef ANIMATION_H
#define ANIMATION_H

#include "cstddef"
#include "SDL.h"
#include "iostream"

struct Pimpl;

class Animation
{
public:
    enum Mode
    {
        Overlap = 0,
        Stop
    };

    Animation();
    ~Animation();

    void setValueRange(const uint32_t& start, const uint32_t& end);

    uint32_t currentValue() const;

    void start(const uint32_t& duration);

    void setTick(const uint32_t& tick);

    void setSpeed(const uint32_t& speed);

    bool isRunning() const;


    Pimpl* pimpl;
};


struct Pimpl
{
    Pimpl();

    uint32_t end_time;
    bool is_running;
    uint32_t start_value;
    uint32_t end_value;
    uint32_t current_value;
    uint32_t tick;
    uint32_t speed;
    Animation::Mode mode;
};

#endif // ANIMATION_H
