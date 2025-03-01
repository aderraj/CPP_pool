#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != d: " << (b != d) << std::endl;

    std::cout << "b + c: " << (b + c) << std::endl;
    std::cout << "c - b: " << (c - b) << std::endl;
    std::cout << "b * c: " << (b * c) << std::endl;
    std::cout << "c / b: " << (c / b) << std::endl;

    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "Fixed::min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "Fixed::max(b, c): " << Fixed::max(b, c) << std::endl;
    std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;

    return 0;
}