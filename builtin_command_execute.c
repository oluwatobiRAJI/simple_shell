#include "header.h"

/**
 * change_dir - Changes directory
 * @cmd: Parsed command
 * @st: Status of last command exected
 *
 * Return: 0 on Success 1 if failed (For OLDPWD Always
 * 0 incase of no OLDPWD)
 */
int change_dir(char **cmd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);
	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * echo_bul - Execute echo cases
 * @st: statue of last command executed
 * @cmd: parsed command
 *
 * Return: Always 1 or execute normal echo
 */

int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmp[1], "&?", 2) == 0)
	{
		print_number_int(st);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_echo(cmd));
	return (1);
}

/**
 * history_dis - DIsplay history of user input on simple_shell
 * @c: parsed commond
 * @str: Status of last command executed
 *
 * Return: 0 Sucess otherwise -1 Fail
 */
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused))int str)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *linn = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
