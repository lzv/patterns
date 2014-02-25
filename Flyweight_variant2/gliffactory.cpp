#include "gliffactory.h"
#include "glif.h"

glifFactory & glifFactory::I ()
{
    static glifFactory obj;
    return obj;
}

glifFactory::~glifFactory ()
{
    for (auto i: symbols) delete i.second;
}

unsigned int glifFactory::count ()
{
    return symbols.size();
}

symbol * glifFactory::create_symbol (char c)
{
    auto iter = symbols.find(c);
    if (iter == symbols.end())
    {
        symbol * obj = new symbol(c);
        symbols[c] = obj;
        return obj;
    }
    else {
        return iter->second;
    }
}

composite * glifFactory::create_composite ()
{
    return new composite;
}
