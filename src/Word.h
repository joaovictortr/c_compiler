#pragma once

#include <string>
#include "Token.h"

using namespace std;

class Word : public Token {
public:
    Word() = default;
    Word(int type, string word) : type_(type), lexeme_(word) { setType(type); }
    Word& operator=(const Word& other) {
        type_ = other.getType();
        lexeme_ = other.getLexeme();
        return *this;
    }
    string & getLexeme() { return lexeme_; }
    const string & getLexeme() const { return lexeme_; }
private:
    int type_;
    string lexeme_;
};
