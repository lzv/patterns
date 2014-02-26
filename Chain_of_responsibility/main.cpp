#include "handler.h"
#include <string>

using namespace std;

int main()
{
    // Создадим объекты и присвоим им данные.
    HandlerTypeNoHelp * obj1 = new HandlerTypeNoHelp;
    HandlerTypeNoHelp * obj2 = new HandlerTypeNoHelp;
    HaldlerTypeHelp * obj3 = new HaldlerTypeHelp;
    HaldlerTypeHelp * obj4 = new HaldlerTypeHelp;
    HaldlerTypeHelp * obj5 = new HaldlerTypeHelp;
    obj3->setHelpMessage("Это объект номер 3");
    obj5->setHelpMessage("Это объект номер 5");
    
    // Свяжем объекты в две цепочки: 1-3-5 и 2-4-5
    obj1->set_next(obj3);
    obj3->set_next(obj5);
    obj2->set_next(obj4);
    obj4->set_next(obj5);
    
    // Запускаем события в каждую цепочку. obj1 и obj2 не обрабатывают их и пропустят событие дальше. 
    // obj4 может его обработать, но у него нет данных, поэтому он тоже его пропустит дальше. 
    obj1->helpHandle();
    obj2->helpHandle();
    
    delete obj1;
    delete obj2;
    delete obj3;
    delete obj4;
    delete obj5;
    
    return 0;
    
    /*
Вывод программы:

Это объект номер 3
Это объект номер 5
    */
}

