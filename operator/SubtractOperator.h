//
// Created by Wang, John on 2021-06-12.
//
#ifndef SUBTRACT_OPERATOR_H
#define SUBTRACT_OPERATOR_H

#include "Operator.h"

class SubtractOperator : public Operator {
public:
    SubtractOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    double evaluate() const {
        return left->evaluate() - right->evaluate();
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //SUBTRACT_OPERATOR_H
