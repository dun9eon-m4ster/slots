#include "barrel.h"
#include "paintevent.h"
#include "painter.h"


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
							rect.y() + margin_top,
							rect.width() - margin_left - margin_right,
							element_height));

	painter->setRenderColor(Color::Green);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + element_height + spacing + margin_top,
							rect.width() - margin_left - margin_right,
							element_height));

	painter->setRenderColor(Color::Blue);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + element_height*2 + spacing + margin_top,
							rect.width() - margin_left - margin_right,
							element_height));
}


Barrel::Barrel(const Rect& _new_rect)
	: GraphicsObject(_new_rect)
{
}

void Barrel::paintEvent(PaintEvent* event)
{
	auto painter = event->painter();

	painter->setRenderColor(0x00afafaf);

	painter->drawRect(rect());

	drawElements(painter, rect(), 0);
}
