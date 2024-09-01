#include "graphicsobject.h"
#include "paintevent.h"


GraphicsObject::GraphicsObject(const Rect& _new_rect)
    : _rect(_new_rect)
{
}

void GraphicsObject::handleEvent(Event* event)
{
    if (auto paint_event = dynamic_cast<PaintEvent*>(event))
        paintEvent(paint_event);
}

Rect GraphicsObject::rect() const
{
    return _rect;
}
