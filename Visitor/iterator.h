#ifndef ITERATOR_H
#define ITERATOR_H

#include <stack>
using std::stack;
#include <vector>
using std::vector;

#include "glifs.h"

class iterator
{
	protected:
		iterator();
	public:
		virtual void first () = 0;
		virtual void next () = 0;
		virtual bool isDone () = 0;
		virtual glif * currentItem () = 0;
};

// Итератор для листьев, всегда возвращающий, что обход завершен
class nullIterator : public iterator 
{
	public:
		nullIterator ();
		void first ();
		void next ();
		bool isDone ();
		glif * currentItem ();
};

// Итератор для составных объектов
class componentIterator : public iterator
{
	protected:
		glif::container * _root;
		glif::container::iterator iter;
		iterator * sub_iter;
	public:
		componentIterator (glif::container *);
		~componentIterator ();
		void first ();
		void next ();
		bool isDone ();
		glif * currentItem ();
};

#endif // ITERATOR_H
