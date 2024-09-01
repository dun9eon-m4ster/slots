#include "interactiveobject.h"
#include "mouseevent.h"


InteractiveObject::InteractiveObject(const Rect& rect)
	:	GraphicsObject(rect),
		is_hovered(false),
		is_pressed(false)
{

}

void InteractiveObject::handleEvent(Event* event)
{
	if		(auto mouse_move_event = dynamic_cast<MouseMoveEvent*>(event))
	{
		if (rect().contains(mouse_move_event->pos()))
		{
			is_hovered = true;
			mouseMoveEvent(mouse_move_event);
			return;
		}
		is_hovered = false;
		is_pressed = false;
	}
	else if (auto mouse_press_event = dynamic_cast<MousePressEvent*>(event))
	{
		if (rect().contains(mouse_press_event->pos()))
		{
			is_pressed = true;
			mousePressEvent(mouse_press_event);
			return;
		}
		is_pressed = false;
	}
	else if (auto mouse_release_event = dynamic_cast<MouseReleaseEvent*>(event))
	{
		if (is_pressed)
		{
			is_pressed = false;
			mouseReleaseEvent(mouse_release_event);
			return;
		}
	}

	GraphicsObject::handleEvent(event);
}

bool InteractiveObject::isHovered() const
{
	return is_hovered;
}

bool InteractiveObject::isPressed() const
{
	return is_pressed;
}

void InteractiveObject::mouseMoveEvent(MouseMoveEvent* event)
{
}

void InteractiveObject::mousePressEvent(MousePressEvent* event)
{
}

void InteractiveObject::mouseReleaseEvent(MouseReleaseEvent* event)
{
}
