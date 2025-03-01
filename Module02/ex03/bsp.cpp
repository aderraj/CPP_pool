#include "Point.hpp"

Fixed	crossProduct( Point const x, Point const y, Point const z) {
	return ((y.getX() - x.getX()) * (z.getY() - x.getY()))
				- ((y.getY() - x.getY()) * (z.getX() - x.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	if (a == point || b == point || c == point)
		return (false);

	Fixed cross1 = crossProduct(a, b, point);
	Fixed cross2 = crossProduct(b, c, point);
	Fixed cross3 = crossProduct(c, a, point);

	if (cross1 == 0 || cross2 == 0 || cross3 == 0)
			return false;

	bool hasNeg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
	bool hasPos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);	
	return !(hasNeg && hasPos);

}