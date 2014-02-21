#ifndef BUILDER_H
#define BUILDER_H

/*
Родительский класс (интерфейс) может иметь много методов по получению разных кусочков 
итогового результата. Но классы-наследники переопределяют только те методы, которые им нужны. 

В интерфейсе нет метода возвращения результата, так как возвращаться могут разные типы. 
Но в месте использования строителя обычно известно о его типе.
*/

#include "data.h"
#include <string>

class Builder
{
    public:
        Builder () {}
        virtual void buildChar (char) {}
        virtual void buildCommand (TextFormatCommand) {}
};

class htmlBuilder : public Builder
{
    private:
        std::string content;
        
    public:
        htmlBuilder () : content("") {}
        
        void buildChar (char c);
        void buildCommand (TextFormatCommand command);
        std::string getResult ();
        
};

class plainTextBuilder : public Builder
{
    private:
        std::string content;
        
    public:
        plainTextBuilder () : content("") {}
        
        void buildChar (char c);
        void buildCommand (TextFormatCommand command);
        std::string result ();
};

#endif // BUILDER_H
