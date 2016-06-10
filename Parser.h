#pragma once

#include <iostream>
#include <stack>
#include "src/Token.h"
#include "ParserState.h"
#include "ParserTable.h"

using namespace std;

class Parser {
public:
    Parser() = default;
    ~Parser() = default;

    bool parse(Token& tok);
private:
    stack<ParserState> stackSLR_;
    ParserTable table_;
};
