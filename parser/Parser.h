//
// Created by Wang, John on 2021-06-12.
//

#ifndef PARSER_H
#define PARSER_H


#include <vector>
#include <stack>
#include "../operator/Operator.h"
#include "../tokenizer/Token.h"

class Parser {

public:
    Operator parse(const std::vector<Token>& vector);
private:
    Operator resolve(const std::stack<std::unique_ptr<Operator>>& operators,
                     const std::stack<std::unique_ptr<Operator>>& values, int precedence);
};


#endif //PARSER_H
