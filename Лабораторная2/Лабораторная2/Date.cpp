#include "Date.h"
#include <iostream>
using namespace std;



// Конструктор с параметрами
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Деструктор
Date::~Date() {
    cout << "Объект уничтожен." << endl;
}

// Метод для проверки, является ли год високосным
bool Date::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Метод для увеличения даты на 5 дней
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

// Вспомогательная функция для определения количества дней в месяце
int Date::daysInMonth(int m) {
    static const int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
    if (m == 2 && isLeapYear(true)) {
        return 29;
    }
    return days[m];
}

// Формирование строки информации об объекте
    string Date::toString() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}