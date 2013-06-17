#ifndef SIMBOLS_H
#define SIMBOLS_H

// Определяем классы для символов. Каждый символ может быть больним и маленьким. 
// Стиль символов должен быть единообразен, поэтому используем фабрику.
// В дальнейшем можно будет добавить новый вид символа, например средний или сверхбольшой. 
// Набор методов у родительских абстрактных классов может быть разный.

class SimbolA
{
	public:
		virtual void print () = 0;
};

class SimbolABig : public SimbolA
{
	public:
		void print ();
};

class SimbolASmall : public SimbolA
{
	public:
		void print ();
};

class SimbolB
{
	public:
		virtual void print () = 0;
};

class SimbolBBig : public SimbolB
{
	public:
		void print ();
};

class SimbolBSmall : public SimbolB
{
	public:
		void print ();
};

class SimbolC
{
	public:
		virtual void print () = 0;
};

class SimbolCBig : public SimbolC
{
	public:
		void print ();
};

class SimbolCSmall : public SimbolC
{
	public:
		void print ();
};

#endif // SIMBOLS_H
