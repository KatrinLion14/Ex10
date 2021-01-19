// Copyright 2020 Khoroshavina Ekaterina
#include <iostream>
#include <string>
#include "postfix.h"

int main() {
    std::string test("(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9");
    std::string result = infix2postfix(test);
    std::cout << result;  // 6 4 2 - * 5 + 2.6 3 7 * + * 9 -
    return 0;
}
