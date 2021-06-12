//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H


#include <vector>
#include "../operator/Operator.h"
#include "../tokenizer/Token.h"

class Parser {

public:
    Operator parse(const std::vector<Token>& vector);
};


#endif //CALCULATOR_PARSER_H
