#ifndef GLIFS_H
#define GLIFS_H

#include <vector>
using std::vector;

class visitor;
class iterator;

// Интерфейс для всей иерархии глифов.
class glif
{
	public:
		typedef vector <glif *> container;
		
		glif ();
		virtual ~glif ();
		
		virtual void Add (glif *, container::size_type = -1) = 0;	// Второй параметр - индекс, перед которым будет добавлен новый элемент.
		virtual void Delete (container::size_type ind, bool del_obj) = 0;	// Если del_obj, то объект так же удаляется из ОП, иначе просто удаляется указатель из контейнера. 
		virtual container::size_type Count () const = 0;
		virtual glif * GetChild (container::size_type) const = 0;
		virtual iterator * createIterator () = 0;
		
		virtual void Show () const = 0;
        virtual void Accept (visitor *) = 0;
};

// Интерфейс для глифов-листьев с реализацией по умолчанию части методов.
class list_glif : public glif
{
	public:
		list_glif ();
		virtual ~list_glif ();
		
		virtual void Add (glif *, container::size_type = -1);
		virtual void Delete (container::size_type ind, bool del_obj);
		virtual container::size_type Count () const;
		virtual glif * GetChild (container::size_type) const;
		virtual iterator * createIterator ();
};

// Глиф-лист символ.
class simbol : public list_glif
{
	private:
		char c;
	public:
		simbol (char content);
		void Show () const;
        
        char GetSimbol () const;
        void Accept (visitor *);
};

// Глиф-лист пробел.
class space : public list_glif
{
	public:
		space ();
		void Show () const;
        
        void Accept (visitor *);
};

// Глиф-лист перевод строки.
class new_line : public list_glif
{
	public:
		new_line();
		void Show () const;
        
        void Accept (visitor *);
};

// Интерфейс для глифов-контейнеров, так же с реализацией части методов.
class container_glif : public glif
{
	protected:
		container children;
		
	public:
		container_glif ();
		virtual ~container_glif ();
		
		virtual void Add (glif *, container::size_type = -1);
		virtual void Delete (container::size_type ind, bool del_obj);
		virtual container::size_type Count () const;
		virtual glif * GetChild (container::size_type) const;
		virtual iterator * createIterator ();
		
		virtual void Show () const;
};

// Глиф-контейнер текст.
class text : public container_glif
{
	public:
		text();
		void Show () const;
        
        void Accept (visitor *);
};

// Глиф-контейнер параграф.
class paragraph : public container_glif
{
	public:
		paragraph ();
		void Show () const;
        
        void Accept (visitor *);
};

// Глиф-контейнер строка.
class row : public container_glif
{
	public:
		row ();
		void Show () const;
        
        void Accept (visitor *);
};

#endif // GLIFS_H
