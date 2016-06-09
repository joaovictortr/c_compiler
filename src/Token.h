#pragma once

#include <map>
#include "TokenType.h"

using namespace std;

class Token {
public:
    Token() = default;
    Token(int type) : type_(type) {}
    ~Token() = default;

    int getType() const { return type_; };
    string strType() const { return TokenType::type2Str(type_); }

    Token& operator=(const Token& other) {
        setType(other.getType());
        return *this;
    }

protected:
    int type_;
    void setType(int type) { type_ = type; }
};
