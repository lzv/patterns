#ifndef DECORATORS_H
#define DECORATORS_H

#include "glifs.h"

// Интерфейс для декораторов. 
class decorator : public glif
{
	protected:
		glif * element;

	public:
		decorator (glif * element);
		virtual ~decorator ();
		
		virtual void Add (glif *, container::size_type = -1);
		virtual void Delete (container::size_type ind, bool del_obj); 
		virtual container::size_type Count () const;
		virtual glif * GetChild (container::size_type ind) const;
		
		virtual int GetType () const;
		virtual void Show () const;
};

// Декоратор для выделения текста жирным.
class decorator_strong : public decorator
{
	public:
		decorator_strong (glif * element);
		void Show () const;
};

// Декоратор для выделения текста курсивом.
class decorator_italic : public decorator
{
	public:
		decorator_italic (glif * element);
		void Show () const;
};

#endif // DECORATORS_H
