#include "visitors.h"
#include "glifs.h"

#include <iostream>
using std::cout;
using std::endl;

// Алгоритм подсчета символов.

void count_simbols::add_char (char c)
{
	if (result.count(c)) result[c] += 1;
	else result[c] = 1; 
}

void count_simbols::ShowResult ()
{
	result_type::const_iterator i, end = result.end();
	for (i = result.begin(); i != end; ++i)
	{
		if (i->first == ' ') cout << "space";
		else if (i->first == '\n') cout << "end line";
		else cout << i->first;
		cout << ": " << i->second << endl;
	}
}

void count_simbols::visit_simbol (simbol * obj) {add_char(obj->GetSimbol());}
void count_simbols::visit_space (space *) {add_char(' ');}
void count_simbols::visit_new_line (new_line *) {add_char('\n');}

void count_simbols::visit_text (text *) {}
void count_simbols::visit_paragraph (paragraph *) {}
void count_simbols::visit_row (row *) {}

// Алгоритм подсчета типов объектов.

count_types::count_types ()
{
	result["simbol"] = 0;
	result["space"] = 0;
	result["new_line"] = 0;
	result["text"] = 0;
	result["paragraph"] = 0;
	result["row"] = 0;
}

void count_types::ShowResult ()
{
	result_type::const_iterator i, end = result.end();
	for (i = result.begin(); i != end; ++i) cout << i->first << ": " << i->second << endl;
}

void count_types::visit_simbol (simbol *) {result["simbol"] += 1;}
void count_types::visit_space (space *) {result["space"] += 1;}
void count_types::visit_new_line (new_line *) {result["new_line"] += 1;}
void count_types::visit_text (text *) {result["text"] += 1;}
void count_types::visit_paragraph (paragraph *) {result["paragraph"] += 1;}
void count_types::visit_row (row *) {result["row"] += 1;}
