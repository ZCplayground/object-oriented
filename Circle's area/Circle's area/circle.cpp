#include "circle.h"
#include<iostream>

using namespace std;

const double PI = 3.141592653;
double radius;

void Scan()
{
	cout << "������Բ�İ뾶��";
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
	cout << "��İ뾶Ϊ��" << radius << endl;
	cout << "������Ϊ��" << Area() << endl;
	cout << "Done." << endl;
}