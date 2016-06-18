#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include "src/Token.h"
#include "ParserState.h"

using namespace std;

int main(int argc, char **argv)
{
    string emptyStr("");
    string str0("E");

    // special states for error and accept
    ParserState errSt = ParserState(ParserState::ERROR, emptyStr, 0);
    ParserState accSt = ParserState(ParserState::ACCEPT, emptyStr, 0);
    // shift states
    ParserState e0 = ParserState(ParserState::SHIFT, emptyStr, 0);
    ParserState e1 = ParserState(ParserState::SHIFT, str0, 0);
    ParserState e2 = ParserState(ParserState::SHIFT, emptyStr, 0);
    ParserState e3 = ParserState(ParserState::SHIFT, emptyStr, 0);
    ParserState e4 = ParserState(ParserState::SHIFT, emptyStr, 0);
    ParserState e5 = ParserState(ParserState::SHIFT, emptyStr, 0);
    ParserState e6 = ParserState(ParserState::SHIFT, emptyStr, 0);
    ParserState e7 = ParserState(ParserState::SHIFT, emptyStr, 0);
    ParserState e8 = ParserState(ParserState::SHIFT, emptyStr, 0);
    // reduction states
    ParserState r1 = ParserState(ParserState::REDUCE, emptyStr, 0);
    ParserState r2 = ParserState(ParserState::REDUCE, emptyStr, 0);
    ParserState r3 = ParserState(ParserState::REDUCE, emptyStr, 0);
    ParserState r4 = ParserState(ParserState::REDUCE, emptyStr, 0);

    auto search_key = make_pair<>(e0, str0);
    map< decltype(search_key), ParserState> table_ = {
        { search_key, e1 }
    };

    auto search = table_.find(search_key);
    if (search == table_.end())
    {
        cout << "Element not found in the table!" << endl;
        return 1;
    }

    ParserState s = search->second;
    cout << "production head = \"" << s.prodHead() << "\"" << endl;

    return 0;
}
