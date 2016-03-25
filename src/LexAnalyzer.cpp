#include <string>
#include <boost/regex.hpp>
#include "LexAnalyzer.h"

using namespace std;

LexAnalyzer::LexAnalyzer(IOHandler& input)
{
}

bool LexAnalyzer::getToken(string& tokenDst)
{
}

void LexAnalyzer::compileRules()
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
