#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <limits>
#include <cmath>

#define FIXED_EPSILON 0.00390625

class Fixed {

	public :
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& ref);
		Fixed&	operator=(const Fixed& ref);
		~Fixed();
		bool					operator>(const Fixed& ref);
		bool					operator<(const Fixed& ref);
		bool					operator>=(const Fixed& ref);
		bool					operator<=(const Fixed& ref);
		bool					operator==(const Fixed& ref);
		bool					operator!=(const Fixed& ref);
		Fixed					operator+(const Fixed& ref);
		Fixed					operator-(const Fixed& ref);
		Fixed					operator*(const Fixed& ref);
		Fixed					operator/(const Fixed& ref);
		Fixed&				operator++();
		Fixed&				operator--();
		Fixed					operator++(int);
		Fixed					operator--(int);
		static Fixed	min(Fixed& x, Fixed& y);
		static Fixed	min(const Fixed& x, const Fixed& y);
		static Fixed	max(Fixed& x, Fixed& y);
		static Fixed	max(const Fixed& x, const Fixed& y);
		int						getRawBits( void ) const;
		void					setRawBits( int const raw );
		float					toFloat( void ) const;
		int						toInt( void ) const;

	private :
		int								value;
		static const int	fra_bits = 8;

};

std::ostream&	operator<<(std::ostream& out, const Fixed& ref);

#endif