#include "Fixed.hpp"

Fixed::Fixed() : value(0) { }

Fixed::Fixed(const int n) { value = n << fra_bits; }

Fixed::Fixed(const float f) { value = roundf(f * (1 << fra_bits)); }

Fixed::Fixed(const Fixed& ref) { *this = ref; }

Fixed& Fixed::operator=(const Fixed& ref) {
	if (this != &ref)
		this->setRawBits(ref.getRawBits());
	return (*this);
}

Fixed::~Fixed() {}


bool	Fixed::operator>(const Fixed& ref) { return (value > ref.getRawBits()); }

bool	Fixed::operator<(const Fixed& ref) { return (value < ref.getRawBits()); }

bool	Fixed::operator>=(const Fixed& ref) { return (value >= ref.getRawBits()); }

bool	Fixed::operator<=(const Fixed& ref) { return (value <= ref.getRawBits()); }

bool	Fixed::operator==(const Fixed& ref) { return (value == ref.getRawBits()); }

bool	Fixed::operator!=(const Fixed& ref) { return (value != ref.getRawBits()); }

Fixed	Fixed::operator+(const Fixed& ref) {
	Fixed	tmp;
	tmp.setRawBits(value + ref.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& ref) {
	Fixed	tmp;
	tmp.setRawBits(value - ref.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& ref) {
	Fixed tmp;
	tmp.setRawBits((value * ref.getRawBits()) >> fra_bits);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& ref) {
	Fixed tmp;
	tmp.setRawBits((value << fra_bits) / ref.getRawBits());
	return (tmp);
}

Fixed&	Fixed::operator++() { return (value += 1, *this); }

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	value += 1;
	return (tmp);
}

Fixed&	Fixed::operator--() { return (value -= 1, *this); }

Fixed		Fixed::operator--(int) {
	Fixed tmp = *this;
	value -= 1;
	return (tmp);
}

Fixed	Fixed::min(Fixed& x, Fixed& y) {
	return (x.getRawBits() < y.getRawBits() ? x : y );
}

Fixed	Fixed::min(const Fixed& x, const Fixed& y) {
	return (x.getRawBits() < y.getRawBits() ? x : y );
}

Fixed	Fixed::max(Fixed& x, Fixed& y) {
	return (x.getRawBits() > y.getRawBits() ? x : y );
}

Fixed	Fixed::max(const Fixed& x, const Fixed& y) { 
	return (x.getRawBits() > y.getRawBits() ? x : y );
}

int	Fixed::getRawBits() const { return value; }

void	Fixed::setRawBits(int raw) { value = raw; }

float	Fixed::toFloat( void ) const { return (float)value / (1 << fra_bits); }

int		Fixed::toInt( void ) const { return (value >> fra_bits); }

std::ostream&	operator<<(std::ostream& out, const Fixed& ref) {
	out << ref.toFloat();
	return (out);
}