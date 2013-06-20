#include "iterator.h"

// Интерфейс итератора

iterator::iterator () {}

// Нулевой итератор для листьев 

nullIterator::nullIterator () {}

void nullIterator::first () {}

void nullIterator::next () {}

bool nullIterator::isDone () {return true;}

glif * nullIterator::currentItem () {return 0;}

// Итератор для составных объектов, в некотором роде его можно назвать рекурсивным

componentIterator::componentIterator (glif::container * root) : _root(root), sub_iter(0)
{
	first();
}

componentIterator::~componentIterator ()
{
	if (sub_iter != 0) delete sub_iter;
}

void componentIterator::first ()
{
	iter = _root->begin();
	if (sub_iter != 0) delete sub_iter;
	sub_iter = 0;
}

void componentIterator::next ()
{
	if (!isDone())
	{
		if (sub_iter == 0) sub_iter = (*iter)->createIterator();
		else sub_iter->next();
		if (sub_iter->isDone())
		{
			delete sub_iter;
			sub_iter = 0;
			++iter;
		}
	}
}

bool componentIterator::isDone ()
{
	return iter == _root->end();
}

glif * componentIterator::currentItem ()
{
	if (isDone()) {
		return 0;
	} else {
		if (sub_iter == 0) return *iter;
		else return sub_iter->currentItem();
	}
}
