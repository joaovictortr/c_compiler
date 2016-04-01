#pragma once

#include <string>
#include "Tag.h"
#include "Token.h"

using namespace std;

class Num : public Token {
public:
    Num(int value) : value_(value) { setTag(Tag::NUM); }
    int getValue() const { return value_; }
    Num& operator=(const Num& other) {
        tag_ = other.getTag();
        value_ = other.getValue();
        return *this;
    }
private:
    int value_;
};
