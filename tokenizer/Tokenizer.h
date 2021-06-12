//
// Created by Wang, John on 2021-06-12.
//

#ifndef TOKENIZER_H
#define TOKENIZER_H


#include <string>
#include "Token.h"

class Tokenizer {
public:
    std::vector<Token> tokenize(const std::string& input);
};


#endif //TOKENIZER_H
