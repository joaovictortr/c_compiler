#pragma once

#include <boost/variant/variant.hpp>

class SymbolTableVisitor
    : public boost::static_visitor<>
{
public:
    void operator()(int & intVal) const { intVal = intVal; }
    void operator()(float & floatVal) const { floatVal = floatVal; }
    void operator()(char & charVal) const { charVal = charVal; }
    void operator()(string & strVal) const { strVal = strVal; }
};
