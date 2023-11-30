#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a;
    Point p(-1, -1);
    Point q(1, 2);
	std::cout << "A" << a.to_string() << std::endl;
	std::cout << "P" << p.to_string() << std::endl;
	std::cout << "Q" << q.to_string() << std::endl;
    std::cout << "Q-origin distance: " << q.distance() << std::endl;
    std::cout << "Q-P distance: " << q.distance(p) << std::endl;
	std::cout << "polar coords of P: " << p.distance() << "@" << p.angle() \
		<< std::endl;
	std::cout << "Is P == Q: " << (p == q) << std::endl;
	std::cout << "Is P != Q: " << (p != q) << std::endl;
	q.set_x(p.get_x());
	q.set_y(p.get_y());
	std::cout << "now Q is " << q.to_string() << std::endl;
	std::cout << "Is P == Q: " << (p == q) << std::endl;
}
