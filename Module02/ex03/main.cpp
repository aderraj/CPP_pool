#include "Point.hpp"
#include <iostream>

int main() {
    // Define points for the triangle
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    // Define a point to test
    Point point(-1, 2);

    // Check if the point is inside the triangle
    bool result = bsp(a, b, c, point);

    // Output the result
    std::cout << "Point is " << (result ? "inside" : "outside") << " the triangle." << std::endl;

    return 0;
}