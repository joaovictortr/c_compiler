#pragma once

#include <string>

using namespace std;

struct TokenType {
    // numeric literal
    static const int NUM_INT = 256; // literal numerico (numero real), ex. 26.5
    static const int NUM_FLOAT = 257; // literal numerico (numero real), ex. 26.5
    // string
    static const int STRING = 258;
    // identifier
    static const int ID = 259;
    // logical operator
    static const int LOGOP = 260;
    // relational operator
    static const int RELOP = 261;
    // arithmetic operator
    static const int ARTOP = 262;
    // commands
    static const int FOR = 263;
    static const int WHILE = 264;
    static const int IF = 265;
    static const int ELSE = 266;
    static const int RETURN = 267;
    // basic types
    static const int TYPE = 268;
    static const int TYPE_CONST = 269;
    static const int MAIN = 270;
    static const int INCROP = 271;
    static const int FUNCTION = 272;

    static string type2Str(int type) {
        switch(type) {
            case NUM_INT:
                return "NUM_INT"; break;
            case NUM_FLOAT:
                return "NUM_FLOAT"; break;
            case STRING:
                return "string"; break;
            case ID:
                return "id"; break;
            /* logical operator */
            case LOGOP:
                return "OP_LOG"; break;
            /* relational operator */
            case RELOP:
                return "OP_REL"; break;
            /* arithmetic operator */
            case ARTOP:
                return "OP_ART"; break;
            case INCROP:
                return "OP_INCR"; break;
            /* commands */
            case FOR:
                return "for"; break;
            case WHILE:
                return "while"; break;
            case IF:
                return "if"; break;
            case ELSE:
                return "else"; break;
            case RETURN:
                return "return"; break;
            /* basic types */
            case TYPE:
                return "TIPO"; break;
            case TYPE_CONST:
                return "const"; break;
            case MAIN:
                return "main"; break;
            case FUNCTION:
                return "func"; break;
            default:
                string s;
                s += static_cast<char>(type);
                return s;
        }
    }
}; // struct TokenType

class Token {
public:
    Token() : tokenId_(0) {}
    Token(int type, bool hasValue = true) : type_(type)
    {
        static size_t tid(1);
        // generate unique token id only if token has a value, i.e.
        //  < STRING, "Hello world" >
        // has a value and therefore this token will have a tokenId != 0.
        if (hasValue) tokenId_= tid++;
        else tokenId_ = 0;
    }
    ~Token() = default;

    int getType() const { return type_; };
    string strType() const { return TokenType::type2Str(type_); }
    size_t id() const { return tokenId_; }

    Token& operator=(const Token& other) {
        setType(other.getType());
        tokenId_ = other.id();
        return *this;
    }

protected:
    int type_;
    size_t tokenId_;
    void setType(int type) { type_ = type; }
};
