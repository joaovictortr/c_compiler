#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <memory>
#include "Token.h"
#include "SymbolTable.h"

using namespace std;

class LexAnalyzer {
public:
    LexAnalyzer(ifstream & input, SymbolTable & symTable);
    bool getToken(Token & tok);
    size_t getLine() const { return lineCount_; }
private:
    //Word & getWord(int tag, string& word);
    //void reserve(Word & w) { getWord(w.getType(), w.getLexeme()); }
    bool readLine();
    bool readChar(char & c, string & buffer, string::iterator & it);
    bool hasToken(string & strTok);
    void lexError(string s);
    Token & makeToken(const int type, bool hasValue = 0);

    ifstream & inStream_;
    SymbolTable & symTable_;
    size_t lineCount_;
    string lineBuf_;
    map<string, Token> tokenTable_;
    vector< shared_ptr<Token> > tokenPtrs_;
};
