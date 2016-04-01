#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <boost/regex.hpp>
#include "Tag.h"
#include "Token.h"
#include "Num.h"
#include "Word.h"
#include "LexAnalyzer.h"

using namespace std;

LexAnalyzer::LexAnalyzer(fstream& input) : inStream_(input), lineCount_(1)
{
    string t = "true";
    Word w = Word(Tag::TRUE, t);
    reserve( w );
    t = "false";
    w = Word(Tag::FALSE, t);
    reserve( w );
}

bool LexAnalyzer::getToken(Token& token)
{
    char peek = ' ';
    while(inStream_.get(peek)) {
        // remove tabs, quebras de linha e espacos
        if ((peek == '\t') || (peek == ' '))
            continue;
        else if (peek == '\n') { ++lineCount_; continue; }

        if (peek == '/') {
            if(!inStream_.get(peek)) return false;
            bool stopScan = false;
            switch(peek) {
                case '/':  // trata comentario de uma linha
                    do {
                        if(!inStream_.get(peek)) return false;
                    } while(peek != '\n');
                    continue;
                    break;
                case '*':  // trata comentario de uma ou mais linhas
                    do {
                        switch(peek) {
                            case '\n':
                                ++lineCount_;
                                break;
                            case '*':
                                if(!inStream_.get(peek)) {
                                    cerr << "[linha " << getLine() << "] Erro léxico: comentário não fechado!" << endl;
                                    exit(1);
                                }
                                if (peek == '/') {
                                    stopScan = true;
                                }
                                break;
                        }
                    } while(inStream_.get(peek) && !stopScan);
                    // coloca ultimo caracter lido de volta na stream
                    inStream_.putback(peek);
                    if (inStream_.eof()) {
                        cerr << "[linha " << getLine() << "] Erro léxico: comentário não fechado!" << endl;
                        exit(1);
                    }
                    continue;
                    break;
                default:
                    // coloca caracter de volta na stream
                    inStream_.putback(peek);
                    // TODO: devolve token de divisão '/'
                    token = Token(peek);
                    return true;
            }
        }

        if (isdigit(peek)) {
            int v = 0;
            do {
                // string temp para conversao de peek para inteiro
                string s;
                s += peek;
                v = 10 * v + atoi(s.c_str());
                if (!inStream_.get(peek)) break;
            } while(isdigit(peek));
            token = Num(v);
            return true;
        }

        if (isalpha(peek)) {
            string word;
            do {
                word += peek;
                if (!inStream_.get(peek)) break;
            } while(isalpha(peek));

            token = getWord(Tag::ID, word);
            return true;
        }

        // cria um token com a tag correspondente ao valor ASCII
        // de peek
        token = Token(peek);
        return true;
    }
    return false;

    /*

    }
    return false;
    */
}

Word& LexAnalyzer::getWord(int tag, string& s)
{
    Word w = Word(tag, s);
    words_.insert({ s, w });
    return words_[s];
}

bool LexAnalyzer::readLine()
{
    if (lineBuf_.empty()) {
        if (!getline(inStream_, lineBuf_)) {
            if (inStream_.bad()) {
                cerr << "IO error!" << endl;
                exit(1);
            }
            // fim de arquivo, devolve false
            return false;
        }
        // incrementa contador de linha
        ++lineCount_;
    }
    return true;
}

bool LexAnalyzer::readChar(char & c, string & buffer, string::iterator & it)
{
    if (it != buffer.end()) {
        c = *it;
        ++it;
        return true;
    }
    return false;
}
