#pragma once

#include <string>
#include "Token.h"

using namespace std;

class Word : public Token {
public:
    Word() = default;
    Word(int type, string & word) : type_(type), lexeme_(word) { setTag(type); }
    string& getLexeme() { return lexeme_; }
    const string& getLexeme() const { return lexeme_; }
    Word& operator=(const Word& other) {
        tag_ = other.getTag();
        lexeme_ = other.getLexeme();
        return *this;
    }
private:
    int type_;
    string lexeme_;
};
