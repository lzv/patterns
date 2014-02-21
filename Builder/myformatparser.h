#ifndef MYFORMATPARSER_H
#define MYFORMATPARSER_H

/*
Парсер распознает свой формат и переводит его специфические команды форматирования в объекты, известные 
и парсеру, и всем строителям. В данном случае в роли объектов используется перечисление TextFormatCommand
из файла data.h.
Благодаря этому, можно сделать парсеры других форматов, которые смогут использовать тех же строителей
для конвертирования.
*/

#include <string>

class Builder;

class MyFormatParser
{
    public:
        MyFormatParser();
        void convert (const std::string & str, Builder * builder);
};

#endif // MYFORMATPARSER_H
