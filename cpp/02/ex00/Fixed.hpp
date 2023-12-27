#pragma once

#include <iostream>

class Fixed {
	private:
		int					_fixedNumber;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};