#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <limits>
#include <cmath>

class Fixed {

	public :
		Fixed();
		Fixed(const Fixed& ref);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();
		Fixed&	operator=(const Fixed& ref);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private :
		int								value;
		static const int	fra_bits = 8;

};

std::ostream&	operator<<(std::ostream& out, const Fixed& ref);

#endif