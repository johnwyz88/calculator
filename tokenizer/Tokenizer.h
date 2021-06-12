//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_TOKENIZER_H
#define CALCULATOR_TOKENIZER_H


#include <string>
#include "Token.h"

class Tokenizer {
public:
    std::vector<Token> tokenize(const std::string& input);
};


#endif //CALCULATOR_TOKENIZER_H
