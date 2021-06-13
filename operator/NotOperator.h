//
// Created by Wang, John on 2021-06-12.
//
#ifndef NOT_OPERATOR_H
#define NOT_OPERATOR_H

#include "Operator.h"

class NotOperator : public Operator {
public:
    NotOperator(std::unique_ptr<Operator> arg, int precedence)
        : arg(std::move(arg)), precedence(precedence) {}
    Value evaluate(EvaluationContext* context) const {
        return { (double) !((bool) arg->evaluate(nullptr).doubleVal) };
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> arg;
    int precedence;
};


#endif //NOT_OPERATOR_H
