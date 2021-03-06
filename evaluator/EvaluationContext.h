//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_EVALUATION_CONTEXT_H
#define CALCULATOR_EVALUATION_CONTEXT_H

#include <unordered_map>
#include <string>

class EvaluationContext {
public:
    void registerVariable(const std::string &name, double val) {
        variables[name] = val;
    }
    std::optional<double> getVariable(const std::string &name) {
        if (variables.find(name) != variables.end()) return variables[name];
        return {};
    }
private:
    std::unordered_map<std::string, double> variables;
};



#endif //CALCULATOR_EVALUATION_CONTEXT_H
