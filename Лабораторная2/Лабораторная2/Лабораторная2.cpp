#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    int day, month, year;
    cout << "Введите дату (ДД ММ ГГГГ): ";
    cin >> day >> month >> year;
    // Создание объектов
    Date date(day, month, year);   

    // Проверка методов
    cout << "Дата: " << date.toString() << endl;

    cout << "Год високосный? ";
    if (date.isLeapYear(year)) {
        cout << "Да" << endl;
    }
    else {
        cout << "Нет" << endl;
    }

    cout << "Увеличение даты на 5 дней..." << endl;
    date.increaseByFiveDays();
    cout << "Новая дата: " << date.toString() << endl;

    return 0;
}
