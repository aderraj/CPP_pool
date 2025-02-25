#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	public :
		Fixed();
		Fixed(const Fixed& ref);
		Fixed& operator=(const Fixed& ref);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private :
		int								value;
		static const int	fra_bits = 8;

};

#endif