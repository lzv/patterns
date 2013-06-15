#ifndef STRATEGIES_H
#define STRATEGIES_H

#include "glifs.h"

// Интерфейс стратегий.
class strategy
{
	public:
		strategy ();
		virtual void Run (glif *) = 0;
};

// Очистка текста от строк и символов переноса строк
class clear_text : public strategy
{
	public:
		clear_text ();
		void Run (glif * glif_obj);
};

// Разбиение на строки по символам
class row_split_by_simbols : public strategy
{
	private:
		unsigned int lenght;
	public:
		row_split_by_simbols (unsigned int len);
		void Run (glif * glif_obj);
};

// Разбиение на строки по словам
class row_split_by_words : public strategy
{
	private:
		unsigned int lenght;
	public:
		row_split_by_words (unsigned int len);
		void Run (glif * glif_obj);
};

#endif // STRATEGIES_H
