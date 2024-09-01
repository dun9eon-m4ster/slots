#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H

#include "graphicsobject.h"

class MouseMoveEvent;
class MousePressEvent;
class MouseReleaseEvent;


class InteractiveObject : public GraphicsObject
{
public:
	InteractiveObject(const Rect& rect);
	virtual void handleEvent(Event* event) override;
	bool isHovered() const;
	bool isPressed() const;

protected:
	virtual void mouseMoveEvent(MouseMoveEvent* event);
	virtual void mousePressEvent(MousePressEvent* event);
	virtual void mouseReleaseEvent(MouseReleaseEvent* event);

private:
	bool is_hovered;
	bool is_pressed;
};

#endif // INTERACTIVEOBJECT_H
