#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {
	
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {
	
}

Point::~Point() {

}

Point::Point(const Point &copy) {
	_x = copy.getX();
	_y = copy.getY();
}

Point &Point::operator=(const Point &obj) {
	if (this == &obj)
		return *this;
	_x = obj.getX();
	_y = obj.getY();
	return *this;
}

const Fixed& Point::getX(void) const {
	return _x;
}

const Fixed& Point::getY(void) const {
	return _y;
}
