#include <iostream>
#include "prototype.h"
#include "creator.h"

using namespace std;

int main()
{
    Creator creator;
    Prototype * copy;
    
    // Устанавливаем прототип. 
    creator.setPrototype(new Type1);
    
    // Создаем объекты. 
    copy = creator.create();
    cout << "Создан объект " << copy->get_name() << endl;
    delete copy;
    copy = creator.create();
    cout << "Создан объект " << copy->get_name() << endl;
    delete copy;
    
    // Установим другой прототип. 
    creator.setPrototype(new Type2);
    
    // Создаем объекты. 
    copy = creator.create();
    cout << "Создан объект " << copy->get_name() << endl;
    delete copy;
    copy = creator.create();
    cout << "Создан объект " << copy->get_name() << endl;
    delete copy;
    
    return 0;
    
    /*

Вывод программы:

Создан объект type 1
Создан объект type 1
Создан объект type 2
Создан объект type 2

    */
}

