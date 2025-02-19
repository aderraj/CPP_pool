#include <string>
#include <iostream>

int main() {

	std::string		str = "HI THIS IS BRAIN";
	std::string*	str_ptr = &str;
	std::string&	str_ref = str;

	std::cout << "address of the var =      [" << &str << "]" << std::endl;
	std::cout << "address held by str_ptr = [" << str_ptr << "]" << std::endl;
	std::cout << "address held by str_ref = [" << str_ptr << "]" << std::endl;

	std::cout << "value of the var  = [" << str << "]" << std::endl;
	std::cout << "value pointed to by str_ptr = [" << *str_ptr << "]" << std::endl;
	std::cout << "value pointed to by str_ref = [" << str_ref << "]" << std::endl;
}