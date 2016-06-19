#include <iostream>
#include <map>
#include <stdexcept>
#include "SymbolTable.h"

using namespace std;

void SymbolTable::insert(size_t tokenId, int value)
{
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

void SymbolTable::insert(size_t tokenId, float value)
{
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

void SymbolTable::insert(size_t tokenId, char value)
{
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

void SymbolTable::insert(size_t tokenId, string value)
{
    if (tokenId == 0) throw std::runtime_error( "Token ID is not valid!");
    if (hasToken(tokenId)) throw std::runtime_error( "Token ID already present!");
    SymbolTableElement element(value);
    table_.insert(pair<size_t, SymbolTableElement>(tokenId, element));
}

SymbolTableElement SymbolTable::operator[](size_t &tokenId)
{
    auto search = table_.find(tokenId);
    if (search == table_.end()) {
        cerr << "Received token ID = " << tokenId << endl;
        throw std::runtime_error( "Invalid token ID!" );
    }
    SymbolTableElement tokenValue = search->second;
    return tokenValue;
}

SymbolTableElement SymbolTable::operator[](const size_t &tokenId)
{
    auto search = table_.find(tokenId);
    if (search == table_.end()) {
        cerr << "Received token ID = " << tokenId << endl;
        throw std::runtime_error( "Invalid token ID!" );
    }
    SymbolTableElement tokenValue = search->second;
    return tokenValue;
}
