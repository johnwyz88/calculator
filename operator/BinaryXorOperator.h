//
// Created by Wang, John on 2021-06-12.
//
#ifndef BINARY_XOR_OPERATOR_H
#define BINARY_XOR_OPERATOR_H

#include "Operator.h"

class BinaryXorOperator : public Operator {
public:
    BinaryXorOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    Value evaluate(EvaluationContext* context) const {
        return { (double) (((int) left->evaluate(context).doubleVal) ^ ((int) right->evaluate(context).doubleVal)) };
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //BINARY_XOR_OPERATOR_H
