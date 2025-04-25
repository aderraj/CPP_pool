#include "Span.hpp"
#include <ctime>
#include <vector>

int main() {
    std::srand(std::time(0)); // seed RNG

    std::cout << "==== Basic Test ====" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "Trying to add one more element..." << std::endl;
        sp.addNumber(42); // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== Exception on Too Few Elements ====" << std::endl;
    try {
        Span sp2(2);
        sp2.addNumber(42);
        std::cout << sp2.shortestSpan() << std::endl; // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== Range Test ====" << std::endl;
    try {
        Span sp3(10);
        std::vector<int> numbers;
        for (int i = 1; i <= 10; ++i)
            numbers.push_back(i * 10); // 10, 20, ..., 100

        sp3.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== Large Random Range Test (10,000 numbers) ====" << std::endl;
    try {
        Span largeSpan(10000);
        std::vector<int> bigRange;
        for (int i = 0; i < 10000; ++i)
            bigRange.push_back(rand());

        largeSpan.addNumbers(bigRange.begin(), bigRange.end());

        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== All Tests Done ====" << std::endl;
    return 0;
}
