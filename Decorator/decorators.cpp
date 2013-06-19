#include "decorators.h"

#include <iostream>
using std::cout;
using std::endl;

// Интерфейс для всех декораторов.

decorator::decorator (glif * element) : element(element) {}

decorator::~decorator () {if (element) delete element;}

void decorator::Add (glif * elem, container::size_type)
{
	if (element) delete element;
	element = elem;
}

void decorator::Delete (container::size_type ind, bool del_obj)
{
	if (ind == 0 and element)
	{
		if (del_obj) delete element;
		element = 0;
	}
}

glif::container::size_type decorator::Count () const {return element ? 1 : 0;}

glif * decorator::GetChild (container::size_type ind) const {return ind == 0 ? element : 0;}

int decorator::GetType () const {return 200;}

void decorator::Show () const {if (element) element->Show();}

// Декоратор для выделения текста жирным.

decorator_strong::decorator_strong (glif * element) : decorator(element) {}

void decorator_strong::Show () const
{
	cout << "<strong>";
	decorator::Show();
	cout << "</strong>";
}

// Декоратор для выделения текста курсивом.

decorator_italic::decorator_italic (glif * element) : decorator(element) {}

void decorator_italic::Show () const
{
	cout << "<italic>";
	decorator::Show();
	cout << "</italic>";
}
