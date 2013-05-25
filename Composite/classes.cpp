#include "classes.h"

#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>

// Конструктор и деструктор ничего не делают
component::component () {}
component::~component () {
	//cout << "deleted component" << endl;
}

// Реализация методов для листьев
void component::Add (component *) {}
void component::Delete (component *) {}
component::container::size_type component::Count () {return 0;}
component * component::GetChild (unsigned int) {return 0;}
void component::Show (unsigned int scount) {
	for (unsigned int i = 0; i < scount; ++i) cout << " ";
}

// Определяем первый лист
list1::list1 () {}
void list1::Show (unsigned int scount) {
	component::Show(scount);
	cout << "list type 1" << endl;
}
list1::~list1 () {
	cout << "deleted list1" << endl;
}

// Определяем второй лист
list2::list2 () {}
void list2::Show (unsigned int scount) {
	component::Show(scount);
	cout << "list type 2" << endl;
}
list2::~list2 () {
	cout << "deleted list2" << endl;
}

// Родительский класс для составных объектов

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

// Определяем первый контейнер
con1::con1 () {}
void con1::Show (unsigned int scount) {
	component::Show(scount);
	cout << "container type 1" << endl;
	composite::Show(scount);
}
con1::~con1 () {
	cout << "deleted con1" << endl;
}

// Определяем второй контейнер
con2::con2 () {}
void con2::Show (unsigned int scount) {
	component::Show(scount);
	cout << "container type 2" << endl;
	composite::Show(scount);
}
con2::~con2 () {
	cout << "deleted con2" << endl;
}
