//
// Created by Wang, John on 2021-06-12.
//

#ifndef OPERATOR_H
#define OPERATOR_H

#include "../evaluator/EvaluationContext.h"
#include "Value.h"

class Operator {
public:
    Operator() = default;
    virtual Value evaluate(EvaluationContext* context) const {};
    virtual int getPrecedence() const {};
};


#endif //OPERATOR_H
