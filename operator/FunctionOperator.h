//
// Created by Wang, John on 2021-06-12.
//
#ifndef FUNCTION_OPERATOR_H
#define FUNCTION_OPERATOR_H

#include <sstream>

#include "../function/FunctionRegistry.h"

class FunctionOperator : public Operator {
public:
    FunctionOperator(const std::string& value) {
        std::size_t parenOpen = value.find_first_of('(');
        std::size_t parenClose = value.find_first_of(')');
        functionName = value.substr(0, parenOpen);

        std::stringstream ss(value.substr(parenOpen + 1, parenClose - parenOpen - 1));
        for (std::string arg; std::getline(ss, arg, ',');) {
            args.push_back(arg);
        }
    }
    Value evaluate(EvaluationContext* context) const {
        return FunctionRegistry::evaluate(functionName, args);
    }
    int getPrecedence() const {
        return 1;
    }
private:
    std::string functionName;
    std::vector<std::string> args;
};


#endif //FUNCTION_OPERATOR_H
