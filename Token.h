#pragma once

#include <string>

using namespace std;


struct TokenType {
    // numeric literal
    static const int NUM = 256; // literal numerico (numero real), ex. 26.5
    // string
    static const int STRING = 257;
    // identifier
    static const int ID = 258;
    // logical operator
    static const int LOGOP = 259;
    // relational operator
    static const int RELOP = 260;
    // arithmetic operator
    static const int ARTOP = 261;
    // commands
    static const int FOR = 262;
    static const int WHILE = 263;
    static const int IF = 264;
    static const int ELSE = 265;
    static const int RETURN = 266;
    // basic types
    static const int TYPE = 267;
    static const int TYPE_CONST = 268;

    static string type2Str(int type) {
        switch(type) {
            case NUM:
                return "NUM"; break;
            case STRING:
                return "STRING"; break;
            case ID:
                return "ID"; break;
            /* logical operator */
            case LOGOP:
                return "LOGOP"; break;
            /* relational operator */
            case RELOP:
                return "RELOP"; break;
            /* arithmetic operator */
            case ARTOP:
                return "ARTOP"; break;
            /* commands */
            case FOR:
                return "FOR"; break;
            case WHILE:
                return "WHILE"; break;
            case IF:
                return "IF"; break;
            case ELSE:
                return "ELSE"; break;
            case RETURN:
                return "RETURN"; break;
            /* basic types */
            case TYPE:
                return "TYPE"; break;
            case TYPE_CONST:
                return "TYPE_CONST"; break;
            default:
                string s;
                s += static_cast<char>(type);
                return s;
        }
    }
}; // struct TokenType

class Token {
public:
    Token() = default;
    Token(int type, bool hasValue = true) : type_(type)
    {
        static size_t tokenId(1);
        // generate unique token id only if token has a value, i.e.
        //  < STRING, "Hello world" >
        // has a value and therefore this token will have a tokenId != 0.
        if (hasValue) tokenId_= tokenId++;
        else tokenId_ = 0;
    }
    ~Token() = default;

    int getType() const { return type_; };
    string strType() const { return TokenType::type2Str(type_); }
    size_t id() const { return tokenId_; }

    Token& operator=(const Token& other) {
        setType(other.getType());
        return *this;
    }

protected:
    int type_;
    size_t tokenId_;
    void setType(int type) { type_ = type; }
};

