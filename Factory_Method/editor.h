#ifndef EDITOR_H
#define EDITOR_H

#include "document.h"

class Editor
{
    public:
        virtual Document * createDocument () = 0;
        virtual ~Editor () {}
};

class htmlEditor : public Editor
{
    public:
        Document * createDocument () {return new htmlDocument;}
};

class plainTextEditor : public Editor
{
    public:
        Document * createDocument () {return new plainTextDocument;}
};

#endif // EDITOR_H
