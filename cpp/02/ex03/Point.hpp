#pragma once
#include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		~Point();
		Point(const Point &copy);
		Point &operator=(const Point &obj);

		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);