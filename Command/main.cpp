#include "application.h"
#include "command.h"

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::shared_ptr;

// Переменные для эмулирования окружения. 
unsigned int select_start_position = 0;
unsigned int select_end_position = 0;
unsigned int cursor_position = 0;
string text_in_buffer("");

int main()
{
	application app;
	
	// Определяем команды, которые будут выполняться.
	shared_ptr<add_text_command> add_text(new add_text_command(& app));
	shared_ptr<del_selected_command> del_text(new del_selected_command(& app));
	
	// Добавляем в приложение меню и кнопки.
	menu * app_menu = new menu();
	app_menu->add(new menu_item("Вставить", add_text));
	app_menu->add(new menu_item("Удалить", del_text));
	app.set_menu(app_menu);
	app.add_button(new button("Удалить", del_text)); // Разделяем объект команды между двумя элементами интерфейса.
	
	// Начинаем работать с приложением.
	
	// Скопируем текст в буфер обмена и вставим его в приложение.
	text_in_buffer = "This signal is emitted when the application is about to quit \nthe main event loop, e.g. when the event loop level drops to zero.";
	cursor_position = 0;
	app.get_menu()->get(0)->clicked();
	text_in_buffer = "";
	cursor_position = 0;
	
	cout << "Добавили исходный текст" << endl;
	app.Show();
	
	// Удалим часть текста через меню.
	select_start_position = 10;
	select_end_position = 20;
	app.get_menu()->get(1)->clicked();
	select_start_position = 0;
	select_end_position = 0;
	
	cout << "Часть текста удалена" << endl;
	app.Show();

	// Вставим еще текст из буфера.
	text_in_buffer = "1111111111111111111111111";
	cursor_position = 15;
	app.get_menu()->get(0)->clicked();
	text_in_buffer = "";
	cursor_position = 0;
	
	cout << "Часть текста добавлена" << endl;
	app.Show();
	
	// Удалим часть текста через кнопку.
	select_start_position = 20;
	select_end_position = 50;
	app.get_button(0)->clicked();
	select_start_position = 0;
	select_end_position = 0;
	
	cout << "Часть текста удалена" << endl;
	app.Show();
	
	// Теперь будем производить последовательные отмены и смотреть результат.
	cout << "Начинаем отменять операции" << endl << endl;
	while (app.undo()) app.Show();
	
	// Теперь снова все повторим.
	cout << "Повторяем операции" << endl << endl;
	while (app.redo()) app.Show();
	
	return 0;
}

/*
Результат выполнения программы:

Добавили исходный текст
"This signal is emitted when the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

Часть текста удалена
"This signaed when the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

Часть текста добавлена
"This signaed wh1111111111111111111111111en the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

Часть текста удалена
"This signaed wh11111lication is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

Начинаем отменять операции

"This signaed wh1111111111111111111111111en the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

"This signaed when the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

"This signal is emitted when the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

""

Повторяем операции

"This signal is emitted when the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

"This signaed when the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

"This signaed wh1111111111111111111111111en the application is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

"This signaed wh11111lication is about to quit 
the main event loop, e.g. when the event loop level drops to zero."

*/
