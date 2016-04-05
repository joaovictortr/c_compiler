#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <map>
#include <boost/regex.hpp>
#include "Tag.h"
#include "Token.h"
#include "NumInt.h"
#include "NumReal.h"
#include "Word.h"
#include "LexAnalyzer.h"

using namespace std;

LexAnalyzer::LexAnalyzer(fstream& input) : inStream_(input), lineCount_(1)
{
    map< string, int > reserved_words = {
        { "for", Tag::FOR },
        { "while", Tag::WHILE },
        { "if", Tag::IF },
        { "else", Tag::ELSE },
        { "return", Tag::RETURN },
        { "char", Tag::TIPO_CHAR },
        { "int", Tag::TIPO_INT },
        { "float", Tag::TIPO_FLOAT },
        { "string", Tag::TIPO_STRING },
        { "const", Tag::TIPO_CONST }
    };

    for(auto it = reserved_words.begin(); it != reserved_words.end(); ++it) {
        Word w;
        w = Word(it->second, it->first);
        reserve( w );
    }
}

bool LexAnalyzer::getToken(Token& token, string & lexeme)
{
    char peek = ' ';
    while(inStream_.get(peek)) {
        // remove tabs, quebras de linha e espacos
        if ((peek == '\t') || (peek == ' '))
            continue;
        else if (peek == '\n') { ++lineCount_; continue; }

        // remove comentários
        if (peek == '/') {
            if(!inStream_.get(peek)) return false;
            bool stopScan = false;
            switch(peek) {
                case '/':  // trata comentario de uma linha
                    do {
                        if(!inStream_.get(peek)) return false;
                    } while(peek != '\n');
                    ++lineCount_;
                    continue;
                    break;
                case '*':  // trata comentario de uma ou mais linhas
                    do {
                        if (peek == '*') {
                            if(!inStream_.get(peek)) { erroLexico("Comentário não fechado!"); }
                            if (peek == '/') { stopScan = true; }
                        }

                        if (peek == '\n')
                            ++lineCount_;

                    } while(inStream_.get(peek) && !stopScan);

                    if (!stopScan) { // nao encontrou '*/'
                        erroLexico("Comentário não fechado!");
                    }
                    // coloca ultimo caracter lido de volta na stream
                    inStream_.putback(peek);
                    continue;
                    break;
                default:
                    // coloca caracter de volta na stream
                    inStream_.putback(peek);
                    // cria token operador de divisão por inteiro
                    token = Word(Tag::ARTOP_DIV_INT, Tag::tag2Str(Tag::ARTOP_DIV_INT));
                    return true;
            }
        }

        // processamento dos operadores
        string strBuf;
        switch(peek) {
            /**
             * operadores relacionais
             */
            case '=':
                if (!inStream_.get(peek)) return false;

                if (peek == '=') {  // encontrou '=='
                    // cria token para operador de igualdade
                    token = Word(Tag::RELOP_EQ, Tag::tag2Str(Tag::RELOP_EQ));
                } else { // atribuição
                    // coloca caracter lido de volta no buffer
                    inStream_.putback(peek);
                    // cria token de atribuição
                    token = Word(Tag::OP_ASSIGN, Tag::tag2Str(Tag::OP_ASSIGN));
                }
                return true;
                break;
            case '!':
                if (!inStream_.get(peek))
                    erroLexico("Operador '!' não suportado!");
                if (peek == '=') {  // encontrou '!='
                    token = Word(Tag::RELOP_NEQ, Tag::tag2Str(Tag::RELOP_NEQ));
                    return true;
                } else {
                    erroLexico("Operador '!' não suportado!");
                }
                break;
            case '>':
                if (!inStream_.get(peek)) return false;

                if (peek == '=') {  // encontrou '>='
                    // cria token de maior ou igual
                    token = Word(Tag::RELOP_BGT_EQ, Tag::tag2Str(Tag::RELOP_BGT_EQ));
                } else { // operador '>'
                    // coloca caracter lido de volta no buffer
                    inStream_.putback(peek);
                    // cria token de maior
                    token = Word(Tag::RELOP_BGT, Tag::tag2Str(Tag::RELOP_BGT));
                }
                return true;
                break;
            case '<':
                if (!inStream_.get(peek)) return false;
                    // cria token com operador menor
                if (peek == '=') {  // encontrou '<='
                    token = Word(Tag::RELOP_SLT_EQ, Tag::tag2Str(Tag::RELOP_SLT_EQ));
                } else { // operador '<'
                    // coloca caracter lido de volta no buffer
                    inStream_.putback(peek);
                    // cria token de menor
                    token = Word(Tag::RELOP_SLT, Tag::tag2Str(Tag::RELOP_SLT));
                }
                return true;
                break;
            /**
             * operadores lógicos
             */
            case '&':
                if (!inStream_.get(peek))
                    erroLexico("Operador '&' não suportado!");
                if (peek == '&') {  // encontrou '&&'
                    token = Word(Tag::LOGOP_AND, Tag::tag2Str(Tag::LOGOP_AND));
                    return true;
                } else {
                    erroLexico("Operador '&' não suportado!");
                }
                break;
            case '|':
                if (!inStream_.get(peek))
                    erroLexico("Operador '|' não suportado!");
                if (peek == '|') {  // encontrou '||'
                    token = Word(Tag::LOGOP_OR, Tag::tag2Str(Tag::LOGOP_OR));
                    return true;
                } else {
                    erroLexico("Operador '|' não suportado!");
                }
                break;
            /**
             * operadores aritméticos
             */
            case '#':
                token = Word(Tag::ARTOP_DIV_REAL, Tag::tag2Str(Tag::ARTOP_DIV_REAL));
                return true;
                break;
            case '+':
                if (inStream_.get(peek)) {
                    if (peek == '+') { // encontrou '++', cria operador incremento
                        token = Word(Tag::INCOP_PLUS, Tag::tag2Str(Tag::INCOP_PLUS));
                        return true;
                    } else {
                        // peek nao eh '+', coloca '+' de volta no buffer
                        inStream_.putback(peek);
                    }
                }
                token = Word(Tag::ARTOP_PLUS, Tag::tag2Str(Tag::ARTOP_PLUS));
                return true;
                break;
            case '-':
                if (inStream_.get(peek)) {
                    if (peek == '-') { // encontrou '--', cria operador decremento
                        token = Word(Tag::INCOP_MINUS, Tag::tag2Str(Tag::INCOP_MINUS));
                        return true;
                    } else {
                        // peek nao eh '-', coloca '+' de volta no buffer
                        inStream_.putback(peek);
                    }
                }
                token = Word(Tag::ARTOP_MINUS, Tag::tag2Str(Tag::ARTOP_MINUS));
                return true;
                break;
            case '%':
                token = Word(Tag::ARTOP_MOD, Tag::tag2Str(Tag::ARTOP_MOD));
                return true;
                break;
            case '*':
                token = Word(Tag::ARTOP_MULT, Tag::tag2Str(Tag::ARTOP_MULT));
                return true;
                break;
            /**
             * outros
             */
            case '"':  // string
                strBuf += peek;
                do {
                    if (!inStream_.get(peek)) { erroLexico("String não fechada!"); }

                    if (peek == '\n') ++lineCount_;

                    strBuf += peek;
                } while(peek != '"');
                token = Word(Tag::STRING, strBuf);
                lexeme = strBuf;
                strBuf.clear();
                return true;
                break;
            case '\'':  // char
                strBuf += peek;
                if (!inStream_.get(peek)) { erroLexico("Caracter não fechado!"); }
                strBuf += peek;
                if (!inStream_.get(peek)) { erroLexico("Caracter não fechado!"); }
                if (peek != '\'') {
                    erroLexico("Tipo char pode ter somente um caracter ou caracter não fechado!");
                } else {
                    strBuf += peek;
                    token = Word(Tag::CHAR, Tag::tag2Str(Tag::CHAR));
                    lexeme = strBuf;
                    strBuf.clear();
                    return true;
                }
                break;
        }

        if (isdigit(peek)) {
            int v = 0;
            bool stop = false;
            do {
                // string temp para conversao de peek para inteiro
                string s;
                s += peek;
                v = 10 * v + atoi(s.c_str());
                if (!inStream_.get(peek)) stop = true;
            } while(isdigit(peek) && !stop);

            if (peek == '.') {  // achou . depois do primeiro numero, verifica se eh numero real
                int n_digitos = 0;
                float frac = 0.1;
                float r = static_cast<float>(v);

                if (!inStream_.get(peek)) { erroLexico("Número real inválido!"); }

                bool stop = false;
                while(isdigit(peek) && !stop) {
                    string s;
                    s += peek;
                    r += frac * atof(s.c_str());
                    frac *= 0.1;
                    ++n_digitos;
                    if (!inStream_.get(peek)) { stop = true; }
                }

                if (n_digitos == 0) {
                    erroLexico("Número real inválido!\n");
                }
                // ultimo peek lido nao era digito, coloca
                // peek de volta no buffer
                inStream_.putback(peek);

                token = NumReal(r);
                lexeme = to_string(r);
            } else {
                // nao era '.', coloca caracter de volta no buffer
                inStream_.putback(peek);
                // cria token numero inteiro
                token = NumInt(v);
                // atribui o numero ao lexema
                lexeme = to_string(v);
            }
            return true;
        }

        if (isalpha(peek)) {
            string word;
            bool stop = false;
            do {
                word += peek;
                if (!inStream_.get(peek)) stop = true;
            } while(isalnum(peek) && !stop);

            inStream_.putback(peek);

            if (isPresent(word))
                token = words_[word];
            else
                token = getWord(Tag::ID, word);
            lexeme = word;
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
 * Verifica se uma string ja existe na tabela words
 *
 * @param word string a ser verificada
 * @return true se string estiver presente em words, false caso contrario.
 */
bool LexAnalyzer::isPresent(string & word)
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


void LexAnalyzer::erroLexico(string s) {
    cerr << "[linha " << getLine() << "] Erro léxico: " << s << endl;
    exit(1);
}
