//
// Created by Wang, John on 2021-06-12.
//

#ifndef CALCULATOR_OPERATORREGISTRY_H
#define CALCULATOR_OPERATORREGISTRY_H

#include <string>
#include <unordered_map>

namespace Calculator {

class OperatorRegistry {
public:
    static int OperatorRegistry::getPrecedence(const std::string& op) {
        return operators[op];
    }
private:
    static std::unordered_map<std::string, int> operators = {
            { "*", 3 },
            { "/", 3 },
            { "%", 3 },
            { "+", 4 },
            { "-", 4 },
            { "&", 8 },
            { "^", 9 },
            { "|", 10 },
            { "&&", 11 },
            { "||", 12 }
    }
};

}


#endif //CALCULATOR_OPERATORREGISTRY_H
