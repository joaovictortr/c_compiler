#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Tag {
public:
    static const int CHAR = 256; // caracter, ex 'c'
    static const int NUM_INT = 257; // literal numerico (numero inteiro), ex. 40
    static const int NUM_REAL = 258; // literal numerico (numero real), ex. 26.5
    static const int STRING = 259; // string
    static const int ID = 260; // identificador
    static const int OP_ASSIGN = 261; // atribuição
    // operadores lógicos
    static const int LOGOP_AND = 262; // &&
    static const int LOGOP_OR = 263; // ||
    // operadores relacionais
    static const int RELOP_EQ = 264;  // ==
    static const int RELOP_NEQ = 265; // !=
    static const int RELOP_BGT = 266; // >
    static const int RELOP_SLT = 267; // <
    static const int RELOP_BGT_EQ = 268; // >=
    static const int RELOP_SLT_EQ = 269; // <=
    // incrementos
    static const int INCOP_PLUS = 270; // id++
    static const int INCOP_MINUS = 271; // id--
    // operadores aritméticos
    static const int ARTOP_DIV_INT = 272; // /
    static const int ARTOP_DIV_REAL = 273; // #
    static const int ARTOP_PLUS = 274; // +
    static const int ARTOP_MINUS = 275; // -
    static const int ARTOP_MOD = 276; // %
    static const int ARTOP_MULT = 277; // *
    // comandos
    static const int FOR = 278;
    static const int WHILE = 279;
    static const int IF = 280;
    static const int ELSE = 281;
    static const int RETURN = 282;
    // tipos basicos
    static const int TIPO_CHAR = 283;
    static const int TIPO_INT = 284;
    static const int TIPO_FLOAT = 285;
    static const int TIPO_STRING = 286;
    static const int TIPO_CONST = 287;

    static string tag2Str(int tag) {
        switch(tag) {
            case CHAR:
                return "CHAR"; break;
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
            case TIPO_CONST:
                return "TIPO_CONST"; break;
            default:
                string s;
                s += static_cast<char>(tag);
                return s;
        }
    }
};
