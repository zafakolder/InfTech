#include "Date.h"
#include <iostream>
using namespace std;



// ����������� � �����������
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// ����������
Date::~Date() {
    cout << "������ ���������." << endl;
}

// ����� ��� ��������, �������� �� ��� ����������
bool Date::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// ����� ��� ���������� ���� �� 5 ����
void Date::increaseByFiveDays() {
    day += 5;

    while (day > daysInMonth(month)) {
        day -= daysInMonth(month);
        if (++month > 12) {
            month = 1;
            ++year;
        }
    }
}

// ��������������� ������� ��� ����������� ���������� ���� � ������
int Date::daysInMonth(int m) {
    static const int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
    if (m == 2 && isLeapYear(true)) {
        return 29;
    }
    return days[m];
}

// ������������ ������ ���������� �� �������
    string Date::toString() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}