#ifndef BUTTON_H
#define BUTTON_H

#include <string>
using std::string;
#include <memory>
using std::shared_ptr;

class command;

class button
{
	private:
		string name;
		shared_ptr<command> com;

	public:
		button (string name, shared_ptr<command> com);
		void clicked ();
};

#endif // BUTTON_H
