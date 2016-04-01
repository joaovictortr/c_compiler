#include <string>
#include "Token.h"

using namespace std;


Token::Token(int tag) : tag_(tag)
{
}

int Token::getTag() const
{
    return tag_;
}

void Token::setTag(int tag)
{
    tag_ = tag;
}

Token& Token::operator=(const Token& other)
{
    setTag(other.getTag());
    return *this;
}
