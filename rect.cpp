#include "rect.h"
#include "SDL_rect.h"

Rect::Rect()
{
}

Rect::Rect(const Point& _new_top_left, const Point& _new_bottom_right)
	:	_top_left(_new_top_left),
		_bottom_right(_new_bottom_right)
{
}

Rect::Rect(const int& x, const int& y, const int& width, const int& height)
	: Rect(Point(x, y), Point(x + width - 1, y + height - 1))
{
}

Rect::Rect(const SDL_Rect& sdl_rect)
	: Rect(sdl_rect.x, sdl_rect.y, sdl_rect.w, sdl_rect.h)
{
}

bool Rect::contains(const Point& point) const
{
	return	(point.x() >= _top_left.x() && point.x() <= _bottom_right.x()) &&
			(point.y() >= _top_left.y() && point.y() <= _bottom_right.y());
}

bool Rect::isNull() const
{
	return width() == 0 || height() == 0;
}

int Rect::x() const
{
	return _top_left.x();
}

int Rect::y() const
{
	return _top_left.y();
}

int Rect::width() const
{
	return _bottom_right.x() - _top_left.x();
}

int Rect::height() const
{
	return _bottom_right.y() - _top_left.y();
}

Point Rect::topLeft() const
{
	return _top_left;
}

Point Rect::bottomRight() const
{
	return _bottom_right;
}

Point Rect::topRight() const
{
	return Point(_bottom_right.x(), _top_left.y());
}

Point Rect::bottomLeft() const
{
	return Point(_top_left.x(), _bottom_right.y());
}

SDL_Rect Rect::sdlRect() const
{
	return SDL_Rect{x(), y(), width(), height()};
}

