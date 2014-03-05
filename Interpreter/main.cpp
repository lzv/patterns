#include <iostream>
#include "expression.h"

int main()
{
    // Сделанная реализация проверяет с начала строки, но если проверка завершена до конца строки,
    // то она все равно считается пройденной успешно. 
    
    // Регулярное выражение: ("dog" | "cat") & " runs to " & ("eat" +)
    Sequence expr(
                new Alternation(
                    new Literal("dog"), 
                    new Literal("cat")
                    ), 
                new Sequence(
                    new Literal(" runs to "), 
                    new Repetition(
                        new Literal("eat")
                        )
                    )
                );
    
    // Строки для проверки: 
    std::string str1("cat runs to eateateat!");
    std::string str2("dog runs to great eat!");
    
    // Проверяем:
    Context c1(str1);
    std::cout << str1 << " - проверка " << (expr.Check(c1) ? "пройдена" : "провалена") << std::endl;
    Context c2(str2);
    std::cout << str2 << " - проверка " << (expr.Check(c2) ? "пройдена" : "провалена") << std::endl;
    
    return 0;
    
    /*

Вывод программы:

cat runs to eateateat! - проверка пройдена
dog runs to great eat! - проверка провалена

    */
}

