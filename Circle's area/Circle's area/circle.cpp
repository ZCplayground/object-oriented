#include "circle.h"
#include<iostream>

using namespace std;

const double Circle::PI = 3.141592653;

/*显示交互信息，并获得半径*/
void Circle::Scan()
{
	cout << "请输入圆的半径：";
	cin >> radius;
}

/*计算圆的面积*/
double Circle::Area()
{
	area = radius * radius * PI;
	return area;
}

/*显示结果*/
void Circle::Display()
{
	cout << "球的半径为：" << radius << endl;
	cout << "球的面积为：" << Area() << endl;
	cout << "Done." << endl;
}