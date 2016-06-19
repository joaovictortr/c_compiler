// compile with g++ -std=c++11 -g -o <out file> <this file>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include "Token.h"
//#include "SymbolTable.h"
#include "Parser.h"

using namespace std;

int main(int argc, char **argv)
{
    Parser parser;
    //SymbolTable symTable;

    string input("((a)a(aa))$");
    vector< Token > inTokens;

    for(char& c : input) {
        inTokens.push_back( Token(c) );
    }

    for(auto it = inTokens.begin(); it != inTokens.end(); ++it) {
        Token tok = *it;
        if (!parser.parse(tok)) {
            cerr << "Syntax error!" << endl;
            return 1;
        }
    }

    cout << "Input string \"" << input << "\" accepted!" << endl;

    /*
    Token t0 = Token('a');
    cout << "t0.id = " << t0.id() << endl;

    Token t1 = Token(TokenType::STRING);
    cout << "t1.id = " << t1.id() << endl;

    Token t2 = Token(TokenType::RELOP);
    cout << "t2.id = " << t2.id() << endl;
    */

    /**
    symTable.insert(t1.id(), "Hello world");
    symTable.insert(t2.id(), "<=");

    const size_t t2_id = t2.id();
    SymbolTableElement t2_element = symTable[t2_id];
    boost::apply_visitor(SymbolTableVisitor(), t2_element);
    **/

    return 0;
}
