#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LexAnalyzer.h"

using namespace std;

void usage(string& filename)
{
    cout << filename << " "
        << " <source file>"
        << " <output file>"
        << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        string filename = string(argv[0]);
        usage(filename);
        return 1;
    }

    const string input_fname = string(argv[1]);
    const string output_fname = string(argv[2]);

    // open input stream
    fstream input(input_fname);
    if (input.fail()) {  /* Check if failbit is set */
        cerr << "Failed to open input source file '" << input_fname << "'" << endl;
        return 1;
    }

    // open output stream
    fstream output(output_fname);
    if (output.fail()) {  /* Check if failbit is set */
        cerr << "Failed to open output file '" << output_fname << "'" << endl;
        return 1;
    }

    LexAnalyzer lex = LexAnalyzer(input);

    Token token;
    string lexeme;
    while(lex.getToken(token, lexeme)) {
        cout << "<";
        switch(token.getTag()) {
            case Tag::ID:
                cout << token.getStr() << "," << lexeme;
                lexeme.clear();
                break;
            case Tag::STRING:
                cout << token.getStr() << "," << lexeme;
                break;
            case Tag::NUM_INT:
                cout << token.getStr() << "," << lexeme;
                break;
            case Tag::NUM_REAL:
                cout << token.getStr() << "," << lexeme;
                break;
            default:
                cout << token.getStr() << ",";
        }
        cout << ">" << endl;
    }
    return 0;
}
