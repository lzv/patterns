#include "glif.h"
#include "gliffactory.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    root text;
    std::string my_str_1("This is first test string.");
    std::string my_str_2("This is second test string.");
    
    glif * row = glifFactory::I().create_composite();
    for (char c: my_str_1) row->Add(glifFactory::I().create_symbol(c));
    text.Add(row);
    
    row = glifFactory::I().create_composite();
    for (char c: my_str_2) row->Add(glifFactory::I().create_symbol(c));
    text.Add(row);
    
    cout << "В тексте всего символов: " << text.Count() - 2 << endl;
    cout << "Но реально в памяти объектов: " << glifFactory::I().count() << endl;
    
    return 0;
    
    /*
Вывод программы: 

В тексте всего символов: 53
Но реально в памяти объектов: 15
    */
}

