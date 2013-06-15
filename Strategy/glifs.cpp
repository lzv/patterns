#include "glifs.h"

#include "strategies.h"

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>

// Интерфейс для всех глифов.

glif::glif () {}
glif::~glif () {}

// Интерфейс для листьев.

list_glif::list_glif () {}
list_glif::~list_glif () {}
void list_glif::Add (glif *) {}
void list_glif::Delete (container::size_type, bool) {}
void list_glif::Clear (bool) {}
glif::container::size_type list_glif::Count () const {return 0;}
glif * list_glif::GetChild (container::size_type) const {return 0;}
void list_glif::RunAlgorithm (strategy *, bool) {}
glif::container * list_glif::GetContainer () {return 0;}

// Глиф-лист символ.

simbol::simbol (char content) : c(content) {}
void simbol::Show () const {cout << c;}
int simbol::GetType () const {return 1;}

// Глиф-лист пробел.

space::space () {}
void space::Show () const {cout << ' ';}
int space::GetType () const {return 3;}

// Глиф-лист перевод строки.

new_line::new_line () {}
void new_line::Show () const {cout << endl;}
int new_line::GetType () const {return 2;}

// Интерфейс для глифов-контейнеров.

container_glif::container_glif () {}

container_glif::~container_glif ()
{
	Clear(true);
}

// Добавляем объект, если его еще нет в контейнере.
void container_glif::Add (glif * element)
{
	container::iterator eli = find(children.begin(), children.end(), element);
	if (eli == children.end()) children.push_back(element);
}

void container_glif::Delete (container::size_type ind, bool del_obj)
{
	container::size_type cnt = children.size();
	if (ind < cnt) 
	{
		if (del_obj) delete children[ind];
		children.erase(children.begin() + ind);
	}
}

void container_glif::Clear (bool del_obj)
{
	if (del_obj)
	{
		container::size_type i, c = children.size();
		for (i = 0; i < c; ++i) delete children[i];
	}
	children.clear();
}

glif::container::size_type container_glif::Count () const 
{
	return children.size();
}

glif * container_glif::GetChild (container::size_type ind) const
{
	return ind < children.size() ? children[ind] : 0;
}

void container_glif::Show () const
{
	container::const_iterator i, end = children.end();
	for (i = children.begin(); i != end; ++i) (*i)->Show();
}

void container_glif::RunAlgorithm (strategy * algorithm, bool del_obj) 
{
	algorithm->Run(this);
	if (del_obj) delete algorithm;
}

glif::container * container_glif::GetContainer ()
{
	return & children;
}

// Глиф-контейнер текст.

text::text () {}

int text::GetType () const {return 101;}

void text::Show () const 
{
	cout << "-- begin text --" << endl;
	container_glif::Show();
	cout << "-- end text --" << endl;
}

// Глиф-контейнер параграф.

paragraph::paragraph () {}

int paragraph::GetType () const {return 102;}

void paragraph::Show () const
{
	cout << "    ";
	container_glif::Show();
}

// Глиф-контейнер строка.

row::row () {}

int row::GetType () const {return 103;}

void row::Show () const 
{
	container_glif::Show();
	cout << endl;
}
