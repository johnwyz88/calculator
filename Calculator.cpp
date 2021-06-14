//
// Created by Wang, John on 2021-06-12.
//
#include <vector>

#include "Calculator.h"
#include "operator/Operator.h"

double Calculator::evaluate(const std::string &input) {
    EvaluationContext context;
    std::vector<std::string> lines = preprocessor.preprocess(input);
    double result;
    for (const std::string& line : lines) {
        std::vector<Token> tokens = tokenizer.tokenize(line);
        std::unique_ptr<Operator> root = parser.parse(tokens);
        result = evaluator.evaluate(*root, &context);
    }
    return result;
}
