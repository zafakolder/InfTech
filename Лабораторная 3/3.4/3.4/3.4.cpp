#include <iostream>
#include <string>

using namespace std;

// Функция подсчета частоты символов
void count(const string& str1, const string& str2) {
    // Создаем массив частот символов
    int frequencies['z' - 'a' + 1]; // Массив длиной 26 (алфавит a-z)
    fill(frequencies, frequencies + sizeof(frequencies) / sizeof(int), 0); // Обнуляем массив

    // Переводим обе строки в нижний регистр и считаем каждую букву
    for (char ch : str2) {
        if (isalpha(ch)) {
            frequencies[tolower(ch) - 'a']++;
        }
    }

    // Для каждой буквы первой строки выводим количество совпадений
    for (char ch : str1) {
        if (isalpha(ch)) {
            char lowerCh = tolower(ch);
            cout << "'" << ch << "' встречается " << frequencies[lowerCh - 'a'] << " раз\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    string str1, str2;

    // Сначала читаем полную строку через getline(), чтобы захватить весь ввод
    cout << "Введите первую строку: ";
    getline(cin, str1);

    cout << "Введите вторую строку: ";
    getline(cin, str2);

    // Подсчитываем частоту символов
    count(str1, str2);

    return 0;
}