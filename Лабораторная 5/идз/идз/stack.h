#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// ����� Stack
class Stack {
private:
    static const int maxSize = 100; // ������������ ������ �����
    int top;                       // ������ ������� �����
    int data[maxSize];             // ������ � �����

public:
    Stack() : top(-1) {}           // �����������
    ~Stack() {}                    // ���������� (������ ��������)

    void push(int value) {
        if (isFull())
            throw runtime_error("���� �����.");
        data[++top] = value;
    }

    int pop() {
        if (isEmpty())
            throw runtime_error("���� ����.");
        return data[top--];
    }

    int peek() {
        if (isEmpty())
            throw runtime_error("���� ����.");
        return data[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top >= maxSize - 1;
    }

    // �������� ��������� ����� �����
    Stack clone() const {
        Stack result;
        result.top = top;
        for (int i = 0; i <= top; i++)
            result.data[i] = data[i];
        return result;
    }
};