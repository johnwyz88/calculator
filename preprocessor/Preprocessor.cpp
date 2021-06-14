//
// Created by Wang, John on 2021-06-13.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include "Preprocessor.h"

std::vector<std::string> Preprocessor::preprocess(const std::string &input) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    for (std::string line; std::getline(ss, line);) {
        std::cout << line << std::endl;
        result.push_back(line);
    }
    return result;
}

std::vector<std::string> Preprocessor::preprocess(std::ifstream& input) {
    std::vector<std::string> result;
    for (std::string line; std::getline(input, line);) {
        std::cout << line << std::endl;
        result.push_back(line);
    }
    return result;
}
