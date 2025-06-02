#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция преобразования символа в нижний регистр
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    return ch;
}

// Подсчёт слов, начинающихся на букву 'м'
int countWordsStartingWith(const vector<string>& words, char firstLetter) {
    int count = 0;
    for (const auto& word : words) {
        if (!word.empty() && toLower(word[0]) == toLower(firstLetter))
            count++;
    }
    return count;
}

// Подсчёт точного количества слов ("компьютер")
int countExactWord(const vector<string>& words, const string& target) {
    int count = 0;
    for (const auto& word : words) {
        if (word == target)
            count++;
    }
    return count;
}

// Подсчёт предложений по знакам препинания
int countSentences(const string& inputText) {
    int sentenceCount = 0;
    for (size_t i = 0; i < inputText.size(); ++i) {
        if (inputText[i] == '.' || inputText[i] == '?' || inputText[i] == '!') {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

// Нормализация текста и выделение чистых слов
void normalizeText(const string& inputText, vector<string>& words) {
    string currentWord;
    for (char ch : inputText) {
        if (isspace(ch) || ispunct(ch)) {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else {
            currentWord += ch;
        }
    }
    if (!currentWord.empty())
        words.push_back(currentWord);
}

int main() {
    setlocale(LC_ALL, "Russian");
    string inputText;
    cout << "Введите текст: ";
    getline(cin, inputText);

    // Формируем нормальный набор слов
    vector<string> words;
    normalizeText(inputText, words);

    // Подсчёт слов, начинающихся на 'м'
    int m_words_count = countWordsStartingWith(words, 'm');

    // Подсчёт слов "компьютер"
    int computer_word_count = countExactWord(words, "computer");

    // Подсчёт предложений
    int sentence_count = countSentences(inputText);

    // Выводим результаты
    cout << "Количество слов, начинающихся на 'м': " << m_words_count << endl;
    cout << "Количество слов 'Компьютер'/\"компьютер\": " << computer_word_count << endl;
    cout << "Количество предложений: " << sentence_count << endl;

    return 0;
}