// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CTungalag
{
private:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
	int check;
public:
	CTungalag();
	CTungalag(int y, int m, int d, int h, int mi, int s);
	CTungalag()
	{
		cout << "被调用了" << endl;
	}
	void print();
	void addoneday();
	int setDay(int y, int m, int d, int h, int mi, int s);
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();
};
CTungalag::CTungalag()
{
	Year = 1999;
	Month = 4;
	Day = 3;
	Hour = 12;
	Minute = 35;
	Second = 45;
}
CTungalag::CTungalag(int y, int m, int d, int h, int mi, int s)
{
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	if (check() == -1 || check() == 1)
	{
		Month = 1;
		Day = 1;
		cout << "输入有误,月日已置1" << endl;
	}
}
int CTungalag::getYear()
{
	return Year;
}
int CTungalag::getMonth()
{
	return Month;
}
int CTungalag::getDay()
{
	return Day;
}
int CTungalag::getHour()
{
	return Hour;
}
int CTungalag::getMinute()
{
	return Minute;
}
int CTungalag::getSecond()
{
	return Second;
}
int CTungalag::check()
{
	int flatYearDays::[12] = { 31,28,31,30,31,31,30,31,30,31 };
	int leapYearDays::[12] = { 31,29,31,30,31,31,30,31,30,31 };
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
	{
		if (leapYearDays[Month - 1] < 1 || Day < 1)
			return 1;
	}
	system("pause");
	return 0;
}
}