#pragma once

#include <string>
#include "Tag.h"
#include "Token.h"

using namespace std;

class NumInt : public Token {
public:
    typedef Token super;

    NumInt(int value) : value_(value) { super::setTag(Tag::NUM); }
    string getStr() const { return std::to_string(value_); }
    NumInt& operator=(const NumInt& other) {
        tag_ = other.getTag();
        value_ = other.value_;
        return *this;
    }
protected:
    int value_;
};
