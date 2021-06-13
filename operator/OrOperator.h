//
// Created by Wang, John on 2021-06-12.
//
#ifndef OR_OPERATOR_H
#define OR_OPERATOR_H

#include "Operator.h"

class OrOperator : public Operator {
public:
    OrOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    double evaluate() const {
        return ((bool) left->evaluate()) || ((bool) right->evaluate());
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //OR_OPERATOR_H
