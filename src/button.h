#ifndef BUTTON_H
#define BUTTON_H

#include "interactiveobject.h"

class PaintEvent;

class Button : public InteractiveObject
{
public:
	Button(const Rect& rect);

protected:
	virtual void paintEvent(PaintEvent* event);
	virtual void mouseReleaseEvent(MouseReleaseEvent *event) override;
};

#endif // BUTTON_H
