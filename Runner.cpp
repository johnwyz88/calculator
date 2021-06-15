//
// Created by Wang, John on 2021-06-12.
//
#include <vector>
#include <sstream>
#include <iostream>

#include "Calculator.h"
#include "operator/Operator.h"

void showHelp();

int main() {
    EvaluationContext context;
    Calculator calculator;
    std::cout << "Welcome to RU! Type 'help' for list of available operators." << std::endl;
    std::string buffer;
    while (true) {
        if (buffer.empty()) {
            std::cout << ">>> ";
        } else {
            std::cout << "... ";
        }
        std::string line;
        std::getline(std::cin, line);
        if (line == "help") {
            showHelp();
        } else if (line.ends_with(':')) {
            buffer.append(line + "\n");
        } else if (!buffer.empty() && line.starts_with("    ")) {
            buffer.append(line + "\n");
        } else {
            buffer.append(line);
            std::cout << calculator.evaluate(buffer, &context) << std::endl;
            buffer = {};
        }
    }
}

void showHelp() {
    std::cout << "Here's the list of operators available: "
    << R"(
( -> Open Paren
) -> Close Paren
* -> Multiply
/ -> Divide
% -> Modulo
+ -> Add
- -> Subtract
| -> Binary Or
& -> Binary And
^ -> Xor
! -> Not
&& -> Boolean And
|| -> Boolean Or
= -> Assignment
** -> Exponent
)" << std::endl;
}
