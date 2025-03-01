#include "Point.hpp"

Fixed	crossProduct( Point const x, Point const y, Point const z) {
	Fixed	tmp;
	tmp.setRawBits(((y.getX().getRawBits() - x.getX().getRawBits())
										* (z.getY().getRawBits() - x.getY().getRawBits()))
							- ((y.getY().getRawBits() - x.getY().getRawBits())
										* (z.getX().getRawBits() - y.getX().getRawBits())));
	return (tmp);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed cross1 = crossProduct(a, b, point);
	Fixed cross2 = crossProduct(b, c, point);
	Fixed cross3 = crossProduct(c, a, point);

	bool hasNeg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
	bool hasPos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);	
	return !(hasNeg && hasPos);
}