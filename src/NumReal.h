#pragma once

#include <string>
#include "Tag.h"
#include "Token.h"

using namespace std;

class NumReal : public Token {
public:
    typedef Token super;

    NumReal(float value) : value_(value) { super::setTag(Tag::NUM_REAL); }
    string getStr() const { return std::to_string(value_); }
    NumReal& operator=(const NumReal& other) {
        tag_ = other.getTag();
        value_ = other.value_;
        return *this;
    }
protected:
    int value_;
};
