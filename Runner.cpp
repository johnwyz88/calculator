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
    while (true) {
        std::cout << ">>> ";
        std::string line;
        std::getline(std::cin, line);
        if (line == "help") {
            showHelp();
        } else {
            std::cout << calculator.eval(line, &context) << std::endl;
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
^ -> Not
! -> Not
&& -> Boolean And
|| -> Boolean Or
= -> Assignment
)" << std::endl;
}
