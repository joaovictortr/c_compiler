#pragma once

#include <string>

using namespace std;

class ParserState {
public:
    enum state_type_t { SHIFT, REDUCE, ACCEPT, ERROR };

    ParserState(state_type_t type, string& prodHead, int prodSiz) : type_(type), prodHead_(prodHead), prodSiz_(prodSiz) {}

    int prodSiz() const { return prodSiz_; }

    string prodHead() const { return prodHead_; }

    state_type_t type() { return type_; }

    bool isShift() { return type_ == SHIFT; }

    bool isReduction() { return type_ == REDUCE; }

    bool isAccept() { return type_ == ACCEPT; }

    bool isError() { return type_ == ERROR; }

    friend bool operator<(const ParserState &lhs, const ParserState &rhs);
private:
    state_type_t type_;
    string prodHead_;
    int prodSiz_;
};

bool operator<(const ParserState &lhs, const ParserState &rhs) { return lhs.prodHead() < rhs.prodHead() && lhs.prodSiz() < rhs.prodSiz(); }
