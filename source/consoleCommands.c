// ConsoleCommands.c
// This is where you add commands:
//		1. Add a protoype
//			static eCommandResult_T ConsoleCommandVer(const char buffer[]);
//		2. Add the command to mConsoleCommandTable
//		    {"ver", &ConsoleCommandVer, HELP("Get the version string")},
//		3. Implement the function, using ConsoleReceiveParam<Type> to get the parameters from the buffer.

#include <string.h>
#include "consoleCommands.h"
#include "console.h"
#include "baseCommands.h"
#include "consoleIo.h"
#include "version.h"

#define IGNORE_UNUSED_VARIABLE(x)     if ( &x == &x ) {}

eCommandResult_T ConsoleCommandComment(const char buffer[])
{
	// do nothing
	IGNORE_UNUSED_VARIABLE(buffer);
	return COMMAND_SUCCESS;
}

eCommandResult_T ConsoleCommandHelp(const char buffer[])
{
	uint32_t i;
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

    const sConsoleCommandTable_T *table = ConsoleCommandsGetTable();

	for ( i = 0u ; table[i].name != NULL; i++ )
	{
		ConsoleIoSendString(table[i].name);
        if ( CONSOLE_COMMAND_MAX_HELP_LENGTH > 0 )
        {
		    ConsoleIoSendString(" : ");
		    ConsoleIoSendString(table[i].help);
        }
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}


eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[])
{
	uint16_t parameterUint16;
	eCommandResult_T result;
	result = ConsoleReceiveParamHexUint16(buffer, 1, &parameterUint16);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is 0x");
		ConsoleSendParamHexUint16(parameterUint16);
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

eCommandResult_T ConsoleCommandVer(const char buffer[])
{
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

	ConsoleIoSendString(VERSION_STRING);
	ConsoleIoSendString(STR_ENDLINE);
	return result;
}

eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[])
{
	int16_t parameterInt;
	eCommandResult_T result;
	result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is ");
		ConsoleSendParamInt16(parameterInt);
		ConsoleIoSendString(" (0x");
		ConsoleSendParamHexUint16((uint16_t)parameterInt);
		ConsoleIoSendString(")");
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}
