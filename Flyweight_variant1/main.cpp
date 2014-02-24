#include <iostream>
#include "symbol.h"
#include <vector>
#include <string>

int main()
{
    std::string my_str ("This is test string for Flyweight pattern.");
    std::vector <std::shared_ptr <Symbol> > row;
    
    for (char c: my_str) row.push_back(Symbol::getSymbol(c));
    
    std::cout << "Для строки длинной " << row.size() << " используется объектов: " << Symbol::count() << std::endl;
    
    return 0;
    
    /*
Вывод программы:

Для строки длинной 42 используется объектов: 19
    */
}

