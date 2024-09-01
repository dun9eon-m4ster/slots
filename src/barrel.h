#ifndef BARREL_H
#define BARREL_H

#include "graphicsobject.h"

class PaintEvent;

class Barrel : public GraphicsObject
{
public:
	Barrel(const Rect& _new_rect);

protected:
	virtual void paintEvent(PaintEvent *event) override;
};

#endif // BARREL_H
