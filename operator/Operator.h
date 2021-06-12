//
// Created by Wang, John on 2021-06-12.
//

#ifndef OPERATOR_H
#define OPERATOR_H

class Operator {
public:
    Operator() = default;
    virtual double evaluate() const {};
    virtual int getPrecedence() const {};
};


#endif //OPERATOR_H
