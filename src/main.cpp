#include <iostream>
#include <fstream>
#include <string>
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

    // open input stream
    fstream input(input_fname);
    if (input.fail()) {  /* Check if failbit is set */
        cerr << "Failed to open input source file '" << input_fname << "'" << endl;
        return 1;
    }

    // open output stream
    fstream output(output_fname, std::fstream::out);
    if (output.fail()) {  /* Check if failbit is set */
        cerr << "Failed to open output file '" << output_fname << "'" << endl;
        return 1;
    }

    vector<string> rules = { "(float|int|const|string|char)" };
    LexAnalyzer lex = LexAnalyzer(input);

    string token;
    while(lex.getToken(token)) {
        //output.append(token);
        cout << "Token = " << token << endl;
    }

    /*
    } catch(LexicalError &e) {
    } catch(IOError &e) {
    }
    */


    return 0;
}
