#include "circle.h"
#include<iostream>

using namespace std;

const double Circle::PI = 3.141592653;

/*��ʾ������Ϣ������ð뾶*/
void Circle::Scan()
{
	cout << "������Բ�İ뾶��";
	cin >> radius;
}

/*����Բ�����*/
double Circle::Area()
{
	area = radius * radius * PI;
	return area;
}

/*��ʾ���*/
void Circle::Display()
{
	cout << "��İ뾶Ϊ��" << radius << endl;
	cout << "������Ϊ��" << Area() << endl;
	cout << "Done." << endl;
}