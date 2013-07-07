#include "command.h"
#include "application.h"

#include <memory>
using std::shared_ptr;

extern unsigned int select_start_position;
extern unsigned int select_end_position;
extern unsigned int cursor_position;
extern string text_in_buffer;

//#include <iostream>
//using std::cout;
//using std::endl;

// Интерфейс для команд.

command::~command () {}

// Команда добавления текста.

add_text_command::add_text_command (application * receiver) : position(0), text(""), receiver(receiver) {}

void add_text_command::Execute ()
{
	// Запоминаем параметры.
	position = cursor_position;
	text = text_in_buffer;
	// Выполняем действие.
	this->ReExecute();
	// Создаем копию команды для сохранения параметров и добавляем ее в историю.
	add_text_command * new_command = new add_text_command(receiver);
	(*new_command) = (*this);
	receiver->add_command_in_history(shared_ptr<command>(new_command));
}

void add_text_command::UnExecute ()
{
	//cout << endl << "UnExecute добавления, удаляем с " << position << " по " << position + text.length() << endl;
	receiver->remove_text(position, position + text.length());
}

void add_text_command::ReExecute ()
{
	//cout << endl << "ReExecute добавления, вставляем на " << position << " текст " << text << endl;
	receiver->insert_text(position, text);
}

// Команда удаления текста.

del_selected_command::del_selected_command (application * receiver) 
	: first(0), last(0), deleted_text(string("")), receiver(receiver) {}

void del_selected_command::Execute ()
{
	// Запоминаем параметры.
	first = select_start_position;
	last = select_end_position;
	if (first < last) deleted_text = receiver->get_text(first, last);
	// Выполняем действие.
	this->ReExecute();
	// Создаем копию команды для сохранения параметров и добавляем ее в историю.
	del_selected_command * new_command = new del_selected_command(receiver);
	(*new_command) = (*this);
	receiver->add_command_in_history(shared_ptr<command>(new_command));
}

void del_selected_command::UnExecute ()
{
	//cout << endl << "UnExecute удаления, вставляем на " << first << " текст " << deleted_text << endl;
	receiver->insert_text(first, deleted_text);
}

void del_selected_command::ReExecute ()
{
	//cout << endl << "ReExecute удаления, удаляем с " << first << " до " << last << endl;
	receiver->remove_text(first, last);
}
