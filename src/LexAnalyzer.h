#pragma once

#include <string>
#include <fstream>
#include <map>
#include <boost/regex.hpp>

using namespace std;

class LexAnalyzer {
public:
    LexAnalyzer(fstream& input);
    bool getToken(string& tokenDst);

private:
    string lineBuffer_; // buffer de linha de arquivo
    string peekBuffer_; // buffer para peek da entrada
    size_t lineCount_; // contador de linhas

    fstream& inStream_;
    map<string, boost::regex> rules_;
    map<string, int> flags_;

    map<string, string> rsvWords_; // tabela de palavras reservadas

    void compileRules();

    bool isReserved(string & word);
};
