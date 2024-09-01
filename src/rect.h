#ifndef RECT_H
#define RECT_H

#include "point.h"

struct SDL_Rect;

class Rect
{
public:
	Rect();
	Rect(const Point &_new_top_left, const Point &_new_bottom_right);
	Rect(const int& x, const int& y, const int& width, const int& height);
	Rect(const SDL_Rect& sdl_rect);
	bool contains(const Point& point) const;
	bool isNull() const;
	int x() const;
	int y() const;
	int width() const;
	int height() const;
	Point topLeft()const;
	Point bottomRight() const;
	Point topRight() const;
	Point bottomLeft() const;
	SDL_Rect sdlRect() const;

private:
	Point _top_left;
	Point _bottom_right;
};


#endif // RECT_H