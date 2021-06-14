//
// Created by Wang, John on 2021-06-12.
//

#include "Evaluator.h"

double Evaluator::evaluate(const Operator& op, EvaluationContext* context) {
    return op.evaluate(context).doubleVal;
}
