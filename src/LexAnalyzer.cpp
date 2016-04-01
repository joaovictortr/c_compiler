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

        switch(peek) {
            case '=':
                string s("equal");
                token = Word(Tag::EQ, s);
                return true;
                break;
        }

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
                    string s("intdiv");
                    token = Word(Tag::INT_DIV, s);
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
            inStream_.putback(peek);
            token = Num(v);
            return true;
        }

        if (isalpha(peek)) {
            string word;
            do {
                word += peek;
                if (!inStream_.get(peek)) break;
            } while(isalpha(peek));
            inStream_.putback(peek);

            if (isReserved(word))
                token = words_[word];
            else
                token = getWord(Tag::ID, word);
            return true;
        }

        // cria um token com a tag correspondente ao valor ASCII
        // de peek
        token = Token(peek);
        return true;
    }
    return false;
}

/**
 * Verifica se uma string e palavra reservada
 *
 * @param word string a ser verificada
 * @return true se string for palavra reservada, false caso contrario.
 */
bool LexAnalyzer::isReserved(string & word)
{
    return words_.find(word) != words_.end();
}

Word & LexAnalyzer::getWord(int tag, string& lexeme)
{
    Word word = Word(tag, lexeme);
    auto ret = words_.insert({ lexeme, word });
    auto item = ret.first; // iterador sobre o par no map
    return (*item).second;
}
