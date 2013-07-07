#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "command_history.h"
#include "menu.h"
#include "button.h"

class application
{
	private:
		string content;
		command_history com_history;
		menu * p_menu;
		vector<button *> buttons;

	public:
		application ();
		~application ();

		void add_button (button * but);
		button * get_button (unsigned int index);
		
		void set_menu (menu * p);
		menu * get_menu ();

		void add_command_in_history (shared_ptr<command> com);
		bool undo ();
		bool redo ();
		
		void insert_text (unsigned int position, string text);
		void remove_text (unsigned int first, unsigned int last); // Удаляется текст в [firs, last).
		string get_text (unsigned int first, unsigned int last); // Возвращается текст в [firs, last).
		
		void Show ();
};

#endif // APPLICATION_H
