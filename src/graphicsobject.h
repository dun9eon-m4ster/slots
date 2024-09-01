#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include "object.h"
#include "rect.h"

class PaintEvent;


class GraphicsObject : public Object
{
public:
    GraphicsObject(const Rect& _new_rect);
    virtual void handleEvent(Event* event) override;
    Rect rect() const;

protected:
    virtual void paintEvent(PaintEvent* event) = 0;

private:
    Rect _rect;
};


#endif // GRAPHICSOBJECT_H
