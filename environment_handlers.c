#include "header.h"

/**
 * create_envi - Creates an array of Enviroments Variables
 * @envi: Array to store Enviroment Variable
 */
void create_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_env - Frees the memory of the created Enviroment Variables array
 * @env: Array of enviroment variables
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
