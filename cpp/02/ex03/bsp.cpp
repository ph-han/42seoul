#include "Point.hpp"

float getTriArea(Point a, Point b, Point c) {
	float area;
	float tmp1;
	float tmp2;

	tmp1 = a.getX().toFloat() * b.getY().toFloat() + b.getX().toFloat() * c.getY().toFloat() + c.getX().toFloat() * a.getY().toFloat();
	tmp2 = b.getX().toFloat() * a.getY().toFloat() + c.getX().toFloat() * b.getY().toFloat() + a.getX().toFloat() * c.getY().toFloat();

	area = fabs(tmp1 - tmp2) / 2;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float abcArea = getTriArea(a, b, c);
	float apbArea = getTriArea(a, b, point);
	float apcArea = getTriArea(a, point, c);
	float bpcArea = getTriArea(point, b, c);

	if (abcArea == apbArea + apcArea + bpcArea)
		return true;
	else
		return false;
}