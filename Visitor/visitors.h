#ifndef VISITORS_H
#define VISITORS_H

#include <map>
#include <string>
using std::map;
using std::string;

class simbol;
class space;
class new_line;
class text;
class paragraph;
class row;

// Интерфейс для посетителей 
class visitor 
{
	public:
		virtual void visit_simbol (simbol *) = 0;
		virtual void visit_space (space *) = 0;
		virtual void visit_new_line (new_line *) = 0;
		virtual void visit_text (text *) = 0;
		virtual void visit_paragraph (paragraph *) = 0;
		virtual void visit_row (row *) = 0;
};

// Алгоритм подсчета символов.
class count_simbols : public visitor
{
	public:
		typedef map<char, int> result_type;
	private:
		result_type result;
		void add_char (char c);
	public:
		void ShowResult ();
		void visit_simbol (simbol *);
		void visit_space (space *);
		void visit_new_line (new_line *);
		void visit_text (text *);
		void visit_paragraph (paragraph *);
		void visit_row (row *);
};

// Алгоритм подсчета типов объектов.
class count_types : public visitor
{
	public:
		typedef map<string, int> result_type;
	private:
		result_type result;
	public:
		count_types ();
		void ShowResult ();
		void visit_simbol (simbol *);
		void visit_space (space *);
		void visit_new_line (new_line *);
		void visit_text (text *);
		void visit_paragraph (paragraph *);
		void visit_row (row *);
};

#endif // VISITORS_H
