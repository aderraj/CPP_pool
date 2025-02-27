#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const int n) {
		std::cout << "Int constructor called" << std::endl;
		value = n << fra_bits;
}

Fixed::Fixed(const float f) {
		std::cout << "Float constructor called" << std::endl;
		value = roundf(f * 256);
}

Fixed& Fixed::operator=(const Fixed& ref) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &ref)
		this->setRawBits(ref.getRawBits());
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int	Fixed::getRawBits() const { return value; }

void	Fixed::setRawBits(int raw) { value = raw; }

float	Fixed::toFloat( void ) const { return (float)value / 256.0f; }

int		Fixed::toInt( void ) const { return (value >> 8); }

std::ostream&	operator<<(std::ostream& out, const Fixed& ref) {
	out << ref.toFloat();
	return (out);
}