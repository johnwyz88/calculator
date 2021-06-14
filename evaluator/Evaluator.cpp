//
// Created by Wang, John on 2021-06-12.
//

#include <iostream>

#include "Evaluator.h"

double Evaluator::evaluate(const Operator& op, EvaluationContext* context) {
    std::cout << "Evaluator::evaluate starting.." << std::endl;
    return op.evaluate(context).doubleVal;
}
