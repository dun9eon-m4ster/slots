#include "rect.h"

Rect::Rect()
{
}

Rect::Rect(const Point& _new_top_left, const Point& _new_bottom_right)
	:	_top_left(_new_top_left),
		_bottom_right(_new_bottom_right)
{
}

Rect::Rect(const int& x, const int& y, const int& width, const int& height)
	: Rect(Point(x, y), Point(x + width, y + height))
{
}

bool Rect::contains(const Point& point) const
{
	return	(point.x() >= _top_left.x() && point.x() <= _bottom_right.x()) &&
			(point.y() >= _top_left.y() && point.y() <= _bottom_right.y());
}
