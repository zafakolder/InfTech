#include <iostream>
#include <string>
#include <vector>


using namespace std;

// Функция коррекции текста и подсчета статистики
void correctAndCount(string& text, int& numWords, int& numSentences) {
    bool inSentence = false;           // Индикатор нахождения внутри предложения
    bool lastWasDot = false;           // Был ли последний символ точкой

    // Пересбор строки с нужными изменениями
    string correctedText;
    for (char ch : text) {
        if (ch == '.') {
            // Запоминаем последнюю точку
            lastWasDot = true;
            correctedText += ch;
        }
        else if (lastWasDot && !isspace(ch)) {
            // Если после точки идет слово без пробела, добавляем пробел
            correctedText += ' ';
            correctedText += ch;
            lastWasDot = false;
        }
        else {
            // Остальное копируем как есть
            correctedText += ch;
            lastWasDot = false;
        }

        // Обработка подсчета слов и предложений
        if (isspace(ch)) {
            if (inSentence) {
                numWords++;
                inSentence = false;
            }
        }
        else if (ispunct(ch)) {
            // Знаки препинания могут завершать слово
            if (inSentence) {
                numWords++;
                inSentence = false;
            }

            // Отдельно считаем предложения по завершающим знакам препинания
            if (ch == '.' || ch == '!' || ch == '?') {
                numSentences++;
            }
        }
        else {
            // Слово продолжается или начинается
            inSentence = true;
        }
    }

    // Последнее слово тоже считаем, если оно было активно
    if (inSentence) {
        numWords++;
    }

    // Замещаем исходный текст новым откорректированным
    text.swap(correctedText);
}

int main() {
    setlocale(LC_CTYPE, "Rus");

    string inputText;
    cout << "Введите текст: ";
    getline(cin, inputText);

    int numWords = 0;
    int numSentences = 0;

    // Выполняем коррекцию и получаем результаты
    correctAndCount(inputText, numWords, numSentences);

    // Вывод откорректированного текста
    cout << "\nОткорректированный текст:\n";
    cout << inputText << endl;

    // Вывод статистики
    cout << "\nСтатистика:" << endl;
    cout << "Количество слов: " << numWords << endl;
    cout << "Количество предложений: " << numSentences << endl;

    return 0;
}