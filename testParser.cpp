// compile with g++ -std=c++11 -g -o <out file> <this file>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include "ParserTable.h"

using namespace std;

int main(int argc, char **argv)
{
    ParserTable table;
    ParserState startState = table.startState();

    return 0;
}
