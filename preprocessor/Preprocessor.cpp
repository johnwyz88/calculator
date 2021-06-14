//
// Created by Wang, John on 2021-06-13.
//

#include <sstream>
#include <fstream>
#include "Preprocessor.h"

std::vector<std::string> Preprocessor::preprocess(const std::string &input) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string buf;
    while(std::getline(ss,buf,'\n')){
        result.push_back(buf);
    }
    return result;
}

std::vector<std::string> Preprocessor::preprocess(std::ifstream& input) {
    std::vector<std::string> result;
    std::string buf;
    while(std::getline(input, buf)){
        result.push_back(buf);
    }
    return result;
}
