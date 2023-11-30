#ifndef POINT_HPP
#define POINT_HPP

class Point
{
	double x;
	double y;

	public:
		Point(double x = 0, double y = 0);

		double get_x(void);
		double get_y(void);
		void set_x(double x);
		void set_y(double y);

		double distance(void);
		double distance(Point p);
		double angle(void);

		bool operator==(Point p);
		bool operator!=(Point p);
		std::string to_string();
};

#endif /* POINT_HPP */
