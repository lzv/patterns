#include "symbol.h"
#include <iostream>

std::map <char, std::shared_ptr <Symbol> > Symbol::symbols;

std::shared_ptr <Symbol> Symbol::getSymbol (char c)
{
    std::map <char, std::shared_ptr<Symbol> > :: iterator iter = symbols.find(c);
    if (iter == symbols.end())
    {
        std::shared_ptr <Symbol> obj (new Symbol (c));
        symbols[c] = obj;
        return obj;
    }
    else {
        return iter->second;
    }
}

int Symbol::count ()
{
    return symbols.size();
}

Symbol::Symbol (char c) : c(c) {}

void Symbol::print (TextType type)
{
    switch (type)
    {
        case TextType::ITALIC:
            std::cout << "<i>" << c << "</i>";
            break;
            
        case TextType::BOLD:
            std::cout << "<b>" << c << "</b>";
            break;
            
        default:
            std::cout << c;
    }
}
