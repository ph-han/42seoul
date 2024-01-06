#include "Fixed.hpp"

Fixed::Fixed() : _fixedNumber(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedNumber(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedNumber(roundf((value * (1 << _fractionalBits)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedNumber = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	_fixedNumber = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedNumber;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedNumber = raw << _fractionalBits;
}

int Fixed::toInt(void) const {
	return (_fixedNumber >> _fractionalBits);
}

float Fixed::toFloat(void) const {
	return (((float)_fixedNumber) / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}