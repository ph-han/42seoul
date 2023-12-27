#pragma once

#include <iostream>
#include <cmath>


class Fixed {
	private:
		int					_fixedNumber;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &obj);

		Fixed(const int value);
		Fixed(const float value);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);