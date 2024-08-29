#ifndef RECT_H
#define RECT_H

#include "point.h"

class Rect
{
public:
	Rect();
	Rect(const Point &_new_top_left, const Point &_new_bottom_right);
	Rect(const int& x, const int& y, const int& width, const int& height);
	bool contains(const Point& point) const;

private:
	Point _top_left;
	Point _bottom_right;
};


#endif // RECT_H