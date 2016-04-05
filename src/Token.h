#pragma once

#include <map>
#include "Tag.h"

using namespace std;

class Token {
public:
    Token() = default;
    ~Token() = default;
    virtual string getStr() const { return Tag::tag2Str(tag_); }
    Token(int tag);
    int getTag() const;
    void setTag(int tag);
    Token& operator=(const Token& other);

protected:
    int tag_;
};
