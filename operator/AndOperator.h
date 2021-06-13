//
// Created by Wang, John on 2021-06-12.
//
#ifndef AND_OPERATOR_H
#define AND_OPERATOR_H

#include "Operator.h"

class AndOperator : public Operator {
public:
    AndOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    double evaluate() const {
        return ((bool) left->evaluate()) && ((bool) right->evaluate());
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //AND_OPERATOR_H
