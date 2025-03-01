#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(const float x1, const float y1) : x(x1), y(y1) {}

Point::Point(const Point& ref) { *this = ref; }

Point::~Point() {}

Point& Point::operator=(const Point& ref) {
	if (this != &ref) {
		const_cast<Fixed&>(this->x) = ref.x;
		const_cast<Fixed&>(this->y) = ref.y;
	}
	return *this;
}

bool	Point::operator==(const Point& ref) const {
	return (x == ref.getX() && y == ref.getY());
}

Fixed	Point::getX() const { return (x); }

Fixed	Point::getY() const { return (y); }
