#include <iostream>
#include "document.h"
#include "editor.h"

using namespace std;

int main()
{
    Document * doc;
    
    htmlEditor html_editor;
    doc = html_editor.createDocument();
    cout << "Тип созданного документа: " << doc->getType() << endl; // Будет выведен тип html
    delete doc;
    
    plainTextEditor ptext_editor;
    doc = ptext_editor.createDocument();
    cout << "Тип созданного документа: " << doc->getType() << endl; // Будет выведен тип plain text
    delete doc;
    
    return 0;
}
