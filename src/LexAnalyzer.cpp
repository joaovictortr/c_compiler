#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <map>
#include "TokenType.h"
#include "Token.h"
#include "Types.h"  // all token types

using namespace std;

LexAnalyzer::LexAnalyzer(fstream& input) : inStream_(input), lineCount_(1)
{
    map< string, int > reserved_words = {
        { "for", TokenType::FOR },
        { "while", TokenType::WHILE },
        { "if", TokenType::IF },
        { "else", TokenType::ELSE },
        { "return", TokenType::RETURN },
        { "char", TokenType::TYPE },
        { "int", TokenType::TYPE },
        { "float", TokenType::TYPE },
        { "string", TokenType::TYPE },
        { "const", TokenType::TYPE_CONST }
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
                    // create integer division operator
                    token = Word(TokenType::ARTOP, "/");
                    lexeme = "/";
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
                    token = Word(TokenType::RELOP, "==");
                    lexeme = "==";

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
                    token = Word(TokenType::RELOP, "!=");
                    lexeme = "!=";

                    return true;
                } else {
                    lexError("Operator '!' not supported!");
                }
                break;
            case '>':
                if (!inStream_.get(peek)) return false;

                if (peek == '=') {  // found '>=' operator
                    // create token with ">=" operator
                    token = Word(TokenType::RELOP, ">=");
                    lexeme = ">=";
                } else { // found '>' operator
                    // put last read character back on the stream
                    inStream_.putback(peek);
                    // create ">" token
                    token = Word(TokenType::RELOP, ">");
                    lexeme = ">";
                }
                return true;
                break;
            case '<':
                if (!inStream_.get(peek)) return false;

                // crate token for operator "<" and its derivative
                if (peek == '=') {  // found '<=' operator
                    token = Word(TokenType::RELOP, "<=");
                    lexeme = "<=";
                } else { // found '<' operator
                    // put last read character back on the stream
                    inStream_.putback(peek);
                    // create token for "<"
                    token = Word(TokenType::RELOP, "<");
                    lexeme = "<";
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
                    token = Word(TokenType::LOGOP, "&&");
                    lexeme = "&&";
                    return true;
                } else {
                    lexError("Operator '&' not supported!");
                }
                break;
            case '|':
                if (!inStream_.get(peek))
                    lexError("Operator '|' not supported!");

                if (peek == '|') {  // found '||' operator
                    token = Word(TokenType::LOGOP, "||");
                    lexeme = "||";

                    return true;
                } else {
                    lexError("Operator '|' not supported!");
                }
                break;
            /**
             * arithmetic operators
             */
            case '#':
                token = Word(TokenType::ARTOP, "#");
                lexeme = "#";

                return true;
                break;
            case '+':
                /*
                if (inStream_.get(peek)) {
                    if (peek == '+') { // encontrou '++', cria operador incremento
                        token = Word(TokenType::INCOP_PLUS, TokenType::tag2Str(TokenType::INCOP_PLUS));
                        return true;
                    } else {
                        // peek nao eh '+', coloca '+' de volta no buffer
                        inStream_.putback(peek);
                    }
                }
                token = Word(TokenType::ARTOP_PLUS, TokenType::type2Str(TokenType::ARTOP_PLUS));
                */
                token = Word(TokenType::ARTOP, "+");
                lexeme = "+";

                return true;
                break;
            case '-':
                /*
                if (inStream_.get(peek)) {
                    if (peek == '-') { // found '--', create '--' operator
                        token = Word(TokenType::INCOP_MINUS, TokenType::tag2Str(TokenType::INCOP_MINUS));
                        return true;
                    } else {
                        // peek nao eh '-', coloca '+' de volta no buffer
                        inStream_.putback(peek);
                    }
                }
                */
                token = Word(TokenType::ARTOP, "-");
                lexeme = "-";

                return true;
                break;
            case '%':
                //token = Word(TokenType::ARTOP_MOD, TokenType::tag2Str(TokenType::ARTOP_MOD));

                token = Word(TokenType::ARTOP, "%");
                lexeme = "%";

                return true;
                break;
            case '*':
                //token = Word(TokenType::ARTOP_MULT, TokenType::tag2Str(TokenType::ARTOP_MULT));
                token = Word(TokenType::ARTOP, "*");
                lexeme = "*";

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

                token = Word(TokenType::STRING, strBuf);
                lexeme = strBuf;
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
                    token = Word(TokenType::STRING, strBuf);
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

                token = NumReal(r);
                lexeme = to_string(r);
            } else {
                // peek was not '.', put character back on the stream
                inStream_.putback(peek);
                // create integeger number token
                token = NumInt(v);
                // assign number to lexeme
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
                token = getWord(TokenType::ID, word);
            lexeme = word;
            return true;
        }

        // create token with the tag corresponding to peek's
        // value in the ASCII table
        token = Token(peek);
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


void LexAnalyzer::lexError(string s) {
    cerr << "[line " << getLine() << "] Lexical error: " << s << endl;
    exit(1);
}
