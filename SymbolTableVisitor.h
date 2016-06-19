#pragma once

#include <boost/variant/variant.hpp>

class SymbolTableVisitor
    : public boost::static_visitor<>
{
public:
    void operator()(int & intVal) const {}
    void operator()(float & floatVal) const {}
    void operator()(char & charVal) const {}
    void operator()(string & strVal) const {}
};
