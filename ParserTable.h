#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <memory>
#include <map>
#include "Token.h"
#include "ParserState.h"

using namespace std;

class ParserTable
{
public:
    typedef shared_ptr< ParserState > ParserStatePtr;
    typedef pair<int, string> ParserTableKey;

    ParserTable();
    ~ParserTable() = default;

    ParserState startState() const { return *startSt_; }
    ParserState errorState() const { return *errSt_; }
    ParserState acceptState() const { return *accSt_; }
    ParserState action(ParserState &state, Token &tok);
    ParserState goToState(ParserState &state, string &head);
private:
    ParserStatePtr startSt_;
    ParserStatePtr errSt_;
    ParserStatePtr accSt_;
    map< pair<int, string>, ParserState> table_;

    ParserState lookup(ParserState &state, string &tok);
    ParserState makeState(ParserState::state_type_t type, int tblIdx, string prodHead = string(), int prodSiz = 0);
    void initTable();
};
