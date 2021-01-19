// Copyright 2020 Khoroshavina Ekaterina
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>
#include <string>

template<class T>
class MyStack {
 private:
    T* stack;
    int size;
    int top;

 public:
    explicit MyStack(int n) {
        this->size = n;
        this->top = -1;
        this->stack = new T[n];
    }
    MyStack(const MyStack& copy) {
        this->size = copy.size;
        this->top = copy.top;
        this->stack = new T[copy.size];
        for (int i = 0; i < size; i++) {
            this->stack[i] = copy.stack[i];
        }
    }
    ~MyStack() {
        this->size = 0;
        this->top = -1;
        delete[] stack;
    }
    T get() const {
        if (!isEmpty()) {
            return stack[top];
        }
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }
    T pop() {
        if (!isEmpty()) {
            top--;
            return stack[top + 1];
        }
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }
    void push(T num) {
        if (!isFull()) {
            stack[top + 1] = num;
            top++;
        } else {
            std::cout << "Stack is full" << std::endl;
        }
    }
    bool isFull() const {
        return (top == size - 1);
    }
    bool isEmpty() const {
        return (top == -1);
    }
};

#endif  // INCLUDE_MYSTACK_H_
