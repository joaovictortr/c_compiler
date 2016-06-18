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
    ParserTableKey searchTok = ParserTableKey(state.tblIndex(), symbol);
    auto result = table_.find(searchTok);
    if (result == table_.end()) {  // element not found, return error
        return errorState();
    }
    return result->second;
}

ParserState ParserTable::makeState(ParserState::state_type_t type, int tblIdx, string prodHead, int prodSiz)
{
    ParserStatePtr stPtr = make_shared< ParserState >( type, tblIdx, prodHead, prodSiz );
    return *stPtr;
}

void ParserTable::initTable()
{
    string emptyStr("");

    int idxCounter = 0;
    // shift states
    startSt_ = make_shared< ParserState >(ParserState::SHIFT, idxCounter++); // equivalent to e0
    ParserState e1 = makeState(ParserState::SHIFT, idxCounter++);
    ParserState e2 = makeState(ParserState::SHIFT, idxCounter++);
    ParserState e3 = makeState(ParserState::SHIFT, idxCounter++);
    ParserState e4 = makeState(ParserState::SHIFT, idxCounter++);
    ParserState e5 = makeState(ParserState::SHIFT, idxCounter++);
    ParserState e6 = makeState(ParserState::SHIFT, idxCounter++);
    ParserState e7 = makeState(ParserState::SHIFT, idxCounter++);
    ParserState e8 = makeState(ParserState::SHIFT, idxCounter++);
    // reduction states
    ParserState r1 = makeState(ParserState::REDUCE, idxCounter++, "E", 3);
    ParserState r2 = makeState(ParserState::REDUCE, idxCounter++, "E", 1);
    ParserState r3 = makeState(ParserState::REDUCE, idxCounter++, "L", 2);
    ParserState r4 = makeState(ParserState::REDUCE, idxCounter++, "L", 1);

    // special states for error and accept
    errSt_ = make_shared< ParserState >(ParserState::ERROR, idxCounter++);
    accSt_ = make_shared< ParserState >(ParserState::ACCEPT, idxCounter++);

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
    map< pair<int, string>, ParserState> table_ = {
        { pair<int, string>(startState().tblIndex(), "E"), e1 },
        { pair<int, string>(startState().tblIndex(), "("), e2 },
        { pair<int, string>(startState().tblIndex(), "a"), e3 },
        { pair<int, string>(e1.tblIndex(), "$"), acceptState() },
        { pair<int, string>(e2.tblIndex(), "E"), e4 },
        { pair<int, string>(e2.tblIndex(), "L"), e6 },
        { pair<int, string>(e2.tblIndex(), "("), e2 },
        { pair<int, string>(e2.tblIndex(), "a"), e3 },
        { pair<int, string>(e3.tblIndex(), "("), r2 },
        { pair<int, string>(e3.tblIndex(), ")"), r2 },
        { pair<int, string>(e3.tblIndex(), "a"), r2 },
        { pair<int, string>(e3.tblIndex(), "$"), r2 },
        { pair<int, string>(e4.tblIndex(), "E"), e4 },
        { pair<int, string>(e4.tblIndex(), "L"), e5 },
        { pair<int, string>(e4.tblIndex(), "("), e2 },
        { pair<int, string>(e4.tblIndex(), ")"), r4 },
        { pair<int, string>(e4.tblIndex(), "a"), e3 },
        { pair<int, string>(e5.tblIndex(), ")"), r3 },
        { pair<int, string>(e6.tblIndex(), ")"), e7 },
        { pair<int, string>(e7.tblIndex(), "("), r1 },
        { pair<int, string>(e7.tblIndex(), ")"), r1 },
        { pair<int, string>(e7.tblIndex(), "a"), r1 },
        { pair<int, string>(e7.tblIndex(), "$"), r1 }
    };
}
