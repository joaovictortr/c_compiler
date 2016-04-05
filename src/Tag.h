#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Tag {
public:
    static const int NUM_INT = 256; // literal numerico (numero inteiro), ex. 40
    static const int NUM_REAL = 257; // literal numerico (numero real), ex. 26.5
    static const int STRING = 258; // string
    static const int ID = 259; // identificador
    static const int OP_ASSIGN = 260; // atribuição
    // operadores lógicos
    static const int LOGOP_AND = 261; // &&
    static const int LOGOP_OR = 262; // ||
    // operadores relacionais
    static const int RELOP_EQ = 263;  // ==
    static const int RELOP_NEQ = 264; // !=
    static const int RELOP_BGT = 265; // >
    static const int RELOP_SLT = 266; // <
    static const int RELOP_BGT_EQ = 267; // >=
    static const int RELOP_SLT_EQ = 268; // <=
    // incrementos
    static const int INCOP_PLUS = 269; // id++
    static const int INCOP_MINUS = 270; // id--
    // operadores aritméticos
    static const int ARTOP_DIV_INT = 271; // /
    static const int ARTOP_DIV_REAL = 272; // #
    static const int ARTOP_PLUS = 273; // +
    static const int ARTOP_MINUS = 274; // -
    static const int ARTOP_MOD = 275; // %
    static const int ARTOP_MULT = 276; // *
    // comandos
    static const int FOR = 277;
    static const int WHILE = 278;
    static const int IF = 279;
    static const int ELSE = 280;
    static const int RETURN = 281;
    // tipos basicos
    static const int TIPO_CHAR = 282;
    static const int TIPO_INT = 283;
    static const int TIPO_FLOAT = 284;
    static const int TIPO_STRING = 285;

    static string tag2Str(int tag) {
        switch(tag) {
            case NUM_INT:
                return "NUM_INT"; break;
            case NUM_REAL:
                return "NUM_REAL"; break;
            case STRING:
                return "STRING"; break;
            case ID:
                return "ID"; break;
            case OP_ASSIGN:
                return "OP_ASSIGN"; break;
            /* operadores lógicos */
            case LOGOP_AND:
                return "LOGOP_AND"; break;
            case LOGOP_OR:
                return "LOGOP_OR"; break;
            /* operadores relacionais */
            case RELOP_EQ:
                return "RELOP_EQ"; break;
            case RELOP_NEQ:
                return "RELOP_NEQ"; break;
            case RELOP_BGT:
                return "RELOP_BGT"; break;
            case RELOP_SLT:
                return "RELOP_SLT"; break;
            case RELOP_BGT_EQ:
                return "RELOP_BGT_EQ"; break;
            case RELOP_SLT_EQ:
                return "RELOP_SLT_EQ"; break;
            case INCOP_PLUS:
                return "INCOP_PLUS"; break;
            case INCOP_MINUS:
                return "INCOP_MINUS"; break;
            /* operadores aritméticos */
            case ARTOP_DIV_INT:
                return "ARTOP_DIV_INT"; break;
            case ARTOP_DIV_REAL:
                return "ARTOP_DIV_REAL"; break;
            case ARTOP_PLUS:
                return "ARTOP_PLUS"; break;
            case ARTOP_MINUS:
                return "ARTOP_MINUS"; break;
            case ARTOP_MOD:
                return "ARTOP_MOD"; break;
            case ARTOP_MULT:
                return "ARTOP_MULT"; break;
            /* Comandos */
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
            /* Tipos basicos */
            case TIPO_CHAR:
                return "TIPO_CHAR"; break;
            case TIPO_INT:
                return "TIPO_INT"; break;
            case TIPO_FLOAT:
                return "TIPO_FLOAT"; break;
            case TIPO_STRING:
                return "TIPO_STRING"; break;
            default:
                string s;
                s += static_cast<char>(tag);
                return s;
        }
    }
};
