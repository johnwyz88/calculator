//
// Created by Wang, John on 2021-06-12.
//
#include <stack>

#include "Parser.h"
#include "../operator/ValueOperator.h"
#include "../operator/OperatorRegistry.h"
#include "../operator/MultiplyOperator.h"

Operator Parser::parse(const std::vector<Token>& input) {
    std::stack<std::unique_ptr<Operator>> operators;
    std::stack<std::unique_ptr<Operator>> values;
    for (int i = 0; i < input.size(); i++) {
        if (input[i].type == TokenType::VALUE) {
            values.push(std::make_unique<ValueOperator>(input[i].value));
        } else {
            Token next = input[i];
            int precedence = OperatorRegistry::getPrecedence(next.value);
            values.push(std::make_unique<Operator>(resolve(operators, values, precedence)));
            if (next.value == "*") {
                std::unique_ptr<Operator> rightValue = std::move(values.top());
                values.pop();
                std::unique_ptr<Operator> leftValue = std::move(values.top());
                values.pop();
                operators.push(std::make_unique<MultiplyOperator>(std::move(leftValue), std::move(rightValue), precedence));
            }
        }
    }
    return resolve(operators, values, 0);
}

Operator Parser::resolve(const std::stack<std::unique_ptr<Operator>>& operators,
                         const std::stack<std::unique_ptr<Operator>>& values, int precedence) {
    while (!operators.empty() && precedence >= operators.top()->getPrecedence()) {

    }
    return Operator();
}
