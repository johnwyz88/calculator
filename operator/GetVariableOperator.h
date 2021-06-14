//
// Created by Wang, John on 2021-06-12.
//
#ifndef GET_VARIABLE_OPERATOR_H
#define GET_VARIABLE_OPERATOR_H

class GetVariableOperator : public Operator {
public:
    GetVariableOperator(const std::string& value) : value(value) {}
    Value evaluate(EvaluationContext* context) const {
        std::optional<double> optionalValue = context->getVariable(value.stringVal);
        if (!optionalValue) throw std::runtime_error("Variable doesn't exist.");
        return optionalValue.value();
    }
    int getPrecedence() const {
        return 1;
    }
private:
    Value value;
};


#endif //GET_VARIABLE_OPERATOR_H
