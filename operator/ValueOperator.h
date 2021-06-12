//
// Created by Wang, John on 2021-06-12.
//
#ifndef VALUE_OPERATOR_H
#define VALUE_OPERATOR_H

class ValueOperator : public Operator {
public:
    ValueOperator(const std::string& value) : value(stod(value)) {}
    double evaluate() const {
        return value;
    }
    int getPrecedence() const {
        return 1;
    }
private:
    double value;
};


#endif //VALUE_OPERATOR_H
