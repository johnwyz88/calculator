//
// Created by Wang, John on 2021-06-12.
//
#ifndef VARIABLE_OPERATOR_H
#define VARIABLE_OPERATOR_H

class VariableOperator : public Operator {
public:
    VariableOperator(const std::string& value) : value(value) {}
    Value evaluate(EvaluationContext* context) const {
        return value;
    }
    int getPrecedence() const {
        return 1;
    }
private:
    Value value;
};


#endif //VARIABLE_OPERATOR_H
