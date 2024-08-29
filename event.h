#ifndef EVENT_H
#define EVENT_H

#include "point.h"

typedef unsigned int Uint32;


enum class MouseButton
{
	None = 0,
	LeftButton,
	RightButton,
	MiddleButton
};


MouseButton mouseButtonFromSDL(const Uint32& mouse_button_num);


class Event
{
public:
	virtual ~Event();
};


class MouseMoveEvent : public Event
{
public:
	MouseMoveEvent(const Point &_new_pos);

	Point pos() const;

private:
	Point _pos;
};


class MouseEvent : public Event
{
public:
	MouseEvent(const Point& _new_pos, const MouseButton& _new_button);

	Point pos() const;
	MouseButton button() const;

private:
	MouseButton _button;
	Point _pos;
};


class MousePressEvent : public MouseEvent
{
public:
	MousePressEvent(const Point& _new_pos, const MouseButton& _new_button);
};


class MouseReleaseEvent : public MouseEvent
{
public:
	MouseReleaseEvent(const Point& _new_pos, const MouseButton& _new_button);
};




#endif // EVENT_H
