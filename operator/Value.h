//
// Created by Wang, John on 2021-06-12.
//

#ifndef VALUE_H
#define VALUE_H

#include <string>

struct Value {
    enum{DOUBLE, STRING} type;
    union {
        double doubleVal;
        std::string stringVal;
    };

    Value(const Value& other) {
        if (other.type == DOUBLE) {
            doubleVal = other.doubleVal;
        } else {
            stringVal = other.stringVal;
        }
        type = other.type;
    }
    Value(double val) : type(DOUBLE), doubleVal(val) {
    }
    Value(const std::string& val) : type(STRING), stringVal(val) {
    }

    ~Value() {
        if (type == STRING) {
            stringVal.~basic_string();
        }
    }
};


#endif //VALUE_H
