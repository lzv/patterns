#ifndef HANDLER_H
#define HANDLER_H

#include <string>
#include <iostream>

class Handler
{
    protected:
        Handler * next;
        
    public:
        Handler (Handler * n = 0) : next(n) {}
        virtual ~Handler () {}
        void set_next (Handler * n) {next = n;}
        virtual void helpHandle () {if (next) next->helpHandle();}
};

class HandlerTypeNoHelp : public Handler
{
    public:
        HandlerTypeNoHelp (Handler * n = 0) : Handler(n) {}
};

class HaldlerTypeHelp : public Handler
{
    private:
        std::string help_message;
        
    public:
        HaldlerTypeHelp (Handler * n = 0) : Handler(n), help_message("") {}
        void setHelpMessage (const std::string & mess) {help_message = mess;}
        void helpHandle ()
        {
            if (help_message.length() > 0) std::cout << help_message << std::endl;
            else Handler::helpHandle();
        }
};

#endif // HANDLER_H
