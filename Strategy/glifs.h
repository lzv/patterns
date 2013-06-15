#ifndef GLIFS_H
#define GLIFS_H

#include <vector>
using std::vector;

class strategy;

// Интерфейс для всей иерархии глифов.
class glif
{
	public:
		typedef vector <glif *> container;
		
		glif ();
		virtual ~glif ();
		
		virtual void Add (glif *) = 0;
		virtual void Delete (container::size_type ind, bool del_obj = false) = 0;	// Если del_obj, то объект так же удаляется из ОП, иначе просто удаляется указатель из контейнера. 
		virtual void Clear (bool del_obj = false) = 0;	// Очистка всех дочерних элементов. Если del_obj, они так же удаляются из ОП.
		virtual container::size_type Count () const = 0;
		virtual glif * GetChild (container::size_type) const = 0;
		
		virtual int GetType () const = 0;
		virtual void Show () const = 0;
		virtual void RunAlgorithm (strategy * algorithm, bool del_obj = false) = 0;
		
		virtual container * GetContainer () = 0;
};

// Интерфейс для глифов-листьев с реализацией по умолчанию части методов.
class list_glif : public glif
{
	public:
		list_glif ();
		virtual ~list_glif ();
		
		virtual void Add (glif *);
		virtual void Delete (container::size_type ind, bool del_obj = false);
		virtual void Clear (bool del_obj = false);
		virtual container::size_type Count () const;
		virtual glif * GetChild (container::size_type) const;
		virtual void RunAlgorithm (strategy * algorithm, bool del_obj = false);
		virtual container * GetContainer ();
};

// Глиф-лист символ.
class simbol : public list_glif
{
	private:
		char c;
	public:
		simbol (char content);
		int GetType () const;
		void Show () const;
};

// Глиф-лист пробел.
class space : public list_glif
{
	public:
		space ();
		int GetType () const;
		void Show () const;
};

// Глиф-лист перевод строки.
class new_line : public list_glif
{
	public:
		new_line();
		int GetType () const;
		void Show () const;
};

// Интерфейс для глифов-контейнеров, так же с реализацией части методов.
class container_glif : public glif
{
	protected:
		container children;
		
	public:
		container_glif ();
		virtual ~container_glif ();
		
		virtual void Add (glif *);
		virtual void Delete (container::size_type ind, bool del_obj = false);
		virtual void Clear (bool del_obj = false);
		virtual container::size_type Count () const;
		virtual glif * GetChild (container::size_type) const;
		
		virtual void Show () const;
		virtual void RunAlgorithm (strategy * algorithm, bool del_obj = false);
		virtual container * GetContainer ();
};

// Глиф-контейнер текст.
class text : public container_glif
{
	public:
		text();
		int GetType () const;
		void Show () const;
};

// Глиф-контейнер параграф.
class paragraph : public container_glif
{
	public:
		paragraph ();
		int GetType () const;
		void Show () const;
};

// Глиф-контейнер строка.
class row : public container_glif
{
	public:
		row ();
		int GetType () const;
		void Show () const;
};

#endif // GLIFS_H
