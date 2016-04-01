#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Tag {
public:
    static const int NUM = 256;
    static const int ID = 257;
    static const int TRUE = 258;
    static const int FALSE = 259;

    static string tag2Str(int tag) {
        switch(tag) {
            case NUM:
                return "Numero";
                break;
            case ID:
                return "ID";
                break;
            case TRUE:
                return "True";
                break;
            case FALSE:
                return "False";
                break;
            default:
                string s;
                s += static_cast<unsigned char>(tag);
                return s;
        }
    }
};
