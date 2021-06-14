//
// Created by Wang, John on 2021-06-12.
//
#ifndef SET_VARIABLE_OPERATOR_H
#define SET_VARIABLE_OPERATOR_H

#include <iostream>

class SetVariableOperator : public Operator {
public:
    SetVariableOperator(const std::string& value) : value(value) {}
    Value evaluate(EvaluationContext* context) const {
        std::cout << "SetVariableOperator.evaluate starting.." << std::endl;
        return value.stringVal;
    }
    int getPrecedence() const {
        return 1;
    }
private:
    Value value;
};


#endif //SET_VARIABLE_OPERATOR_H
