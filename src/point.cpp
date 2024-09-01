#include "point.h"

Point::Point()
	:	_x(0),
		_y(0)
{
}

Point::Point(const int& _new_x, const int& _new_y)
	:	_x(_new_x),
		_y(_new_y)
{
}

int Point::x() const
{
	return _x;
}

int Point::y() const
{
	return _y;
}
