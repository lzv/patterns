#include "simbols.h"
#include "factory.h"

int main()
{
	Factory * pfactory;
	SimbolA * psa;
	SimbolB * psb;
	SimbolC * psc;
	
	// Получим три символа в разных стилях. Сначала получим большие символы.
	
	pfactory = new BigSimbolsFactory();
	
	psa = pfactory->GetA();
	psb = pfactory->GetB();
	psc = pfactory->GetC();
	
	// Проверим их, выведя на экран. 
	
	psa->print();
	psb->print();
	psc->print();
	
	// Очистим память.
	
	delete pfactory;
	delete psa;
	delete psb;
	delete psc;
	
	// Теперь получим маленькие символы.
	
	pfactory = new SmallSimbolsFactory();
	
	psa = pfactory->GetA();
	psb = pfactory->GetB();
	psc = pfactory->GetC();
	
	// Проверим их, выведя на экран. 
	
	psa->print();
	psb->print();
	psc->print();
	
	// Очистим память.
	
	delete pfactory;
	delete psa;
	delete psb;
	delete psc;
	
	return 0;
}

/*
Результат выполнения программы:

A
B
C
a
b
c

*/
