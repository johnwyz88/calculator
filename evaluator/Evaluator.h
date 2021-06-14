//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_EVALUATOR_H
#define CALCULATOR_EVALUATOR_H


#include "../operator/Operator.h"

class Evaluator {

public:
    double evaluate(const Operator& op, EvaluationContext* context);
};


#endif //CALCULATOR_EVALUATOR_H
