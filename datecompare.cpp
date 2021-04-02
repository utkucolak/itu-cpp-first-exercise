// lecture5hw.cpp : Bu dosya 'main' iþlevi içeriyor. Program yürütme orada baþlayýp biter.
//

#include <iostream>
using namespace std;

class Date {
	int month;
	int day;
	int year;

public:
	Date();
	void print() const;
	Date& operator+=(int a_day);
	Date& operator++();
	int compare_dates(Date a, Date b);

};

Date::Date() {
	month = 4;
	day = 3;
	year = 2021;

}
Date & Date::operator+=(int a_day) {
	day = a_day + day;
	if (day - 30 > 0) {
		day = day - 30;
		month = month + 1;
		if ((month - 12) > 0) {
			month = 1;
			year = year + 1;
		}
	}
	return *this;
}

//preincrement
Date & Date::operator++() {
	day = day + 1;
	return *this;
}
void Date::print() const {
	cout << month << " / " << day << " / " << year << endl;
}

int Date::compare_dates(Date a, Date b){
	if ((a.year > b.year) || (((a.year) == (b.year)) && ((a.month) > (b.month))) || (((a.year) == (b.year)) && ((a.month) == (b.month)) && ((a.day) > (b.day))))
		return -1;
	else if ((a.year < b.year) || (((a.year) == (b.year)) && ((a.month) < (b.month))) || (((a.year) == (b.year)) && ((a.month) == (b.month)) && ((a.day) < (b.day))))
		return 0;
	else if ((a.year == b.year) && (a.month == b.month) && (a.day == b.day))
		return 1;
}
int main()
{
	Date *d1;
	d1 = new Date;
	d1->print();
	(*d1) += 30;
	d1->print();
	Date d2, d_compare;
	d2 += 55;
	//d2 is earlier, value must be zero.
	int test = d_compare.compare_dates(*d1, d2);
	cout << test;
	return 0;

}
