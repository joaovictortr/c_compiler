#pragma once

#include <string>
#include <fstream>
#include <boost/regex.hpp>

class LexAnalyzer {
public:
    LexAnalyzer(fstream& input);
    bool getToken(string& tokenDst);
private:
    fstream& inStream_;
    map<string, boost::regex> rules_;
    map<string, int> flags_;
    string curLine_;

    void compileRules();
};
