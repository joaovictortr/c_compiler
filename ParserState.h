#pragma once

#include <string>

using namespace std;

class ParserState {
public:
    enum state_type_t { SHIFT, REDUCE, ACCEPT, ERROR };

    int prodSiz() { return prodSiz_; }

    string& prodHead() { return prodHead_; }

    state_type_t type() { return type_; }

    bool isShift() { return type_ == SHIFT; }

    bool isReduction() { return type_ == REDUCE; }

    bool isAccept() { return type_ == ACCEPT; }

    bool isError() { return type_ == ERROR; }

private:
    state_type_t type_;
    int prodSiz_;
    string prodHead_;
};

