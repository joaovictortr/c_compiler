#include <iostream>
#include <map>
#include <utility>
#include "src/Token.h"
#include "ParserState.h"
#include "ParserTable.h"

using namespace std;

ParserState ParserTable::lookup(ParserState& state, string& symbol)
{
    auto searchTok = make_pair<ParserState, string>(state, symbol);
    auto result = table_.find(searchTok);
    if (result == table_.end()) {
        cerr << "[" << __FUNCTION__ << ":" << __LINE__
            << "] Element not found in the parser table!" << endl;
        exit(1);
    }
    return result->second;
}
