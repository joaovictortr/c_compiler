#include "ParserTable.h"

using namespace std;

ParserTable::ParserTable() : startSt_(nullptr), errSt_(nullptr), accSt_(nullptr)
{
    // initialize SLR(1) parsing table
    initTable();
}

ParserState ParserTable::action(ParserState& state, Token& tok)
{
    string tok_type = tok.strType();
    return lookup(state, ref(tok_type));
}

ParserState ParserTable::goToState(ParserState& state, string& head)
{
    return lookup(state, head);
}

ParserState ParserTable::lookup(ParserState &state, string &symbol)
{
    ParserTableKey searchTok(state.tblIndex(), symbol);
    auto result = table_.find(searchTok);
    if (result == table_.end()) {  // element not found, return error
        printTable();
        return errorState();
    }
    return result->second;
}

ParserState ParserTable::makeState(ParserState::state_type_t type, string name, string prodHead, int prodSiz)
{
    ParserStatePtr stPtr = make_shared< ParserState >( type, name, prodHead, prodSiz );
    return *stPtr;
}

void ParserTable::initTable()
{
    // shift states
    startSt_ = make_shared< ParserState >(ParserState::SHIFT, "e0"); // equivalent to e0
    ParserState e1 = makeState(ParserState::SHIFT, "e1");
    ParserState e2 = makeState(ParserState::SHIFT, "e2");
    ParserState e3 = makeState(ParserState::SHIFT, "e3");
    ParserState e4 = makeState(ParserState::SHIFT, "e4");
    ParserState e5 = makeState(ParserState::SHIFT, "e5");
    ParserState e6 = makeState(ParserState::SHIFT, "e6");
    ParserState e7 = makeState(ParserState::SHIFT, "e7");
    // reduction states
    ParserState r1 = makeState(ParserState::REDUCE, "r1", "E", 3);
    ParserState r2 = makeState(ParserState::REDUCE, "r2", "E", 1);
    ParserState r3 = makeState(ParserState::REDUCE, "r3", "L", 2);
    ParserState r4 = makeState(ParserState::REDUCE, "r4", "L", 1);

    // special states for error and accept
    errSt_ = make_shared< ParserState >(ParserState::ERROR, "error");
    accSt_ = make_shared< ParserState >(ParserState::ACCEPT, "accept");

    /**
     * Example table:
     *
     *   +----------------------------------------+
     *   |    |  E  |  L  |  (  |  )  |  a  |  $  |
     *   +----------------------------------------+
     *   | e0 | e1  |     | e2  |     |  e3 |     |
     *   | e1 |     |     |     |     |     |  ac |
     *   | e2 | e4  | e6  | e2  |     |  e3 |     |
     *   | e3 |     |     | r2  | r2  |  r2 |  r2 |
     *   | e4 | e4  | e5  | e2  | r4  |  e3 |     |
     *   | e5 |     |     |     | r3  |     |     |
     *   | e6 |     |     |     | e7  |     |     |
     *   | e7 |     |     | r1  | r1  |  r1 |  r1 |
     *   +----------------------------------------+
     */
    table_ = {
        { ParserTableKey(startState().tblIndex(), "E"), e1 },
        { ParserTableKey(startState().tblIndex(), "("), e2 },
        { ParserTableKey(startState().tblIndex(), "a"), e3 },
        { ParserTableKey(e1.tblIndex(), "$"), acceptState() },
        { ParserTableKey(e2.tblIndex(), "E"), e4 },
        { ParserTableKey(e2.tblIndex(), "L"), e6 },
        { ParserTableKey(e2.tblIndex(), "("), e2 },
        { ParserTableKey(e2.tblIndex(), "a"), e3 },
        { ParserTableKey(e3.tblIndex(), "("), r2 },
        { ParserTableKey(e3.tblIndex(), ")"), r2 },
        { ParserTableKey(e3.tblIndex(), "a"), r2 },
        { ParserTableKey(e3.tblIndex(), "$"), r2 },
        { ParserTableKey(e4.tblIndex(), "E"), e4 },
        { ParserTableKey(e4.tblIndex(), "L"), e5 },
        { ParserTableKey(e4.tblIndex(), "("), e2 },
        { ParserTableKey(e4.tblIndex(), ")"), r4 },
        { ParserTableKey(e4.tblIndex(), "a"), e3 },
        { ParserTableKey(e5.tblIndex(), ")"), r3 },
        { ParserTableKey(e6.tblIndex(), ")"), e7 },
        { ParserTableKey(e7.tblIndex(), "("), r1 },
        { ParserTableKey(e7.tblIndex(), ")"), r1 },
        { ParserTableKey(e7.tblIndex(), "a"), r1 },
        { ParserTableKey(e7.tblIndex(), "$"), r1 }
    };
}

void ParserTable::printTable()
{
    cout << " -- BEGIN TABLE --" << endl;
    for(auto it = table_.begin(); it != table_.end(); ++it) {
        ParserTableKey key = it->first;
        ParserState value = it->second;
        cout << "(e" << (key.first-1) << ", \"" << key.second << "\") -> " << value.name() << endl;
    }
    cout << "-- END TABLE --" << endl << endl;
}
