#include "component.h"
#include "iterator.h"

#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>

// Конструктор и деструктор ничего не делают
component::component () {}
component::~component () {}

// Обрабатываем флаг is_list
bool const component::is_list = true;
bool component::check_is_list () const {return is_list;}

// Реализация методов для листьев
void component::Add (component *) {}
void component::Delete (component *) {}
component::container::size_type component::Count () {return 0;}
component * component::GetChild (unsigned int) {return 0;}
void component::Show (unsigned int scount) {
	for (unsigned int i = 0; i < scount; ++i) cout << " ";
}
iterator * component::createIterator () {
	return new nullIterator();
}

// Определяем первый лист
list1::list1 () {}
void list1::Show (unsigned int scount) {
	component::Show(scount);
	cout << "list type 1" << endl;
}
list1::~list1 () {}

// Определяем второй лист
list2::list2 () {}
void list2::Show (unsigned int scount) {
	component::Show(scount);
	cout << "list type 2" << endl;
}
list2::~list2 () {}

// Родительский класс для составных объектов

bool const composite::is_list = false;
bool composite::check_is_list () const {return is_list;}

composite::composite () {}

composite::~composite ()
{
	//cout << "deleted composite" << endl;
	container::size_type i, c = children.size();
	for (i = 0; i < c; ++i) delete children[i];
}

// Добавляем дочерний, если его еще нет в контейнере
void composite::Add (component * element)
{
	container::iterator eli = find(children.begin(), children.end(), element);
	if (eli == children.end()) children.push_back(element);
}

// Удаляем дочерний, если он присутствует в контейнере
void composite::Delete (component * element)
{
	container::iterator eli = find(children.begin(), children.end(), element);
	if (eli != children.end()) children.erase(eli);
}

component::container::size_type composite::Count () {
	return children.size();
}

component * composite::GetChild (unsigned int i) {
	return i < children.size() ? children[i] : 0;
}

void composite::Show (unsigned int scount) {
	scount += 4;
	for (container::iterator i = children.begin(); i != children.end(); ++i) (*i)->Show(scount);
}

iterator * composite::createIterator () {
	iterator * result;
	if (variant_iterator == 1) result = new componentIterator(& children);
	else result = new vectorIterator<component>(& children);
	return result;
}

// Определяем первый контейнер
con1::con1 () {}
void con1::Show (unsigned int scount) {
	component::Show(scount);
	cout << "container type 1" << endl;
	composite::Show(scount);
}
con1::~con1 () {}

// Определяем второй контейнер
con2::con2 () {}
void con2::Show (unsigned int scount) {
	component::Show(scount);
	cout << "container type 2" << endl;
	composite::Show(scount);
}
con2::~con2 () {}
