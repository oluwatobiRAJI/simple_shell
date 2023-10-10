#include "header.h"

/**
 * parse_cmd - Parses the command recieved from stdin
 * @input: String gathered from stdin
 *
 * Return: Parsed strings to be used as arguments
 */
char **parse_cmd(charr *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(chr *) * buffsize);

	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argment = _strtok(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}
