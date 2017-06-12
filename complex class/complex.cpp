#include<iostream>
#include<cstdlib>
#include<cctype>
#include<string>

using namespace std;

class complex {
private:
	string e;
	int imaginarypart;
	int realpart;
public:
	complex() { imaginarypart = 0; realpart = 0; }
	complex(string &s);
	complex(int i, int r) { imaginarypart = i; realpart = r; }

	complex operator+(const complex &c1) const;
	friend ostream & operator<<(ostream &os, complex &c1);
};

complex::complex(string &s)//根据一个符合数学书写规范的式子来构造一个complex对象
{
	int i = 0;
	char sign;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')i++;//取开头的符号

	int num = 0;
	for (; isdigit(s[i]); i++)//读取第一个数字
	{
		num *= 10;
		num += s[i] - '0';
	}

	if (s[i] == '\0')//只有实部
	{
		realpart = num*sign;
		imaginarypart = 0;
	}
	else if (s[i] == '+' || s[i] == '-')////有实部有虚部
	{
		realpart = num*sign;
		sign = (s[i] == '-') ? -1 : 1;//取虚部符号
		i++;

		num = 0;

		for (; isdigit(s[i]); i++)//取虚部的数字
		{
			num *= 10;
			num += s[i] - '0';
		}
		if (num == 0)//形如1+i，虚部取不到数字，但虚部为1，不是0
			num = 1;
		imaginarypart = num*sign;
	}
	else if (s[i] == 'i')//只有虚部
	{
		if (num == 0)
			num = 1;
		imaginarypart = num*sign;
		realpart = 0;
	}

}

complex complex::operator+(const complex &c1)const
{
	int i = imaginarypart + c1.imaginarypart;
	int r = realpart + c1.realpart;

	return complex(i, r);
}

ostream & operator<<(ostream &os, complex &s)//输出符合数学规范写法
{
	cout << "expression: ";
	if (s.realpart != 0 && s.imaginarypart == 0)//只有实部
	{
		//printf("%d", s.realpart);
		os << s.realpart;

	}
	else if (s.realpart == 0 && s.imaginarypart != 0)//只有虚部
	{
		if (s.imaginarypart == 1)
			os << "i";
		else if (s.imaginarypart == -1)
			os << "-i";
		else
			os << s.imaginarypart << "i";
	}
	else//有实部有虚部
	{
		os << s.realpart;

		if (s.imaginarypart == -1)
			os << "-i";
		else if (s.imaginarypart == 1)
			os << "+i";
		else if (s.imaginarypart > 0)
			os << "+" << s.imaginarypart << "i";
		else if (s.imaginarypart < 0)
			os << s.imaginarypart << "i";
	}
	cout << endl;
	cout << "realpart: " << s.realpart << " imaginarypart: " << s.imaginarypart;
	return os;
}

int main()
{
	string s1;
	complex sum = complex(0, 0);
	while (1)
	{
		cin >> s1;
		if (s1 == "exit")break;

		complex c = complex(s1);
		cout << c << endl;
	}
	
	return 0;
}



//需要考虑的各种例子形如：
/*
10
-10 //没有虚部
1+5i
1-5i
-1+5i //有实部有虚部
-i
i
10i
-10i //只有虚部
*/

