#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>

class Prototype
{
    public:
        virtual Prototype * clone () = 0;
        virtual std::string get_name () = 0;
        virtual ~Prototype () {}
};

class Type1 : public Prototype
{
    public:
        std::string get_name ()
        {
            return "type 1";
        }
        
        Prototype * clone ()
        {
            Type1 * copy = new Type1;
            *copy = *this;
            return copy;
        }
};

class Type2 : public Prototype
{
    public:
        std::string get_name ()
        {
            return "type 2";
        }
        
        Prototype * clone ()
        {
            Type2 * copy = new Type2;
            *copy = *this;
            return copy;
        }
};

#endif // PROTOTYPE_H
