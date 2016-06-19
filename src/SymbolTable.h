#pragma once

#include <map>
#include <memory>
#include <boost/variant/variant.hpp>
#include "Token.h"
#include "SymbolTableVisitor.h"

using namespace std;

typedef boost::variant< int, float, char, std::string> SymbolTableElement;

class SymbolTable
{
public:
    SymbolTable() = default;
    ~SymbolTable() = default;

    void insert(size_t tokenId, int value);
    void insert(size_t tokenId, float value);
    void insert(size_t tokenId, char value);
    void insert(size_t tokenId, string value);
    SymbolTableElement operator[](size_t &tokenId);
    SymbolTableElement operator[](const size_t &tokenId);
    bool hasToken(size_t tokenId) const { return table_.find(tokenId) != table_.end(); }

private:
    // symbol table supports the types specified in the boost::variant template
    // instantiation. It uses the token id as a key.
    map< size_t, SymbolTableElement > table_;
}; // class SymbolTable

