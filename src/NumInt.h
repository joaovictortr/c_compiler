#pragma once

#include <string>
#include "Tag.h"
#include "Token.h"

using namespace std;

class NumInt : public Token {
public:
    NumInt(int value) : value_(value) { setTag(Tag::NUM_INT); }
    int getValue() const { return value_; }
    NumInt& operator=(const NumInt& other) {
        tag_ = other.getTag();
        value_ = other.getValue();
        return *this;
    }
private:
    int value_;
};
