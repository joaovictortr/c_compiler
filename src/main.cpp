#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LexAnalyzer.h"
#include "Parser.h"
#include "SymbolTable.h"

using namespace std;

void usage(string& filename)
{
    cout << filename << " "
        << "[-o <output file>]"
        << " <source file>"
        << endl;
}

int main(int argc, char *argv[]) {
    string input_fname,
           output_fname;
    int c, index;
    opterr = 0;

    if (argc < 2) {
        string filename = string(argv[0]);
        usage(filename);
        return 1;
    }

    while ((c = getopt (argc, argv, "o:")) != -1) {
        switch (c)
        {
        case 'o':
            output_fname = string(optarg);
            break;
        case '?':
            if (optopt == 'o')
              fprintf (stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint (optopt))
              fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            else
              fprintf (stderr,
                       "Unknown option character `\\x%x'.\n",
                       optopt);
            return 1;
        default:
            return 1;
        }
    }

    for (index = optind; index < argc; index++) {
        // first non-option argument is assumed to be the source file
        input_fname = string(argv[index]);
        cout << "Input file name: " << input_fname << endl;
        break;
    }

    // open input stream
    ifstream input(input_fname);
    if (input.fail()) {  /* Check if failbit is set */
        cerr << "Failed to open input source file '" << input_fname << "'" << endl;
        return 1;
    }

    // open output stream
    std::streambuf *wrBuf;
    std::ofstream of;
    if(!output_fname.empty())
    {
        of.open(output_fname);
        if(of.fail()) {
            cerr << "Fail to open output file \"" << output_fname << "\"" << endl;
            return 1;
        }
        wrBuf = of.rdbuf();
        cout << "Output file name: " << output_fname << endl;
    } else {
        wrBuf = std::cout.rdbuf();
    }
    std::ostream output(wrBuf);

    // initialize symbol table
    SymbolTable symTable = SymbolTable();
    // initialize lexical analyzer
    LexAnalyzer lex = LexAnalyzer(input, symTable);
    // initialize parser
    Parser parser = Parser();


    Token token;

    while(lex.getToken(token)) {
        // feed token into the parser stage
        if (!parser.parse(token)) {
            cerr << "Syntax error on line " << lex.getLine() << endl;
            return 1;
        }

        output << "<" << TokenType::type2Str(token.getType()) << ",";
        if (token.id() > 0) {
            cout << "id(token) = " << token.id() << endl;
            cout << "type(token) = " << TokenType::type2Str(token.getType()) << endl;
            // if token has a value (e.g. int or string), lookup its value in
            // the symtable
            const size_t tokId = token.id();
            SymbolTableElement tblElement = symTable[tokId];
            boost::apply_visitor(SymbolTableVisitor(), tblElement);
            output << tblElement << ">";
        }
        output << ">" << endl;
    }
    // insert end-of-input symbol and parse it
    token = Token('$', 0);
    if (!parser.parse(token))
    {
        cerr << "Syntax error on line " << lex.getLine() << endl;
        return 1;
    }
    output << endl;
    // close input stream
    input.close();
    return 0;
}
