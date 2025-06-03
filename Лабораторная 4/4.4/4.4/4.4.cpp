#include <iostream>
#include <cstring> // Для работы с функциями strlen и strcpy

// Максимальное количество фамилий
#define MAX_NAMES 10

// Фамилия сотрудника
struct EmployeeSurname {
    char surname[50];
};

void bubbleSort(EmployeeSurname arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].surname, arr[j + 1].surname) > 0) {
                // Меняем местами элементы
                EmployeeSurname temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Если не было обменов, значит массив отсортирован
        if (!swapped) break;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    EmployeeSurname employees[MAX_NAMES] = {
        {"Иванов"},
        {"Петрова"},
        {"Смирнова"},
        {"Попова"},
        {"Васечкин"},
        {"Рябов"},
        {"Федоров"},
        {"Горбачев"},
        {"Жуков"},
        {"Шестаков"}
    };

    EmployeeSurname filteredEmployees[MAX_NAMES]; // Новый массив для фильтрованных фамилий
    int filteredCount = 0; // Кол-во перенесённых фамилий

    // Копируем фамилии длиной больше 7 символов
    for (int i = 0; i < MAX_NAMES; i++) {
        if (strlen(employees[i].surname) > 7) {
            strcpy_s(filteredEmployees[filteredCount].surname, employees[i].surname); // Копирование фамилии
            filteredCount++;
        }
    }

    // Сортируем полученный список фамилий по алфавиту
    bubbleSort(filteredEmployees, filteredCount);

    // Вывод результата
    std::cout << "Отфильтрованные и отсортированные фамилии:\n";
    for (int i = 0; i < filteredCount; i++)
        std::cout << filteredEmployees[i].surname << "\n";

    return 0;
}