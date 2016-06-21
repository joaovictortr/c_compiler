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
	startSt_ = make_shared< ParserState >(ParserState::SHIFT, "e0");
	ParserState e1 = makeState(ParserState::SHIFT, "e1");
	ParserState e2 = makeState(ParserState::SHIFT, "e2");
	ParserState e3 = makeState(ParserState::SHIFT, "e3");
	ParserState e4 = makeState(ParserState::SHIFT, "e4");
	ParserState e5 = makeState(ParserState::SHIFT, "e5");
	ParserState e6 = makeState(ParserState::SHIFT, "e6");
	ParserState e7 = makeState(ParserState::SHIFT, "e7");
	ParserState e8 = makeState(ParserState::SHIFT, "e8");
	ParserState e9 = makeState(ParserState::SHIFT, "e9");
	ParserState e10 = makeState(ParserState::SHIFT, "e10");
	ParserState e11 = makeState(ParserState::SHIFT, "e11");
	ParserState e12 = makeState(ParserState::SHIFT, "e12");
	ParserState e13 = makeState(ParserState::SHIFT, "e13");
	ParserState e14 = makeState(ParserState::SHIFT, "e14");
	ParserState e15 = makeState(ParserState::SHIFT, "e15");
	ParserState e16 = makeState(ParserState::SHIFT, "e16");
	ParserState e17 = makeState(ParserState::SHIFT, "e17");
	ParserState e18 = makeState(ParserState::SHIFT, "e18");
	ParserState e19 = makeState(ParserState::SHIFT, "e19");
	ParserState e20 = makeState(ParserState::SHIFT, "e20");
	ParserState e21 = makeState(ParserState::SHIFT, "e21");
	ParserState e22 = makeState(ParserState::SHIFT, "e22");
	ParserState e23 = makeState(ParserState::SHIFT, "e23");
	ParserState e24 = makeState(ParserState::SHIFT, "e24");
	ParserState e25 = makeState(ParserState::SHIFT, "e25");
	ParserState e26 = makeState(ParserState::SHIFT, "e26");
	ParserState e27 = makeState(ParserState::SHIFT, "e27");
	ParserState e28 = makeState(ParserState::SHIFT, "e28");
	ParserState e29 = makeState(ParserState::SHIFT, "e29");
	ParserState e30 = makeState(ParserState::SHIFT, "e30");
	ParserState e31 = makeState(ParserState::SHIFT, "e31");
	ParserState e32 = makeState(ParserState::SHIFT, "e32");
	ParserState e33 = makeState(ParserState::SHIFT, "e33");
	ParserState e34 = makeState(ParserState::SHIFT, "e34");
	ParserState e35 = makeState(ParserState::SHIFT, "e35");
	ParserState e36 = makeState(ParserState::SHIFT, "e36");
	ParserState e37 = makeState(ParserState::SHIFT, "e37");
	ParserState e38 = makeState(ParserState::SHIFT, "e38");
	ParserState e39 = makeState(ParserState::SHIFT, "e39");
	ParserState e40 = makeState(ParserState::SHIFT, "e40");
	ParserState e41 = makeState(ParserState::SHIFT, "e41");
	ParserState e42 = makeState(ParserState::SHIFT, "e42");
	ParserState e43 = makeState(ParserState::SHIFT, "e43");
	ParserState e44 = makeState(ParserState::SHIFT, "e44");
	ParserState e46 = makeState(ParserState::SHIFT, "e46");
	ParserState e47 = makeState(ParserState::SHIFT, "e47");
	ParserState e48 = makeState(ParserState::SHIFT, "e48");
	ParserState e49 = makeState(ParserState::SHIFT, "e49");
	ParserState e50 = makeState(ParserState::SHIFT, "e50");
	ParserState e51 = makeState(ParserState::SHIFT, "e51");
	ParserState e52 = makeState(ParserState::SHIFT, "e52");
	ParserState e53 = makeState(ParserState::SHIFT, "e53");
	ParserState e54 = makeState(ParserState::SHIFT, "e54");
	ParserState e55 = makeState(ParserState::SHIFT, "e55");
	ParserState e56 = makeState(ParserState::SHIFT, "e56");
	ParserState e57 = makeState(ParserState::SHIFT, "e57");
	ParserState e58 = makeState(ParserState::SHIFT, "e58");
	ParserState e61 = makeState(ParserState::SHIFT, "e61");
	ParserState e62 = makeState(ParserState::SHIFT, "e62");
	ParserState e63 = makeState(ParserState::SHIFT, "e63");
	ParserState e64 = makeState(ParserState::SHIFT, "e64");
	ParserState e65 = makeState(ParserState::SHIFT, "e65");
	ParserState e66 = makeState(ParserState::SHIFT, "e66");
	ParserState e67 = makeState(ParserState::SHIFT, "e67");
	ParserState e68 = makeState(ParserState::SHIFT, "e68");
	ParserState e69 = makeState(ParserState::SHIFT, "e69");
	ParserState e70 = makeState(ParserState::SHIFT, "e70");
	ParserState e71 = makeState(ParserState::SHIFT, "e71");
	ParserState e72 = makeState(ParserState::SHIFT, "e72");
	ParserState e73 = makeState(ParserState::SHIFT, "e73");
	ParserState e74 = makeState(ParserState::SHIFT, "e74");
	ParserState e75 = makeState(ParserState::SHIFT, "e75");
	ParserState e76 = makeState(ParserState::SHIFT, "e76");
	ParserState e77 = makeState(ParserState::SHIFT, "e77");
	ParserState e78 = makeState(ParserState::SHIFT, "e78");
	ParserState e79 = makeState(ParserState::SHIFT, "e79");
	ParserState e80 = makeState(ParserState::SHIFT, "e80");
	ParserState e81 = makeState(ParserState::SHIFT, "e81");
	ParserState e82 = makeState(ParserState::SHIFT, "e82");
	ParserState e83 = makeState(ParserState::SHIFT, "e83");
	ParserState e84 = makeState(ParserState::SHIFT, "e84");
	ParserState e85 = makeState(ParserState::SHIFT, "e85");
	ParserState e86 = makeState(ParserState::SHIFT, "e86");
	ParserState e87 = makeState(ParserState::SHIFT, "e87");
	ParserState e88 = makeState(ParserState::SHIFT, "e88");
	ParserState e89 = makeState(ParserState::SHIFT, "e89");
	ParserState e90 = makeState(ParserState::SHIFT, "e90");
	ParserState e91 = makeState(ParserState::SHIFT, "e91");
	ParserState e92 = makeState(ParserState::SHIFT, "e92");
	ParserState e93 = makeState(ParserState::SHIFT, "e93");
	ParserState e94 = makeState(ParserState::SHIFT, "e94");
	ParserState e95 = makeState(ParserState::SHIFT, "e95");
	ParserState e96 = makeState(ParserState::SHIFT, "e96");
	ParserState e97 = makeState(ParserState::SHIFT, "e97");
	ParserState e98 = makeState(ParserState::SHIFT, "e98");
	ParserState e99 = makeState(ParserState::SHIFT, "e99");
	ParserState e100 = makeState(ParserState::SHIFT, "e100");
	ParserState e101 = makeState(ParserState::SHIFT, "e101");
	ParserState e102 = makeState(ParserState::SHIFT, "e102");
	ParserState e103 = makeState(ParserState::SHIFT, "e103");
	ParserState e104 = makeState(ParserState::SHIFT, "e104");
	ParserState e105 = makeState(ParserState::SHIFT, "e105");
	ParserState e106 = makeState(ParserState::SHIFT, "e106");
	ParserState e107 = makeState(ParserState::SHIFT, "e107");
	ParserState e108 = makeState(ParserState::SHIFT, "e108");
	ParserState e109 = makeState(ParserState::SHIFT, "e109");
	ParserState e110 = makeState(ParserState::SHIFT, "e110");
	ParserState e111 = makeState(ParserState::SHIFT, "e111");
	ParserState e112 = makeState(ParserState::SHIFT, "e112");
	ParserState e113 = makeState(ParserState::SHIFT, "e113");
	/* Reductions */


	ParserState r1 = makeState(ParserState::REDUCE, "r1", "PROG", 4);
	ParserState r2 = makeState(ParserState::REDUCE, "r2", "DECL_VAR", 4);
	ParserState r3 = makeState(ParserState::REDUCE, "r3", "DECL_VAR", 0);
	ParserState r4 = makeState(ParserState::REDUCE, "r4", "CONST", 6);
	ParserState r5 = makeState(ParserState::REDUCE, "r5", "CONST", 0);
	ParserState r6 = makeState(ParserState::REDUCE, "r6", "FUNCOES", 2);
	ParserState r7 = makeState(ParserState::REDUCE, "r7", "FUNCOES", 0);
	ParserState r8 = makeState(ParserState::REDUCE, "r8", "FUNCAO", 12);
	ParserState r9 = makeState(ParserState::REDUCE, "r9", "MAIN", 5);
	ParserState r10 = makeState(ParserState::REDUCE, "r10", "CMDS", 2);
	ParserState r11 = makeState(ParserState::REDUCE, "r11", "CMDS", 0);
	ParserState r12 = makeState(ParserState::REDUCE, "r12", "CMD", 1);
	ParserState r13 = makeState(ParserState::REDUCE, "r13", "CMD", 1);
	ParserState r14 = makeState(ParserState::REDUCE, "r14", "CMD", 1);
	ParserState r15 = makeState(ParserState::REDUCE, "r15", "CMD", 1);
	ParserState r16 = makeState(ParserState::REDUCE, "r16", "CMD", 2);
	ParserState r17 = makeState(ParserState::REDUCE, "r17", "CMD", 1);
	ParserState r18 = makeState(ParserState::REDUCE, "r18", "IF", 7);
	ParserState r19 = makeState(ParserState::REDUCE, "r19", "IF", 11);
	ParserState r20 = makeState(ParserState::REDUCE, "r20", "WHILE", 7);
	ParserState r21 = makeState(ParserState::REDUCE, "r21", "FOR", 11);
	ParserState r22 = makeState(ParserState::REDUCE, "r22", "ATR", 4);
	ParserState r23 = makeState(ParserState::REDUCE, "r23", "ATR", 4);
	ParserState r24 = makeState(ParserState::REDUCE, "r24", "ATR", 4);
	ParserState r25 = makeState(ParserState::REDUCE, "r25", "ATR", 3);
	ParserState r26 = makeState(ParserState::REDUCE, "r26", "ATR", 4);
	ParserState r27 = makeState(ParserState::REDUCE, "r27", "ATR_FOR", 3);
	ParserState r28 = makeState(ParserState::REDUCE, "r28", "CH_FUNC", 4);
	ParserState r29 = makeState(ParserState::REDUCE, "r29", "INCR", 2);
	ParserState r31 = makeState(ParserState::REDUCE, "r31", "EXPR_MAT", 3);
	ParserState r32 = makeState(ParserState::REDUCE, "r32", "EXPR_MAT", 3);
	ParserState r33 = makeState(ParserState::REDUCE, "r33", "EXPR_MAT", 3);
	ParserState r34 = makeState(ParserState::REDUCE, "r34", "EXPR_MAT", 3);
	ParserState r35 = makeState(ParserState::REDUCE, "r35", "TESTE", 1);
	ParserState r36 = makeState(ParserState::REDUCE, "r36", "TESTE", 3);
	ParserState r37 = makeState(ParserState::REDUCE, "r37", "EXPR_REL", 3);
	ParserState r38 = makeState(ParserState::REDUCE, "r38", "EXPR_REL", 3);
	ParserState r39 = makeState(ParserState::REDUCE, "r39", "EXPR_REL", 3);
	ParserState r40 = makeState(ParserState::REDUCE, "r40", "EXPR_REL", 3);
	ParserState r41 = makeState(ParserState::REDUCE, "r41", "NUM", 1);
	ParserState r42 = makeState(ParserState::REDUCE, "r42", "NUM", 1);


	// special states for error and accept
	errSt_ = make_shared< ParserState >(ParserState::ERROR, "error");
	accSt_ = make_shared< ParserState >(ParserState::ACCEPT, "accept");
	table_ = {
	{ ParserTableKey(startState().tblIndex(), "PROG"), e1},
	{ ParserTableKey(startState().tblIndex(), "DECL_VAR"), e2},
	{ ParserTableKey(startState().tblIndex(), "TIPO"), e3},
	{ ParserTableKey(startState().tblIndex(), "func"), r3},
	{ ParserTableKey(startState().tblIndex(), "main"), r3},
	{ ParserTableKey(startState().tblIndex(), "if"), r3},
	{ ParserTableKey(startState().tblIndex(), "while"), r3},
	{ ParserTableKey(startState().tblIndex(), "for"), r3},
	{ ParserTableKey(startState().tblIndex(), "id"), r3},
	{ ParserTableKey(startState().tblIndex(), "const"), r3},
	{ ParserTableKey(startState().tblIndex(), "}"), r3},
	{ ParserTableKey(startState().tblIndex(), "return"), r3},
	{ ParserTableKey(e1.tblIndex(), "$"), acceptState()},
	{ ParserTableKey(e2.tblIndex(), "CONST"), e4},
	{ ParserTableKey(e2.tblIndex(), "func"), r5},
	{ ParserTableKey(e2.tblIndex(), "main"), r5},
	{ ParserTableKey(e2.tblIndex(), "const"), e5},
	{ ParserTableKey(e3.tblIndex(), "id"), e6},
	{ ParserTableKey(e4.tblIndex(), "FUNCOES"), e7},
	{ ParserTableKey(e4.tblIndex(), "FUNCAO"), e8},
	{ ParserTableKey(e4.tblIndex(), "func"), e113},
	{ ParserTableKey(e4.tblIndex(), "main"), r7},
	{ ParserTableKey(e5.tblIndex(), "id"), e10},
	{ ParserTableKey(e6.tblIndex(), ";"), e11},
	{ ParserTableKey(e7.tblIndex(), "MAIN"), e12},
	{ ParserTableKey(e7.tblIndex(), "main"), e13},
	{ ParserTableKey(e8.tblIndex(), "FUNCOES"), e14},
	{ ParserTableKey(e8.tblIndex(), "FUNCAO"), e8},
	{ ParserTableKey(e8.tblIndex(), "func"), e113},
	{ ParserTableKey(e8.tblIndex(), "main"), r7},
	{ ParserTableKey(e9.tblIndex(), "id"), e15},
	{ ParserTableKey(e10.tblIndex(), "="), e16},
	{ ParserTableKey(e11.tblIndex(), "DECL_VAR"), e17},
	{ ParserTableKey(e11.tblIndex(), "TIPO"), e3},
	{ ParserTableKey(e11.tblIndex(), "func"), r3},
	{ ParserTableKey(e11.tblIndex(), "main"), r3},
	{ ParserTableKey(e11.tblIndex(), "if"), r3},
	{ ParserTableKey(e11.tblIndex(), "while"), r3},
	{ ParserTableKey(e11.tblIndex(), "for"), r3},
	{ ParserTableKey(e11.tblIndex(), "id"), r3},
	{ ParserTableKey(e11.tblIndex(), "const"), r3},
	{ ParserTableKey(e11.tblIndex(), "}"), r3},
	{ ParserTableKey(e11.tblIndex(), "return"), r3},
	{ ParserTableKey(e12.tblIndex(), "$"), r1},
	{ ParserTableKey(e13.tblIndex(), "{"), e18},
	{ ParserTableKey(e14.tblIndex(), "main"), r6},
	{ ParserTableKey(e15.tblIndex(), "("), e19},
	{ ParserTableKey(e16.tblIndex(), "NUM"), e20},
	{ ParserTableKey(e16.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e16.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e17.tblIndex(), "func"), r2},
	{ ParserTableKey(e17.tblIndex(), "main"), r2},
	{ ParserTableKey(e17.tblIndex(), "if"), r2},
	{ ParserTableKey(e17.tblIndex(), "while"), r2},
	{ ParserTableKey(e17.tblIndex(), "for"), r2},
	{ ParserTableKey(e17.tblIndex(), "id"), r2},
	{ ParserTableKey(e17.tblIndex(), "const"), r2},
	{ ParserTableKey(e18.tblIndex(), "DECL_VAR"), e21},
	{ ParserTableKey(e18.tblIndex(), "TIPO"), e3},
	{ ParserTableKey(e18.tblIndex(), "func"), r3},
	{ ParserTableKey(e18.tblIndex(), "main"), r3},
	{ ParserTableKey(e18.tblIndex(), "if"), r3},
	{ ParserTableKey(e18.tblIndex(), "while"), r3},
	{ ParserTableKey(e18.tblIndex(), "for"), r3},
	{ ParserTableKey(e18.tblIndex(), "id"), r3},
	{ ParserTableKey(e18.tblIndex(), "const"), r3},
	{ ParserTableKey(e18.tblIndex(), "}"), r3},
	{ ParserTableKey(e18.tblIndex(), "return"), r3},
	{ ParserTableKey(e19.tblIndex(), ")"), e22},
	{ ParserTableKey(e20.tblIndex(), ";"), e23},
	{ ParserTableKey(e21.tblIndex(), "CMDS"), e24},
	{ ParserTableKey(e21.tblIndex(), "CMD"), e25},
	{ ParserTableKey(e21.tblIndex(), "IF"), e26},
	{ ParserTableKey(e21.tblIndex(), "WHILE"), e27},
	{ ParserTableKey(e21.tblIndex(), "FOR"), e28},
	{ ParserTableKey(e21.tblIndex(), "ATR"), e29},
	{ ParserTableKey(e21.tblIndex(), "INCR"), e30},
	{ ParserTableKey(e21.tblIndex(), "CH_FUNC"), e31},
	{ ParserTableKey(e21.tblIndex(), "if"), e32},
	{ ParserTableKey(e21.tblIndex(), "while"), e33},
	{ ParserTableKey(e21.tblIndex(), "for"), e34},
	{ ParserTableKey(e21.tblIndex(), "id"), e35},
	{ ParserTableKey(e21.tblIndex(), "}"), r11},
	{ ParserTableKey(e21.tblIndex(), "return"), r11},
	{ ParserTableKey(e22.tblIndex(), "{"), e36},
	{ ParserTableKey(e23.tblIndex(), "CONST"), e37},
	{ ParserTableKey(e23.tblIndex(), "func"), r5},
	{ ParserTableKey(e23.tblIndex(), "main"), r5},
	{ ParserTableKey(e23.tblIndex(), "const"), e5},
	{ ParserTableKey(e24.tblIndex(), "}"), e38},
	{ ParserTableKey(e25.tblIndex(), "CMDS"), e39},
	{ ParserTableKey(e25.tblIndex(), "CMD"), e25},
	{ ParserTableKey(e25.tblIndex(), "IF"), e26},
	{ ParserTableKey(e25.tblIndex(), "WHILE"), e27},
	{ ParserTableKey(e25.tblIndex(), "FOR"), e28},
	{ ParserTableKey(e25.tblIndex(), "ATR"), e29},
	{ ParserTableKey(e25.tblIndex(), "INCR"), e30},
	{ ParserTableKey(e25.tblIndex(), "CH_FUNC"), e31},
	{ ParserTableKey(e25.tblIndex(), "if"), e32},
	{ ParserTableKey(e25.tblIndex(), "while"), e33},
	{ ParserTableKey(e25.tblIndex(), "for"), e34},
	{ ParserTableKey(e25.tblIndex(), "id"), e35},
	{ ParserTableKey(e25.tblIndex(), "}"), r11},
	{ ParserTableKey(e25.tblIndex(), "return"), r11},
	{ ParserTableKey(e26.tblIndex(), "if"), r12},
	{ ParserTableKey(e26.tblIndex(), "while"), r12},
	{ ParserTableKey(e26.tblIndex(), "for"), r12},
	{ ParserTableKey(e26.tblIndex(), "id"), r12},
	{ ParserTableKey(e26.tblIndex(), "}"), r12},
	{ ParserTableKey(e26.tblIndex(), "return"), r12},
	{ ParserTableKey(e27.tblIndex(), "if"), r13},
	{ ParserTableKey(e27.tblIndex(), "while"), r13},
	{ ParserTableKey(e27.tblIndex(), "for"), r13},
	{ ParserTableKey(e27.tblIndex(), "id"), r13},
	{ ParserTableKey(e27.tblIndex(), "}"), r13},
	{ ParserTableKey(e27.tblIndex(), "return"), r13},
	{ ParserTableKey(e28.tblIndex(), "if"), r14},
	{ ParserTableKey(e28.tblIndex(), "while"), r14},
	{ ParserTableKey(e28.tblIndex(), "for"), r14},
	{ ParserTableKey(e28.tblIndex(), "id"), r14},
	{ ParserTableKey(e28.tblIndex(), "}"), r14},
	{ ParserTableKey(e28.tblIndex(), "return"), r14},
	{ ParserTableKey(e29.tblIndex(), "if"), r15},
	{ ParserTableKey(e29.tblIndex(), "while"), r15},
	{ ParserTableKey(e29.tblIndex(), "for"), r15},
	{ ParserTableKey(e29.tblIndex(), "id"), r15},
	{ ParserTableKey(e29.tblIndex(), "}"), r15},
	{ ParserTableKey(e29.tblIndex(), "return"), r15},
	{ ParserTableKey(e30.tblIndex(), ";"), e86},
	{ ParserTableKey(e31.tblIndex(), "if"), r17},
	{ ParserTableKey(e31.tblIndex(), "while"), r17},
	{ ParserTableKey(e31.tblIndex(), "for"), r17},
	{ ParserTableKey(e31.tblIndex(), "id"), r17},
	{ ParserTableKey(e31.tblIndex(), "}"), r17},
	{ ParserTableKey(e31.tblIndex(), "return"), r17},
	{ ParserTableKey(e32.tblIndex(), "("), e40},
	{ ParserTableKey(e33.tblIndex(), "("), e41},
	{ ParserTableKey(e34.tblIndex(), "("), e42},
	{ ParserTableKey(e35.tblIndex(), "OP_INCR"), e44},
	{ ParserTableKey(e35.tblIndex(), "="), e43},
	{ ParserTableKey(e35.tblIndex(), "("), e46},
	{ ParserTableKey(e36.tblIndex(), "DECL_VAR"), e47},
	{ ParserTableKey(e36.tblIndex(), "TIPO"), e3},
	{ ParserTableKey(e36.tblIndex(), "func"), r3},
	{ ParserTableKey(e36.tblIndex(), "main"), r3},
	{ ParserTableKey(e36.tblIndex(), "if"), r3},
	{ ParserTableKey(e36.tblIndex(), "while"), r3},
	{ ParserTableKey(e36.tblIndex(), "for"), r3},
	{ ParserTableKey(e36.tblIndex(), "id"), r3},
	{ ParserTableKey(e36.tblIndex(), "const"), r3},
	{ ParserTableKey(e36.tblIndex(), "}"), r3},
	{ ParserTableKey(e36.tblIndex(), "return"), r3},
	{ ParserTableKey(e37.tblIndex(), "func"), r4},
	{ ParserTableKey(e37.tblIndex(), "main"), r4},
	{ ParserTableKey(e38.tblIndex(), "$"), r9},
	{ ParserTableKey(e39.tblIndex(), "}"), r10},
	{ ParserTableKey(e39.tblIndex(), "return"), r10},
	{ ParserTableKey(e40.tblIndex(), "NUM"), e51},
	{ ParserTableKey(e40.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e40.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e40.tblIndex(), "TESTE"), e48},
	{ ParserTableKey(e40.tblIndex(), "EXPR_REL"), e49},
	{ ParserTableKey(e40.tblIndex(), "id"), e50},
	{ ParserTableKey(e41.tblIndex(), "NUM"), e51},
	{ ParserTableKey(e41.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e41.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e41.tblIndex(), "TESTE"), e52},
	{ ParserTableKey(e41.tblIndex(), "EXPR_REL"), e49},
	{ ParserTableKey(e41.tblIndex(), "id"), e50},
	{ ParserTableKey(e42.tblIndex(), "ATR_FOR"), e53},
	{ ParserTableKey(e42.tblIndex(), "id"), e54},
	{ ParserTableKey(e43.tblIndex(), "NUM"), e56},
	{ ParserTableKey(e43.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e43.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e43.tblIndex(), "CH_FUNC"), e112},
	{ ParserTableKey(e43.tblIndex(), "EXPR_MAT"), e55},
	{ ParserTableKey(e43.tblIndex(), "id"), e57},
	{ ParserTableKey(e43.tblIndex(), "string"), e58},
	{ ParserTableKey(e44.tblIndex(), ";"), r29},
	{ ParserTableKey(e44.tblIndex(), ")"), r29},
	{ ParserTableKey(e46.tblIndex(), ")"), e61},
	{ ParserTableKey(e47.tblIndex(), "CMDS"), e62},
	{ ParserTableKey(e47.tblIndex(), "CMD"), e25},
	{ ParserTableKey(e47.tblIndex(), "IF"), e26},
	{ ParserTableKey(e47.tblIndex(), "WHILE"), e27},
	{ ParserTableKey(e47.tblIndex(), "FOR"), e28},
	{ ParserTableKey(e47.tblIndex(), "ATR"), e29},
	{ ParserTableKey(e47.tblIndex(), "INCR"), e30},
	{ ParserTableKey(e47.tblIndex(), "CH_FUNC"), e31},
	{ ParserTableKey(e47.tblIndex(), "if"), e32},
	{ ParserTableKey(e47.tblIndex(), "while"), e33},
	{ ParserTableKey(e47.tblIndex(), "for"), e34},
	{ ParserTableKey(e47.tblIndex(), "id"), e35},
	{ ParserTableKey(e47.tblIndex(), "}"), r11},
	{ ParserTableKey(e47.tblIndex(), "return"), r11},
	{ ParserTableKey(e48.tblIndex(), ")"), e63},
	{ ParserTableKey(e49.tblIndex(), "OP_LOG"), e87},
	{ ParserTableKey(e49.tblIndex(), ";"), r35},
	{ ParserTableKey(e49.tblIndex(), ")"), r35},
	{ ParserTableKey(e50.tblIndex(), "OP_REL"), e76},
	{ ParserTableKey(e51.tblIndex(), "OP_REL"), e77},
	{ ParserTableKey(e52.tblIndex(), ")"), e64},
	{ ParserTableKey(e53.tblIndex(), ";"), e65},
	{ ParserTableKey(e54.tblIndex(), "="), e66},
	{ ParserTableKey(e55.tblIndex(), ";"), e67},
	{ ParserTableKey(e56.tblIndex(), "OP_ART"), e69},
	{ ParserTableKey(e56.tblIndex(), ";"), e70},
	{ ParserTableKey(e57.tblIndex(), "OP_ART"), e68},
	{ ParserTableKey(e57.tblIndex(), ";"), e71},
	{ ParserTableKey(e57.tblIndex(), "("), e46},
	{ ParserTableKey(e58.tblIndex(), ";"), e72},
	{ ParserTableKey(e61.tblIndex(), ";"), e73},
	{ ParserTableKey(e62.tblIndex(), "return"), e74},
	{ ParserTableKey(e63.tblIndex(), "{"), e75},
	{ ParserTableKey(e64.tblIndex(), "{"), e79},
	{ ParserTableKey(e65.tblIndex(), "NUM"), e51},
	{ ParserTableKey(e65.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e65.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e65.tblIndex(), "TESTE"), e80},
	{ ParserTableKey(e65.tblIndex(), "EXPR_REL"), e49},
	{ ParserTableKey(e65.tblIndex(), "id"), e50},
	{ ParserTableKey(e66.tblIndex(), "NUM"), e81},
	{ ParserTableKey(e66.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e66.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e67.tblIndex(), "if"), r23},
	{ ParserTableKey(e67.tblIndex(), "while"), r23},
	{ ParserTableKey(e67.tblIndex(), "for"), r23},
	{ ParserTableKey(e67.tblIndex(), "id"), r23},
	{ ParserTableKey(e67.tblIndex(), "}"), r23},
	{ ParserTableKey(e67.tblIndex(), "return"), r23},
	{ ParserTableKey(e68.tblIndex(), "NUM"), e83},
	{ ParserTableKey(e68.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e68.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e68.tblIndex(), "id"), e82},
	{ ParserTableKey(e69.tblIndex(), "NUM"), e85},
	{ ParserTableKey(e69.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e69.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e69.tblIndex(), "id"), e84},
	{ ParserTableKey(e70.tblIndex(), "if"), r22},
	{ ParserTableKey(e70.tblIndex(), "while"), r22},
	{ ParserTableKey(e70.tblIndex(), "for"), r22},
	{ ParserTableKey(e70.tblIndex(), "id"), r22},
	{ ParserTableKey(e70.tblIndex(), "}"), r22},
	{ ParserTableKey(e70.tblIndex(), "return"), r22},
	{ ParserTableKey(e71.tblIndex(), "if"), r26},
	{ ParserTableKey(e71.tblIndex(), "while"), r26},
	{ ParserTableKey(e71.tblIndex(), "for"), r26},
	{ ParserTableKey(e71.tblIndex(), "id"), r26},
	{ ParserTableKey(e71.tblIndex(), "}"), r26},
	{ ParserTableKey(e71.tblIndex(), "return"), r26},
	{ ParserTableKey(e72.tblIndex(), "if"), r24},
	{ ParserTableKey(e72.tblIndex(), "while"), r24},
	{ ParserTableKey(e72.tblIndex(), "for"), r24},
	{ ParserTableKey(e72.tblIndex(), "id"), r24},
	{ ParserTableKey(e72.tblIndex(), "}"), r24},
	{ ParserTableKey(e72.tblIndex(), "return"), r24},
	{ ParserTableKey(e73.tblIndex(), "if"), r28},
	{ ParserTableKey(e73.tblIndex(), "while"), r28},
	{ ParserTableKey(e73.tblIndex(), "for"), r28},
	{ ParserTableKey(e73.tblIndex(), "id"), r28},
	{ ParserTableKey(e73.tblIndex(), "}"), r28},
	{ ParserTableKey(e73.tblIndex(), "return"), r28},
	{ ParserTableKey(e74.tblIndex(), "id"), e93},
	{ ParserTableKey(e75.tblIndex(), "CMDS"), e94},
	{ ParserTableKey(e75.tblIndex(), "CMD"), e25},
	{ ParserTableKey(e75.tblIndex(), "IF"), e26},
	{ ParserTableKey(e75.tblIndex(), "WHILE"), e27},
	{ ParserTableKey(e75.tblIndex(), "FOR"), e28},
	{ ParserTableKey(e75.tblIndex(), "ATR"), e29},
	{ ParserTableKey(e75.tblIndex(), "INCR"), e30},
	{ ParserTableKey(e75.tblIndex(), "CH_FUNC"), e31},
	{ ParserTableKey(e75.tblIndex(), "if"), e32},
	{ ParserTableKey(e75.tblIndex(), "while"), e33},
	{ ParserTableKey(e75.tblIndex(), "for"), e34},
	{ ParserTableKey(e75.tblIndex(), "id"), e35},
	{ ParserTableKey(e75.tblIndex(), "}"), r11},
	{ ParserTableKey(e75.tblIndex(), "return"), r11},
	{ ParserTableKey(e76.tblIndex(), "NUM"), e89},
	{ ParserTableKey(e76.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e76.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e76.tblIndex(), "id"), e88},
	{ ParserTableKey(e77.tblIndex(), "NUM"), e91},
	{ ParserTableKey(e77.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e77.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e77.tblIndex(), "id"), e90},
	{ ParserTableKey(e78.tblIndex(), "NUM"), e51},
	{ ParserTableKey(e78.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e78.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e78.tblIndex(), "TESTE"), e92},
	{ ParserTableKey(e78.tblIndex(), "EXPR_REL"), e49},
	{ ParserTableKey(e78.tblIndex(), "id"), e50},
	{ ParserTableKey(e79.tblIndex(), "CMDS"), e95},
	{ ParserTableKey(e79.tblIndex(), "CMD"), e25},
	{ ParserTableKey(e79.tblIndex(), "IF"), e26},
	{ ParserTableKey(e79.tblIndex(), "WHILE"), e27},
	{ ParserTableKey(e79.tblIndex(), "FOR"), e28},
	{ ParserTableKey(e79.tblIndex(), "ATR"), e29},
	{ ParserTableKey(e79.tblIndex(), "INCR"), e30},
	{ ParserTableKey(e79.tblIndex(), "CH_FUNC"), e31},
	{ ParserTableKey(e79.tblIndex(), "if"), e32},
	{ ParserTableKey(e79.tblIndex(), "while"), e33},
	{ ParserTableKey(e79.tblIndex(), "for"), e34},
	{ ParserTableKey(e79.tblIndex(), "id"), e35},
	{ ParserTableKey(e79.tblIndex(), "}"), r11},
	{ ParserTableKey(e79.tblIndex(), "return"), r11},
	{ ParserTableKey(e80.tblIndex(), ";"), e96},
	{ ParserTableKey(e81.tblIndex(), ";"), r27},
	{ ParserTableKey(e82.tblIndex(), ";"), r32},
	{ ParserTableKey(e83.tblIndex(), ";"), r33},
	{ ParserTableKey(e84.tblIndex(), ";"), r34},
	{ ParserTableKey(e85.tblIndex(), ";"), r31},
	{ ParserTableKey(e86.tblIndex(), "if"), r16},
	{ ParserTableKey(e86.tblIndex(), "while"), r16},
	{ ParserTableKey(e86.tblIndex(), "for"), r16},
	{ ParserTableKey(e86.tblIndex(), "id"), r16},
	{ ParserTableKey(e86.tblIndex(), "}"), r16},
	{ ParserTableKey(e86.tblIndex(), "return"), r16},
	{ ParserTableKey(e87.tblIndex(), "NUM"), e51},
	{ ParserTableKey(e87.tblIndex(), "NUM_INT"), e110},
	{ ParserTableKey(e87.tblIndex(), "NUM_FLOAT"), e111},
	{ ParserTableKey(e87.tblIndex(), "TESTE"), e92},
	{ ParserTableKey(e87.tblIndex(), "EXPR_REL"), e49},
	{ ParserTableKey(e87.tblIndex(), "id"), e50},
	{ ParserTableKey(e88.tblIndex(), "OP_LOG"), r37},
	{ ParserTableKey(e88.tblIndex(), ";"), r37},
	{ ParserTableKey(e88.tblIndex(), ")"), r37},
	{ ParserTableKey(e89.tblIndex(), "OP_LOG"), r38},
	{ ParserTableKey(e89.tblIndex(), ";"), r38},
	{ ParserTableKey(e89.tblIndex(), ")"), r38},
	{ ParserTableKey(e90.tblIndex(), "OP_LOG"), r39},
	{ ParserTableKey(e90.tblIndex(), ";"), r39},
	{ ParserTableKey(e90.tblIndex(), ")"), r39},
	{ ParserTableKey(e91.tblIndex(), "OP_LOG"), r40},
	{ ParserTableKey(e91.tblIndex(), ";"), r40},
	{ ParserTableKey(e91.tblIndex(), ")"), r40},
	{ ParserTableKey(e92.tblIndex(), ";"), r36},
	{ ParserTableKey(e92.tblIndex(), ")"), r36},
	{ ParserTableKey(e93.tblIndex(), ";"), e97},
	{ ParserTableKey(e94.tblIndex(), "}"), e98},
	{ ParserTableKey(e95.tblIndex(), "}"), e99},
	{ ParserTableKey(e96.tblIndex(), "INCR"), e100},
	{ ParserTableKey(e96.tblIndex(), "id"), e35},
	{ ParserTableKey(e97.tblIndex(), "}"), e101},
	{ ParserTableKey(e98.tblIndex(), "if"), r18},
	{ ParserTableKey(e98.tblIndex(), "while"), r18},
	{ ParserTableKey(e98.tblIndex(), "for"), r18},
	{ ParserTableKey(e98.tblIndex(), "else"), e102},
	{ ParserTableKey(e98.tblIndex(), "id"), r18},
	{ ParserTableKey(e98.tblIndex(), "}"), r18},
	{ ParserTableKey(e98.tblIndex(), "return"), r18},
	{ ParserTableKey(e99.tblIndex(), "if"), r20},
	{ ParserTableKey(e99.tblIndex(), "while"), r20},
	{ ParserTableKey(e99.tblIndex(), "for"), r20},
	{ ParserTableKey(e99.tblIndex(), "id"), r20},
	{ ParserTableKey(e99.tblIndex(), "}"), r20},
	{ ParserTableKey(e99.tblIndex(), "return"), r20},
	{ ParserTableKey(e100.tblIndex(), ")"), e103},
	{ ParserTableKey(e101.tblIndex(), "func"), r8},
	{ ParserTableKey(e101.tblIndex(), "main"), r8},
	{ ParserTableKey(e102.tblIndex(), "{"), e104},
	{ ParserTableKey(e103.tblIndex(), "{"), e105},
	{ ParserTableKey(e104.tblIndex(), "CMDS"), e106},
	{ ParserTableKey(e104.tblIndex(), "CMD"), e25},
	{ ParserTableKey(e104.tblIndex(), "IF"), e26},
	{ ParserTableKey(e104.tblIndex(), "WHILE"), e27},
	{ ParserTableKey(e104.tblIndex(), "FOR"), e28},
	{ ParserTableKey(e104.tblIndex(), "ATR"), e29},
	{ ParserTableKey(e104.tblIndex(), "INCR"), e30},
	{ ParserTableKey(e104.tblIndex(), "CH_FUNC"), e31},
	{ ParserTableKey(e104.tblIndex(), "if"), e32},
	{ ParserTableKey(e104.tblIndex(), "while"), e33},
	{ ParserTableKey(e104.tblIndex(), "for"), e34},
	{ ParserTableKey(e104.tblIndex(), "id"), e35},
	{ ParserTableKey(e104.tblIndex(), "}"), r11},
	{ ParserTableKey(e104.tblIndex(), "return"), r11},
	{ ParserTableKey(e105.tblIndex(), "CMDS"), e107},
	{ ParserTableKey(e105.tblIndex(), "CMD"), e25},
	{ ParserTableKey(e105.tblIndex(), "IF"), e26},
	{ ParserTableKey(e105.tblIndex(), "WHILE"), e27},
	{ ParserTableKey(e105.tblIndex(), "FOR"), e28},
	{ ParserTableKey(e105.tblIndex(), "ATR"), e29},
	{ ParserTableKey(e105.tblIndex(), "INCR"), e30},
	{ ParserTableKey(e105.tblIndex(), "CH_FUNC"), e31},
	{ ParserTableKey(e105.tblIndex(), "if"), e32},
	{ ParserTableKey(e105.tblIndex(), "while"), e33},
	{ ParserTableKey(e105.tblIndex(), "for"), e34},
	{ ParserTableKey(e105.tblIndex(), "id"), e35},
	{ ParserTableKey(e105.tblIndex(), "}"), r11},
	{ ParserTableKey(e105.tblIndex(), "return"), r11},
	{ ParserTableKey(e106.tblIndex(), "}"), e108},
	{ ParserTableKey(e107.tblIndex(), "}"), e109},
	{ ParserTableKey(e108.tblIndex(), "if"), r19},
	{ ParserTableKey(e108.tblIndex(), "while"), r19},
	{ ParserTableKey(e108.tblIndex(), "for"), r19},
	{ ParserTableKey(e108.tblIndex(), "id"), r19},
	{ ParserTableKey(e108.tblIndex(), "}"), r19},
	{ ParserTableKey(e108.tblIndex(), "return"), r19},
	{ ParserTableKey(e109.tblIndex(), "if"), r21},
	{ ParserTableKey(e109.tblIndex(), "while"), r21},
	{ ParserTableKey(e109.tblIndex(), "for"), r21},
	{ ParserTableKey(e109.tblIndex(), "id"), r21},
	{ ParserTableKey(e109.tblIndex(), "}"), r21},
	{ ParserTableKey(e109.tblIndex(), "return"), r21},
	{ ParserTableKey(e110.tblIndex(), "OP_REL"), r41},
	{ ParserTableKey(e110.tblIndex(), "OP_LOG"), r41},
	{ ParserTableKey(e110.tblIndex(), "OP_ART"), r41},
	{ ParserTableKey(e110.tblIndex(), ";"), r41},
	{ ParserTableKey(e110.tblIndex(), ")"), r41},
	{ ParserTableKey(e111.tblIndex(), "OP_REL"), r42},
	{ ParserTableKey(e111.tblIndex(), "OP_LOG"), r42},
	{ ParserTableKey(e111.tblIndex(), "OP_ART"), r42},
	{ ParserTableKey(e111.tblIndex(), ";"), r42},
	{ ParserTableKey(e111.tblIndex(), ")"), r42},
	{ ParserTableKey(e112.tblIndex(), "if"), r25},
	{ ParserTableKey(e112.tblIndex(), "while"), r25},
	{ ParserTableKey(e112.tblIndex(), "for"), r25},
	{ ParserTableKey(e112.tblIndex(), "id"), r25},
	{ ParserTableKey(e112.tblIndex(), "}"), r25},
	{ ParserTableKey(e112.tblIndex(), "return"), r25},
	{ ParserTableKey(e113.tblIndex(), "TIPO"), e9}
	};



    /*
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
    */
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
    /*
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
    */
    printTable();
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
