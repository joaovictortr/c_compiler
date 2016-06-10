#pragma once

#include <iostream>
#include <functional>
#include <unordered_map>
#include <utility>
#include <string>
#include "src/Token.h"
#include "ParserState.h"

using namespace std;

typedef pair<ParserState, string> ParserTableElement;

struct ElementHash {
    std::size_t operator()(const ParserTableElement& elem) const
    {
        auto state = elem.first;
        int state_type = static_cast<int>(state.type());
        string state_type_str = to_string(state_type);

        auto symbol = elem.second;
        return std::hash<std::string>()(state_type_str) ^
            (std::hash<std::string>()(symbol) << 1);
    }
};

struct ElementEqual {
    bool operator()(const ParserTableElement& lhs, const ParserTableElement& rhs) const
    {
        auto lhs_state = lhs.first;
        auto rhs_state = rhs.first;

        auto lhs_symbol = lhs.second;
        auto rhs_symbol = rhs.second;

        return static_cast<int>(lhs_state.type()) == static_cast<int>(rhs_state.type()) &&
            lhs_symbol == rhs_symbol;
    }
};

class ParserTable {
public:
    ParserTable() = default;
    ~ParserTable() = default;

    ParserState action(ParserState& state, Token& tok)
    {
        string tok_type = tok.strType();
        return lookup(state, ref(tok_type));
    }
    ParserState goToState(ParserState& state, string& head) { return lookup(state, head); }

private:
    unordered_map< pair<ParserState, string>, ElementEqual, ElementHash, ParserState > table_;
    ParserState lookup(ParserState& state, string& symbol);
};
