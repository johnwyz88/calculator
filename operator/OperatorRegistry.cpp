//
// Created by Wang, John on 2021-06-12.
//

#include <string>
#include <unordered_map>

#include "OperatorRegistry.h"

std::unordered_map<std::string, int> OperatorRegistry::precedence = {
        { "(", 1 },
        { ")", 1 },
        { "**", 2 },
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
        { "||", 12 },
        { "=", 14}
};