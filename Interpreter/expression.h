#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

/*
expression   ::= literal | alternation | sequence | repetition | '('expression')' 
alternation  ::= expression '|' expression 
sequence     ::= expression '&' expression 
repetition   ::= expression '+' 
literal      ::= 'a' | 'b' | 'c' | ... { 'a' | 'b' | 'c' | ... }+ 
*/

class Context 
{
    public:
        std::string _str;
        unsigned int _index;
        
        Context (const std::string & str) : _str(str), _index(0) {}
};

class Expression
{
    public:
        Expression () {}
        virtual ~Expression () {}
        virtual bool Check (Context &) = 0; // _index у Context меняется, только если Check возвращает true.
};

class Alternation : public Expression
{
    private:
        Expression * _first, * _second;
        
    public:
        Alternation (Expression * first, Expression * second);
        ~Alternation ();
        bool Check (Context & con);
};

class Sequence : public Expression
{
    private:
        Expression * _first, * _second;
        
    public:
        Sequence (Expression * first, Expression * second);
        ~Sequence ();
        bool Check (Context & con);
};

class Repetition : public Expression
{
    private:
        Expression * _expr;
        
    public:
        Repetition (Expression * expr);
        ~Repetition ();
        bool Check (Context & con);
};

class Literal : public Expression
{
    private:
        std::string _str;
        
    public:
        Literal (const std::string & str);
        bool Check (Context & con);
};

#endif // EXPRESSION_H
