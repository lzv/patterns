#include <string>
using std::string;

#include "glifs.h"
#include "strategies.h"

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
	
	cout << endl << "Проверка разбиения текста на строки по символам" << endl << endl;
	full_text.RunAlgorithm(new row_split_by_simbols(15), true);
	full_text.Show();
	
	cout << endl << "Проверка очистки текста от строк и переводов строк" << endl << endl;
	full_text.RunAlgorithm(new clear_text(), true);
	full_text.Show();
	
	cout << endl << "Проверка разбиения текста на строки по словам" << endl << endl;
	full_text.RunAlgorithm(new row_split_by_words(15), true);
	full_text.Show();
	
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

Проверка разбиения текста на строки по символам

-- begin text --
    This signal is 
emitted when th
e application i
s about to quit
 the main event
 loop, e.g. whe
n the event loo
p level drops t
o zero. This ma
y happen either
 after a call t
o quit() from i
nside the appli
cation or when 
the users shuts
 down the entir
e desktop sessi
on.
    The signal is p
articularly use
ful if your app
lication has to
 do some last-s
econd cleanup. 
Note that no us
er interaction 
is possible in 
this state.
Prepends path t
o the beginning
 of the library
 path list, ens
uring that it i
s searched for 
libraries first
. If path is em
pty or already 
in the path lis
t, the path lis
t is not change
d.
-- end text --

Проверка очистки текста от строк и переводов строк

-- begin text --
    This signal is emitted when the application is about to quit the main event loop, e.g. when the event loop level drops to zero. This may happen either after a call to quit() from inside the application or when the users shuts down the entire desktop session.    The signal is particularly useful if your application has to do some last-second cleanup. Note that no user interaction is possible in this state.Prepends path to the beginning of the library path list, ensuring that it is searched for libraries first. If path is empty or already in the path list, the path list is not changed.-- end text --

Проверка разбиения текста на строки по словам

-- begin text --
    This signal is 
emitted when 
the 
application is 
about to quit 
the main event 
loop, e.g. 
when the event 
loop level 
drops to zero. 
This may 
happen either 
after a call 
to quit() from 
inside the 
application or 
when the users 
shuts down the 
entire desktop 
session.
    The signal is 
particularly 
useful if your 
application 
has to do some 
last-second 
cleanup. Note 
that no user 
interaction is 
possible in 
this state.
Prepends path 
to the 
beginning of 
the library 
path list, 
ensuring that 
it is searched 
for libraries 
first. If path 
is empty or 
already in the 
path list, the 
path list is 
not changed.
-- end text --

*/
