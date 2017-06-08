#include<iostream>
#include<iostream>
#include<ctime>
using namespace std;

template<class T>
class Random {
protected:
	static unsigned int seed;
public:
	static void NextSeed();//����Ҫ����Ϊ��̬����������ᱨ���������� C2352
	T Next();
};

template<class T>
unsigned int Random<T>::seed = (unsigned int)time(NULL);

template<class T>
void Random<T>::NextSeed()
{
	seed = seed * 11035 + 12345;
	seed = (unsigned int)(seed % 32768);
	srand(seed);
}

template<>//��ģ����ػ�����һ��ֻҪдһ�Σ�д��λᱨ���������� C2910
class Random<int>
{
public:
	int Next(int n);
};

int Random<int>::Next(int n)
{
	int num = rand() % n;
	Random<class T>::NextSeed();//NextSeed��û���ػ��ģ�Ҫ������T��ȥ
	return num;
}

template<>//��ģ����ػ�
class Random<char>
{
public:
	char Next();
};

char Random<char>::Next()
{
	char oper;
	int choice = rand() % 4;
	switch (choice)
	{
	case 0:oper = '+'; break;
	case 1:oper = '-'; break;
	case 2:oper = '*'; break;
	case 3:oper = '/'; break;
	default:
		break;
	}
	Random<class T>::NextSeed();
	return oper;
}

int main()
{
	Random<int>rnd1;
	Random<char>rnd2;

	for (int i = 0; i < 10; i++)
	{
		cout << rnd1.Next(11) << " " << rnd2.Next() << endl;
	}

	return 0;
}
