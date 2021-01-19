// Copyright 2020 Khoroshavina Ekaterina
#include <string>
#include "MyStack.h"
#include "postfix.h"

int order(char sign) {
    switch (sign) {
    case '(':
        return 0;
        break;
    case ')':
        return 1;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}

bool isNum(char c) {
    return ((c >= '0' && c <= '9') || c == '.');
}

std::string infix2postfix(std::string str) {
    MyStack<char> stack(100);
    std::string result;
    std::string num;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (num != "") {
                result = result + num + " ";
                num = "";
            }
            continue;
        }
        if (isNum(str[i])) {
            num += str[i];
        }
        if (order(str[i]) == 0) {
            stack.push(str[i]);
        }
        if (order(str[i]) == 1) {
            if (num != "") {
                result = result + num + " ";
                num = "";
            }
            while (stack.get() != '(') {
                result = result + stack.pop() + " ";
            }
            stack.pop();
        }
        if (order(str[i]) == 2 || order(str[i]) == 3) {
            if (stack.isEmpty() || order(stack.get()) < order(str[i])) {
                stack.push(str[i]);
            } else {
                result = result + stack.pop() + " ";
                stack.push(str[i]);
            }
        }
    }
    if (num != "") {
        result = result + num + " ";
    }
    while (!stack.isEmpty()) {
        result = result + stack.pop() + " ";
    }
    result.pop_back();
    return result;
}
