//
// Created by Wang, John on 2021-06-12.
//
#include <vector>
#include <sstream>
#include <memory>

#include "Calculator.h"
#include "operator/Operator.h"

double Calculator::evaluate(const std::string &input) {
    std::vector<std::string> lines = preprocessor.preprocess(input);
    return eval(lines);
}

double Calculator::eval(const std::vector<std::string>& lines) {
    double result;
    EvaluationContext context;
    for (const std::string& line : lines) {
        std::vector<Token> tokens = tokenizer.tokenize(line);
        std::unique_ptr<Operator> root = parser.parse(tokens);
        result = evaluator.evaluate(*root, &context);
    }
    return result;
}

double Calculator::eval(const std::string& line, EvaluationContext* context) {
    double result;
    std::vector<Token> tokens = tokenizer.tokenize(line);
    std::unique_ptr<Operator> root = parser.parse(tokens);
    result = evaluator.evaluate(*root, context);
    return result;
}