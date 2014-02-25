#ifndef GLIFFACTORY_H
#define GLIFFACTORY_H

#include <map>

class glif;
class symbol;
class composite;

class glifFactory
{
    // Шаблон Одиночка
    private:
        glifFactory () {}
        glifFactory (const glifFactory &);
        glifFactory & operator = (const glifFactory &);
    public:
        static glifFactory & I ();
    // Завершение шаблона Одиночки.
        
    private:
        std::map <char, symbol *> symbols;
        
    public:
        ~glifFactory ();
        unsigned int count ();
        
        symbol * create_symbol (char c);
        composite * create_composite ();
};

#endif // GLIFFACTORY_H
