//
// Created by Wang, John on 2021-06-12.
//

#ifndef VALUE_H
#define VALUE_H

#include <string>

union Value {
    enum{DOUBLE, STRING} type;
    double doubleVal;
    std::string stringVal;

    Value(const Value& other) {
        if (other.type == DOUBLE) {
            doubleVal = other.doubleVal;
        } else {
            stringVal = other.stringVal;
        }
        type = other.type;
    }
    Value(Value&& other) {
        if (other.type == DOUBLE) {
            doubleVal = other.doubleVal;
        } else {
            stringVal = std::move(other.stringVal);
        }
        type = other.type;
    }
    Value(double val) : type(DOUBLE) {
        doubleVal = val;
    }
    Value(std::string val) : type(STRING) {
        stringVal = std::move(val);
    }

    ~Value() {
        if (type == STRING) {
            stringVal.~basic_string();
        }
    }
};


#endif //VALUE_H
