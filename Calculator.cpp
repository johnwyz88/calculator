//
// Created by Wang, John on 2021-06-12.
//
#include <vector>

#include "Calculator.h"
#include "operator/Operator.h"

double Calculator::evaluate(const std::string &input) {
    std::vector<Token> tokens = tokenizer.tokenize(input);
    Operator root = parser.parse(tokens);
    return evaluator.evaluate(root);
}
