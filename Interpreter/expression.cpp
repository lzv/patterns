#include "expression.h"

Alternation::Alternation (Expression * first, Expression * second)
    : _first(first), _second(second)
{}

Alternation::~Alternation ()
{
    delete _first;
    delete _second;
}

bool Alternation::Check (Context & con)
{
    return _first->Check(con) || _second->Check(con);
}

// ------------------------------------------

Sequence::Sequence (Expression * first, Expression * second)
    : _first(first), _second(second)
{}

Sequence::~Sequence ()
{
    delete _first;
    delete _second;
}

bool Sequence::Check (Context & con) 
{
    return _first->Check(con) && _second->Check(con);
}

// ------------------------------------------

Repetition::Repetition (Expression * expr)
    : _expr(expr)
{}

Repetition::~Repetition ()
{
    delete _expr;
}

bool Repetition::Check (Context & con)
{
    int count = 0;
    while (_expr->Check(con)) ++count;
    return count > 0;
}

// ------------------------------------------

Literal::Literal (const std::string & str)
    : _str(str)
{}

bool Literal::Check (Context & con)
{
    unsigned int con_index = con._index;
    unsigned int con_length = con._str.length();
    bool result = true;
    for (unsigned int i = 0; i < _str.length(); ++i)
        if (con_index < con_length && _str[i] == con._str[con_index])
        {
            ++con_index;
        }
        else {
            result = false;
            break;
        }
    if (result) con._index = con_index;
    return result;
}
