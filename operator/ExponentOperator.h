//
// Created by Wang, John on 2021-06-12.
//
#ifndef EXPONENT_OPERATOR_H
#define EXPONENT_OPERATOR_H

#include <math.h>

#include "Operator.h"

class ExponentOperator : public Operator {
public:
    ExponentOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    Value evaluate(EvaluationContext* context) const {
        return { pow(left->evaluate(context).doubleVal, right->evaluate(context).doubleVal) };
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //EXPONENT_OPERATOR_H
