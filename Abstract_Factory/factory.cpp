#include "factory.h"

SimbolA * BigSimbolsFactory::GetA () {return new SimbolABig();}
SimbolB * BigSimbolsFactory::GetB () {return new SimbolBBig();}
SimbolC * BigSimbolsFactory::GetC () {return new SimbolCBig();}

SimbolA * SmallSimbolsFactory::GetA () {return new SimbolASmall();}
SimbolB * SmallSimbolsFactory::GetB () {return new SimbolBSmall();}
SimbolC * SmallSimbolsFactory::GetC () {return new SimbolCSmall();}
