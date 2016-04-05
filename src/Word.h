#pragma once

#include <string>
#include "Token.h"

using namespace std;

class Word : public Token {
public:
    typedef Token super;

    Word() = default;
    Word(int type, string word) : type_(type), lexeme_(word) { super::setTag(type); }
    Word& operator=(const Word& other) {
        tag_ = other.getTag();
        lexeme_ = other.getLexeme();
        return *this;
    }
    string & getLexeme() { return lexeme_; }
    const string & getLexeme() const { return lexeme_; }
private:
    int type_;
    string lexeme_;
};
