//
// Created by Wang, John on 2021-06-13.
//

#include <sstream>
#include <istream>
#include <iostream>
#include "Preprocessor.h"

std::vector<std::string> Preprocessor::preprocess(const std::string &input) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    for (std::string line; std::getline(ss, line, '\n');) {
        std::cout << line << std::endl;
        result.push_back(line);
    }
    return result;
}
