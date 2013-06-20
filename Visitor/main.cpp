#include "glifs.h"
#include "iterator.h"
#include "visitors.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	string par1("This signal is emitted when the application is about to quit the main event loop, e.g. when the event loop level drops to zero. This may happen either after a call to quit() from inside the application or when the users shuts down the entire desktop session.");
	string par2("The signal is particularly useful if your application has to do some last-second cleanup. Note that no user interaction is possible in this state.");
	string par3("Prepends path to the beginning of the library path list, ensuring that it is searched for libraries first. If path is empty or already in the path list, the path list is not changed.");
	
	text full_text;
	
	paragraph * parag1 = new paragraph();
	paragraph * parag2 = new paragraph();
	
	unsigned int i;
	for (i = 0; i < par1.length(); ++i)
		if (par1[i] == ' ') parag1->Add(new space());
		else parag1->Add(new simbol(par1[i]));
	parag1->Add(new new_line());
	for (i = 0; i < par2.length(); ++i)
		if (par2[i] == ' ') parag2->Add(new space());
		else parag2->Add(new simbol(par2[i]));
	parag2->Add(new new_line());
	
	full_text.Add(parag1);
	full_text.Add(parag2);
	
	for (i = 0; i < par3.length(); ++i)
		if (par3[i] == ' ') full_text.Add(new space());
		else full_text.Add(new simbol(par3[i]));
	full_text.Add(new new_line());
	
	cout << "Проверка отображения текста" << endl << endl;
	full_text.Show();
	
	// Посчитаем количество символов каждого вида в тексте.
	count_simbols cs_visitor;
	iterator * iter = full_text.createIterator();
	full_text.Accept(& cs_visitor); // Так как сам корень не обходится итератором.
	for (; !iter->isDone(); iter->next()) iter->currentItem()->Accept(& cs_visitor);
	cout << endl << "Количество символов в тексте:" << endl;
	cs_visitor.ShowResult();
	
	// Теперь посчитаем количество типов объектов.
	count_types ct_visitor;
	iter->first();
	full_text.Accept(& ct_visitor); // Так как сам корень не обходится итератором.
	for (; !iter->isDone(); iter->next()) iter->currentItem()->Accept(& ct_visitor);
	cout << endl << "Количество типов объектов:" << endl;
	ct_visitor.ShowResult();
	
	delete iter;
	
	return 0;
}

/*
Результат выполнения программы:

Проверка отображения текста

-- begin text --
    This signal is emitted when the application is about to quit the main event loop, e.g. when the event loop level drops to zero. This may happen either after a call to quit() from inside the application or when the users shuts down the entire desktop session.
    The signal is particularly useful if your application has to do some last-second cleanup. Note that no user interaction is possible in this state.
Prepends path to the beginning of the library path list, ensuring that it is searched for libraries first. If path is empty or already in the path list, the path list is not changed.
-- end text --

Количество символов в тексте:
end line: 3
space: 102
(: 1
): 1
,: 3
-: 1
.: 8
I: 1
N: 1
P: 1
T: 3
a: 35
b: 5
c: 10
d: 11
e: 53
f: 8
g: 7
h: 30
i: 45
k: 1
l: 23
m: 6
n: 31
o: 32
p: 22
q: 2
r: 24
s: 39
t: 54
u: 12
v: 3
w: 4
y: 6
z: 1

Количество типов объектов:
new_line: 3
paragraph: 2
row: 0
simbol: 484
space: 102
text: 1

*/
