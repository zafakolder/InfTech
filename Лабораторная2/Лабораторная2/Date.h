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
    // Конструктор с параметрами
    Date(int d, int m, int y);

    // Деструктор
    ~Date();

    // Метод для проверки, является ли год високосным
    static bool isLeapYear(int year);

    // Метод для увеличения даты на 5 дней
    void increaseByFiveDays();

    // Вспомогательная функция для определения количества дней в месяце
    static int daysInMonth(int m);

    // Формирование строки информации об объекте
    string toString() const;
};

#endif