#ifndef BASE_COMMANDS_H
#define BASE_COMMANDS_H

#include "consoleCommands.h"

eCommandResult_T ConsoleCommandComment(const char buffer[]);
eCommandResult_T ConsoleCommandVer(const char buffer[]);
eCommandResult_T ConsoleCommandHelp(const char buffer[]);
eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[]);
eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[]);

#endif // BASE_COMMANDS_H
