#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <boost/regex.hpp>
#include "LexAnalyzer.h"

using namespace std;

LexAnalyzer::LexAnalyzer(fstream& input) : inStream_(input)
{
    /* Define rules */
    const string sType = "(float|int|const|string|char)";
    const string sLetter = "[A-Z]|[a-z]";
    const string sDigit = "[0-9]";
    const string sDigits = "[0-9]+"; //at least one
    const string sId = sLetter+"("+sLetter+"|"+sDigit+")*"; //id = letra(letra|digito)*
    const string sNum = sDigits+"\\."+sDigits;
    const string sDelim = "(\\s|\\t|\\n)"; //delim = espaco|tab|quebra_linha
    const string sChar = "\'"+sLetter+"\'"; // char = 'letra'
    const string sString = "\"(" +sLetter+ "|" +sDigit+ "|" +"\\s)*\""; //string = "[letra|digito|espaco]*"
    const string sOP_log = "(&&|\\|\\|)"; //oper_log = &&| ||
    const string sOP_rel = "(!=|==|<=|>=|>|<)";
    const string sOP_art = "(+|-|*|%|/|#)";
    const string sExpr = "("+sNum+"|"+sId+")" + "("+sOP_log+"|"+sOP_rel+")" + "("+sNum+"|"+sId+")";
    const string sExpr_art = "("+sNum+"|"+sId+")" + sOP_art + "("+sNum+"|"+sId+")";
    const string sVar = sType+"\\s"+sId;
    const string sAttribution = "("+sId+"="+sNum+";)|("+sId+"="+sId+";)|("+sId+"="+sChar+";)|("+sId+"="+sString+";)|("+sId+"="+sExpr_art+";)";
    const string sIncrement = "("+sId+"++\\))|("+sId+"++;)|("+sId+"--\\))|("+sId+"--;))";

    rules_ = {
        { "Type",         boost::regex(sType) },
        { "sLetter",      boost::regex(sLetter) },
        { "sDigit",       boost::regex(sDigit) },
        { "sDigits",      boost::regex(sDigits) }, //at least one
        { "sId",          boost::regex(sId) }, //id = letra(letra|digito)*
        { "sNum",         boost::regex(sNum) },
        { "sDelim",       boost::regex(sDelim) },
        { "sChar",        boost::regex(sChar) },
        { "sString",      boost::regex(sString) },
        { "sOP_log",      boost::regex(sOP_log) },
        { "sOP_rel",      boost::regex(sOP_rel) },
        { "sOP_art",      boost::regex(sOP_art) },
        { "sExpr",        boost::regex(sExpr) },
        { "sExpr_art",    boost::regex(sExpr_art) },
        { "sVar",         boost::regex(sVar) },
        { "sAttribution", boost::regex(sAttribution) },
        { "sIncrement",   boost::regex(sIncrement) }
    };
}

bool LexAnalyzer::getToken(string& tokenDst)
{
    /*
    int line_pos = 0;
    while(1) {
        if (curLine_.empty()) {
            if (!getline(inStream_, curLine_)) {
                return false;
            }
        }

        bool isString = false,
             isComment = false,
             foundChar = false;

        do {
            if (curLine_[position] != " ")
                foundChar = true;
        } while(!isString && !isComment && !foundChar);


    }
    */
    return true;
}

/*
void LexAnalyzer::compileRules(vector<string>& rulesList)
{
  // Setup step
  //
  // Iterator over compiler rule set creating a boost::regex
  // for each rule.
  //Patterns
  string sType = "(float|int|const|string|char)";
  string sLetter = "[A-Z]|[a-z]";
  string sDigit = "[0-9]";
  string sDigits = "[0-9]+"; //at least one
  string sId = sLetter+"("+sLetter+"|"+sDigit+")*"; //id = letra(letra|digito)*
  string sNum = sDigits+"\\."+sDigits;
  string sDelim = "(\\s|\\t|\\n)"; //delim = espaco|tab|quebra_linha
  string sChar = "\'"+sLetter+"\'"; // char = 'letra'
  string sString = "\"(" +sLetter+ "|" +sDigit+ "|" +"\\s)*\""; //string = "[letra|digito|espaco]*"
  string sOP_log = "(&&|\\|\\|)"; //oper_log = &&| ||
  string sOP_rel = "(!=|==|<=|>=|>|<)";
  string sOP_art = "(+|-|*|%|/|#)";
  string sExpr = "("+sNum+"|"+sId+")" + "("+sOP_log+"|"+sOP_rel+")" + "("+sNum+"|"+sId+")";
  string sExpr_art = "("+sNum+"|"+sId+")" + sOP_art + "("+sNum+"|"+sId+")";
  string sVar = sType+"\\s"+sId;
  string sAttribution = "("+sId+"="+sNum+";)|("+sId+"="+sId+";)|("+sId+"="+sChar+";)|("+sId+"="+sString+";)|("+sId+"="+sExpr_art+";)";
  string sIncrement = "("+sId+"++\\))|("+sId+"++;)|("+sId+"--\\))|("+sId+"--;))";

  //Regular Expressions
  boost::regex tipo (sType);
  boost::regex letra (sLetter);
  boost::regex digito (sDigit);
  boost::regex id (sId);
  boost::regex num (sNum);
  boost::regex delim (sDelim);
  boost::regex character (sChar);
  boost::regex literal (sString);
  boost::regex oper_log (sOP_log);
  boost::regex oper_art (sOP_art);
  boost::regex expressao (sExpr);
  boost::regex expressao_art (sExpr_art);
  boost::regex variavel (sVar);
  boost::regex atribuicao (sAttribution);
  boost::regex incremento (sIncrement);
}
*/
