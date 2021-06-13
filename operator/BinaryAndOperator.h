//
// Created by Wang, John on 2021-06-12.
//
#ifndef BINARY_AND_OPERATOR_H
#define BINARY_AND_OPERATOR_H

#include "Operator.h"

class BinaryAndOperator : public Operator {
public:
    BinaryAndOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    double evaluate() const {
        return ((int) left->evaluate()) & ((int) right->evaluate());
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //BINARY_AND_OPERATOR_H
