//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H

#include <string>

enum TokenType {
    VALUE,
    OPERATOR
};

struct Token {
    Token(TokenType type, const std::string &value) : type(type), value(value) {}

    TokenType type;
    std::string value;
};


#endif //CALCULATOR_TOKEN_H
