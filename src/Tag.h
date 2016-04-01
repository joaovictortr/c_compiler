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
    static const int EQ = 260;
    static const int INT_DIV = 261;

    static string tag2Str(int tag) {
        switch(tag) {
            case NUM:
                return "NUM";
                break;
            case ID:
                return "ID";
                break;
            case TRUE:
                return "TRUE";
                break;
            case FALSE:
                return "FALSE";
                break;
            case INT_DIV:
                return "/";
                break;
            case EQ:
                return "EQ";
                break;
            default:
                string s;
                s += static_cast<char>(tag);
                return s;
        }
    }
};
