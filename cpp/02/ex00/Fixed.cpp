#include "Fixed.hpp"

Fixed::Fixed() : _fixedNumber(0){
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_fixedNumber = obj.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return _fixedNumber;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_fixedNumber = raw << _fractionalBits;
}