//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "tokenizer/Tokenizer.h"
#include "parser/Parser.h"
#include "evaluator/Evaluator.h"

class Calculator {
public:
    Calculator() : tokenizer(Tokenizer()), parser(Parser()), evaluator(Evaluator()) {}
    double evaluate(const std::string& input);
private:
    Tokenizer tokenizer;
    Parser parser;
    Evaluator evaluator;
};


#endif //CALCULATOR_H
