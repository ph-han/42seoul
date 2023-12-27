#include "Fixed.hpp"

Fixed::Fixed() : _fixedNumber(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : _fixedNumber(value << _fractionalBits) {
	
}

Fixed::Fixed(const float value) : _fixedNumber(roundf((value * (1 << _fractionalBits))))
{
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called\n";
	_fixedNumber = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_fixedNumber = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return _fixedNumber;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
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