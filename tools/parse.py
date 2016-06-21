#!/usr/bin/python
# encoding: utf-8

import sys

with open(sys.argv[1]) as f:
    header= f.readline().strip().split(",")

    header_tbl = list()

    numStates = 0
    for line in f:
        linebuf = line.strip().split(",")
        state = 'e' + linebuf[0]
        if numStates is 0:
            print "startSt_ = make_shared< ParserState >(ParserState::SHIFT, \"{0}\");".format(state)
            numStates += 1
        else:
            print "ParserState {0} = makeState(ParserState::SHIFT, \"{0}\");".format(state)
            numStates += 1

        for index, action in enumerate(linebuf[1:]):  # processa linha
            if len(action) > 0:
                if action[0] is 'e':  # shift
                    header_tbl.append((state, header[index+1], action))
                elif action[0] is 'r':  # reduce
                    header_tbl.append((state, header[index+1], action))
                elif action[0] is 'a':  # accept
                    header_tbl.append((state, header[index+1], "acceptState()"))

    print u"/* Reductions */\n\n"

    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(1, "PROG", 4)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(2, "DECL_VAR", 4)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(3, "DECL_VAR", 0)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(4, "CONST", 6)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(5, "CONST", 0)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(6, "FUNCOES", 2)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(7, "FUNCOES", 0)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(8, "FUNCAO", 11)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(9, "MAIN", 5)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(10, "CMDS", 2)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(11, "CMDS", 0)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(12, "CMD", 1)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(13, "CMD", 1)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(14, "CMD", 1)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(15, "CMD", 1)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(16, "CMD", 2)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(17, "CMD", 1)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(18, "IF", 7)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(19, "IF", 11)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(20, "WHILE", 7)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(21, "FOR", 11)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(22, "ATR", 4)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(23, "ATR", 4)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(24, "ATR", 4)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(25, "ATR", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(26, "ATR", 4)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(27, "ATR_FOR", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(28, "CH_FUNC", 4)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(29, "INCR", 2)
    #print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(30, "INCR", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(31, "EXPR_MAT", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(32, "EXPR_MAT", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(33, "EXPR_MAT", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(34, "EXPR_MAT", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(35, "TESTE", 1)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(36, "TESTE", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(37, "EXPR_REL", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(38, "EXPR_REL", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(39, "EXPR_REL", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(40, "EXPR_REL", 3)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(41, "NUM", 1)
    print "ParserState r{0} = makeState(ParserState::REDUCE, \"r{0}\", \"{1}\", {2});".format(42, "NUM", 1)
    print "\n"
    print "// special states for error and accept"
    print "errSt_ = make_shared< ParserState >(ParserState::ERROR, \"error\");"
    print "accSt_ = make_shared< ParserState >(ParserState::ACCEPT, \"accept\");"


    last = header_tbl.pop()

    print "table_ = {"
    for item in header_tbl:
        state, action, header = item
        sys.stdout.write('{ ')
        if state == "e0":
            pstr = "ParserTableKey(startState().tblIndex(), \"{1}\"), {2}".format(*item)
        else:
            pstr = "ParserTableKey({0}.tblIndex(), \"{1}\"), {2}".format(*item)
        sys.stdout.write(pstr)
        print "},"
    sys.stdout.write('{ ')
    pstr = "ParserTableKey({0}.tblIndex(), \"{1}\"), {2}".format(*last)
    sys.stdout.write(pstr)
    print "}"
    print "};\n"


