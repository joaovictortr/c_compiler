#include <iostream>
#include <string>
#include "IOHandler.h"
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
    /**
    string text="f";

    boost::regex letra("[A-Z]|[a-z]");

    if (boost::regex_match (text, letra) )
        cout << "string literal matched\n";
    else
        cout << "none";
     */

    if (argc < 3) {
        string filename = string(argv[0]);
        usage(filename);
        return 1;
    }

    const string input_fname = string(argv[1]);
    const string output_fname = string(argv[2]);

    /*
    try {
    */

    IOHandler input(input_fname),
              output(output_fname);

    LexAnalyzer lex = LexAnalyzer(input);

    string token;
    while(lex.getToken(token)) {
        output.append(token);
    }

    /*
    } catch(LexicalError &e) {
    } catch(IOError &e) {
    }
    */


    return 0;
}
