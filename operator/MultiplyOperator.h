//
// Created by Wang, John on 2021-06-12.
//
#ifndef MULTIPLY_OPERATOR_H
#define MULTIPLY_OPERATOR_H

#include "Operator.h"

class MultiplyOperator : public Operator {
public:
    MultiplyOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    Value evaluate(EvaluationContext* context) const {
        return { left->evaluate(context).doubleVal * right->evaluate(context).doubleVal };
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //MULTIPLY_OPERATOR_H
