#include <iostream>
#include <cstring> // Библиотека для работы со строками
using namespace std;

const char* cities[] = {
    "Москва",
    "Санкт-Петербург",
    "Владивосток",
    "Волгоград",
    "Калининград",
    "Хабаровск",
    "Иркутск",
    "Краснодар",
    "Архангельск",
    "Орел"
};

// Проверка наличия буквы 'в' в строке
bool containsLetterV(const char* str) {
    while (*str != '\0') {
        if (*str == 'в' || *str == 'В')
            return true;
        str++; // Переход к следующему символу
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Rus");
    const size_t numCities = sizeof(cities) / sizeof(cities[0]); // Размер массива
    int count = 0;

    for (size_t i = 0; i < numCities; ++i) {
        if (containsLetterV(cities[i]))
            count++;
    }

    cout << "Количество городов, содержащих букву 'в': " << count << endl;

    return 0;
}