//
// Created by Wang, John on 2021-06-12.
//

#ifndef OPERATOR_H
#define OPERATOR_H

#include "../evaluator/EvaluationContext.h"
#include "Value.h"

class Operator {
public:
    virtual Value evaluate(EvaluationContext* context) const = 0;
    virtual int getPrecedence() const = 0;
};


#endif //OPERATOR_H
