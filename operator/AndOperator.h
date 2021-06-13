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
    Value evaluate(EvaluationContext* context) const {
        return { (double) (((bool) left->evaluate(context).doubleVal) && ((bool) right->evaluate(context).doubleVal)) };
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //AND_OPERATOR_H
