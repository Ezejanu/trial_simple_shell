#include "shell.h"

/* Built ins */

/**
 * shouldExit - A function to check exit condition.
 * @command: command issued to the shell
 * Return: 0 if it isn't a match, otherwise return 1.
 */

/* Made a change here- changed data type of 'command' from 'char' to 'char *' */
int shouldExit(char *command)
{
    char *expectedExitCommand = "exit";

    if (strcmp(command, expectedExitCommand) == 0)
    {
        return (1);
    }
    return (0)
}

/**
 * _env - a function to compare if command is 'env'
 * and print the environment if it is a match.
 *
 * @command: command to be compared and printed.
 *
 * Return: void.
 */

void isEnvCommand(char *command)
{
    int i, commandLength;
    struct stat statbuf;

    char *expectedEnvCommand = "env";

    int commandLength = strlen(command);
    char lastThreeChar[3] = {
        command[commandLength - 3],
        command[commandLength - 2],
        command[commandLength - 1]};

    if (strcmp(command, expectedEnvCommand) == 0)
    {
        if (
            commandLength == 3 ||
            (commandLength > 3 && stat(command, &statbuf) == 0))
        {
            return (1);
        }
    }

    return (0);
}

/**
 * _printenv - A function to print the environment.
 *
 * Return: void.
 */
void _printEnv()
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        _write(environ[i]);
        _write("\n");
    }
}