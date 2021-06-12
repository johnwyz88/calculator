//
// Created by Wang, John on 2021-06-12.
//

#include <vector>
#include <iostream>
#include <sstream>

#include "Tokenizer.h"
#include "../operator/OperatorRegistry.h"

std::vector<Token> Tokenizer::tokenize(const std::string& input) {
    std::vector<Token> result;
    for (int i = 0; i < input.size(); i++) {
        if (i < input.size() - 1 && OperatorRegistry::isOperator(input.substr(i, 2))) {
            result.emplace_back(TokenType::OPERATOR, input.substr(i, 2));
            i++;
        } else if (OperatorRegistry::isOperator(input.substr(i, 1))) {
            result.emplace_back(TokenType::OPERATOR, input.substr(i, 1));
        } else if (input[i] == ' ') {
            continue;
        } else {
            int cur = i;
            while (input[cur] >= '0' && input[cur] <= '9') {
                cur++;
            }
            result.emplace_back(TokenType::VALUE, input.substr(i, cur - i));
        }
    }
    return result;
}
