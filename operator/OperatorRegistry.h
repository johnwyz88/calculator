//
// Created by Wang, John on 2021-06-12.
//

#ifndef OPERATOR_REGISTRY_H
#define OPERATOR_REGISTRY_H

#include <string>
#include <unordered_map>

class OperatorRegistry {
public:
    static int getPrecedence(const std::string& op) {
        return precedence[op];
    }
    static bool isOperator(const std::string& op) {
        return precedence.find(op) != precedence.end();
    }
private:
    static std::unordered_map<std::string, int> precedence;

};

#endif //OPERATOR_REGISTRY_H
