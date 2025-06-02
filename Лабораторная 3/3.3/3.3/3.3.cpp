#include <iostream>
#include <string>

using namespace std;

// Функция сортировки пузырьком
void bubbleSort(string& s) {
    int n = s.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

// Главная функция для упорядочивания символов
void sort(string& text) {
    // Поиск позиции первого символа '?'
    int startPos = -1;
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == '?') {
            startPos = i;
            break;
        }
    }

    // Поиск позиции последнего символа '!'
    int endPos = -1;
    for (int i = text.length() - 1; i >= 0; --i) {
        if (text[i] == '!') {
            endPos = i;
            break;
        }
    }

    // Если оба символа найдены, извлекаем подстроку и сортируем её
    if (startPos != -1 && endPos != -1 && startPos < endPos) {
        string subStr = text.substr(startPos + 1, endPos - startPos - 1);
        bubbleSort(subStr);

        // Возвращаем отсортированные символы назад в оригинальную строку
        for (int i = 0; i < subStr.length(); ++i) {
            text[startPos + 1 + i] = subStr[i];
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    string inputText;
    cout << "Введите строку текста: ";
    getline(cin, inputText);

    // Сортируем подстроку
    sort(inputText);

    // Выводим результат
    cout << "Изменённая строка: " << inputText << endl;

    return 0;
}