#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using std::string;

class application;

// Член класса receiver не объявлен в классе command, так как он может быть разного типа. В данном коде 
// просто случайно так получилось, что во всех классах наследниках он одного и того же типа application.
// Так же, в методе Execute определяется, добавлять ли команду в историю команд.

class command
{
	public:
		virtual ~command();
		virtual void Execute () = 0;
		virtual void UnExecute () = 0;
		virtual void ReExecute () = 0;	// Здесь мы не собираем данные о окружении, а берем их из членов класса.
};

class add_text_command : public command
{
	protected:
		unsigned int position;	// Номер символа, перед которым будет вставлен текст. 
		string text;
		application * receiver;	// Получатель команды.

	public:
		add_text_command (application * receiver);
		void Execute ();
		void UnExecute ();
		void ReExecute ();
};

class del_selected_command : public command
{
	protected:
		unsigned int first;		// Включается в промежуток.
		unsigned int last;		// Не включается в промежуток.
		string deleted_text;	// Удаленный текст на случай восстановления.
		application * receiver;	// Получатель команды.

	public:
		del_selected_command (application * receiver);
		void Execute ();
		void UnExecute ();
		void ReExecute ();
};

#endif // COMMAND_H
