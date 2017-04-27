#include "circle.h"
#include<iostream>

using namespace std;

const double PI = 3.141592653;
double radius;

void Scan()
{
	cout << "请输入圆的半径：";
	cin >> radius;
}

double Area()
{
	double area;
	area = radius * radius * PI;
	return area;
}

void Display()
{
	cout << "球的半径为：" << radius << endl;
	cout << "球的面积为：" << Area() << endl;
	cout << "Done." << endl;
}