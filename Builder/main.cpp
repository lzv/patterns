#include <iostream>
#include "builder.h"
#include "myformatparser.h"

int main()
{
    std::string text("[PARAGRAPH_START]Это мой текст для [BOLD_START]примера[BOLD_END]. Первый параграф. [PARAGRAPH_END]"
                     "[PARAGRAPH_START]Это второй параграф моего текста для примера.[NEW_LINE]"
                     "Начнем [ITALIC_START]новую[ITALIC_END] строку.[PARAGRAPH_END]");
    
    // Выводим исходный текст. 
    std::cout << text << std::endl << std::endl;
    
    // Объект для парсинга текста.
    MyFormatParser parser;
    
    // Сконвертируем исходный текст в html и выведем результат.
    htmlBuilder to_thml;
    parser.convert(text, & to_thml);
    std::cout << to_thml.getResult() << std::endl << std::endl;
    
    // Сконвертируем исходный текст в простой текст и выведем результат.
    plainTextBuilder to_plain_text;
    parser.convert(text, & to_plain_text);
    std::cout << to_plain_text.result() << std::endl << std::endl;
    
    return 0;
    
    /*
Результат выполнения:

[PARAGRAPH_START]Это мой текст для [BOLD_START]примера[BOLD_END]. Первый параграф. [PARAGRAPH_END][PARAGRAPH_START]Это второй параграф моего текста для примера.[NEW_LINE]Начнем [ITALIC_START]новую[ITALIC_END] строку.[PARAGRAPH_END]

<p>Это мой текст для <b>примера</b>. Первый параграф. </p><p>Это второй параграф моего текста для примера.<br/>Начнем <i>новую</i> строку.</p>

    Это мой текст для примера. Первый параграф. 
    Это второй параграф моего текста для примера.
Начнем новую строку.
    */
}

