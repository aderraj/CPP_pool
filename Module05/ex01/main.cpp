#include "Bureaucrat.hpp"

int main() {
	try {
			Bureaucrat b1("Alice", 2);
			std::cout << b1;
			b1.incrementGrade();
			std::cout << b1;
			b1.incrementGrade(); // This should throw an exception
	} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
	}

	std::cout << "------------" << std::endl;
	try {
			Bureaucrat b2("Bob", 149);
			std::cout << b2;
			b2.decrementGrade();
			std::cout << b2;
			b2.decrementGrade(); // This should throw an exception
	} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
	}

	std::cout << "------------" << std::endl;
	try {
			Bureaucrat b3("Charlie", 151); // This should throw an exception
	} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
	}

	try {
			Bureaucrat b4("Dave", 0); // This should throw an exception
	} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
	}

	return 0;
}