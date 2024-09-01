#ifndef FPSWIDGET_H
#define FPSWIDGET_H

#include "graphicsobject.h"
#include "memory"

class FpsEvent;
class Texture;

class FpsWidget : public GraphicsObject
{
public:
	FpsWidget(const Rect& _new_rect);
	virtual void handleEvent(Event* event) override;

protected:
	virtual void paintEvent(PaintEvent* event);
	virtual void updateFpsEvent(FpsEvent* event);

private:
	std::vector<std::pair<Rect, std::shared_ptr<Texture>>> paint_data_array;
};

#endif // FPSWIDGET_H
