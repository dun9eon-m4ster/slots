#include "button.h"
#include "paintevent.h"
#include "painter.h"
#include "SDL_render.h"
#include "SDL_events.h"
#include "SDL_timer.h"
#include "callbackevent.h"
#include "buttonclickevent.h"
#include "iostream"

Button::Button(const Rect& rect)
	:	InteractiveObject(rect)
{
}

void Button::paintEvent(PaintEvent* event)
{
	auto painter = event->painter();

	if (isPressed())
		painter->setRenderColor(Color::Red);
	else
		painter->setRenderColor(Color::Blue);

	painter->drawRect(rect());

	if (isHovered())
		painter->setRenderColor(Color::Yellow);
	else
		painter->setRenderColor(Color::Green);

	painter->drawLine(rect().topLeft().x(),
		rect().topLeft().y(),
		rect().topRight().x(),
		rect().topRight().y());

	painter->drawLine(rect().topRight().x(),
		rect().topRight().y(),
		rect().bottomRight().x(),
		rect().bottomRight().y());

	painter->drawLine(rect().bottomRight().x(),
		rect().bottomRight().y(),
		rect().bottomLeft().x(),
		rect().bottomLeft().y());

	painter->drawLine(rect().bottomLeft().x(),
		rect().bottomLeft().y(),
		rect().topLeft().x(),
		rect().topLeft().y());
}

void Button::mouseReleaseEvent(MouseReleaseEvent* event)
{
	SDL_Event _new_event;
	_new_event.type = SDL_EventType::SDL_USEREVENT;
	_new_event.user.timestamp = SDL_GetTicks();
	_new_event.user.data1 = new ButtonClickEvent(this);
	SDL_PushEvent(&_new_event);

	InteractiveObject::mouseReleaseEvent(event);
}
