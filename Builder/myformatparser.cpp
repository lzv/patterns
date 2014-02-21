#include "myformatparser.h"
#include "data.h"
#include "builder.h"

MyFormatParser::MyFormatParser() {}

void MyFormatParser::convert (const std::string & str, Builder * builder)
{
    if (builder)
    {
        int len = str.length();
        std::string command_str;
        bool is_command = false;
        for (int i = 0; i < len; ++i)
        {
            if (is_command)
            {
                if (str[i] == ']') {
                    is_command = false;
                    TextFormatCommand command = EMPTY_COMMAND;
                    if (command_str == "ITALIC_START") command = ITALIC_START;
                    else if (command_str == "ITALIC_END") command = ITALIC_END;
                    else if (command_str == "BOLD_START") command = BOLD_START;
                    else if (command_str == "BOLD_END") command = BOLD_END;
                    else if (command_str == "PARAGRAPH_START") command = PARAGRAPH_START;
                    else if (command_str == "PARAGRAPH_END") command = PARAGRAPH_END;
                    else if (command_str == "NEW_LINE") command = NEW_LINE;
                    builder->buildCommand(command);
                }
                else {
                    command_str.push_back(str[i]);
                }
            }
            else {
                if (str[i] == '[')
                {
                    is_command = true;
                    command_str = "";
                }
                else {
                    builder->buildChar(str[i]);
                }
            }
        }
    }
}
