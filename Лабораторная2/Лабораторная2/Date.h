#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // ����������� � �����������
    Date(int d, int m, int y);

    // ����������
    ~Date();

    // ����� ��� ��������, �������� �� ��� ����������
    static bool isLeapYear(int year);

    // ����� ��� ���������� ���� �� 5 ����
    void increaseByFiveDays();

    // ��������������� ������� ��� ����������� ���������� ���� � ������
    static int daysInMonth(int m);

    // ������������ ������ ���������� �� �������
    string toString() const;
};

#endif