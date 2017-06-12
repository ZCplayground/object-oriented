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

complex::complex(string &s)//����һ��������ѧ��д�淶��ʽ��������һ��complex����
{
	int i = 0;
	char sign;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')i++;//ȡ��ͷ�ķ���

	int num = 0;
	for (; isdigit(s[i]); i++)//��ȡ��һ������
	{
		num *= 10;
		num += s[i] - '0';
	}

	if (s[i] == '\0')//ֻ��ʵ��
	{
		realpart = num*sign;
		imaginarypart = 0;
	}
	else if (s[i] == '+' || s[i] == '-')////��ʵ�����鲿
	{
		realpart = num*sign;
		sign = (s[i] == '-') ? -1 : 1;//ȡ�鲿����
		i++;

		num = 0;

		for (; isdigit(s[i]); i++)//ȡ�鲿������
		{
			num *= 10;
			num += s[i] - '0';
		}
		if (num == 0)//����1+i���鲿ȡ�������֣����鲿Ϊ1������0
			num = 1;
		imaginarypart = num*sign;
	}
	else if (s[i] == 'i')//ֻ���鲿
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

ostream & operator<<(ostream &os, complex &s)//���������ѧ�淶д��
{
	cout << "expression: ";
	if (s.realpart != 0 && s.imaginarypart == 0)//ֻ��ʵ��
	{
		//printf("%d", s.realpart);
		os << s.realpart;

	}
	else if (s.realpart == 0 && s.imaginarypart != 0)//ֻ���鲿
	{
		if (s.imaginarypart == 1)
			os << "i";
		else if (s.imaginarypart == -1)
			os << "-i";
		else
			os << s.imaginarypart << "i";
	}
	else//��ʵ�����鲿
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



//��Ҫ���ǵĸ����������磺
/*
10
-10 //û���鲿
1+5i
1-5i
-1+5i //��ʵ�����鲿
-i
i
10i
-10i //ֻ���鲿
*/

