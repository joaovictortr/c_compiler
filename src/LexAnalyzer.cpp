#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <map>
#include "Token.h"
#include "LexAnalyzer.h"

using namespace std;

LexAnalyzer::LexAnalyzer(ifstream & input, SymbolTable & symTable) : inStream_(input), symTable_(symTable), lineCount_(1)
{
    tokenTable_ = {
        { "for",    Token(TokenType::FOR, 1) },
        { "while",  Token(TokenType::WHILE, 1) },
        { "if",     Token(TokenType::IF, 1) },
        { "else",   Token(TokenType::ELSE, 1) },
        { "char",   Token(TokenType::TYPE, 1) },
        { "int",    Token(TokenType::TYPE, 1) },
        { "float",  Token(TokenType::TYPE, 1) },
        { "string", Token(TokenType::TYPE, 1) },
        { "const",  Token(TokenType::TYPE_CONST, 1) },
        { "func",  Token(TokenType::FUNCTION, 1) },
        { "/",      Token(TokenType::ARTOP, 1) },
        { "==",     Token(TokenType::RELOP, 1) },
        { "!=",     Token(TokenType::RELOP, 1) },
        { ">=",     Token(TokenType::RELOP, 1) },
        { ">",      Token(TokenType::RELOP, 1) },
        { "<=",     Token(TokenType::RELOP, 1) },
        { "<",      Token(TokenType::RELOP, 1) },
        { "&&",     Token(TokenType::LOGOP, 1) },
        { "||",     Token(TokenType::LOGOP, 1) },
        { "#",      Token(TokenType::ARTOP, 1) },
        { "+",      Token(TokenType::ARTOP, 1) },
        { "-",      Token(TokenType::ARTOP, 1) },
        { "%",      Token(TokenType::ARTOP, 1) },
        { "*",      Token(TokenType::ARTOP, 1) },
        { "main",   Token(TokenType::MAIN, 1)  },
        { "return", Token(TokenType::RETURN, 1) },
        { "++",     Token(TokenType::INCROP, 1) },
        { "--",     Token(TokenType::INCROP, 1) }
    };

    for(auto it = tokenTable_.begin(); it != tokenTable_.end(); ++it)
    {
        const string tokStr = it->first;
        Token & tok = it->second;
        symTable_.insert(tok.id(), tokStr);
    }
}

bool LexAnalyzer::getToken(Token& token)
{
    char peek = ' ';
    while(inStream_.get(peek)) {
        // remove tabs, line breaks and spaces
        if ((peek == '\t') || (peek == ' '))
            continue;
        else if (peek == '\n') { ++lineCount_; continue; }

        // remove comments
        if (peek == '/') {
            if(!inStream_.get(peek)) return false;
            bool stopScan = false;
            switch(peek) {
                case '/':  // handle one line comments
                    do {
                        if(!inStream_.get(peek)) return false;
                    } while(peek != '\n');
                    ++lineCount_;
                    continue;
                    break;
                case '*':  // handle multi-line comments
                    if(!inStream_.get(peek)) { lexError("Comment not closed!"); }
                        do {
                            if (peek == '*') {
                                if(!inStream_.get(peek)) { lexError("Comment not closed!"); }

                                if (peek == '/') { stopScan = true; }
                                else if (peek == '*') { inStream_.putback(peek); }
                            }

                            if (peek == '\n')
                                ++lineCount_;

                        } while(inStream_.get(peek) && !stopScan);

                        if (!stopScan) { // '*/' pattern not found
                            lexError("Comment not closed!");
                        }
                    // put last character back on the stream
                    inStream_.putback(peek);
                    continue;
                    break;
                default:
                    // put character back on the stream
                    inStream_.putback(peek);
                    // get integer division operator from token table
                    token = tokenTable_["/"];
                    return true;
            }
        }

        // handle operators
        string strBuf;

        switch(peek) {
            /**
             * Relational operators
             */
            case '=':
                if (!inStream_.get(peek)) return false;

                if (peek == '=') {  // found '==' operator
                    // create token for equality operator
                    token = tokenTable_["=="];
                    return true;
                } else { // assignment
                    // put last read character back on the stream
                    inStream_.putback(peek);
                    peek = '=';
                    // create assignment operator
                    //token = Word(TokenType::OP_ASSIGN, TokenType::type2Str(TokenType::OP_ASSIGN));
                }
                //return true;
                break;
            case '!':
                if (!inStream_.get(peek))
                    lexError("Operator '!' not supported!");

                if (peek == '=') {  // found '!=' operator
                    token = tokenTable_["!="];
                    return true;
                } else {
                    lexError("Operator '!' not supported!");
                }
                break;
            case '>':
                if (!inStream_.get(peek)) return false;

                if (peek == '=') {  // found '>=' operator
                    // get token with ">=" operator from token table
                    token = tokenTable_[">="];
                } else { // found '>' operator
                    // put last read character back on the stream
                    inStream_.putback(peek);
                    // get ">" token
                    token = tokenTable_[">"];
                }
                return true;
                break;
            case '<':
                if (!inStream_.get(peek)) return false;

                // create token for operator "<" and its derivative
                if (peek == '=') {  // found '<=' operator
                    token = tokenTable_["<="];
                } else { // found '<' operator
                    // put last read character back on the stream
                    inStream_.putback(peek);
                    // get token for "<" operator
                    token = tokenTable_["<"];
                }
                return true;
                break;
            /**
             * logical operators
             */
            case '&':
                if (!inStream_.get(peek))
                    lexError("Operator '&' not supported!");

                if (peek == '&') {  // found '&&' operator
                    token = tokenTable_["&&"];
                    return true;
                } else {
                    lexError("Operator '&' not supported!");
                }
                break;
            case '|':
                if (!inStream_.get(peek))
                    lexError("Operator '|' not supported!");

                if (peek == '|') {  // found '||' operator
                    token = tokenTable_["||"];
                    return true;
                } else {
                    lexError("Operator '|' not supported!");
                }
                break;
            /**
             * arithmetic operators
             */
            case '#':
                token = tokenTable_["#"];
                return true;
                break;
            case '+':
                token = tokenTable_["+"];
                if (inStream_.get(peek)) {
                     if (peek == '+') { // encontrou '++', cria operador incremento
                         token = tokenTable_["++"];
                     } else {
                         // peek nao eh '+', coloca '+' de volta no buffer
                         inStream_.putback(peek);
                     }
                }
                return true;
                break;
            case '-':
                token = tokenTable_["-"];
                if (inStream_.get(peek)) {
                     if (peek == '-') { // encontrou '--', cria operador incremento
                         token = tokenTable_["--"];
                     } else {
                         // peek nao eh '+', coloca '+' de volta no buffer
                         inStream_.putback(peek);
                     }
                }
                return true;
                break;
            case '%':
                token = tokenTable_["%"];
                return true;
                break;
            case '*':
                token = tokenTable_["*"];
                return true;
                break;
            /**
             * etc
             */
            case '"':  // string
                strBuf += peek;
                do {
                    if (!inStream_.get(peek)) { lexError("String is not properly closed!"); }

                    if (peek == '\n') ++lineCount_;

                    strBuf += peek;
                } while(peek != '"');

                // create token for string
                token = makeToken(TokenType::STRING, 1);
                // insert string into symbol table
                symTable_.insert(token.id(), strBuf);
                strBuf.clear();
                return true;
                break;
            case '\'':  // char
                strBuf += peek;
                if (!inStream_.get(peek)) { lexError("Character not properly closed!"); }
                strBuf += peek;
                if (!inStream_.get(peek)) { lexError("Character not properly closed!"); }
                if (peek != '\'') {
                    lexError("Char type can have only one character enclosed by simple quotes (ex. 'a')");
                } else {
                    strBuf += peek;
                    // create token for character
                    token = makeToken(TokenType::STRING, 1);
                    // insert character into symbol table
                    symTable_.insert(token.id(), strBuf);
                    strBuf.clear();
                    return true;
                }
                break;
        }

        if (isdigit(peek)) {
            int v = 0;
            bool stop = false;
            do {
                // temp string to convert peek to number
                string s;
                s += peek;
                v = 10 * v + atoi(s.c_str());
                if (!inStream_.get(peek)) stop = true;
            } while(isdigit(peek) && !stop);

            if (isalpha(peek)) { // number followed by an alphabetic character
                lexError("Literal (integer) followed by alphabetic character!");
            }

            if (peek == '.') {  // found . after first number, check for real number
                int n_digits = 0;
                float frac = 0.1;
                float r = static_cast<float>(v);

                if (!inStream_.get(peek)) { lexError("Invalid real number!"); }

                bool stop = false;
                while(isdigit(peek) && !stop) {
                    string s;
                    s += peek;
                    r += frac * atof(s.c_str());
                    frac *= 0.1;
                    ++n_digits;
                    if (!inStream_.get(peek)) { stop = true; }
                }

                if (isalpha(peek)) {
                    lexError("Literal (real number) followed by alphabetic character!");
                }

                if (n_digits == 0) {
                    lexError("Invalid real number!\n");
                }
                // last read peek was not a digit, put peek back on the stream
                inStream_.putback(peek);

                token = makeToken(TokenType::NUM_FLOAT, 1);
                symTable_.insert(token.id(), r);
            } else {
                // peek was not '.', put character back on the stream
                inStream_.putback(peek);
                // create token for integer
                token = makeToken(TokenType::NUM_INT, 1);
                // insert integer number into the symbol table
                symTable_.insert(token.id(), v);
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

            if (hasToken(word))
                token = tokenTable_[word];
            else {
                token = makeToken(TokenType::ID, 1);
                symTable_.insert(token.id(), word);
            }
            return true;
        }

        // create token with the tag corresponding to peek's
        // value in the ASCII table
        token = makeToken(static_cast<int>(peek), false);
        return true;
    }
    return false;
}

/**
 * Check if a string is a reserved word
 *
 * @param word string to be verified
 * @return true if the string belongs to words, return true. Otherwise, return false.
 */
bool LexAnalyzer::hasToken(string & strTok)
{
    return tokenTable_.find(strTok) != tokenTable_.end();
}

void LexAnalyzer::lexError(string s) {
    cerr << "[line " << getLine() << "] Lexical error: " << s << endl;
    exit(1);
}

Token & LexAnalyzer::makeToken(const int type, bool hasValue)
{
    shared_ptr< Token > tok = make_shared< Token >( type, hasValue );
    tokenPtrs_.push_back(tok);
    return *tok;
}
