//
// Created by Wang, John on 2021-06-12.
//

#ifndef FUNCTION_REGISTRY_H
#define FUNCTION_REGISTRY_H

#include <string>
#include <unordered_map>
#include "../tokenizer/Tokenizer.h"
#include "../parser/Parser.h"
#include "../evaluator/Evaluator.h"

class FunctionRegistry {
public:
    static const std::vector<std::string>& getParameters(const std::string& f) {
        return functionSignature[f];
    }
    static bool isFunction(const std::string& f) {
        return functionSignature.find(f) != functionSignature.end();
    }
    static void registerFunctionSignature(const std::string& f, const std::vector<std::string>& signature) {
        functionSignature[f] = signature;
    }
    static void registerFunctionLogic(const std::string& f, const std::vector<std::string>& logic) {
        functionLogic[f] = logic;
    }
    inline static double evaluate(const std::string& f, const std::vector<std::string>& args) {
        double result;
        const std::vector<std::string>& sig = functionSignature[f];
        if (sig.size() != args.size()) return 0;
        EvaluationContext context;
        for (int i = 0; i < args.size(); i++) {
            context.registerVariable(sig[i], stod(args[i]));
        }
        const std::vector<std::string>& lines = functionLogic[f];
        for (const std::string& line : lines) {
            std::vector<Token> tokens = tokenizer.tokenize(line);
            std::unique_ptr<Operator> root = parser.parse(tokens);
            result = evaluator.evaluate(*root, &context);
        }
        return result;
    }
private:
    inline static std::unordered_map<std::string, std::vector<std::string>> functionSignature;
    inline static std::unordered_map<std::string, std::vector<std::string>> functionLogic;
    inline static Tokenizer tokenizer;
    inline static Parser parser;
    inline static Evaluator evaluator;
};

#endif //FUNCTION_REGISTRY_H
