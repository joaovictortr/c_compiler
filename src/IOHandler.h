#pragma once

#include <string>

using namespace std;

class IOHandler {
public:
    IOHandler(const string& filename);
    void append(const string& data);
private:
};
