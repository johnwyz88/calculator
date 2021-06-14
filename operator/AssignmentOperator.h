//
// Created by Wang, John on 2021-06-12.
//
#ifndef ASSIGNMENT_OPERATOR_H
#define ASSIGNMENT_OPERATOR_H

#include "Operator.h"

class AssignmentOperator : public Operator {
public:
    AssignmentOperator(std::unique_ptr<Operator> left, std::unique_ptr<Operator> right, int precedence)
        : left(std::move(left)), right(std::move(right)), precedence(precedence) {}
    Value evaluate(EvaluationContext* context) const {
        double val = right->evaluate(context).doubleVal;
        context->registerVariable(left->evaluate(context).stringVal, val);
        return {val};
    }
    int getPrecedence() const {
        return precedence;
    }
private:
    std::unique_ptr<Operator> left, right;
    int precedence;
};


#endif //ASSIGNMENT_OPERATOR_H
