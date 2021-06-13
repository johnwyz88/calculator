//
// Created by Wang, John on 2021-06-12.
//
#include <stack>

#include "Parser.h"
#include "../operator/ValueOperator.h"
#include "../operator/OperatorRegistry.h"
#include "../operator/MultiplyOperator.h"
#include "../operator/DivideOperator.h"
#include "../operator/AddOperator.h"
#include "../operator/SubtractOperator.h"
#include "../operator/ModuloOperator.h"
#include "../operator/BinaryAndOperator.h"
#include "../operator/BinaryOrOperator.h"
#include "../operator/AndOperator.h"
#include "../operator/OrOperator.h"
#include "../operator/NotOperator.h"

std::unique_ptr<Operator> Parser::parse(const std::vector<Token>& input) {
    std::stack<Token> operators;
    std::stack<std::unique_ptr<Operator>> values;
    for (int i = 0; i < input.size(); i++) {
        if (input[i].type == TokenType::VALUE) {
            values.push(std::make_unique<ValueOperator>(input[i].value));
        } else if (input[i].value == "(") {
            int open = 1;
            int j = i + 1;
            for (; j < input.size(); j++) {
                if (input[j].value == "(") open++;
                else if (input[j].value == ")") open--;
                if (open == 0) break;
            }
            std::vector<Token> sublist(&input[i+1], &input[j]);
            values.push(std::move(parse(sublist)));
            i = j;
        } else {
            Token next = input[i];
            int precedence = OperatorRegistry::getPrecedence(next.value);
            resolve(&operators, &values, precedence);
            operators.push(next);
        }
    }
    resolve(&operators, &values, 99);
    return std::move(values.top());
}

void Parser::resolve(std::stack<Token>* operators,
                     std::stack<std::unique_ptr<Operator>>* values, int precedence) {
    while (!operators->empty() && precedence >= OperatorRegistry::getPrecedence(operators->top().value)) {
        Token next = operators->top();
        operators->pop();
        if (next.value == "*") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<MultiplyOperator>(std::move(left), std::move(right), precedence);
                          });
        } else if (next.value == "/") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<DivideOperator>(std::move(left), std::move(right), precedence);
                          });
        } else if (next.value == "+") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<AddOperator>(std::move(left), std::move(right), precedence);
                          });
        } else if (next.value == "-") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<SubtractOperator>(std::move(left), std::move(right), precedence);
                          });
        } else if (next.value == "%") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<ModuloOperator>(std::move(left), std::move(right), precedence);
                          });
        } else if (next.value == "&") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<BinaryAndOperator>(std::move(left), std::move(right), precedence);
                          });
        } else if (next.value == "|") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<BinaryOrOperator>(std::move(left), std::move(right), precedence);
                          });

        } else if (next.value == "&&") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<AndOperator>(std::move(left), std::move(right), precedence);
                          });

        } else if (next.value == "||") {
            resolveBinary(operators, values,
                          [precedence](std::unique_ptr<Operator> left, std::unique_ptr<Operator> right) {
                              return std::make_unique<OrOperator>(std::move(left), std::move(right), precedence);
                          });

        } else if (next.value == "^" || next.value == "!") {
            resolveUnary(operators, values,
                          [precedence](std::unique_ptr<Operator> arg) {
                              return std::make_unique<NotOperator>(std::move(arg), precedence);
                          });

        }
    }
}

void Parser::resolveBinary(std::stack<Token>* operators,
                           std::stack<std::unique_ptr<Operator>>* values,
                           std::function<std::unique_ptr<Operator>(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right)> func) {
    if (values->empty()) throw std::runtime_error("Parse failed.");
    std::unique_ptr<Operator> rightValue = std::move(values->top());
    values->pop();
    std::unique_ptr<Operator> leftValue;
    if (values->empty()) leftValue = std::make_unique<ValueOperator>("0");
    else {
        leftValue = std::move(values->top());
        values->pop();
    }
    values->push(func(std::move(leftValue), std::move(rightValue)));
}

void Parser::resolveUnary(std::stack<Token>* operators,
                          std::stack<std::unique_ptr<Operator>>* values,
                          std::function<std::unique_ptr<Operator>(std::unique_ptr<Operator> arg)> func) {
    std::unique_ptr<Operator> arg = std::move(values->top());
    values->pop();
    values->push(func(std::move(arg)));
}
