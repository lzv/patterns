#ifndef SYMBOL_H
#define SYMBOL_H

#include <map>
#include <memory>

enum TextType {ITALIC, BOLD, NOTYPE};

class Symbol
{
    private:
        static std::map <char, std::shared_ptr <Symbol> > symbols;   // Хранилище приспособленцев.
        
    public:
        static std::shared_ptr <Symbol> getSymbol (char c);         // Фабрика приспособленцев.
        static int count ();
        
    // Элементы шаблона Одиночка, что бы создание объектов было возможно только через фабрику. 
    private:
        Symbol (char c);
        Symbol (const Symbol &) {}
        Symbol & operator = (const Symbol &) {return *this;}
        
    private:
        char c;
        
    public:
        void print (TextType type);
};

#endif // SYMBOL_H
