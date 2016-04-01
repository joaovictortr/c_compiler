#pragma once

#include <string>
#include <fstream>
#include <map>
#include "Tag.h"
#include "Token.h"
#include "Num.h"
#include "Word.h"

using namespace std;

class LexAnalyzer {
public:
    LexAnalyzer(fstream& input);
    bool getToken(Token& tokenDst);
    size_t getLine() const { return lineCount_; }
private:
    Word & getWord(int tag, string& word);
    void reserve(Word & w) { getWord(w.getTag(), w.getLexeme()); }
    bool readLine();
    bool readChar(char & c, string & buffer, string::iterator & it);
    bool isReserved(string & word);

    fstream& inStream_;
    size_t lineCount_;
    string lineBuf_;
    map<string, Word> words_;
};
