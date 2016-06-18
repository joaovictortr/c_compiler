#pragma once

#include <string>

using namespace std;

class ParserState {
public:
    enum state_type_t { SHIFT = 0, REDUCE = 1, ACCEPT = 2, ERROR = 3 };

    ParserState(state_type_t type, int tblIdx, string prodHead = string(), int prodSiz = 0) : type_(type), tblIdx_(tblIdx), prodHead_(prodHead), prodSiz_(prodSiz) {}

    int prodSiz() const { return prodSiz_; }

    string prodHead() const { return prodHead_; }

    state_type_t type() { return type_; }

    bool isShift() { return type_ == SHIFT; }

    bool isReduction() { return type_ == REDUCE; }

    bool isAccept() { return type_ == ACCEPT; }

    bool isError() { return type_ == ERROR; }

    int tblIndex() const { return tblIdx_; }
private:
    state_type_t type_;
    int tblIdx_;
    string prodHead_;
    int prodSiz_;
};
