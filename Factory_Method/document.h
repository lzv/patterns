#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document
{
    public:
        virtual std::string getType () = 0;
        virtual ~Document () {}
};

class htmlDocument : public Document
{
    public:
        std::string getType () {return "html";}
};

class plainTextDocument : public Document
{
    public:
        std::string getType () {return "plain text";}
};


#endif // DOCUMENT_H
