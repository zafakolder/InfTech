#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// Класс Stack
class Stack {
private:
    static const int maxSize = 100; // максимальный размер стэка
    int top;                       // индекс вершины стека
    int data[maxSize];             // данные в стеке

public:
    Stack() : top(-1) {}           // конструктор
    ~Stack() {}                    // деструктор (ничего сложного)

    void push(int value) {
        if (isFull())
            throw runtime_error("Стэк полон.");
        data[++top] = value;
    }

    int pop() {
        if (isEmpty())
            throw runtime_error("Стэк пуст.");
        return data[top--];
    }

    int peek() {
        if (isEmpty())
            throw runtime_error("Стэк пуст.");
        return data[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top >= maxSize - 1;
    }

    // Создание временной копии стека
    Stack clone() const {
        Stack result;
        result.top = top;
        for (int i = 0; i <= top; i++)
            result.data[i] = data[i];
        return result;
    }
};