#ifndef CREATOR_H
#define CREATOR_H

#include "prototype.h"

class Creator
{
    private:
        Prototype * obj;
        
    public:
        Creator () : obj(0) {}
        
        ~Creator ()
        {
            if (obj) delete obj;
        }
        
        void setPrototype (Prototype * o)
        {
            if (obj) delete obj;
            obj = o;
        }
        
        Prototype * create ()
        {
            return obj ? obj->clone() : 0;
        }
};

#endif // CREATOR_H
