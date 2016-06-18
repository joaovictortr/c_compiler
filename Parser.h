#pragma once

#include <iostream>
#include <stack>
#include <tuple>
#include "src/Token.h"
#include "ParserState.h"
#include "ParserTable.h"

using namespace std;

class Parser {
public:
    // TODO: add output stream to constructor
    Parser();
    ~Parser() = default;

    bool parse(Token &tok);
private:
    stack< ParserState > stateStack_;
    stack< pair<Token, string> > tokenStack_;
    ParserTable table_;
};
