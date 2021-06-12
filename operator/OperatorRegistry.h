//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_OPERATORREGISTRY_H
#define CALCULATOR_OPERATORREGISTRY_H

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

std::unordered_map<std::string, int> OperatorRegistry::precedence = {
        { "(", 1 },
        { ")", 1 },
        { "*", 3 },
        { "/", 3 },
        { "%", 3 },
        { "+", 4 },
        { "-", 4 },
        { "&", 8 },
        { "^", 9 },
        { "!", 9 },
        { "|", 10 },
        { "&&", 11 },
        { "||", 12 }
};

#endif //CALCULATOR_OPERATORREGISTRY_H
