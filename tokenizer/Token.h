//
// Created by Wang, John on 2021-06-12.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    VALUE,
    OPERATOR,
    VARIABLE
};

struct Token {
    Token(TokenType type, const std::string &value) : type(type), value(value) {}

    TokenType type;
    std::string value;
};


#endif //TOKEN_H
