#include "Point.hpp"
#include <iostream>

int main() {

	Point a;
	Point b(1.3, 2.4);
	a = b;
	std::cout << "a " << a.getX() << std::endl;
	return 0;
}