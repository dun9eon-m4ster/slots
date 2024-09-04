#ifndef BARREL_H
#define BARREL_H

#include "graphicsobject.h"
#include "animation.h"

class Event;
class PaintEvent;

class Barrel : public GraphicsObject
{
	enum State
	{
		Waiting = 0,
		Spining
	};

public:
	Barrel(const Rect& _new_rect);
	//void setSpeed();
	//void setDuration();
	void start();
	virtual void handleEvent(Event *event) override;

protected:
	virtual void paintEvent(PaintEvent *event) override;

private:
	State _state;
	Animation animation;
};

#endif // BARREL_H
