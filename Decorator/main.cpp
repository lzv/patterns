#include <string>
using std::string;

#include "glifs.h"
#include "decorators.h"

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
	
	// Добавим в текст декораторов. 
	
	// Добавим декораторов для символов в первом абзаце.
	glif * p1 = full_text.GetChild(0);
	glif * s1 = p1->GetChild(15);
	glif * s2 = p1->GetChild(18);
	glif * s3 = p1->GetChild(19);
	p1->Delete(15, false);
	p1->Add(new decorator_strong(new decorator_italic(s1)), 15);
	p1->Delete(18, false);
	p1->Add(new decorator_strong(s2), 18);
	p1->Delete(19, false);
	p1->Add(new decorator_italic(s3), 19);
	
	// Добавим декоратор для второго абзаца.
	glif * p2 = full_text.GetChild(1);
	full_text.Delete(1, false);
	full_text.Add(new decorator_strong(new decorator_italic(p2)), 1);
	
	cout << endl << "Проверка отображения текста с декораторами" << endl << endl;
	full_text.Show();
	
	return 0;
}

/*
Результат выполнения программы: 

-- begin text --
    This signal is emitted when the application is about to quit the main event loop, e.g. when the event loop level drops to zero. This may happen either after a call to quit() from inside the application or when the users shuts down the entire desktop session.
    The signal is particularly useful if your application has to do some last-second cleanup. Note that no user interaction is possible in this state.
Prepends path to the beginning of the library path list, ensuring that it is searched for libraries first. If path is empty or already in the path list, the path list is not changed.
-- end text --

Проверка отображения текста с декораторами

-- begin text --
    This signal is <strong><italic>e</italic></strong>mi<strong>t</strong><italic>t</italic>ed when the application is about to quit the main event loop, e.g. when the event loop level drops to zero. This may happen either after a call to quit() from inside the application or when the users shuts down the entire desktop session.
<strong><italic>    The signal is particularly useful if your application has to do some last-second cleanup. Note that no user interaction is possible in this state.
</italic></strong>Prepends path to the beginning of the library path list, ensuring that it is searched for libraries first. If path is empty or already in the path list, the path list is not changed.
-- end text --

*/
