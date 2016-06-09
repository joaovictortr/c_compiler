#pragma once

#include <string>
#include "TokenType.h"
#include "Token.h"

using namespace std;

class NumReal : public Token {
public:
    NumReal(float value) : value_(value) { setType(TokenType::NUM); }
    string getStr() const { return std::to_string(value_); }
    NumReal& operator=(const NumReal& other) {
        type_ = other.getType();
        value_ = other.value_;
        return *this;
    }
protected:
    int value_;
};
