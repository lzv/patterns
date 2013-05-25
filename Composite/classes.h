#ifndef CLASSES_H
#define CLASSES_H

#include <vector>
using std::vector;

/*
 * Абстрактный класс-интерфейс для всех объектов системы
 */
class component 
{
	public:
		typedef vector <component *> container;
	protected:
		component ();						// Конструктор protected, так как создавать объекты этого класса не нужно
	public:
		virtual ~component ();				// Виртуальный деструктор
		virtual void Add (component *);		// Добавление объекта в дочерние
		virtual void Delete (component *);	// Удаление объекта с заданным порядковым номером с очисткой памяти 
		virtual container::size_type Count ();		// Возвращает количество дочерних объектов
		virtual component * GetChild (unsigned int);// Возвращает объект с указанным номером 
		
		virtual void Show (unsigned int = 0);	// Операция, которая должна единообразно применяться ко всем объектам
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
	public:
		virtual ~composite ();				// Виртуальный деструктор. Удаляем все дочерние объекты
		void Add (component *);				// Добавление объекта в дочерние
		void Delete (component *);			// Удаление объекта с заданным порядковым номером с очисткой памяти 
		container::size_type Count ();		// Возвращает количество дочерних объектов
		component * GetChild (unsigned int);	// Возвращает объект с указанным номером 
		
		virtual void Show (unsigned int = 0);	// Операция, которая должна единообразно применяться ко всем объектам
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
