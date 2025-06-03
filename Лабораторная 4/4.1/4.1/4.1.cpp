#include <iostream>
#include <cstring> 

using namespace std;

const char* cities[] = {
    "Москва",
    "Санкт-Петербург",
    "Новосибирск",
    "Екатеринбург",
    "Нижний Новгород",
    "Казань",
    "Челябинск",
    "Омск",
    "Самара",
    "Ростов"
};

// Функция проверяет, заканчивается ли строка буквой 'В'
bool endsWithV(const char* cityName) {
    int len = strlen(cityName);
    return len > 0 && cityName[len - 1] == 'в';
}

int main() {
    setlocale(LC_ALL, "Rus");
    const size_t numCities = sizeof(cities) / sizeof(cities[0]);

    int count = 0;
    for (size_t i = 0; i < numCities; ++i) {
        if (endsWithV(cities[i])) {
            count++;
        }
    }

    cout << "Количество городов, заканчивающихся на букву \"в\": " << count << endl;

    return 0;
}