#pragma once

class Circle {
private:
	double radius;
	double area;
	static const double PI;
public:
	void Scan();
	double Area();
	void Display();
};
