#ifndef PAINTEVENT_H
#define PAINTEVENT_H

#include "event.h"
class Painter;

class PaintEvent : public Event
{
public:
	PaintEvent() = delete;
	PaintEvent(Painter* _new_painter);
	Painter* painter();

private:
	Painter* _painter;
};


#endif // PAINTEVENT_H
