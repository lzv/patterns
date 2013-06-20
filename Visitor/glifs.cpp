#include "glifs.h"
#include "visitors.h"
#include "iterator.h"

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
void list_glif::Add (glif *, container::size_type) {}
void list_glif::Delete (container::size_type, bool) {}
glif::container::size_type list_glif::Count () const {return 0;}
glif * list_glif::GetChild (container::size_type) const {return 0;}
iterator * list_glif::createIterator () {return new nullIterator();}

// Глиф-лист символ.

simbol::simbol (char content) : c(content) {}
void simbol::Show () const {cout << c;}
char simbol::GetSimbol () const {return c;}
void simbol::Accept (visitor * obj) {obj->visit_simbol(this);}

// Глиф-лист пробел.

space::space () {}
void space::Show () const {cout << ' ';}
void space::Accept (visitor * obj) {obj->visit_space(this);}

// Глиф-лист перевод строки.

new_line::new_line () {}
void new_line::Show () const {cout << endl;}
void new_line::Accept (visitor * obj) {obj->visit_new_line(this);}

// Интерфейс для глифов-контейнеров.

container_glif::container_glif () {}

container_glif::~container_glif ()
{
    container::size_type i, c = children.size();
    for (i = 0; i < c; ++i) delete children[i];
}

// Добавляем объект, если его еще нет в контейнере.
void container_glif::Add (glif * element, container::size_type ind)
{
	container::iterator eli = find(children.begin(), children.end(), element);
	container::size_type con_size = children.size();
	if (eli == children.end())
	{
		if (ind <= con_size) children.insert(children.begin() + ind, element);
		else children.push_back(element);
	}
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

glif::container::size_type container_glif::Count () const 
{
	return children.size();
}

glif * container_glif::GetChild (container::size_type ind) const
{
	return ind < children.size() ? children[ind] : 0;
}

iterator * container_glif::createIterator () {return new componentIterator(& children);}

void container_glif::Show () const
{
	container::const_iterator i, end = children.end();
	for (i = children.begin(); i != end; ++i) (*i)->Show();
}

// Глиф-контейнер текст.

text::text () {}

void text::Show () const 
{
	cout << "-- begin text --" << endl;
	container_glif::Show();
	cout << "-- end text --" << endl;
}

void text::Accept (visitor * obj) {obj->visit_text(this);}

// Глиф-контейнер параграф.

paragraph::paragraph () {}

void paragraph::Show () const
{
	cout << "    ";
	container_glif::Show();
}

void paragraph::Accept (visitor * obj) {obj->visit_paragraph(this);}

// Глиф-контейнер строка.

row::row () {}

void row::Show () const 
{
	container_glif::Show();
	cout << endl;
}

void row::Accept (visitor * obj) {obj->visit_row(this);}
