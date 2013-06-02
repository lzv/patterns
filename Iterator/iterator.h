#ifndef ITERATOR_H
#define ITERATOR_H

#include "component.h"
#include <stack>
using std::stack;

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
		void first ();
		void next ();
		bool isDone ();
		component * currentItem ();
};

#endif // ITERATOR_H
