//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H

#include <string>

enum TokenType {
    VALUE,
    EXPRESSION
};

union TokenValue {
    std::string expression;
    double value;

    TokenValue() {}
    TokenValue(const std::string& expression) : expression(expression) {}
    TokenValue(double value) : value(value) {}

    ~TokenValue() {}
};

struct Token {
    TokenType type;
    TokenValue value;
};


#endif //CALCULATOR_TOKEN_H
