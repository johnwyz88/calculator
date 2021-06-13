//
// Created by Wang, John on 2021-06-12.
//
#ifndef ADD_OPERATOR_H
#define ADD_OPERATOR_H

#include "Operator.h"

class AddOperator : public Operator {
public:
    AddOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    double evaluate() const {
        return left->evaluate() + right->evaluate();
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //ADD_OPERATOR_H
