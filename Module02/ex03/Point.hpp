#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class	Point {

	public:
		Point();
		Point(const float x1, const float y1);
		Point(const Point& ref);
		Point&	operator=(const Point& ref);
		~Point();
		bool	operator==(const Point& ref) const;
		Fixed	getX() const;
		Fixed	getY() const;

	private:
		const	Fixed	x;
		const	Fixed	y;
};

bool	bsp( Point const a, Point const b,
					 Point const c, Point const point);
#endif