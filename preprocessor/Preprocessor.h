//
// Created by Wang, John on 2021-06-13.
//

#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <vector>
#include <string>

class Preprocessor {
public:
    std::vector<std::string> preprocess(const std::string& input);
    std::vector<std::string> preprocess(std::ifstream& input);
};


#endif //PREPROCESSOR_H
