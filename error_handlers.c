#include "header.h"

/**
 * print_error - Displays error maessage
 * @input: input recieved from user
 * @counter: Count of shell lopp
 * @argv: Arguments before program starts (argv[0] == Shell
 * program Name)
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINT(agrv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 * _prerror - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell
 * program Name)
 * @c: Error Count
 * @cmd: Array of parsed command string
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er == _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}

/**
 * error_file - Printa custom Error
 * @argv: Arguments before program starts(argv[0] == Shell
 * program Name)
 * @c: Error count
 */
void error_file(char **argv, int c)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": Cant't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(er);
}
