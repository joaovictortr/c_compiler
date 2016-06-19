#pragma once

#include <map>
#include <memory>
#include <boost/variant/variant.hpp>
#include "Token.h"

using namespace std;

typedef boost::variant< int, float, char, std::string> SymbolTableElement;

class SymbolTableVisitor
    : public boost::static_visitor<>
{
public:

    void operator()(int & intVal) const {}

    void operator()(float & floatVal) const {}

    void operator()(char & charVal) const {}

    void operator()(string & strVal) const {}
};

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
    bool hasToken(size_t tokenId) const { table_.find(tokenId) != table_.end(); }

private:
    // symbol table supports the types specified in the boost::variant template
    // instantiation. It uses the token id as a key.
    map< size_t, SymbolTableElement > table_;
}; // class SymbolTable

void SymbolTable::insert(size_t tokenId, int value) {
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

void SymbolTable::insert(size_t tokenId, float value) {
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

void SymbolTable::insert(size_t tokenId, char value) {
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

void SymbolTable::insert(size_t tokenId, string value) {
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

SymbolTableElement SymbolTable::operator[](size_t &tokenId)
{
    auto search = table_.find(tokenId);
    if (search == table_.end()) {
        throw std::runtime_error( "Invalid token ID!" );
    }
    SymbolTableElement tokenValue = search->second;
    return tokenValue;
}

SymbolTableElement SymbolTable::operator[](const size_t &tokenId)
{
    auto search = table_.find(tokenId);
    if (search == table_.end()) {
        throw std::runtime_error( "Invalid token ID!" );
    }
    SymbolTableElement tokenValue = search->second;
    return tokenValue;
}
