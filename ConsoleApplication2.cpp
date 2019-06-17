
#include <iostream>
using namespace std;
class CTungalag {
private:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
	int check();
public:
	CTungalag();
	CTungalag(int y, int m, int d, int h, int mi, int s);
	CTungalag() {
		cout << "被调用了" << endl;
	}
	void print();
	void AddYearDays();
	int SetDays(int y, int m, int d, int h, int mi, int s);
	int BackYear();
	int BackMonth();
	int BackDay();
	int BackHour();
	int BackMinute();
	int BackSecond();
};
CTungalag::CTungalag() {
	Year = 1999;
	Month = 26;
	Day = 12;
	Hour = 11;
	Minute = 19;
	Second = 59;
}
CTungalag::CTungalag(int y, int m, int d, int h, int mi, int s) {
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
	if (check() == -1 || check() == 1) {
		Month = 1;
		Day = 1;
		cout << "输入有误，月日置1" << endl;
	}
}
int CTungalag::BackYear() {
	return Year;
}
int CTungalag::BackMonth() {
	return Month;
}
int CTungalag::BackDay() {
	return Day;
}
int CTungalag::BackHour() {
	return Hour;
}
int CTungalag::BackMinute() {
	return Minute;
}
int CTungalag::BackSecond() {
	return Second;
}
int CTungalag::check() {
	int flatYearDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapYearDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Month > 12 || Month < 1)
		return -1;
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)) {
		if (leapYearDays[Month - 1] < 1 || Day < 1)
			return 1;
	}
	else {
		if (flatYearDays[Month - 1] < Day || Day < 1)
			return 1;
	}
	return 0;
}
int CTungalag::SetDays(int y, int m, int d, int h, int mi, int s) {
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	if (check() == -1 || check() == 1) {
		Month = 1;
		Day = 1;
		cout << "输入有误，月日置1" << endl;
		return -1;
	}
	return 0;
}
void CTungalag::AddYearDays() {
	int flatYearDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapYearDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Day++;
	if (Year % 400 == 0 && (Year % 4 == 0 && Year % 100 != 0)) {
		if (leapYearDays[Month - 1] < Day) {
			Month++;
			Day = 1;
		}
	}
	else {
		if (flatYearDays[Month - 1] < Day) {
			Month++;
			Day = 1;
		}
	}
	if (Month > 12) {
		Year++;
		Month = 1;
	}
}
void CTungalag::print() {
	cout << Year << "年" << Month << "月" << Day << "日" << Hour << "时" << Minute << "分" << Second << "秒" << endl;
}
int main() {
	int count = 1;
	CTungalag oj(1999, 12, 20, 24, 360, 360);
	while (!((oj.BackYear() == 2019) && (oj.BackMonth() == 4) && (oj.BackDay() == 28))) {
		oj.AddYearDays();
		count++;
	}
	cout << count << endl;
	return 0;
}

