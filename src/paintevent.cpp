#include "paintevent.h"
#include "painter.h"

PaintEvent::PaintEvent(Painter* _new_painter)
	: _painter(_new_painter)
{
}

Painter* PaintEvent::painter()
{
	return _painter;
}
