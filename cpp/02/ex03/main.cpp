#include "Point.hpp"

int main( void ) {
	Point a(Fixed(2), Fixed(8));
	Point b(Fixed(8), Fixed(3));
	Point c(Fixed(2), Fixed(3));
	Point point(Fixed(10), Fixed(10));

	if (bsp(a, b, c, point))
		std::cout << "point가 삼각형 내부에 있습니다." << std::endl;
	else
		std::cout << "point가 삼각형 외부에 있습니다." << std::endl;

	return 0;
}