#include "mouseevent.h"


MouseMoveEvent::MouseMoveEvent(const Point& _new_pos)
	: _pos(_new_pos)
{
}

Point MouseMoveEvent::pos() const
{
	return _pos;
}


MouseEvent::MouseEvent(const Point& _new_pos, const MouseButton& _new_button)
	: _pos(_new_pos),
	_button(_new_button)
{
}


Point MouseEvent::pos() const
{
	return _pos;
}


MouseButton MouseEvent::button() const
{
	return _button;
}


MousePressEvent::MousePressEvent(const Point& _new_pos, const MouseButton& _new_button)
	: MouseEvent(_new_pos, _new_button)
{
}

MouseReleaseEvent::MouseReleaseEvent(const Point& _new_pos, const MouseButton& _new_button)
	: MouseEvent(_new_pos, _new_button)
{
}

MouseButton mouseButtonFromSDL(const Uint32& mouse_button_num)
{
	if (mouse_button_num == 1)
		return MouseButton::LeftButton;

	return MouseButton::None;
}