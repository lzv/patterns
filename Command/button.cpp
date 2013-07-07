#include "button.h"
#include "command.h"

button::button (string name, shared_ptr<command> com) : name(name), com(com) {}
void button::clicked () {com->Execute();}
