#include "barrel.h"
#include "paintevent.h"
#include "painter.h"
#include "buttonclickevent.h"
#include "iostream"

void drawElements(Painter* painter, const Rect &rect, Uint32 offset)
{
	int margin_top		= 10;
	int margin_bottom	= 10;
	int margin_left		= 10;
	int margin_right	= 10;
	int spacing = 5;

	int element_height = (rect.height() - margin_top - margin_bottom - spacing * 2 ) / 3;


	painter->setRenderColor(Color::Red);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + margin_top + offset,
							rect.width() - margin_left - margin_right,
							element_height));

	painter->setRenderColor(Color::Green);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + element_height + spacing + margin_top + offset,
							rect.width() - margin_left - margin_right,
							element_height));

	painter->setRenderColor(Color::Blue);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + element_height*2 + spacing*2 + margin_top + offset,
							rect.width() - margin_left - margin_right,
							element_height));
}


Barrel::Barrel(const Rect& _new_rect)
	:	GraphicsObject(_new_rect),
		_state(Waiting)
{
}

void Barrel::start()
{
	//if (_state != Waiting)
	//	return;
	//_state = Spining;

	animation.setValueRange(0, 500);
	animation.setTick(16);
	animation.setSpeed(10);
	animation.start(5000);
}

void Barrel::handleEvent(Event* event)
{
	if (dynamic_cast<ButtonClickEvent*>(event))
	{
		start();
	}

	GraphicsObject::handleEvent(event);
}

void Barrel::paintEvent(PaintEvent* event)
{
	if(animation.isRunning())
		std::cout << "animation current value: " <<  animation.currentValue() << std::endl;

	auto painter = event->painter();

	painter->setRenderColor(0x00afafaf);

	painter->drawRect(rect());

	drawElements(painter, rect(), animation.currentValue());
}
