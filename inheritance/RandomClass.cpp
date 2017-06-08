#include<iostream>
#include<ctime>
using namespace std;

class Random {
private:
	static unsigned int seed;
public:
	void Next();
	virtual ~Random() {}
	virtual void random() = 0;
};

unsigned int Random::seed = (unsigned int)time(NULL);

void Random::Next()/*每次随机后让种子变成一个新的*/
{
	seed = seed * 11035 + 12345;
	seed = (unsigned int)(seed / 65536) % 32768;
}

class RandomNum : public Random
{
private:
	int num;
public:
	RandomNum() { num = 0; }
	virtual void random();
	int GetNum() { return num; }
};

void RandomNum::random()
{
	num = rand() % 11;
	Next();
}

class RandomOper : public Random
{
private:
	char oper;
public:
	RandomOper() { oper = '+'; }
	virtual void random();
	char GetOper() { return oper; }
};

void RandomOper::random()
{
	int choice = rand() % 4;
	switch (choice)
	{
	case'0':oper = '+'; break;
	case'1':oper = '-'; break;
	case'2':oper = '*'; break;
	case'3':oper = '/'; break;
	default:
		break;
	}
	Next();
}

int main()
{
	RandomNum rnd1;
	rnd1.random();
	cout << rnd1.GetNum() << endl;

	RandomOper rnd2;
	rnd2.random();
	cout << rnd2.GetOper() << endl;

	return 0;
}