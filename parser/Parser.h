//
// Created by Wang, John on 2021-06-12.
//

#ifndef PARSER_H
#define PARSER_H


#include <vector>
#include <stack>
#include <functional>
#include "../operator/Operator.h"
#include "../tokenizer/Token.h"

class Parser {

public:
    std::unique_ptr<Operator> parse(const std::vector<Token>& vector);
private:
    void resolve(std::stack<Token>* operators, std::stack<std::unique_ptr<Operator>>* values, int precedence);
    void resolveBinary(std::stack<Token>* operators,
                       std::stack<std::unique_ptr<Operator>>* values,
                       std::function<std::unique_ptr<Operator>(std::unique_ptr<Operator> left,
                                                               std::unique_ptr<Operator> right)> func);
    void resolveUnary(std::stack<Token>* operators,
                      std::stack<std::unique_ptr<Operator>>* values,
                      std::function<std::unique_ptr<Operator>(std::unique_ptr<Operator> arg)> func);
};


#endif //PARSER_H
