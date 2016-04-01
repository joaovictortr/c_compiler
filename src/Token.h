#pragma once

#include <map>

using namespace std;

class Token {
public:
    Token() = default;
    Token(int tag);
    int getTag() const;
    void setTag(int tag);
    virtual Token& operator=(const Token& other);
    string & getLexeme() { return lexeme_; }
    void setLexeme(string & lexeme) { lexeme_ = lexeme; }

    ~Token() = default;
protected:
    int tag_;
    string lexeme_;
};
