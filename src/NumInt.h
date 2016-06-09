#pragma once

#include <string>
#include "TokenType.h"
#include "Token.h"

using namespace std;

class NumInt : public Token {
public:
    NumInt(int value) : value_(value) { setType(TokenType::NUM); }

    // get token value
    string getValue() const { return std::to_string(value_); }

    NumInt& operator=(const NumInt& other) {
        type_ = other.getType();
        value_ = other.value_;
        return *this;
    }

protected:
    int value_;
};
