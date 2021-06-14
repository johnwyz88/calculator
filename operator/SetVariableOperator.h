//
// Created by Wang, John on 2021-06-12.
//
#ifndef SET_VARIABLE_OPERATOR_H
#define SET_VARIABLE_OPERATOR_H

class SetVariableOperator : public Operator {
public:
    SetVariableOperator(const std::string& value) : value(value) {}
    Value evaluate(EvaluationContext* context) const {
        return value;
    }
    int getPrecedence() const {
        return 1;
    }
private:
    Value value;
};


#endif //SET_VARIABLE_OPERATOR_H
