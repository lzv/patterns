#include "builder.h"

void htmlBuilder::buildChar (char c) 
{
    content.push_back(c);
}

void htmlBuilder::buildCommand (TextFormatCommand command)
{
    switch (command)
    {
        case ITALIC_START:      content += "<i>";    break;
        case ITALIC_END:        content += "</i>";   break;
        case BOLD_START:        content += "<b>";    break;
        case BOLD_END:          content += "</b>";   break;
        case PARAGRAPH_START:   content += "<p>";    break;
        case PARAGRAPH_END:     content += "</p>";   break;
        case NEW_LINE:          content += "<br/>";  break;
        default: break;
    }
}

std::string htmlBuilder::getResult ()
{
    return content;
}

// --------------------------------------------------------------

void plainTextBuilder::buildChar (char c)
{
    content.push_back(c);
}

void plainTextBuilder::buildCommand (TextFormatCommand command)
{
    switch (command)
    {
        case PARAGRAPH_START:   content += "    ";    break;
        case PARAGRAPH_END:     content += "\n";      break;
        case NEW_LINE:          content += "\n";      break;
        default: break;
    }
}

std::string plainTextBuilder::result ()
{
    return content;
}
