//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "tokenizer/Tokenizer.h"
#include "parser/Parser.h"
#include "evaluator/Evaluator.h"
#include "preprocessor/Preprocessor.h"

class Calculator {
public:
    Calculator() : preprocessor(Preprocessor()), tokenizer(Tokenizer()), parser(Parser()), evaluator(Evaluator()) {}
    double evaluate(const std::string& input);
    double evaluate(const std::string& input, EvaluationContext* context);
    double evaluate(std::ifstream& input);
private:
    Preprocessor preprocessor;
    Tokenizer tokenizer;
    Parser parser;
    Evaluator evaluator;

    double eval(const std::vector<std::string>& lines);
    double eval(const std::vector<std::string>& lines, EvaluationContext* context);
};


#endif //CALCULATOR_H
