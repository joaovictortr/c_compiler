// regex_match example
//g++ -std=c++0x main.cpp -o ex -lboost_regex
#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;

int main ()
{
	string text="f";

	boost::regex letra("[A-Z]|[a-z]");

	if (boost::regex_match (text, letra) )
		cout << "string literal matched\n";
	else
		cout << "none";

  cout << endl;

  return 0;
}
