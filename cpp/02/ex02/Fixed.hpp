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
		Fixed &operator=(const Fixed &obj);

		Fixed(const int value);
		Fixed(const float value);

		Fixed operator+(const Fixed &obj);
		Fixed operator-(const Fixed &obj);
		Fixed operator*(const Fixed &obj);
		Fixed operator/(const Fixed &obj);

		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed	&min(const Fixed& obj1, const Fixed& obj2);
		static Fixed	&max(const Fixed& obj1, const Fixed& obj2);
		static Fixed	&min(Fixed& obj1, Fixed& obj2);
		static Fixed	&max(Fixed& obj1, Fixed& obj2);
};

bool operator>(const Fixed& obj1, const Fixed& obj2);
bool operator<(const Fixed& obj1, const Fixed& obj2);
bool operator>=(const Fixed& obj1, const Fixed& obj2);
bool operator<=(const Fixed& obj1, const Fixed& obj2);
bool operator==(const Fixed& obj1, const Fixed& obj2);
bool operator!=(const Fixed& obj1, const Fixed& obj2);

std::ostream &operator<<(std::ostream &out, const Fixed &obj);