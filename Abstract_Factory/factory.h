#ifndef FACTORY_H
#define FACTORY_H

#include "simbols.h"

// Для добавления нового типа символа нужно будет добавить класс-наследник фабрики.
// Для добавления нового символа уже имеющихся типов, нужно будет добавить по методу в каждый класс фабрик.

class Factory
{
	public:
		virtual SimbolA * GetA () = 0;
		virtual SimbolB * GetB () = 0;
		virtual SimbolC * GetC () = 0;
};

class BigSimbolsFactory : public Factory
{
	public:
		SimbolA * GetA ();
		SimbolB * GetB ();
		SimbolC * GetC ();
};

class SmallSimbolsFactory : public Factory
{
	public:
		SimbolA * GetA ();
		SimbolB * GetB ();
		SimbolC * GetC ();
};

#endif // FACTORY_H
