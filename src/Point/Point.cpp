#include <string>
#include <cmath>
#include <format>
#include <cmath>
#include "Point.hpp"

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::set_x(double x)
{
	this->x = x;
}

void Point::set_y(double y)
{
	this->y = y;
}

double Point::get_x(void)
{
	return this->x;
}

double Point::get_y(void)
{
	return this->y;
}

double Point::distance(Point p)
{
	return sqrt(pow(p.x-this->x, 2) + pow(p.y-this->y, 2));
}

double Point::angle(void)
{
	return atan2(this->y, this->x)*180/M_PI;
}

double Point::distance(void)
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

bool Point::operator==(Point p)
{
	return (p.x == this->x) && (p.y == this->y);
}

bool Point::operator!=(Point p)
{
	return (p.x != this->x) || (p.y != this->y);
}

std::string Point::to_string()
{
	return std::format("({}, {})", this->x, this->y);
}
