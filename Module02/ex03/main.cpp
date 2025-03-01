#include "Point.hpp"

int main() {

    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point point(0, 0);

    bool result = bsp(a, b, c, point);

    std::cout << "Point is " << (result ? "inside" : "outside") << " the triangle." << std::endl;

    return 0;
}