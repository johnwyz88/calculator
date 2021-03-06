//
// Created by Wang, John on 2021-06-12.
//

#include <vector>
#include <sstream>

#include "Tokenizer.h"
#include "../operator/OperatorRegistry.h"
#include "../function/FunctionRegistry.h"

std::vector<Token> Tokenizer::tokenize(const std::string& input) {
    std::vector<Token> result;
    for (int i = 0; i < input.size(); i++) {
        int cur = i;
        if (i < input.size() - 1 && OperatorRegistry::isOperator(input.substr(i, 2))) {
            result.emplace_back(TokenType::OPERATOR, input.substr(i, 2));
            i++;
        } else if (OperatorRegistry::isOperator(input.substr(i, 1))) {
            result.emplace_back(TokenType::OPERATOR, input.substr(i, 1));
        } else if (input[i] == ' ') {
            continue;
        } else if (input[cur] >= '0' && input[cur] <= '9') {
            while (cur < input.size() && (input[cur] >= '0' && input[cur] <= '9' || input[cur] == '.')) {
                cur++;
            }
            result.emplace_back(TokenType::VALUE, input.substr(i, cur - i));
            i = cur-1;
        } else {
            while (cur < input.size() && !OperatorRegistry::isOperator(input.substr(cur, 1))
                && input[cur] != ' ') {
                cur++;
            }
            std::string value = input.substr(i, cur - i);
            if (FunctionRegistry::isFunction(value)) {
                int parenClose = input.find_first_of(')', i);
                result.emplace_back(TokenType::FUNCTION, input.substr(i, parenClose - i + 1));
                i = parenClose;
            } else if (value == "return") {
                i = cur-1;
            } else {
                result.emplace_back(TokenType::VARIABLE, value);
                i = cur-1;
            }
        }
    }
    return result;
}
