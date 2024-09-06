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
	Barrel(const Rect& _new_rect, const uint32_t& _new_spinning_speed, const uint32_t& _new_duration);
	//void setSpeed();
	//void setDuration();
	bool isSpinning() const;
	void start();
	virtual void handleEvent(Event *event) override;

protected:
	virtual void paintEvent(PaintEvent *event) override;

private:
	State _state;
	Animation animation;
	uint32_t spinning_speed;
	uint32_t duration;
};

#endif // BARREL_H
