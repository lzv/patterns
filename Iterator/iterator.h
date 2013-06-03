#ifndef ITERATOR_H
#define ITERATOR_H

#include "component.h"
#include <stack>
using std::stack;
#include <vector>
using std::vector;

class iterator
{
	protected:
		iterator();
	public:
		virtual void first () = 0;
		virtual void next () = 0;
		virtual bool isDone () = 0;
		virtual component * currentItem () = 0;
};

// Итератор для листьев, всегда возвращающий, что обход завершен
class nullIterator : public iterator 
{
	public:
		nullIterator ();
		void first ();
		void next ();
		bool isDone ();
		component * currentItem ();
};

// Итератор для составных объектов
class componentIterator : public iterator
{
	protected:
		component::container * _root;
		component::container::iterator iter;
		iterator * sub_iter;
	public:
		componentIterator (component::container *);
		~componentIterator ();
		void first ();
		void next ();
		bool isDone ();
		component * currentItem ();
};

// Итератор для вектора указателей - контейнера иерархии. Если какой-нибудь класс, наследующий интерфейс component, будет хранить дочерние объекты не в векторе, то для этого контейнера тоже можно сделать свой итератор
template <typename T>
class vectorIterator : public iterator 
{
	protected:
		vector <T *> * _root;
		typename vector <T *> :: iterator _i;
	public:
		vectorIterator (vector <T *> *);
		void first ();
		void next ();
		bool isDone ();
		T * currentItem ();
};

template <typename T>
vectorIterator<T>::vectorIterator (vector <T *> * root) : _root(root) {
	first();
}

template <typename T>
void vectorIterator<T>::first () {
	_i = _root->begin();
}

template <typename T>
void vectorIterator<T>::next () {
	++_i;
}

template <typename T>
T * vectorIterator<T>::currentItem () {
	return isDone() ? 0 : *_i;
}

template <typename T>
bool vectorIterator<T>::isDone () {
	return _i == _root->end();
}

// Итератор со стеком
class stackIterator : public iterator 
{
	protected:
		component * _root;
		stack <iterator *> _iterators;
		void deleteTop ();
	public:
		stackIterator (component *);
		~stackIterator();
		void first ();
		void next ();
		bool isDone ();
		component * currentItem ();
};

#endif // ITERATOR_H
