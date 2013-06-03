#ifndef CLASSES_H
#define CLASSES_H

#include <vector>
using std::vector;

class iterator;

extern int variant_iterator;

/*
 * Абстрактный класс-интерфейс для всех объектов системы
 */
class component 
{
	protected:
		component ();						// Конструктор protected, так как создавать объекты этого класса не нужно
        static bool const is_list;			// Флаг, что объект - лист, а не составной. 
	public:
        typedef vector <component *> container;
        
        virtual bool check_is_list () const;		// Возвращает значение статической константы is_list.
		virtual ~component ();						// Виртуальный деструктор
		virtual void Add (component *);				// Добавление объекта в дочерние
		virtual void Delete (component *);			// Удаление объекта с заданным порядковым номером с очисткой памяти 
		virtual container::size_type Count ();		// Возвращает количество дочерних объектов
		virtual component * GetChild (unsigned int);// Возвращает объект с указанным номером 
		
		virtual void Show (unsigned int = 0);	// Операция, которая должна единообразно применяться ко всем объектам
		
		virtual iterator * createIterator ();	// Возвращает итератор.
};

/*
 * Первый лист системы объектов
 */
class list1 : public component 
{
	public:
		list1 ();						// Конструктор публичный
		void Show (unsigned int = 0);	// Переопределяемая операция
		~list1 ();
};

/*
 * Второй лист системы объектов
 */
class list2 : public component 
{
	public:
		list2 ();						// Конструктор публичный
		void Show (unsigned int = 0);	// Переопределяемая операция
		~list2 ();
};

/*
 * Родительский класс для составных объектов
 */
class composite : public component 
{
	protected:
		composite ();						// Конструктор protected, так как создавать объекты этого класса не нужно
		container children;					// Контейнер для дочерних объектов 
		static bool const is_list;			// Флаг, что объект - лист, а не составной. 
	public:
		virtual ~composite ();				// Виртуальный деструктор. Удаляем все дочерние объекты
		void Add (component *);				// Добавление объекта в дочерние
		void Delete (component *);			// Удаление объекта с заданным порядковым номером с очисткой памяти 
		container::size_type Count ();		// Возвращает количество дочерних объектов
		component * GetChild (unsigned int);	// Возвращает объект с указанным номером 
		virtual bool check_is_list () const;	// Возвращает значение статической константы is_list.
		
		virtual void Show (unsigned int = 0);	// Операция, которая должна единообразно применяться ко всем объектам
		
		virtual iterator * createIterator ();	// Возвращает итератор.
};

/*
 * Первый контейнер
 */
class con1 : public composite 
{
	public:
		con1 ();						// Конструктор публичный
		void Show (unsigned int = 0);	// Переопределяемая операция
		~con1 ();
};

/*
 * Второй контейнер
 */
class con2 : public composite 
{
	public:
		con2 ();						// Конструктор публичный
		void Show (unsigned int = 0);	// Переопределяемая операция
		~con2 ();
};

#endif // CLASSES_H
