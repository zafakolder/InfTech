#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

// Чтение поезда из файла
void readTrainFromFile(Stack& train, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла '" << filename << "'" << endl;
        exit(EXIT_FAILURE);
    }

    int wagonType;
    while (file >> wagonType) {
        try {
            train.push(wagonType);
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
    }
    file.close();
}

// Формирование состава с клавиатуры
void createTrainFromKeyboard(Stack& train) {
    cout << "Введите номера вагонов (1 или 2, 0 для окончания ввода): ";
    int wagonType;
    cin >> wagonType;
    while (wagonType != 0) {
        try {
            train.push(wagonType);
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        cin >> wagonType;
    }
}

// Распределение вагонов по направлениям
void splitTrain( Stack& inputTrain, Stack& outputLine1, Stack& outputLine2) {
    Stack buffer; // временный буфер
    while (!inputTrain.isEmpty()) {
        buffer.push(inputTrain.peek()); // Кладем сверху
        inputTrain.pop();               // Удаляем из оригинального стека
    }

    while (!buffer.isEmpty()) {
        int currentWagon = buffer.pop();
        if (currentWagon == 1) {
            outputLine1.push(currentWagon);
        }
        else if (currentWagon == 2) {
            outputLine2.push(currentWagon);
        }
    }
}

// Безопасная печать содержимого стека
void printStack(const Stack& stack) {
    Stack copy = stack.clone(); // Создаем копию стека
    while (!copy.isEmpty()) {
        cout << copy.pop() << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    Stack inputTrain;      // Входящий состав
    Stack line1;           // Линия для вагонов типа 1
    Stack line2;           // Линия для вагонов типа 2

    int choice;
    cout << "Выберите способ формирования состава:\n"
        << "1. Из файла\n"
        << "2. С клавиатуры\n"
        << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        readTrainFromFile(inputTrain, "train.txt"); // считывание из файла
        break;
    case 2:
        createTrainFromKeyboard(inputTrain);       // ввод с клавиатуры
        break;
    default:
        cerr << "Неверный выбор.\n";
        return EXIT_FAILURE;
    }

    // Распределение состава по линиям
    splitTrain(inputTrain, line1, line2);

    // Вывод результатов
    cout << "Состав первого типа (линия 1):\n";
    printStack(line1);

    cout << "Состав второго типа (линия 2):\n";
    printStack(line2);

    return 0;
}