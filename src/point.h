#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point();
	Point(const int& _new_x, const int& _new_y);
	int x() const;
	int y() const;

private:
	int _x;
	int _y;
};

#endif // POINT_H