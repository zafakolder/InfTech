#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    const char* names[] = { "Анна", "Ольга", "Марина", "Ирина", "Светлана", "Оля"};
    const size_t n = sizeof(names) / sizeof(names[0]); // Количество элементов в массиве

    // Переменная для хранения имени с минимальной длиной
    const char* d = names[0];

    // Проходим по списку и ищем самое короткое имя
    for (size_t i = 1; i < n; ++i) {
        if (strlen(names[i]) < strlen(d)) { // Если длина текущего имени меньше длины минимального
            d = names[i];                   // Обновляем минимальное имя
        }
    }

    cout << "Имя с наименьшим количеством букв: " << d << endl;

    return 0;
}