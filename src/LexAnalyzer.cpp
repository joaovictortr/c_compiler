#include <string>
#include <boost/regex.hpp>
#include "LexAnalyzer.h"

using namespace std;

LexAnalyzer::LexAnalyzer(IOHandler& input)
{
}

bool LexAnalyzer::getToken(string& tokenDst)
{
}

void LexAnalyzer::compileRules()
{
    // Setup step
    //
    // Iterator over compiler rule set creating a boost::regex
    // for each rule.
}
