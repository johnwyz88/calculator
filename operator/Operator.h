//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_OPERATOR_H
#define CALCULATOR_OPERATOR_H


#include "Context.h"

class Operator {
public:
    virtual bool evaluate(Context* context) {};
};


#endif //CALCULATOR_OPERATOR_H
