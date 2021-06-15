//
// Created by Wang, John on 2021-06-13.
//

#include <sstream>
#include <fstream>

#include "Preprocessor.h"
#include "../function/FunctionRegistry.h"
#include "../utils/StringUtils.h"

std::vector<std::string> Preprocessor::preprocess(const std::string &input) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string functionName;
    std::vector<std::string> functionLogic;
    for (std::string line; std::getline(ss, line);) {
        if (line.starts_with("def") && line.ends_with(":")) {
            std::size_t nameStart = line.find_first_not_of(' ', 3);
            std::size_t parenOpen = line.find_first_of('(');
            std::size_t parenClose = line.find_first_of(')');
            functionName = line.substr(nameStart, parenOpen - nameStart);

            std::vector<std::string> signature;
            std::stringstream ss(line.substr(parenOpen + 1, parenClose - parenOpen - 1));
            for (std::string sig; std::getline(ss, sig, ',');) {
                StringUtils::trim(sig);
                signature.push_back(sig);
            }

            FunctionRegistry::registerFunctionSignature(functionName, signature);
        } else if (!line.starts_with("    ")) {
            if (!functionName.empty()) {
                FunctionRegistry::registerFunctionLogic(functionName, functionLogic);
                functionName = "";
            }
            result.push_back(line);
        } else {
            functionLogic.push_back(line);
        }
    }
    if (!functionName.empty()) {
        FunctionRegistry::registerFunctionLogic(functionName, functionLogic);
        functionName = "";
    }
    return result;
}

std::vector<std::string> Preprocessor::preprocess(std::ifstream& input) {
    std::string str((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());
    return preprocess(str);
}
