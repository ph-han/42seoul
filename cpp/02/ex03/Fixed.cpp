#include "Fixed.hpp"

Fixed::Fixed() : _fixedNumber(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : _fixedNumber(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedNumber(roundf((value * (1 << _fractionalBits)))) {
	std::cout << "Float constructor called" << std::endl;
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

bool operator>(const Fixed &obj1, const Fixed &obj2) {
	return obj1.getRawBits() > obj2.getRawBits();
}

bool operator<(const Fixed &obj1, const Fixed &obj2) {
	return obj1.getRawBits() < obj2.getRawBits();
}

bool operator>=(const Fixed &obj1, const Fixed &obj2) {
	return obj1.getRawBits() >= obj2.getRawBits();
}

bool operator<=(const Fixed &obj1, const Fixed &obj2) {
	return obj1.getRawBits() <= obj2.getRawBits();
}

bool operator==(const Fixed &obj1, const Fixed &obj2) {
	return obj1.getRawBits() == obj2.getRawBits();
}

bool operator!=(const Fixed &obj1, const Fixed &obj2) {
	return obj1.getRawBits() != obj2.getRawBits();
}

Fixed Fixed::operator+(const Fixed &obj) {
	Fixed tmp(this->toFloat() + obj.toFloat());
	return tmp;
}

Fixed Fixed::operator-(const Fixed &obj) {
	Fixed tmp(this->toFloat() - obj.toFloat());
	return tmp;
}

Fixed Fixed::operator*(const Fixed &obj) {
	Fixed tmp(this->toFloat() * obj.toFloat());
	return tmp;
}

Fixed Fixed::operator/(const Fixed &obj) {
	Fixed tmp(this->toFloat() / obj.toFloat());
	return tmp;
}

Fixed &Fixed::operator++() {
	++_fixedNumber;
	return *this;
}

Fixed &Fixed::operator--() {
	--_fixedNumber;
	return *this;
}

Fixed Fixed::operator++(int) {
	const Fixed tmp(*this);
	_fixedNumber++;
	return tmp;
}

Fixed Fixed::operator--(int) {
	const Fixed tmp(*this);
	_fixedNumber--;
	return tmp;
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

Fixed Fixed::min(const Fixed &obj1, const Fixed &obj2) {
	if (obj1 > obj2)
		return obj2;
	else
		return obj1;
}

Fixed Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	if (obj1 > obj2)
		return obj1;
	else
		return obj2;
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}