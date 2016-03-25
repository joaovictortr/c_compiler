#pragma once

#include <string>
#include <boost/regex.hpp>
#include "IOHandler.h"

class LexAnalyzer {
public:
    LexAnalyzer(IOHandler& input);
    bool getToken(string& tokenDst);
private:
    void compileRules();
};
